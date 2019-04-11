//          Copyright Jean Pierre Cimalando 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <zlib.h>
#include <getopt.h>
#include <vector>
#include <string>
#include <memory>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <cstring>

///
struct FILE_delete { void operator()(FILE *x) const noexcept { fclose(x); } };
typedef std::unique_ptr<FILE, FILE_delete> FILE_u;

struct gzFile_delete { void operator()(gzFile x) const noexcept { gzclose(x); } };
typedef std::unique_ptr<gzFile_s, gzFile_delete> gzFile_u;

///
static uint32_t decode_u32(const uint8_t *data);
static uint16_t decode_u16(const uint8_t *data);
static void encode_u32(uint8_t *data, uint32_t x);
static void encode_u16(uint8_t *data, uint16_t x);
static bool read_u32(gzFile in, uint32_t *dst);
static bool read_u16(gzFile in, uint16_t *dst);
static bool write_u32(FILE *out, uint32_t src);
static bool write_u16(FILE *out, uint16_t src);
static bool write_u8(FILE *out, uint8_t src);

///
static std::string hhmmss(uint32_t sec);

///
struct AY_command { uint32_t delay; uint8_t reg; uint8_t val; };
static bool read_ay_vgm(gzFile in, uint32_t *clock, const char **chip_type, std::vector<AY_command> &ay_cmds);
static void make_vgm_size_table(uint8_t *table, unsigned version);

///
static void write_ay_rsf(FILE *out, const std::vector<AY_command> &in_cmds, uint32_t clock, uint32_t src_sample_rate, uint32_t rsf_frequency);
static uint32_t ay_quant(std::vector<AY_command> &cmds, uint32_t old_rate, uint32_t new_rate);

///
static void show_help()
{
    fprintf(stderr,
            "Usage: vgm2rsf [-h] [-o <file.rsf>] [-f <frequency>] <file.vgm>\n"
            "  -h             : show the help\n"
            "  -o <file.rsf>  : output file in RSF3 format\n"
            "  -f <frequency> : interrupt frequency of result file (default 100 Hz)\n"
            "  <file.vgm>     : input file in VGM or VGZ format\n");
}

int main(int argc, char *argv[])
{
    const char *file_out = nullptr;
    uint16_t rsf_frequency = 100;

    if (argc < 2) {
        show_help();
        return 0;
    }

    for (int c; (c = getopt(argc, argv, "o:f:h")) != -1;) {
        switch (c) {
        case 'o':
            file_out = optarg;
            break;
        case 'f': {
            int arg = atoi(optarg);
            if (arg < 1 || arg > 1000) {
                fprintf(stderr, "frequency must be between 1 and 1000 Hz.\n");
                return 1;
            }
            rsf_frequency = arg;
            break;
        }
        case 'h':
            show_help();
            return 0;
        default:
            show_help();
            return 1;
        }
    }

    if (argc - optind != 1) {
        fprintf(stderr, "must specify exactly one input file.\n");
        return 1;
    }

    ///
    const char *file_in = argv[optind];
    gzFile in = gzopen(file_in, "rb");
    if (!in) {
        fprintf(stderr, "cannot open input file.\n");
        return 1;
    }
    gzFile_u in_cleanup(in);

    std::vector<AY_command> ay_cmds;
    uint32_t clock;
    const char *chip_type;

    ay_cmds.reserve(1024);
    if (!read_ay_vgm(in, &clock, &chip_type, ay_cmds)) {
        fprintf(stderr, "cannot load the VGM file.\n");
        return 1;
    }

    uint32_t total_delay = 0;
    for (const AY_command &cmd : ay_cmds)
        total_delay += cmd.delay;

    int vgm_sample_rate = 44100;

    fprintf(stderr, "File: %s\n", file_in);
    fprintf(stderr, "Output file: %s\n", file_out);
    fprintf(stderr, "Chip: %s\n", chip_type);
    fprintf(stderr, "Clock: %u\n", clock);
    fprintf(stderr, "Sample rate: %u\n", vgm_sample_rate);
    fprintf(stderr, "Total samples: %u\n", total_delay);
    fprintf(stderr, "Duration: %s\n", hhmmss(total_delay / vgm_sample_rate).c_str());
    fprintf(stderr, "Output frequency: %u\n", rsf_frequency);

    if (file_out) {
        FILE *out = fopen(file_out, "wb");
        if (!out) {
            fprintf(stderr, "cannot open output file.\n");
            return 1;
        }
        FILE_u out_cleanup(out);

        write_ay_rsf(out, ay_cmds, clock, vgm_sample_rate, rsf_frequency);

        if (fflush(out) != 0) {
            fprintf(stderr, "cannot write output file.\n");
            return 1;
        }
    }

    return 0;
}

///
static uint32_t decode_u32(const uint8_t *data)
{
    return data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
}

static uint16_t decode_u16(const uint8_t *data)
{
    return data[0] | (data[1] << 8);
}

static void encode_u32(uint8_t *data, uint32_t x)
{
    for (unsigned i = 0; i < 4; ++i)
        data[i] = (x >> (8 * i)) & 0xFF;
}

static void encode_u16(uint8_t *data, uint16_t x)
{
    for (unsigned i = 0; i < 2; ++i)
        data[i] = (x >> (8 * i)) & 0xFF;
}

static bool read_u32(gzFile in, uint32_t *dst)
{
    uint8_t tmp[4];
    if (gzread(in, tmp, 4) != 4)
        return false;
    if (dst)
        *dst = decode_u32(tmp);
    return true;
}

static bool read_u16(gzFile in, uint16_t *dst)
{
    uint8_t tmp[2];
    if (gzread(in, tmp, 2) != 2)
        return false;
    if (dst)
        *dst = decode_u16(tmp);
    return true;
}

static bool write_u32(FILE *out, uint32_t src)
{
    uint8_t tmp[4];
    encode_u32(tmp, src);
    return fwrite(tmp, 1, 4, out) == 4;
}

static bool write_u16(FILE *out, uint16_t src)
{
    uint8_t tmp[2];
    encode_u16(tmp, src);
    return fwrite(tmp, 1, 2, out) == 2;
}

static bool write_u8(FILE *out, uint8_t src)
{
    return fwrite(&src, 1, 1, out) == 1;
}

///
static std::string hhmmss(uint32_t sec)
{
    char buf[32];
    unsigned ss = sec;
    unsigned hh = ss / 3600;
    ss -= hh * 3600;
    unsigned mm = ss / 60;
    ss -= mm * 60;
    sprintf(buf, "%02u:%02u:%02u", hh, mm, ss);
    return buf;
}

///
static bool read_ay_vgm(gzFile in, uint32_t *clock, const char **chip_type, std::vector<AY_command> &ay_cmds)
{
    uint8_t vgm_header[0x100];
    if (gzread(in, vgm_header, 0x100) != 0x100 || memcmp(vgm_header, "Vgm ", 4))
        return false;

    uint32_t vgm_version = decode_u32(vgm_header + 0x08);

    uint8_t vgm_sizetable[0x100];
    make_vgm_size_table(vgm_sizetable, vgm_version);

    uint32_t data_offset = 0x0C;
    if (vgm_version >= 0x150)
        data_offset = decode_u32(vgm_header + 0x34);
    if (gzseek(in, 0x34 + data_offset, SEEK_SET) == -1)
        return false;

    uint32_t clock_AY = 0;
    uint32_t clock_YM2608 = 0;
    uint32_t clock_YM2610 = 0;

    if ((clock_AY = decode_u32(vgm_header + 0x74))) {
        switch (vgm_header[0x78]) {
        default: *chip_type = "AY unknown"; break;
        case 0x00: *chip_type = "AY8910"; break;
        case 0x01: *chip_type = "AY8912"; break;
        case 0x02: *chip_type = "AY8913"; break;
        case 0x03: *chip_type = "AY8930"; break;
        case 0x10: *chip_type = "YM2149"; break;
        case 0x11: *chip_type = "YM3439"; break;
        case 0x12: *chip_type = "YMZ284"; break;
        case 0x13: *chip_type = "YMZ294"; break;
        }
        *clock = clock_AY;
    }
    else if ((clock_YM2608 = decode_u32(vgm_header + 0x48))) {
        *chip_type = "YM2608 PSG";
        *clock = clock_YM2608 / 4;
    }
    else if ((clock_YM2610 = decode_u32(vgm_header + 0x4C))) {
        *chip_type = "YM2610 PSG";
        *clock = clock_YM2610 / 4;
    }
    else
        return false; // no compatible device

    // TODO dynamic YM PSG clock

    uint32_t wait = 0;

    for (bool end = false; !end;) {
        uint8_t cmd = 0;

        if (gzread(in, &cmd, 1) != 1) // premature end
            break;

        switch (cmd) {
        default: {
            uint8_t to_skip = vgm_sizetable[cmd];
            if(to_skip != 0xFF) {
                if (gzseek(in, to_skip, SEEK_CUR) == -1)
                    end = true; // premature end
            }
            else
                end = true; // unrecognized command
            break;
        }

        case 0x61: {
            uint16_t delay;
            if (!read_u16(in, &delay))
                end = true;
            else
                wait += delay;
            break;
        }

        case 0x62:
            wait += 735;
            break;

        case 0x63:
            wait += 882;
            break;

        case 0x66: // end of sound data
            end = true;
            break;

        case 0x67: // data block
        {
            uint32_t pcm_offset;
            if (gzseek(in, 2, SEEK_CUR) == -1 || !read_u32(in, &pcm_offset))
                end = true;
            break;
        }

        case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77:
        case 0x78: case 0x79: case 0x7a: case 0x7b: case 0x7c: case 0x7d: case 0x7e: case 0x7f:
            wait += cmd - 0x6f;
            break;

        case 0xa0: // AY8190
            if (clock_AY) {
                uint8_t ay_data[2];
                if (gzread(in, ay_data, 2) != 2) // premature end
                    break;
                AY_command ay;
                ay.delay = wait;
                ay.reg = ay_data[0];
                ay.val = ay_data[1];
                ay_cmds.push_back(ay);
                wait = 0;
            }
            break;

        case 0x56: // YM2608 port 0
        case 0x58: // YM2610 port 0
            if ((clock_YM2608 && cmd == 0x56) || (clock_YM2610 && cmd == 0x58)) {
                uint8_t ym_data[2];
                if (gzread(in, ym_data, 2) != 2) // premature end
                    break;

                if (ym_data[0] < 0x10) {
                    AY_command ay;
                    ay.delay = wait;
                    ay.reg = ym_data[0];
                    ay.val = ym_data[1];
                    ay_cmds.push_back(ay);
                    wait = 0;
                }
            }
            break;
        }
    }

    return true;
}

static void make_vgm_size_table(uint8_t *table, unsigned version)
{
    memset(table, 0xFF, 0x100);
    table[0x4F] = 1;  // Game Gear PSG stereo, write dd to port 0x06
    table[0x50] = 1;  // PSG (SN76489/SN76496) write value dd
    table[0x51] = 2;  // YM2413, write value dd to register aa
    table[0x52] = 2;  // YM2612 port 0, write value dd to register aa
    table[0x53] = 2;  // YM2612 port 1, write value dd to register aa
    table[0x54] = 2;  // YM2151, write value dd to register aa
    table[0x55] = 2;  // YM2203, write value dd to register aa
    table[0x56] = 2;  // YM2608 port 0, write value dd to register aa
    table[0x57] = 2;  // YM2608 port 1, write value dd to register aa
    table[0x58] = 2;  // YM2610 port 0, write value dd to register aa
    table[0x59] = 2;  // YM2610 port 1, write value dd to register aa
    table[0x5A] = 2;  // YM3812, write value dd to register aa
    table[0x5B] = 2;  // YM3526, write value dd to register aa
    table[0x5C] = 2;  // Y8950, write value dd to register aa
    table[0x5D] = 2;  // YMZ280B, write value dd to register aa
    table[0x5E] = 2;  // YMF262 port 0, write value dd to register aa
    table[0x5F] = 2;  // YMF262 port 1, write value dd to register aa
    table[0x61] = 2;  // Wait n samples, n can range from 0 to 65535 (approx 1.49 seconds). Longer pauses than this are represented by multiple wait commands.
    table[0x62] = 0;  // wait 735 samples (60th of a second), a shortcut for 0x61 0xdf 0x02
    table[0x63] = 0;  // wait 882 samples (50th of a second), a shortcut for 0x61 0x72 0x03
    table[0x66] = 0;  // end of sound data
    table[0x67] = /* variable size */0xFF;  // data block: see below
    table[0x68] = 11;  // PCM RAM write: see below
    for(unsigned a = 0x70; a <= 0x7F; ++a)
        table[a] = 0;  // wait n+1 samples, n can range from 0 to 15.
    for(unsigned a = 0x80; a <= 0x8F; ++a)
        table[a] = 0;  // YM2612 port 0 address 2A write from the data bank, then wait n samples; n can range from 0 to 15. Note that the wait is n, NOT n+1. See also command 0xE0.
    table[0x90] = 4;  // Setup Stream Control
    table[0x91] = 4;  // Set Stream Data
    table[0x92] = 5;  // Set Stream Frequency
    table[0x93] = 10;  // Start Stream
    table[0x94] = 1;  // Stop Stream
    table[0x95] = 4;  // Start Stream (fast call)
    table[0xA0] = 2;  // AY8910, write value dd to register aa
    table[0xB0] = 2;  // RF5C68, write value dd to register aa
    table[0xB1] = 2;  // RF5C164, write value dd to register aa
    table[0xB2] = 2;  // PWM, write value ddd to register a (d is MSB, dd is LSB)
    table[0xB3] = 2;  // GameBoy DMG, write value dd to register aa
    table[0xB4] = 2;  // NES APU, write value dd to register aa
    table[0xB5] = 2;  // MultiPCM, write value dd to register aa
    table[0xB6] = 2;  // uPD7759, write value dd to register aa
    table[0xB7] = 2;  // OKIM6258, write value dd to register aa
    table[0xB8] = 2;  // OKIM6295, write value dd to register aa
    table[0xB9] = 2;  // HuC6280, write value dd to register aa
    table[0xBA] = 2;  // K053260, write value dd to register aa
    table[0xBB] = 2;  // Pokey, write value dd to register aa
    table[0xBC] = 2;  // WonderSwan, write value dd to register aa
    table[0xBD] = 2;  // SAA1099, write value dd to register aa
    table[0xBE] = 2;  // ES5506, write value dd to register aa
    table[0xBF] = 2;  // GA20, write value dd to register aa
    table[0xC0] = 3;  // Sega PCM, write value dd to memory offset aabb
    table[0xC1] = 3;  // RF5C68, write value dd to memory offset aabb
    table[0xC2] = 3;  // RF5C164, write value dd to memory offset aabb
    table[0xC3] = 3;  // MultiPCM, write set bank offset aabb to channel cc
    table[0xC4] = 3;  // QSound, write value mmll to register rr (mm - data MSB, ll - data LSB)
    table[0xC5] = 3;  // SCSP, write value dd to memory offset mmll (mm - offset MSB, ll - offset LSB)
    table[0xC6] = 3;  // WonderSwan, write value dd to memory offset mmll (mm - offset MSB, ll - offset LSB)
    table[0xC7] = 3;  // VSU, write value dd to memory offset mmll (mm - offset MSB, ll - offset LSB)
    table[0xC8] = 3;  // X1-010, write value dd to memory offset mmll (mm - offset MSB, ll - offset LSB)
    table[0xD0] = 3;  // YMF278B, port pp, write value dd to register aa
    table[0xD1] = 3;  // YMF271, port pp, write value dd to register aa
    table[0xD2] = 3;  // SCC1, port pp, write value dd to register aa
    table[0xD3] = 3;  // K054539, write value dd to register ppaa
    table[0xD4] = 3;  // C140, write value dd to register ppaa
    table[0xD5] = 3;  // ES5503, write value dd to register ppaa
    table[0xD6] = 3;  // ES5506, write value aadd to register pp
    table[0xE0] = 4;  // Seek to offset dddddddd (Intel byte order) in PCM data bank of data block type 0 (YM2612).
    table[0xE1] = 4;  // C352, write value aadd to register mmll
    for(unsigned a = 0x30; a <= 0x3F; ++a)
        table[a] = 1;  // one operand, reserved for future use
    for(unsigned a = 0x40; a <= 0x4E; ++a)
    {
        if(version >= 0x160)
            table[a] = 2;  // two operands, reserved for future use
        else
            table[a] = 1;  // was one operand only til v1.60
    }
    for(unsigned a = 0xA1; a <= 0xAF; ++a)
        table[a] = 2;  // two operands, reserved for future use
    for(unsigned a = 0xC9; a <= 0xCF; ++a)
        table[a] = 3;  // three operands, reserved for future use
    for(unsigned a = 0xD7; a <= 0xDF; ++a)
        table[a] = 3;  // three operands, reserved for future use
    for(unsigned a = 0xE2; a <= 0xFF; ++a)
        table[a] = 4;  // three operands, reserved for future use
}

static void write_ay_rsf(FILE *out, const std::vector<AY_command> &in_cmds, uint32_t clock, uint32_t src_sample_rate, uint32_t rsf_frequency)
{
    std::vector<AY_command> rsf_cmds = in_cmds;
    uint32_t frame_count = ay_quant(rsf_cmds, src_sample_rate, rsf_frequency);

    off_t pos_begin = ftello(out);
    fwrite("RSF\x03", 1, 4, out);
    write_u16(out, rsf_frequency);

    off_t pos_song_offset = ftello(out);
    write_u16(out, 0); // write later: song offset
    write_u32(out, frame_count);
    write_u32(out, 0); // TODO: loop frame
    write_u32(out, clock);

    char title[] = "";
    char author[] = "";
    char comment[] = "";
    fwrite(title, 1, strlen(title) + 1, out);
    fwrite(author, 1, strlen(author) + 1, out);
    fwrite(comment, 1, strlen(comment) + 1, out);

    off_t pos_song_begin = ftello(out);

    uint8_t ay_regs[16] = {};

    for (size_t i = 0, n = rsf_cmds.size(); i < n; ++i) {
        const AY_command *cmd = &rsf_cmds[i];

        uint32_t delay = cmd->delay;
        if (delay > 1) {
            --delay;
            while (delay > 0) {
                uint32_t current = (delay < 0x100) ? delay : 0xFF;
                fputc(0xFE, out);
                fputc(current, out);
                delay -= current;
            }
        }

        uint8_t ay_old_regs[14];
        memcpy(ay_old_regs, ay_regs, 14);

        if (cmd->reg < 14)
            ay_regs[cmd->reg] = cmd->val;

        while (i + 1 < n && rsf_cmds[i + 1].delay == 0) {
            cmd = &rsf_cmds[++i];
            if (cmd->reg < 14)
                ay_regs[cmd->reg] = cmd->val;
        }

        uint16_t reg_mask = 0;
        for (unsigned i = 0; i < 14; ++i) {
            if (ay_regs[i] != ay_old_regs[i])
                reg_mask |= 1 << i;
        }

        write_u8(out, reg_mask >> 8);
        write_u8(out, reg_mask & 0xFF);
        for (unsigned i = 0; i < 14; ++i) {
            if (reg_mask & (1 << i))
                write_u8(out, ay_regs[i]);
        }
    }

    fseeko(out, pos_song_offset, SEEK_SET);
    write_u16(out, pos_song_begin - pos_begin);
}

static uint32_t ay_quant(std::vector<AY_command> &cmds, uint32_t old_rate, uint32_t new_rate)
{
    uint32_t total_frames = 0;
    double acc_delay = 0;
    double old_interval = 1.0 / old_rate;
    double new_interval = 1.0 / new_rate;

    for (AY_command &cmd : cmds) {
        acc_delay += cmd.delay * old_interval;
        uint32_t frames = acc_delay * new_rate;
        acc_delay -= frames * new_interval;
        cmd.delay = frames;
        total_frames += frames;
    }

    return total_frames;
}
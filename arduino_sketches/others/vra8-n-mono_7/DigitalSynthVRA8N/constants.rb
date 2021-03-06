

A4_PITCH = 440.0

MIDI_CH             = 0
SAMPLING_RATE       = 31250
FREQUENCY_MAX       = 15624
BIT_DEPTH           = 8
NOTE_NUMBER_MIN     = 0
NOTE_NUMBER_MAX     = 120
NOTE_NUMBER_INVALID = 255

PROGRAM_NUMBER_MAX  = 7

OSC_CONTROL_INTERVAL_BITS    = 2
OSC_CONTROL_INTERVAL         = 0x01 << OSC_CONTROL_INTERVAL_BITS
OSC_PHASE_RESOLUTION_BITS    = 24
OSC_TUNE_TABLE_STEPS_BITS    = 8
OSC_TUNE_DENOMINATOR_BITS    = 9
OSC_WAVE_TABLE_AMPLITUDE     = 96
OSC_WAVE_TABLE_SAMPLES_BITS  = 8
OSC_DETUNE_MUL_NUM_BITS      = 4
OSC_DETUNE_FREQ_MIN          = 64
OSC_DETUNE_FREQ_MAX          = 0
FILTER_CONTROL_INTERVAL_BITS = 3
FILTER_CONTROL_INTERVAL      = 0x01 << FILTER_CONTROL_INTERVAL_BITS
FILTER_CUTOFF_THROUGH_RATE   = 24
FILTER_TABLE_FRACTION_BITS   = 14
ENV_GEN_CONTROL_INTERVAL     = 0x08
ENV_GEN_LEVEL_MAX            = 0x8000
ENV_GEN_LEVEL_MAX_X_1_5      = ENV_GEN_LEVEL_MAX + (ENV_GEN_LEVEL_MAX >> 1)
ENV_GEN_LEVEL_RELEASE_STEP   = 0x1600
AMP_ENV_AMT_MAX              = 240
AMP_ENV_AMT_STEP             = 16

DATA_BYTE_MAX         = 0x7F
STATUS_BYTE_INVALID   = 0x7F
DATA_BYTE_INVALID     = 0x80
STATUS_BYTE_MIN       = 0x80
NOTE_OFF              = 0x80
NOTE_ON               = 0x90
CONTROL_CHANGE        = 0xB0
PROGRAM_CHANGE        = 0xC0
PITCH_BEND            = 0xE0
SYSTEM_MESSAGE_MIN    = 0xF0
SYSTEM_EXCLUSIVE      = 0xF0
TIME_CODE             = 0xF1
SONG_POSITION         = 0xF2
SONG_SELECT           = 0xF3
TUNE_REQUEST          = 0xF6
EOX                   = 0xF7
REAL_TIME_MESSAGE_MIN = 0xF8
ACTIVE_SENSING        = 0xFE

MODULATION    = 1
EXPRESSION    = 11

OSC_WAVE      = 24
OSC2_MIX      = 25
OSC2_COARSE   = 20
OSC2_FINE     = 21

SUB_OSC_WAVE  = 29
SUB_OSC_LEVEL = 26
PITCH_EG_AMT  = 104
PITCH_EG_TGT  = 105

FILTER_CUTOFF = 16
FILTER_RESO   = 17
CUTOFF_EG_AMT = 18
AMP_EG_ON     = 31

EG_ATTACK     = 23
EG_DECAY      = 19
EG_SUSTAIN    = 27
EG_RELEASE    = 28

LFO_WAVE      = 14
LFO_RATE      = 80
PITCH_LFO_AMT = 82
CO_LFO_AMT    = 83

LFO_DEPTH     = 81
LFO_RT_EG_AMT = 3
PITCH_LFO_TGT = 9
CC15          = 15

PB_RANGE      = 85
CC86          = 86
CO_EXP_AMT    = 106
AMP_EXP_AMT   = 107

PORTAMENTO    = 22
LEGATO        = 30
KEY_ASSIGN    = 87
EXP_BY_VEL    = 89

ALL_NOTES_OFF = 123
OMNI_MODE_OFF = 124
OMNI_MODE_ON  = 125
MONO_MODE_ON  = 126
POLY_MODE_ON  = 127

OSC_WAVEFORM_SAW = 0
OSC_WAVEFORM_SQ  = 127

SUB_WAVEFORM_SIN   = 0
SUB_WAVEFORM_NOISE = 64
SUB_WAVEFORM_SQ    = 127

LFO_WAVEFORM_TRI_ASYNC = 0
LFO_WAVEFORM_TRI_SYNC  = 32
LFO_WAVEFORM_SAW_DOWN  = 64
LFO_WAVEFORM_RANDOM    = 96
LFO_WAVEFORM_SQ        = 127

KEY_ASSIGN_LOW  = 0
KEY_ASSIGN_DUO  = 64
KEY_ASSIGN_HIGH = 96
KEY_ASSIGN_LAST = 127

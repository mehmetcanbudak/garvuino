//  Tables V2

#ifndef _TABLES
#define _TABLES

//This table id compatible with 20000.00 Hz. sampling rate
//Envelope frequency tuning word vs. MIDI range value [0-127]
const uint16_t PROGMEM EFTWS[]={
0x0371,0x0340,0x0311,0x02E5,0x02BB,0x0294,0x026F,0x024C,0x022B,0x020C,0x01EE,0x01D3,0x01B8,0x01A0,0x0188,0x0172,
0x015D,0x014A,0x0137,0x0126,0x0115,0x0106,0x00F7,0x00E9,0x00DC,0x00D0,0x00C4,0x00B9,0x00AE,0x00A5,0x009B,0x0093,
0x008A,0x0083,0x007B,0x0074,0x006E,0x0068,0x0062,0x005C,0x0057,0x0052,0x004D,0x0049,0x0045,0x0041,0x003D,0x003A,
0x0037,0x0034,0x0031,0x002E,0x002B,0x0029,0x0026,0x0024,0x0022,0x0020,0x001E,0x001D,0x001B,0x001A,0x0018,0x0017,
0x0015,0x0014,0x0013,0x0012,0x0011,0x0010,0x000F,0x000E,0x000D,0x000D,0x000C,0x000B,0x000A,0x000A,0x0009,0x0009,
0x0008,0x0008,0x0007,0x0007,0x0006,0x0006,0x0006,0x0005,0x0005,0x0005,0x0004,0x0004,0x0004,0x0004,0x0003,0x0003,
0x0003,0x0003,0x0003,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,
0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
};

//Voice frequency tuning word vs. MIDI note [0-127]
const uint16_t PROGMEM PITCHS[]={
0x001A,0x001C,0x001E,0x001F,0x0021,0x0023,0x0025,0x0028,0x002A,0x002D,0x002F,0x0032,0x0035,0x0038,0x003C,0x003F,
0x0043,0x0047,0x004B,0x0050,0x0055,0x005A,0x005F,0x0065,0x006B,0x0071,0x0078,0x007F,0x0087,0x008F,0x0097,0x00A0,
0x00AA,0x00B4,0x00BE,0x00CA,0x00D6,0x00E3,0x00F0,0x00FE,0x010E,0x011E,0x012F,0x0141,0x0154,0x0168,0x017D,0x0194,
0x01AC,0x01C6,0x01E1,0x01FD,0x021C,0x023C,0x025E,0x0282,0x02A8,0x02D0,0x02FB,0x0329,0x0359,0x038C,0x03C2,0x03FB,
0x0438,0x0478,0x04BC,0x0504,0x0550,0x05A1,0x05F7,0x0652,0x06B2,0x0718,0x0784,0x07F6,0x0870,0x08F0,0x0978,0x0A08,
0x0AA1,0x0B43,0x0BEF,0x0CA4,0x0D65,0x0E31,0x0F09,0x0FED,0x10E0,0x11E1,0x12F1,0x1411,0x1543,0x1687,0x17DE,0x1949,
0x1ACA,0x1C62,0x1E12,0x1FDB,0x21C0,0x23C2,0x25E3,0x2823,0x2A86,0x2D0E,0x2FBC,0x3292,0x3594,0x38C4,0x3C24,0x3FB7,
0x4381,0x4785,0x4BC6,0x5047,0x550D,0x5A1C,0x5F78,0x6525,0x6B29,0x7188,0x7848,0x7F6F,0x8703,0x8F0A,0x978C,0xA08F,
};

/*
//Arduino synth V4.0
//This table id compatible with 16000.00 Hz. sampling rate
//Envelope frequency tuning word vs. MIDI range value [0-127]
const uint16_t PROGMEM EFTWS[]={
0x044E,0x0410,0x03D5,0x039E,0x036A,0x0339,0x030B,0x02DF,0x02B6,0x028F,0x026A,0x0247,0x0227,0x0208,0x01EA,0x01CF,
0x01B5,0x019C,0x0185,0x016F,0x015B,0x0147,0x0135,0x0123,0x0113,0x0104,0x00F5,0x00E7,0x00DA,0x00CE,0x00C2,0x00B7,
0x00AD,0x00A3,0x009A,0x0091,0x0089,0x0082,0x007A,0x0073,0x006D,0x0067,0x0061,0x005B,0x0056,0x0051,0x004D,0x0048,
0x0044,0x0041,0x003D,0x0039,0x0036,0x0033,0x0030,0x002D,0x002B,0x0028,0x0026,0x0024,0x0022,0x0020,0x001E,0x001C,
0x001B,0x0019,0x0018,0x0016,0x0015,0x0014,0x0013,0x0012,0x0011,0x0010,0x000F,0x000E,0x000D,0x000C,0x000C,0x000B,
0x000A,0x000A,0x0009,0x0009,0x0008,0x0008,0x0007,0x0007,0x0006,0x0006,0x0006,0x0005,0x0005,0x0005,0x0004,0x0004,
0x0004,0x0004,0x0003,0x0003,0x0003,0x0003,0x0003,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0001,0x0001,
0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
};
//Voice frequency tuning word vs. MIDI note [0-127]
const uint16_t PROGMEM PITCHS[]={
0x0021,0x0023,0x0025,0x0027,0x002A,0x002C,0x002F,0x0032,0x0035,0x0038,0x003B,0x003F,0x0042,0x0046,0x004B,0x004F,
0x0054,0x0059,0x005E,0x0064,0x006A,0x0070,0x0077,0x007E,0x0085,0x008D,0x0096,0x009F,0x00A8,0x00B2,0x00BD,0x00C8,
0x00D4,0x00E1,0x00EE,0x00FC,0x010B,0x011B,0x012C,0x013E,0x0151,0x0165,0x017A,0x0191,0x01A9,0x01C2,0x01DD,0x01F9,
0x0217,0x0237,0x0259,0x027D,0x02A3,0x02CB,0x02F5,0x0322,0x0352,0x0385,0x03BA,0x03F3,0x042F,0x046F,0x04B2,0x04FA,
0x0546,0x0596,0x05EB,0x0645,0x06A5,0x070A,0x0775,0x07E6,0x085F,0x08DE,0x0965,0x09F4,0x0A8C,0x0B2C,0x0BD6,0x0C8B,
0x0D4A,0x0E14,0x0EEA,0x0FCD,0x10BE,0x11BD,0x12CB,0x13E9,0x1518,0x1659,0x17AD,0x1916,0x1A94,0x1C28,0x1DD5,0x1F9B,
0x217C,0x237A,0x2596,0x27D2,0x2A31,0x2CB3,0x2F5B,0x322C,0x3528,0x3851,0x3BAB,0x3F37,0x42F9,0x46F5,0x4B2D,0x4FA5,
0x5462,0x5966,0x5EB7,0x6459,0x6A50,0x70A3,0x7756,0x7E6E,0x85F3,0x8DEA,0x965A,0x9F4B,0xA8C4,0xB2CD,0xBD6F,0xC8B2,
};
*/
const PROGMEM char SinTable[]=
{
	0,	//0
	3,	//1
	6,	//2
	9,	//3
	12,	//4
	15,	//5
	18,	//6
	21,	//7
	24,	//8
	27,	//9
	30,	//10
	33,	//11
	36,	//12
	39,	//13
	42,	//14
	45,	//15
	48,	//16
	51,	//17
	54,	//18
	57,	//19
	59,	//20
	62,	//21
	65,	//22
	67,	//23
	70,	//24
	73,	//25
	75,	//26
	78,	//27
	80,	//28
	82,	//29
	85,	//30
	87,	//31
	89,	//32
	91,	//33
	94,	//34
	96,	//35
	98,	//36
	100,	//37
	102,	//38
	103,	//39
	105,	//40
	107,	//41
	108,	//42
	110,	//43
	112,	//44
	113,	//45
	114,	//46
	116,	//47
	117,	//48
	118,	//49
	119,	//50
	120,	//51
	121,	//52
	122,	//53
	123,	//54
	123,	//55
	124,	//56
	125,	//57
	125,	//58
	126,	//59
	126,	//60
	126,	//61
	126,	//62
	126,	//63
	127,	//64
	126,	//65
	126,	//66
	126,	//67
	126,	//68
	126,	//69
	125,	//70
	125,	//71
	124,	//72
	123,	//73
	123,	//74
	122,	//75
	121,	//76
	120,	//77
	119,	//78
	118,	//79
	117,	//80
	116,	//81
	114,	//82
	113,	//83
	112,	//84
	110,	//85
	108,	//86
	107,	//87
	105,	//88
	103,	//89
	102,	//90
	100,	//91
	98,	//92
	96,	//93
	94,	//94
	91,	//95
	89,	//96
	87,	//97
	85,	//98
	82,	//99
	80,	//100
	78,	//101
	75,	//102
	73,	//103
	70,	//104
	67,	//105
	65,	//106
	62,	//107
	59,	//108
	57,	//109
	54,	//110
	51,	//111
	48,	//112
	45,	//113
	42,	//114
	39,	//115
	36,	//116
	33,	//117
	30,	//118
	27,	//119
	24,	//120
	21,	//121
	18,	//122
	15,	//123
	12,	//124
	9,	//125
	6,	//126
	3,	//127
	0,	//128
	-3,	//129
	-6,	//130
	-9,	//131
	-12,	//132
	-15,	//133
	-18,	//134
	-21,	//135
	-24,	//136
	-27,	//137
	-30,	//138
	-33,	//139
	-36,	//140
	-39,	//141
	-42,	//142
	-45,	//143
	-48,	//144
	-51,	//145
	-54,	//146
	-57,	//147
	-59,	//148
	-62,	//149
	-65,	//150
	-67,	//151
	-70,	//152
	-73,	//153
	-75,	//154
	-78,	//155
	-80,	//156
	-82,	//157
	-85,	//158
	-87,	//159
	-89,	//160
	-91,	//161
	-94,	//162
	-96,	//163
	-98,	//164
	-100,	//165
	-102,	//166
	-103,	//167
	-105,	//168
	-107,	//169
	-108,	//170
	-110,	//171
	-112,	//172
	-113,	//173
	-114,	//174
	-116,	//175
	-117,	//176
	-118,	//177
	-119,	//178
	-120,	//179
	-121,	//180
	-122,	//181
	-123,	//182
	-123,	//183
	-124,	//184
	-125,	//185
	-125,	//186
	-126,	//187
	-126,	//188
	-126,	//189
	-126,	//190
	-126,	//191
	-127,	//192
	-126,	//193
	-126,	//194
	-126,	//195
	-126,	//196
	-126,	//197
	-125,	//198
	-125,	//199
	-124,	//200
	-123,	//201
	-123,	//202
	-122,	//203
	-121,	//204
	-120,	//205
	-119,	//206
	-118,	//207
	-117,	//208
	-116,	//209
	-114,	//210
	-113,	//211
	-112,	//212
	-110,	//213
	-108,	//214
	-107,	//215
	-105,	//216
	-103,	//217
	-102,	//218
	-100,	//219
	-98,	//220
	-96,	//221
	-94,	//222
	-91,	//223
	-89,	//224
	-87,	//225
	-85,	//226
	-82,	//227
	-80,	//228
	-78,	//229
	-75,	//230
	-73,	//231
	-70,	//232
	-67,	//233
	-65,	//234
	-62,	//235
	-59,	//236
	-57,	//237
	-54,	//238
	-51,	//239
	-48,	//240
	-45,	//241
	-42,	//242
	-39,	//243
	-36,	//244
	-33,	//245
	-30,	//246
	-27,	//247
	-24,	//248
	-21,	//249
	-18,	//250
	-15,	//251
	-12,	//252
	-9,	//253
	-6,	//254
	-4,	//255
};

const PROGMEM char TriangleTable[]=
{
	0,	//0
	1,	//1
	3,	//2
	5,	//3
	7,	//4
	9,	//5
	11,	//6
	13,	//7
	15,	//8
	17,	//9
	19,	//10
	21,	//11
	23,	//12
	25,	//13
	27,	//14
	29,	//15
	31,	//16
	33,	//17
	35,	//18
	37,	//19
	39,	//20
	41,	//21
	43,	//22
	45,	//23
	47,	//24
	49,	//25
	51,	//26
	53,	//27
	55,	//28
	57,	//29
	59,	//30
	61,	//31
	63,	//32
	65,	//33
	67,	//34
	69,	//35
	71,	//36
	73,	//37
	75,	//38
	77,	//39
	79,	//40
	81,	//41
	83,	//42
	85,	//43
	87,	//44
	89,	//45
	91,	//46
	93,	//47
	95,	//48
	97,	//49
	99,	//50
	101,	//51
	103,	//52
	105,	//53
	107,	//54
	109,	//55
	111,	//56
	113,	//57
	115,	//58
	117,	//59
	119,	//60
	121,	//61
	123,	//62
	125,	//63
	127,	//64
	125,	//65
	123,	//66
	121,	//67
	119,	//68
	117,	//69
	115,	//70
	113,	//71
	111,	//72
	109,	//73
	107,	//74
	105,	//75
	103,	//76
	101,	//77
	99,	//78
	97,	//79
	95,	//80
	93,	//81
	91,	//82
	89,	//83
	87,	//84
	85,	//85
	83,	//86
	81,	//87
	79,	//88
	77,	//89
	75,	//90
	73,	//91
	71,	//92
	69,	//93
	67,	//94
	65,	//95
	63,	//96
	61,	//97
	59,	//98
	57,	//99
	55,	//100
	53,	//101
	51,	//102
	49,	//103
	47,	//104
	45,	//105
	43,	//106
	41,	//107
	39,	//108
	37,	//109
	35,	//110
	33,	//111
	31,	//112
	29,	//113
	27,	//114
	25,	//115
	23,	//116
	21,	//117
	19,	//118
	17,	//119
	15,	//120
	13,	//121
	11,	//122
	9,	//123
	7,	//124
	5,	//125
	3,	//126
	1,	//127
	0,	//128
	-1,	//129
	-3,	//130
	-5,	//131
	-7,	//132
	-9,	//133
	-11,	//134
	-13,	//135
	-15,	//136
	-17,	//137
	-19,	//138
	-21,	//139
	-23,	//140
	-25,	//141
	-27,	//142
	-29,	//143
	-31,	//144
	-33,	//145
	-35,	//146
	-37,	//147
	-39,	//148
	-41,	//149
	-43,	//150
	-45,	//151
	-47,	//152
	-49,	//153
	-51,	//154
	-53,	//155
	-55,	//156
	-57,	//157
	-59,	//158
	-61,	//159
	-63,	//160
	-65,	//161
	-67,	//162
	-69,	//163
	-71,	//164
	-73,	//165
	-75,	//166
	-77,	//167
	-79,	//168
	-81,	//169
	-83,	//170
	-85,	//171
	-87,	//172
	-89,	//173
	-91,	//174
	-93,	//175
	-95,	//176
	-97,	//177
	-99,	//178
	-101,	//179
	-103,	//180
	-105,	//181
	-107,	//182
	-109,	//183
	-111,	//184
	-113,	//185
	-115,	//186
	-117,	//187
	-119,	//188
	-121,	//189
	-123,	//190
	-125,	//191
	-127,	//192
	-125,	//193
	-123,	//194
	-121,	//195
	-119,	//196
	-117,	//197
	-115,	//198
	-113,	//199
	-111,	//200
	-109,	//201
	-107,	//202
	-105,	//203
	-103,	//204
	-101,	//205
	-99,	//206
	-97,	//207
	-95,	//208
	-93,	//209
	-91,	//210
	-89,	//211
	-87,	//212
	-85,	//213
	-83,	//214
	-81,	//215
	-79,	//216
	-77,	//217
	-75,	//218
	-73,	//219
	-71,	//220
	-69,	//221
	-67,	//222
	-65,	//223
	-63,	//224
	-61,	//225
	-59,	//226
	-57,	//227
	-55,	//228
	-53,	//229
	-51,	//230
	-49,	//231
	-47,	//232
	-45,	//233
	-43,	//234
	-41,	//235
	-39,	//236
	-37,	//237
	-35,	//238
	-33,	//239
	-31,	//240
	-29,	//241
	-27,	//242
	-25,	//243
	-23,	//244
	-21,	//245
	-19,	//246
	-17,	//247
	-15,	//248
	-13,	//249
	-11,	//250
	-9,	//251
	-7,	//252
	-5,	//253
	-3,	//254
	-2,	//255
};

const PROGMEM char  SquareTable[]=
{
	127,	//0
	127,	//1
	127,	//2
	127,	//3
	127,	//4
	127,	//5
	127,	//6
	127,	//7
	127,	//8
	127,	//9
	127,	//10
	127,	//11
	127,	//12
	127,	//13
	127,	//14
	127,	//15
	127,	//16
	127,	//17
	127,	//18
	127,	//19
	127,	//20
	127,	//21
	127,	//22
	127,	//23
	127,	//24
	127,	//25
	127,	//26
	127,	//27
	127,	//28
	127,	//29
	127,	//30
	127,	//31
	127,	//32
	127,	//33
	127,	//34
	127,	//35
	127,	//36
	127,	//37
	127,	//38
	127,	//39
	127,	//40
	127,	//41
	127,	//42
	127,	//43
	127,	//44
	127,	//45
	127,	//46
	127,	//47
	127,	//48
	127,	//49
	127,	//50
	127,	//51
	127,	//52
	127,	//53
	127,	//54
	127,	//55
	127,	//56
	127,	//57
	127,	//58
	127,	//59
	127,	//60
	127,	//61
	127,	//62
	127,	//63
	127,	//64
	127,	//65
	127,	//66
	127,	//67
	127,	//68
	127,	//69
	127,	//70
	127,	//71
	127,	//72
	127,	//73
	127,	//74
	127,	//75
	127,	//76
	127,	//77
	127,	//78
	127,	//79
	127,	//80
	127,	//81
	127,	//82
	127,	//83
	127,	//84
	127,	//85
	127,	//86
	127,	//87
	127,	//88
	127,	//89
	127,	//90
	127,	//91
	127,	//92
	127,	//93
	127,	//94
	127,	//95
	127,	//96
	127,	//97
	127,	//98
	127,	//99
	127,	//100
	127,	//101
	127,	//102
	127,	//103
	127,	//104
	127,	//105
	127,	//106
	127,	//107
	127,	//108
	127,	//109
	127,	//110
	127,	//111
	127,	//112
	127,	//113
	127,	//114
	127,	//115
	127,	//116
	127,	//117
	127,	//118
	127,	//119
	127,	//120
	127,	//121
	127,	//122
	127,	//123
	127,	//124
	127,	//125
	127,	//126
	127,	//127
	-125,	//128
	-125,	//129
	-125,	//130
	-125,	//131
	-125,	//132
	-125,	//133
	-125,	//134
	-125,	//135
	-125,	//136
	-125,	//137
	-125,	//138
	-125,	//139
	-125,	//140
	-125,	//141
	-125,	//142
	-125,	//143
	-125,	//144
	-125,	//145
	-125,	//146
	-125,	//147
	-125,	//148
	-125,	//149
	-125,	//150
	-125,	//151
	-125,	//152
	-125,	//153
	-125,	//154
	-125,	//155
	-125,	//156
	-125,	//157
	-125,	//158
	-125,	//159
	-125,	//160
	-125,	//161
	-125,	//162
	-125,	//163
	-125,	//164
	-125,	//165
	-125,	//166
	-125,	//167
	-125,	//168
	-125,	//169
	-125,	//170
	-125,	//171
	-125,	//172
	-125,	//173
	-125,	//174
	-125,	//175
	-125,	//176
	-125,	//177
	-125,	//178
	-125,	//179
	-125,	//180
	-125,	//181
	-125,	//182
	-125,	//183
	-125,	//184
	-125,	//185
	-125,	//186
	-125,	//187
	-125,	//188
	-125,	//189
	-125,	//190
	-125,	//191
	-125,	//192
	-125,	//193
	-125,	//194
	-125,	//195
	-125,	//196
	-125,	//197
	-125,	//198
	-125,	//199
	-125,	//200
	-125,	//201
	-125,	//202
	-125,	//203
	-125,	//204
	-125,	//205
	-125,	//206
	-125,	//207
	-125,	//208
	-125,	//209
	-125,	//210
	-125,	//211
	-125,	//212
	-125,	//213
	-125,	//214
	-125,	//215
	-125,	//216
	-125,	//217
	-125,	//218
	-125,	//219
	-125,	//220
	-125,	//221
	-125,	//222
	-125,	//223
	-125,	//224
	-125,	//225
	-125,	//226
	-125,	//227
	-125,	//228
	-125,	//229
	-125,	//230
	-125,	//231
	-125,	//232
	-125,	//233
	-125,	//234
	-125,	//235
	-125,	//236
	-125,	//237
	-125,	//238
	-125,	//239
	-125,	//240
	-125,	//241
	-125,	//242
	-125,	//243
	-125,	//244
	-125,	//245
	-125,	//246
	-125,	//247
	-125,	//248
	-125,	//249
	-125,	//250
	-125,	//251
	-125,	//252
	-125,	//253
	-125,	//254
	-1,	//255
};
const PROGMEM char SawTable[]=
{
	128,	//0
	127,	//1
	126,	//2
	125,	//3
	124,	//4
	123,	//5
	122,	//6
	121,	//7
	120,	//8
	119,	//9
	118,	//10
	117,	//11
	116,	//12
	115,	//13
	114,	//14
	113,	//15
	112,	//16
	111,	//17
	110,	//18
	109,	//19
	108,	//20
	107,	//21
	106,	//22
	105,	//23
	104,	//24
	103,	//25
	102,	//26
	101,	//27
	100,	//28
	99,	//29
	98,	//30
	97,	//31
	96,	//32
	95,	//33
	94,	//34
	93,	//35
	92,	//36
	91,	//37
	90,	//38
	89,	//39
	88,	//40
	87,	//41
	86,	//42
	85,	//43
	84,	//44
	83,	//45
	82,	//46
	81,	//47
	80,	//48
	79,	//49
	78,	//50
	77,	//51
	76,	//52
	75,	//53
	74,	//54
	73,	//55
	72,	//56
	71,	//57
	70,	//58
	69,	//59
	68,	//60
	67,	//61
	66,	//62
	65,	//63
	64,	//64
	63,	//65
	62,	//66
	61,	//67
	60,	//68
	59,	//69
	58,	//70
	57,	//71
	56,	//72
	55,	//73
	54,	//74
	53,	//75
	52,	//76
	51,	//77
	50,	//78
	49,	//79
	48,	//80
	47,	//81
	46,	//82
	45,	//83
	44,	//84
	43,	//85
	42,	//86
	41,	//87
	40,	//88
	39,	//89
	38,	//90
	37,	//91
	36,	//92
	35,	//93
	34,	//94
	33,	//95
	32,	//96
	31,	//97
	30,	//98
	29,	//99
	28,	//100
	27,	//101
	26,	//102
	25,	//103
	24,	//104
	23,	//105
	22,	//106
	21,	//107
	20,	//108
	19,	//109
	18,	//110
	17,	//111
	16,	//112
	15,	//113
	14,	//114
	13,	//115
	12,	//116
	11,	//117
	10,	//118
	9,	//119
	8,	//120
	7,	//121
	6,	//122
	5,	//123
	4,	//124
	3,	//125
	2,	//126
	1,	//127
	0,	//128
	0,	//129
	-1,	//130
	-2,	//131
	-3,	//132
	-4,	//133
	-5,	//134
	-6,	//135
	-7,	//136
	-8,	//137
	-9,	//138
	-10,	//139
	-11,	//140
	-12,	//141
	-13,	//142
	-14,	//143
	-15,	//144
	-16,	//145
	-17,	//146
	-18,	//147
	-19,	//148
	-20,	//149
	-21,	//150
	-22,	//151
	-23,	//152
	-24,	//153
	-25,	//154
	-26,	//155
	-27,	//156
	-28,	//157
	-29,	//158
	-30,	//159
	-31,	//160
	-32,	//161
	-33,	//162
	-34,	//163
	-35,	//164
	-36,	//165
	-37,	//166
	-38,	//167
	-39,	//168
	-40,	//169
	-41,	//170
	-42,	//171
	-43,	//172
	-44,	//173
	-45,	//174
	-46,	//175
	-47,	//176
	-48,	//177
	-49,	//178
	-50,	//179
	-51,	//180
	-52,	//181
	-53,	//182
	-54,	//183
	-55,	//184
	-56,	//185
	-57,	//186
	-58,	//187
	-59,	//188
	-60,	//189
	-61,	//190
	-62,	//191
	-63,	//192
	-64,	//193
	-65,	//194
	-66,	//195
	-67,	//196
	-68,	//197
	-69,	//198
	-70,	//199
	-71,	//200
	-72,	//201
	-73,	//202
	-74,	//203
	-75,	//204
	-76,	//205
	-77,	//206
	-78,	//207
	-79,	//208
	-80,	//209
	-81,	//210
	-82,	//211
	-83,	//212
	-84,	//213
	-85,	//214
	-86,	//215
	-87,	//216
	-88,	//217
	-89,	//218
	-90,	//219
	-91,	//220
	-92,	//221
	-93,	//222
	-94,	//223
	-95,	//224
	-96,	//225
	-97,	//226
	-98,	//227
	-99,	//228
	-100,	//229
	-101,	//230
	-102,	//231
	-103,	//232
	-104,	//233
	-105,	//234
	-106,	//235
	-107,	//236
	-108,	//237
	-109,	//238
	-110,	//239
	-111,	//240
	-112,	//241
	-113,	//242
	-114,	//243
	-115,	//244
	-116,	//245
	-117,	//246
	-118,	//247
	-119,	//248
	-120,	//249
	-121,	//250
	-122,	//251
	-123,	//252
	-124,	//253
	-125,	//254
	-127,	//255
};
const PROGMEM char RampTable[]=
{
	-127,	//0
	-126,	//1
	-125,	//2
	-124,	//3
	-123,	//4
	-122,	//5
	-121,	//6
	-120,	//7
	-119,	//8
	-118,	//9
	-117,	//10
	-116,	//11
	-115,	//12
	-114,	//13
	-113,	//14
	-112,	//15
	-111,	//16
	-110,	//17
	-109,	//18
	-108,	//19
	-107,	//20
	-106,	//21
	-105,	//22
	-104,	//23
	-103,	//24
	-102,	//25
	-101,	//26
	-100,	//27
	-99,	//28
	-98,	//29
	-97,	//30
	-96,	//31
	-95,	//32
	-94,	//33
	-93,	//34
	-92,	//35
	-91,	//36
	-90,	//37
	-89,	//38
	-88,	//39
	-87,	//40
	-86,	//41
	-85,	//42
	-84,	//43
	-83,	//44
	-82,	//45
	-81,	//46
	-80,	//47
	-79,	//48
	-78,	//49
	-77,	//50
	-76,	//51
	-75,	//52
	-74,	//53
	-73,	//54
	-72,	//55
	-71,	//56
	-70,	//57
	-69,	//58
	-68,	//59
	-67,	//60
	-66,	//61
	-65,	//62
	-64,	//63
	-63,	//64
	-62,	//65
	-61,	//66
	-60,	//67
	-59,	//68
	-58,	//69
	-57,	//70
	-56,	//71
	-55,	//72
	-54,	//73
	-53,	//74
	-52,	//75
	-51,	//76
	-50,	//77
	-49,	//78
	-48,	//79
	-47,	//80
	-46,	//81
	-45,	//82
	-44,	//83
	-43,	//84
	-42,	//85
	-41,	//86
	-40,	//87
	-39,	//88
	-38,	//89
	-37,	//90
	-36,	//91
	-35,	//92
	-34,	//93
	-33,	//94
	-32,	//95
	-31,	//96
	-30,	//97
	-29,	//98
	-28,	//99
	-27,	//100
	-26,	//101
	-25,	//102
	-24,	//103
	-23,	//104
	-22,	//105
	-21,	//106
	-20,	//107
	-19,	//108
	-18,	//109
	-17,	//110
	-16,	//111
	-15,	//112
	-14,	//113
	-13,	//114
	-12,	//115
	-11,	//116
	-10,	//117
	-9,	//118
	-8,	//119
	-7,	//120
	-6,	//121
	-5,	//122
	-4,	//123
	-3,	//124
	-2,	//125
	-1,	//126
	0,	//127
	0,	//128
	1,	//129
	2,	//130
	3,	//131
	4,	//132
	5,	//133
	6,	//134
	7,	//135
	8,	//136
	9,	//137
	10,	//138
	11,	//139
	12,	//140
	13,	//141
	14,	//142
	15,	//143
	16,	//144
	17,	//145
	18,	//146
	19,	//147
	20,	//148
	21,	//149
	22,	//150
	23,	//151
	24,	//152
	25,	//153
	26,	//154
	27,	//155
	28,	//156
	29,	//157
	30,	//158
	31,	//159
	32,	//160
	33,	//161
	34,	//162
	35,	//163
	36,	//164
	37,	//165
	38,	//166
	39,	//167
	40,	//168
	41,	//169
	42,	//170
	43,	//171
	44,	//172
	45,	//173
	46,	//174
	47,	//175
	48,	//176
	49,	//177
	50,	//178
	51,	//179
	52,	//180
	53,	//181
	54,	//182
	55,	//183
	56,	//184
	57,	//185
	58,	//186
	59,	//187
	60,	//188
	61,	//189
	62,	//190
	63,	//191
	64,	//192
	65,	//193
	66,	//194
	67,	//195
	68,	//196
	69,	//197
	70,	//198
	71,	//199
	72,	//200
	73,	//201
	74,	//202
	75,	//203
	76,	//204
	77,	//205
	78,	//206
	79,	//207
	80,	//208
	81,	//209
	82,	//210
	83,	//211
	84,	//212
	85,	//213
	86,	//214
	87,	//215
	88,	//216
	89,	//217
	90,	//218
	91,	//219
	92,	//220
	93,	//221
	94,	//222
	95,	//223
	96,	//224
	97,	//225
	98,	//226
	99,	//227
	100,	//228
	101,	//229
	102,	//230
	103,	//231
	104,	//232
	105,	//233
	106,	//234
	107,	//235
	108,	//236
	109,	//237
	110,	//238
	111,	//239
	112,	//240
	113,	//241
	114,	//242
	115,	//243
	116,	//244
	117,	//245
	118,	//246
	119,	//247
	120,	//248
	121,	//249
	122,	//250
	123,	//251
	124,	//252
	125,	//253
	126,	//254
	127,	//255
};
const PROGMEM char NoiseTable[]=
{
	-62,	//0
	-72,	//1
	-92,	//2
	-98,	//3
	98,	//4
	-103,	//5
	96,	//6
	-89,	//7
	-29,	//8
	-55,	//9
	98,	//10
	-8,	//11
	-118,	//12
	13,	//13
	11,	//14
	-1,	//15
	76,	//16
	-8,	//17
	-116,	//18
	51,	//19
	33,	//20
	-85,	//21
	-43,	//22
	-16,	//23
	-114,	//24
	-47,	//25
	-63,	//26
	-113,	//27
	109,	//28
	-39,	//29
	-127,	//30
	-59,	//31
	0,	//32
	118,	//33
	70,	//34
	62,	//35
	54,	//36
	85,	//37
	51,	//38
	122,	//39
	60,	//40
	30,	//41
	-126,	//42
	-25,	//43
	71,	//44
	-82,	//45
	-11,	//46
	64,	//47
	-95,	//48
	-110,	//49
	127,	//50
	37,	//51
	-14,	//52
	-57,	//53
	51,	//54
	-4,	//55
	-47,	//56
	-80,	//57
	110,	//58
	7,	//59
	-117,	//60
	89,	//61
	65,	//62
	-58,	//63
	50,	//64
	-21,	//65
	33,	//66
	-113,	//67
	-22,	//68
	111,	//69
	-46,	//70
	108,	//71
	112,	//72
	-57,	//73
	-111,	//74
	53,	//75
	-21,	//76
	-22,	//77
	-127,	//78
	-18,	//79
	-9,	//80
	95,	//81
	88,	//82
	99,	//83
	-17,	//84
	-3,	//85
	74,	//86
	2,	//87
	123,	//88
	-31,	//89
	53,	//90
	-7,	//91
	91,	//92
	-80,	//93
	15,	//94
	-112,	//95
	114,	//96
	14,	//97
	-115,	//98
	-55,	//99
	22,	//100
	95,	//101
	21,	//102
	53,	//103
	-105,	//104
	-67,	//105
	-25,	//106
	25,	//107
	13,	//108
	58,	//109
	-121,	//110
	-62,	//111
	103,	//112
	87,	//113
	109,	//114
	38,	//115
	-79,	//116
	-60,	//117
	-16,	//118
	-68,	//119
	-91,	//120
	90,	//121
	112,	//122
	-99,	//123
	118,	//124
	87,	//125
	-61,	//126
	-36,	//127
	-40,	//128
	-39,	//129
	-30,	//130
	34,	//131
	83,	//132
	-100,	//133
	-43,	//134
	-114,	//135
	-54,	//136
	-8,	//137
	-36,	//138
	-52,	//139
	71,	//140
	22,	//141
	-33,	//142
	116,	//143
	9,	//144
	114,	//145
	24,	//146
	-91,	//147
	-48,	//148
	-106,	//149
	-2,	//150
	-31,	//151
	103,	//152
	21,	//153
	117,	//154
	44,	//155
	115,	//156
	-59,	//157
	53,	//158
	97,	//159
	124,	//160
	66,	//161
	120,	//162
	-44,	//163
	57,	//164
	-96,	//165
	-24,	//166
	46,	//167
	32,	//168
	111,	//169
	-56,	//170
	-123,	//171
	46,	//172
	-11,	//173
	97,	//174
	-70,	//175
	-12,	//176
	-89,	//177
	-81,	//178
	24,	//179
	-29,	//180
	-23,	//181
	77,	//182
	42,	//183
	-40,	//184
	8,	//185
	-98,	//186
	-35,	//187
	-21,	//188
	116,	//189
	61,	//190
	-41,	//191
	116,	//192
	66,	//193
	-88,	//194
	22,	//195
	95,	//196
	-31,	//197
	40,	//198
	-51,	//199
	-78,	//200
	28,	//201
	3,	//202
	124,	//203
	92,	//204
	81,	//205
	-27,	//206
	78,	//207
	65,	//208
	-16,	//209
	-116,	//210
	-73,	//211
	-126,	//212
	55,	//213
	-76,	//214
	78,	//215
	17,	//216
	43,	//217
	66,	//218
	-24,	//219
	117,	//220
	-38,	//221
	-76,	//222
	-10,	//223
	-37,	//224
	-47,	//225
	-56,	//226
	33,	//227
	94,	//228
	-40,	//229
	107,	//230
	36,	//231
	-104,	//232
	-11,	//233
	-27,	//234
	-23,	//235
	105,	//236
	-96,	//237
	68,	//238
	-25,	//239
	7,	//240
	67,	//241
	6,	//242
	-69,	//243
	70,	//244
	-10,	//245
	10,	//246
	5,	//247
	42,	//248
	120,	//249
	-71,	//250
	-122,	//251
	-86,	//252
	113,	//253
	112,	//254
	119,	//255
};

const PROGMEM char Env0[]=
{
	255,	//0
	254,	//1
	254,	//2
	254,	//3
	253,	//4
	253,	//5
	253,	//6
	252,	//7
	252,	//8
	251,	//9
	251,	//10
	250,	//11
	249,	//12
	248,	//13
	248,	//14
	247,	//15
	246,	//16
	245,	//17
	241,	//18
	237,	//19
	232,	//20
	228,	//21
	223,	//22
	219,	//23
	215,	//24
	210,	//25
	205,	//26
	200,	//27
	195,	//28
	189,	//29
	184,	//30
	179,	//31
	173,	//32
	168,	//33
	163,	//34
	157,	//35
	151,	//36
	145,	//37
	139,	//38
	133,	//39
	127,	//40
	121,	//41
	115,	//42
	110,	//43
	105,	//44
	101,	//45
	96,	//46
	91,	//47
	86,	//48
	82,	//49
	77,	//50
	72,	//51
	69,	//52
	65,	//53
	62,	//54
	58,	//55
	54,	//56
	51,	//57
	47,	//58
	44,	//59
	41,	//60
	38,	//61
	36,	//62
	33,	//63
	31,	//64
	28,	//65
	26,	//66
	23,	//67
	20,	//68
	19,	//69
	18,	//70
	17,	//71
	15,	//72
	14,	//73
	13,	//74
	12,	//75
	10,	//76
	9,	//77
	9,	//78
	9,	//79
	8,	//80
	8,	//81
	7,	//82
	7,	//83
	6,	//84
	6,	//85
	6,	//86
	6,	//87
	5,	//88
	5,	//89
	5,	//90
	5,	//91
	5,	//92
	5,	//93
	5,	//94
	5,	//95
	5,	//96
	4,	//97
	4,	//98
	4,	//99
	4,	//100
	4,	//101
	4,	//102
	3,	//103
	3,	//104
	3,	//105
	2,	//106
	2,	//107
	2,	//108
	1,	//109
	1,	//110
	1,	//111
	1,	//112
	1,	//113
	0,	//114
	0,	//115
	0,	//116
	0,	//117
	0,	//118
	0,	//119
	0,	//120
	0,	//121
	0,	//122
	0,	//123
	0,	//124
	0,	//125
	0,	//126
	0,	//127
	0,	//127
	0,	//127
};
const PROGMEM char Env1[]=
{
	255,	//0
	242,	//1
	229,	//2
	216,	//3
	204,	//4
	191,	//5
	178,	//6
	165,	//7
	153,	//8
	142,	//9
	134,	//10
	125,	//11
	117,	//12
	108,	//13
	100,	//14
	91,	//15
	83,	//16
	74,	//17
	71,	//18
	68,	//19
	65,	//20
	62,	//21
	59,	//22
	56,	//23
	53,	//24
	50,	//25
	48,	//26
	46,	//27
	44,	//28
	42,	//29
	40,	//30
	38,	//31
	36,	//32
	34,	//33
	32,	//34
	31,	//35
	30,	//36
	29,	//37
	28,	//38
	28,	//39
	27,	//40
	26,	//41
	25,	//42
	25,	//43
	24,	//44
	24,	//45
	23,	//46
	23,	//47
	22,	//48
	22,	//49
	21,	//50
	21,	//51
	20,	//52
	20,	//53
	19,	//54
	19,	//55
	19,	//56
	18,	//57
	18,	//58
	17,	//59
	17,	//60
	16,	//61
	16,	//62
	15,	//63
	15,	//64
	14,	//65
	14,	//66
	13,	//67
	13,	//68
	12,	//69
	12,	//70
	11,	//71
	11,	//72
	10,	//73
	10,	//74
	10,	//75
	9,	//76
	9,	//77
	8,	//78
	8,	//79
	8,	//80
	7,	//81
	7,	//82
	6,	//83
	6,	//84
	6,	//85
	6,	//86
	6,	//87
	5,	//88
	5,	//89
	5,	//90
	5,	//91
	5,	//92
	5,	//93
	5,	//94
	5,	//95
	5,	//96
	4,	//97
	4,	//98
	4,	//99
	4,	//100
	4,	//101
	4,	//102
	3,	//103
	3,	//104
	3,	//105
	2,	//106
	2,	//107
	2,	//108
	1,	//109
	1,	//110
	1,	//111
	1,	//112
	1,	//113
	0,	//114
	0,	//115
	0,	//116
	0,	//117
	0,	//118
	0,	//119
	0,	//120
	0,	//121
	0,	//122
	0,	//123
	0,	//124
	0,	//125
	0,	//126
	0,	//127
	0,	//127
	0,	//127
	0,	//127
};
const PROGMEM char Env2[]=
{
	255,	//0
	254,	//1
	254,	//2
	254,	//3
	253,	//4
	253,	//5
	253,	//6
	252,	//7
	252,	//8
	252,	//9
	251,	//10
	251,	//11
	251,	//12
	250,	//13
	250,	//14
	250,	//15
	249,	//16
	249,	//17
	247,	//18
	244,	//19
	242,	//20
	240,	//21
	237,	//22
	235,	//23
	233,	//24
	230,	//25
	219,	//26
	200,	//27
	180,	//28
	160,	//29
	141,	//30
	121,	//31
	102,	//32
	82,	//33
	62,	//34
	58,	//35
	53,	//36
	49,	//37
	45,	//38
	40,	//39
	36,	//40
	31,	//41
	27,	//42
	25,	//43
	24,	//44
	24,	//45
	23,	//46
	23,	//47
	22,	//48
	22,	//49
	21,	//50
	21,	//51
	20,	//52
	20,	//53
	19,	//54
	19,	//55
	19,	//56
	18,	//57
	18,	//58
	17,	//59
	17,	//60
	16,	//61
	16,	//62
	15,	//63
	15,	//64
	14,	//65
	14,	//66
	13,	//67
	13,	//68
	12,	//69
	12,	//70
	11,	//71
	11,	//72
	10,	//73
	10,	//74
	10,	//75
	9,	//76
	9,	//77
	8,	//78
	8,	//79
	8,	//80
	7,	//81
	7,	//82
	6,	//83
	6,	//84
	6,	//85
	6,	//86
	6,	//87
	5,	//88
	5,	//89
	5,	//90
	5,	//91
	5,	//92
	5,	//93
	5,	//94
	5,	//95
	5,	//96
	4,	//97
	4,	//98
	4,	//99
	4,	//100
	4,	//101
	4,	//102
	3,	//103
	3,	//104
	3,	//105
	2,	//106
	2,	//107
	2,	//108
	1,	//109
	1,	//110
	1,	//111
	1,	//112
	1,	//113
	0,	//114
	0,	//115
	0,	//116
	0,	//117
	0,	//118
	0,	//119
	0,	//120
	0,	//121
	0,	//122
	0,	//123
	0,	//124
	0,	//125
	0,	//126
	0,	//127
	0,	//127
	0,	//127
	0,	//127
};
const PROGMEM char Env3[]=
{
	255,	//0
	250,	//1
	246,	//2
	242,	//3
	238,	//4
	233,	//5
	229,	//6
	225,	//7
	221,	//8
	217,	//9
	213,	//10
	209,	//11
	206,	//12
	202,	//13
	199,	//14
	195,	//15
	191,	//16
	188,	//17
	183,	//18
	179,	//19
	175,	//20
	170,	//21
	166,	//22
	161,	//23
	157,	//24
	153,	//25
	148,	//26
	144,	//27
	139,	//28
	134,	//29
	130,	//30
	125,	//31
	121,	//32
	116,	//33
	112,	//34
	109,	//35
	105,	//36
	102,	//37
	99,	//38
	96,	//39
	93,	//40
	90,	//41
	87,	//42
	83,	//43
	80,	//44
	77,	//45
	74,	//46
	71,	//47
	68,	//48
	65,	//49
	61,	//50
	58,	//51
	56,	//52
	54,	//53
	51,	//54
	49,	//55
	46,	//56
	44,	//57
	42,	//58
	39,	//59
	37,	//60
	34,	//61
	31,	//62
	28,	//63
	25,	//64
	22,	//65
	19,	//66
	16,	//67
	13,	//68
	12,	//69
	12,	//70
	11,	//71
	11,	//72
	10,	//73
	10,	//74
	10,	//75
	9,	//76
	9,	//77
	8,	//78
	8,	//79
	8,	//80
	7,	//81
	7,	//82
	6,	//83
	6,	//84
	6,	//85
	6,	//86
	6,	//87
	5,	//88
	5,	//89
	5,	//90
	5,	//91
	5,	//92
	5,	//93
	5,	//94
	5,	//95
	5,	//96
	4,	//97
	4,	//98
	4,	//99
	4,	//100
	4,	//101
	4,	//102
	3,	//103
	3,	//104
	3,	//105
	2,	//106
	2,	//107
	2,	//108
	1,	//109
	1,	//110
	1,	//111
	1,	//112
	1,	//113
	0,	//114
	0,	//115
	0,	//116
	0,	//117
	0,	//118
	0,	//119
	0,	//120
	0,	//121
	0,	//122
	0,	//123
	0,	//124
	0,	//125
	0,	//126
	0,	//127
	0,	//127
	0,	//127
	0,	//127

};

const PROGMEM char User00Table[]={};
const PROGMEM char User01Table[]={};
const PROGMEM char User02Table[]={};
const PROGMEM char User03Table[]={};
const PROGMEM char User04Table[]={};
const PROGMEM char User05Table[]={};



#endif

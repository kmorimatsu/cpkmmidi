/*
   This file is provided under the LGPL license ver 2.1.
   Written by Katsumi.
   https://github.com/kmorimatsu/
*/

// BOOT region
/*
(0000)
ld hl,7200
ld de,d200
ld bc,0e00
ldir
jp d200
*/
const unsigned char cpmboot[]={
0x21,0x00,0x72,0x11,0x00,0xd2,0x01,0x00,0x0e,0xed,0xb0,0xc3,0x00,0xd2
};

// Bios address: 0xd200
// In ROM, this starts at 0x7200
const unsigned char monitor[]={
//BIOS: 0xD200-0xDFFF
0xc3,0x42,0xd2,0xc3,0xb9,0xd2,0xc3,0x2d,0xd3,0xc3,0x42,0xd3,0xc3,0x57,0xd3,0xc3,
0x6c,0xd3,0xc3,0x6d,0xd3,0xc3,0x6e,0xd3,0xc3,0x71,0xd3,0xc3,0x99,0xd3,0xc3,0xc4,
0xd3,0xc3,0xd3,0xd3,0xc3,0xe2,0xd3,0xc3,0xf1,0xd3,0xc3,0x3e,0xd4,0xc3,0x85,0xd4,
0xc3,0x87,0xd4,0xc3,0x33,0xd2,0xc3,0x36,0xd2,0xc3,0x39,0xd2,0xc3,0x3c,0xd2,0xc3,
0x3f,0xd2,0xf3,0x31,0x40,0xdf,0x3e,0x92,0xd3,0x03,0x3e,0xff,0xd3,0x02,0x3e,0x02,
0xd3,0x03,0x3e,0xc3,0x32,0x00,0x00,0x32,0x05,0x00,0x21,0x03,0xd2,0x22,0x01,0x00,
0x21,0x06,0xc4,0x22,0x06,0x00,0xaf,0x32,0x03,0x00,0x32,0x04,0x00,0x3e,0x03,0xd3,
0x03,0x21,0x7a,0xd2,0xcd,0x8b,0xd4,0xc3,0xb9,0xd2,0x2a,0x2a,0x2a,0x20,0x43,0x50,
0x2f,0x4b,0x4d,0x20,0x42,0x49,0x4f,0x53,0x20,0x4b,0x4d,0x2d,0x32,0x30,0x31,0x31,
0x20,0x28,0x35,0x34,0x6b,0x20,0x73,0x79,0x73,0x74,0x65,0x6d,0x29,0x20,0x31,0x39,
0x35,0x32,0x4b,0x20,0x62,0x79,0x74,0x65,0x73,0x20,0x78,0x20,0x34,0x20,0x44,0x72,
0x69,0x76,0x65,0x73,0x20,0x2a,0x2a,0x2a,0x00,0xf3,0x31,0x40,0xdf,0x3e,0x92,0xd3,
0x03,0x3e,0xff,0xd3,0x02,0x0e,0x00,0xcd,0x99,0xd3,0x01,0x00,0x00,0xcd,0xc4,0xd3,
0x21,0x00,0xbc,0x11,0x00,0x00,0x42,0x4b,0xcd,0xd3,0xd3,0x44,0x4d,0xcd,0xe2,0xd3,
0xcd,0xf1,0xd3,0x3d,0x28,0x17,0x01,0x80,0x00,0x09,0x13,0x3e,0x2c,0xbb,0x20,0xe6,
0x3e,0x02,0xd3,0x03,0x3a,0x04,0x00,0xe6,0x03,0x4f,0xc3,0x00,0xbc,0x21,0x05,0xd3,
0xcd,0x8b,0xd4,0x18,0xfe,0x44,0x69,0x73,0x6b,0x20,0x52,0x65,0x61,0x64,0x20,0x45,
0x72,0x72,0x6f,0x72,0x20,0x64,0x75,0x72,0x69,0x6e,0x67,0x20,0x6c,0x6f,0x61,0x64,
0x69,0x6e,0x67,0x20,0x43,0x43,0x50,0x2f,0x42,0x44,0x4f,0x53,0x00,0xed,0x73,0x00,
0xdc,0x31,0x80,0xdf,0xcd,0x9c,0xd4,0xcd,0x33,0xd2,0xcd,0x95,0xd4,0xed,0x7b,0x00,
0xdc,0xc9,0xed,0x73,0x00,0xdc,0x31,0x80,0xdf,0xcd,0x9c,0xd4,0xcd,0x36,0xd2,0xcd,
0x95,0xd4,0xed,0x7b,0x00,0xdc,0xc9,0xed,0x73,0x00,0xdc,0x31,0x80,0xdf,0xcd,0x9c,
0xd4,0xcd,0x39,0xd2,0xcd,0x95,0xd4,0xed,0x7b,0x00,0xdc,0xc9,0xc9,0xc9,0x3e,0x1a,
0xc9,0x22,0x00,0xdc,0x2a,0x02,0xdc,0x2d,0x20,0x05,0x21,0xf4,0x00,0x18,0x13,0x2d,
0x20,0x05,0x21,0xe8,0x01,0x18,0x0b,0x2d,0x20,0x05,0x21,0xdc,0x02,0x18,0x03,0x21,
0x01,0x00,0x22,0x03,0xdc,0x2a,0x00,0xdc,0xc9,0x32,0x00,0xdc,0x79,0x0d,0x20,0x05,
0x21,0x1b,0xdc,0x18,0x14,0x0d,0x20,0x05,0x21,0x2b,0xdc,0x18,0x0c,0x0d,0x20,0x05,
0x21,0x3b,0xdc,0x18,0x04,0xaf,0x21,0x0b,0xdc,0x22,0x09,0xdc,0x4f,0x32,0x02,0xdc,
0x3a,0x00,0xdc,0xc9,0x32,0x00,0xdc,0x79,0x32,0x03,0xdc,0x78,0x32,0x04,0xdc,0x3a,
0x00,0xdc,0xc9,0x32,0x00,0xdc,0x79,0x32,0x05,0xdc,0x78,0x32,0x06,0xdc,0x3a,0x00,
0xdc,0xc9,0x32,0x00,0xdc,0x79,0x32,0x07,0xdc,0x78,0x32,0x08,0xdc,0x3a,0x00,0xdc,
0xc9,0xed,0x73,0x00,0xdc,0x31,0x80,0xdf,0xe5,0xc5,0xd5,0xcd,0x9c,0xd4,0x2a,0x05,
0xdc,0x54,0x5d,0x2a,0x03,0xdc,0xcb,0x25,0xcb,0x14,0xcb,0x25,0xcb,0x14,0xcb,0x25,
0xcb,0x14,0xcb,0x25,0xcb,0x14,0xcb,0x25,0xcb,0x14,0xcb,0x25,0xcb,0x14,0x19,0xcd,
0x3c,0xd2,0xcd,0x95,0xd4,0xfe,0x01,0x28,0x0d,0x2a,0x07,0xdc,0x54,0x5d,0x21,0x80,
0xdf,0x01,0x80,0x00,0xed,0xb0,0xd1,0xc1,0xe1,0xed,0x7b,0x00,0xdc,0xc9,0xed,0x73,
0x00,0xdc,0x31,0x80,0xdf,0xe5,0xc5,0xd5,0x2a,0x07,0xdc,0x11,0x80,0xdf,0x01,0x80,
0x00,0xed,0xb0,0x2a,0x05,0xdc,0x54,0x5d,0x2a,0x03,0xdc,0xcb,0x25,0xcb,0x14,0xcb,
0x25,0xcb,0x14,0xcb,0x25,0xcb,0x14,0xcb,0x25,0xcb,0x14,0xcb,0x25,0xcb,0x14,0xcb,
0x25,0xcb,0x14,0x19,0xcd,0x9c,0xd4,0xcd,0x3f,0xd2,0xcd,0x95,0xd4,0xd1,0xc1,0xe1,
0xed,0x7b,0x00,0xdc,0xc9,0xaf,0xc9,0x60,0x69,0xc9,0xc9,0x4e,0xaf,0xb9,0xc8,0xcd,
0x57,0xd3,0x23,0x18,0xf6,0xf5,0x3e,0x02,0xd3,0x03,0xf1,0xc9,0xf5,0x3e,0x03,0xd3,
0x03,0xf1,0xc9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6f,0xdf,0x00,0x00,0x00,
0x00,0x00,0x00,0x87,0xdc,0x4b,0xdc,0x07,0xdd,0x87,0xdd,0x6f,0xdf,0x00,0x00,0x00,
0x00,0x00,0x00,0x87,0xdc,0x5a,0xdc,0x27,0xdd,0x01,0xde,0x6f,0xdf,0x00,0x00,0x00,
0x00,0x00,0x00,0x87,0xdc,0x69,0xdc,0x47,0xdd,0x7b,0xde,0x6f,0xdf,0x00,0x00,0x00,
0x00,0x00,0x00,0x87,0xdc,0x78,0xdc,0x67,0xdd,0xf5,0xde,0x40,0x00,0x04,0x0f,0x00,
0xcb,0x03,0x7f,0x00,0xc0,0x00,0x20,0x00,0x01,0x00,0x40,0x00,0x04,0x0f,0x00,0xcf,
0x03,0x7f,0x00,0xc0,0x00,0x20,0x00,0xf4,0x00,0x40,0x00,0x04,0x0f,0x00,0xcf,0x03,
0x7f,0x00,0xc0,0x00,0x20,0x00,0xe8,0x01,0x40,0x00,0x04,0x0f,0x00,0xcf,0x03,0x7f,
0x00,0xc0,0x00,0x20,0x00,0xdc,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
/*
; This file can be assembled by SDCC:
; sdasz80 -o %1
; sdcc *.rel -mz80 --code-loc 0xd200 --data-loc 0xdc00 --no-std-crt0

; There are four drives, A, B, C, and D
; 128 bytes/sector
; 64 sector/track
; 244 track/drive
; The first track in drive A (total 8192 bytes) is used
; to load CCP and BDOS into RAM.

; 8255 is assigned to port 0x00-0x03
; Port C1 (output) is used to select RAM/ROM for address 0x0000-0x7FFF
; If C1=1 (or port C is set for input), ROM is selected.
; If C1=0, RAM is selected.
.area _DATA
; Data area follows
; This area is also used in ROM routines
; Data area is 0xDC00-0xDF7F, including stack area.
; 0xDF80-0xDFFF (128 bytes) is used for buffer for disk read/write
; 

storeSP:   .dw 0
diskNum:   .db 0
trackNum:  .dw 0
sectorNum: .dw 0
dmAddress: .dw 0
pDPH:      .dw 0

jWBOOT     =0x0000  ; JUMP WBOOT address
IOBYTE     =0x0003  ; IOBYTE for CBIOS
CDISK      =0x0004  ; Current drive (MLB 4 bits)
jBDOS      =0x0005  ; JUMP BDOS address
ccpStart   =0xbc00  ; Using 54K system
bootStack  =0xDF40  ; Stark area for BOOT is from 0xDF00 and to 0xDF3F
biosStack  =0xDF80  ; Stack area for BIOS is from 0xDF00 and to 0xDF7F
diskBuff   =0xDF80  ; 128 bytes buffer for disk read/write by BIOS

; Disk Parameter Header (DPH) follows
; There are 4 parameters for drives A, B, C, and D
dph0:
	.dw trans ;XLT: Address of translation table
	.dw 0 ;000: Scratchpad
	.dw 0 ;000: Scratchpad
	.dw 0 ;000: Scratchpad
	.dw dirbuf ;DIRBUF: Address of a dirbuff scratchpad
	.dw dpb0 ;DPB: Address of a disk parameter block
	.dw chk0 ;CSV: Address of scratchpad area for changed disks
	.dw all0 ;ALV: Address of an allocation info scratchpad
dph1:
	.dw trans ;XLT: Address of translation table
	.dw 0 ;000: Scratchpad
	.dw 0 ;000: Scratchpad
	.dw 0 ;000: Scratchpad
	.dw dirbuf ;DIRBUF: Address of a dirbuff scratchpad
	.dw dpb1 ;DPB: Address of a disk parameter block
	.dw chk1 ;CSV: Address of scratchpad area for changed disks
	.dw all1 ;ALV: Address of an allocation info scratchpad
dph2:
	.dw trans ;XLT: Address of translation table
	.dw 0 ;000: Scratchpad
	.dw 0 ;000: Scratchpad
	.dw 0 ;000: Scratchpad
	.dw dirbuf ;DIRBUF: Address of a dirbuff scratchpad
	.dw dpb2 ;DPB: Address of a disk parameter block
	.dw chk2 ;CSV: Address of scratchpad area for changed disks
	.dw all2 ;ALV: Address of an allocation info scratchpad
dph3:
	.dw trans ;XLT: Address of translation table
	.dw 0 ;000: Scratchpad
	.dw 0 ;000: Scratchpad
	.dw 0 ;000: Scratchpad
	.dw dirbuf ;DIRBUF: Address of a dirbuff scratchpad
	.dw dpb3 ;DPB: Address of a disk parameter block
	.dw chk3 ;CSV: Address of scratchpad area for changed disks
	.dw all3 ;ALV: Address of an allocation info scratchpad

; Disk Parameter Brock (DPB) follows
; There are 4 brocks for drives A, B, C, and D
dpb0:
	.dw 64 ;SPT: sectors per track
	.db 4 ;BSH: data allocation block shift factor
	.db 15 ;BLM: Data Allocation Mask
	.db 0 ;Extent mask
	.dw 971 ;DSM: Disk storage capacity. Use 975 for drives 1-3.
	.dw 127 ;DRM, no of directory entries
	.db 192 ;AL0
	.db 0 ;AL1
	.dw 32 ;CKS, size of dir check vector
	.dw 1 ;OFF, no of reserved tracks Use 244, 488, and 732 for drives 1, 2, and 3.
dpb1:
	.dw 64 ;SPT: sectors per track
	.db 4 ;BSH: data allocation block shift factor
	.db 15 ;BLM: Data Allocation Mask
	.db 0 ;Extent mask
	.dw 975 ;DSM: Disk storage capacity.
	.dw 127 ;DRM, no of directory entries
	.db 192 ;AL0
	.db 0 ;AL1
	.dw 32 ;CKS, size of dir check vector
	.dw 244 ;OFF, no of reserved tracks
dpb2:
	.dw 64 ;SPT: sectors per track
	.db 4 ;BSH: data allocation block shift factor
	.db 15 ;BLM: Data Allocation Mask
	.db 0 ;Extent mask
	.dw 975 ;DSM: Disk storage capacity.
	.dw 127 ;DRM, no of directory entries
	.db 192 ;AL0
	.db 0 ;AL1
	.dw 32 ;CKS, size of dir check vector
	.dw 488 ;OFF, no of reserved tracks 
dpb3:
	.dw 64 ;SPT: sectors per track
	.db 4 ;BSH: data allocation block shift factor
	.db 15 ;BLM: Data Allocation Mask
	.db 0 ;Extent mask
	.dw 975 ;DSM: Disk storage capacity.
	.dw 127 ;DRM, no of directory entries
	.db 192 ;AL0
	.db 0 ;AL1
	.dw 32 ;CKS, size of dir check vector
	.dw 732 ;OFF, no of reserved tracks

dirbuf: .ds 128
chk0:   .ds 32
chk1:   .ds 32
chk2:   .ds 32
chk3:   .ds 32
all0:   .ds 122
all1:   .ds 122
all2:   .ds 122
all3:   .ds 122

trans:  .db 0

; End of data area

.area _CODE
; BIOS jump table (CP/M)
JP CBOOT           ;0xd200
JP WBOOT           ;0xd203
JP CONST           ;0xd206
JP CONIN           ;0xd209
JP CONOUT          ;0xd20c
JP LIST            ;0xd20f
JP PUNCH           ;0xd212
JP READER          ;0xd215
JP HOME            ;0xd218
JP SELDSK          ;0xd21b
JP SETTRK          ;0xd21e
JP SETSEC          ;0xd221
JP SETDMA          ;0xd224
JP READ            ;0xd227
JP WRITE           ;0xd22a
JP LISTST          ;0xd22d
JP SECTRAN         ;0xd230

; Environ specific codes jump table (infinite loop for emulator)
romCONST:  JP romCONST  ;0xd233
romCONIN:  JP romCONIN  ;0xd236
romCONOUT: JP romCONOUT ;0xd239
romREAD:   JP romREAD   ;0xd23c
romWRITE:  JP romWRITE  ;0xd23f

; CP/M BIOS routines
CBOOT:
	; On ROM address 0x0000, jump here.
	; Initialize 8255, initialize RAM 0x0000-0x0007, and continue to WBOOT routine.
	; Note that not RAM but ROM is selected from the address 0x0000
	; At the ROM address 0x0000, initializing disk emulation (SD card etc)
	; must be done.

	di
	ld sp,#bootStack

	; Initialize 8255
	; Mode 0 (for both group A and B)
	; Port A: input
	; Port B: input
	; Port C: output (for both upper and lower)
	ld a,#0x92
	out (3),a
	; Port C bits will be all 1 (ROM will be still chosen)
	ld a,#0xff
	out (2),a

	; Select RAM
	ld a,#0x02
	out (3),a

	; Initilize RAM 0x0000-0x0007
	ld a,#0xc3
	ld (#jWBOOT),a
	ld (#jBDOS),a
	ld hl,#ccpStart+0x1603
	ld (#jWBOOT+1),hl
	ld hl,#ccpStart+0x0806
	ld (#jBDOS+1),hl
	xor a
	ld (IOBYTE),a
	ld (CDISK),a

	; Select ROM
	ld a,#0x03
	out (3),a

	ld hl,#WELCOMEMSG
	call PRINTSTR
	jp WBOOT

WELCOMEMSG:
.ascii "*** CP/KM BIOS KM-2011 (54k system) 1952K bytes x 4 Drives ***"
.db 0

WBOOT:
	; Initialize stack and global variables
	di
	ld sp,#bootStack

	; Initialize 8255 (ROM will be still chosen)
	ld a,#0x92
	out (3),a
	ld a,#0xff
	out (2),a

	; Load CCP and BDOS
	; CPM.SYS contains CCP and BDOS and total 0x1600 (5632) bytes
	; This file is stored in drive A at track #0, sector #0-#43

	; Select drive A
	ld c,#0
	call SELDSK
	; Set track #0
	ld bc,#0x0000
	call SETTRK
	; Destination starts from CCP Address
	ld hl,#ccpStart
	; Sector # strats from 0x0000
	ld de,#0x0000
	
	WBOOT_LOOP:
		; Set sector #
		ld b,d
		ld c,e
		call SETSEC
		; Set destination address
		ld b,h
		ld c,l
		call SETDMA
		; Read from disk
		call READ
		; Check error
		dec a
		jr z,WBOOT_ERROR
		; Increment destination
		ld bc,#0x0080
		add hl,bc
		; Increment sector number
		inc de
		ld a,#0x2c ; # of sector is 44 (0x2c)
		cp e
	jr nz,WBOOT_LOOP
	
	; Select RAM
	ld a,#0x02
	out (3),a

	; Select current disk drive in Reg C (valid #:0-3)
	ld a,(CDISK)
	and #0x03
	ld c,a
	; Jump to CCP
	jp ccpStart
	
	WBOOT_ERROR:
		ld hl,#WBOOT_ERROR_STR
		call PRINTSTR
		WBOOT_ERROR_LOOP:
		jr WBOOT_ERROR_LOOP
	WBOOT_ERROR_STR:
		.ascii "Disk Read Error during loading CCP/BDOS"
		.db 0x00
CONST:
	; Store current SP and use BIOS stack area
	ld (#storeSP),sp
	ld sp,#biosStack
	; Use ROM in area from 0x0000
	call SELECTROM
	; Call ROM routine
	call romCONST
	; Use RAM in area from 0x0000
	call SELECTRAM
	; Restore SP and return
	ld sp,(#storeSP)
	ret
CONIN:
	ld (#storeSP),sp
	ld sp,#biosStack
	call SELECTROM
	call romCONIN
	call SELECTRAM
	ld sp,(#storeSP)
	ret
CONOUT:
	ld (#storeSP),sp
	ld sp,#biosStack
	call SELECTROM
	call romCONOUT
	call SELECTRAM
	ld sp,(#storeSP)
	ret
LIST:
	ret
PUNCH:
	ret
READER:
	ld a,#0x1a
	ret
HOME:
	ld (storeSP),hl
	ld hl,(#diskNum)
	dec l
	jr nz,HOME_NB
		; Drive B
		ld hl,#244
		jr HOME_DONE
	HOME_NB:
	dec l
	jr nz,HOME_NC
		; Drive C
		ld hl,#488
		jr HOME_DONE
	HOME_NC:
	dec l
	jr nz,HOME_ND
		; Drive D
		ld hl,#732
		jr HOME_DONE
	HOME_ND:
		; Drive A
		ld hl,#1
	HOME_DONE:
	ld (trackNum),hl
	ld hl,(storeSP)
	ret
SELDSK:
	ld (storeSP),a
	ld a,c
	dec c
	jr nz,SELDSK_LBL1
		; C==1
		; Select drive B
		ld hl,#dph1
		jr SELDSK_DONE
	SELDSK_LBL1:
	dec c
	jr nz,SELDSK_LBL2
		; C==2
		; Select drive C
		ld hl,#dph2
		jr SELDSK_DONE
	SELDSK_LBL2:
	dec c
	jr nz,SELDSK_LBL3
		; C==3
		; Select drive D
		ld hl,#dph3
		jr SELDSK_DONE
	SELDSK_LBL3:
		; Other C value (force C=0)
		; Select drive A
		xor a
		ld hl,#dph0
	SELDSK_DONE:
	ld (pDPH),hl
	ld c,a
	ld (diskNum),a
	ld a,(storeSP)
	ret
SETTRK:
	ld (storeSP),a
	ld a,c
	ld (trackNum),a
	ld a,b
	ld (trackNum+1),a
	ld a,(storeSP)
	ret
SETSEC:
	ld (storeSP),a
	ld a,c
	ld (sectorNum),a
	ld a,b
	ld (sectorNum+1),a
	ld a,(storeSP)
	ret
SETDMA:
	ld (storeSP),a
	ld a,c
	ld (dmAddress),a
	ld a,b
	ld (dmAddress+1),a
	ld a,(storeSP)
	ret
READ:
	ld (#storeSP),sp
	ld sp,#biosStack
	push hl
	push bc
	push de
	call SELECTROM
	; Call main routine
	; Pass HL as disk position # in total and get result in A
	; To calculate HL, get trackNum, shift to left 6 times, then add sectorNum
	ld hl,(sectorNum)
	ld d,h
	ld e,l
	ld hl,(trackNum)
	sla l
	rl h
	sla l
	rl h
	sla l
	rl h
	sla l
	rl h
	sla l
	rl h
	sla l
	rl h
	add hl,de
	call romREAD
	call SELECTRAM
	; SKIP LDIR if error (A==1)
	cp #1
	jr z,READ_SKIP
	; Transfer read data from diskBuff to dmAddress
	ld hl,(dmAddress)
	ld d,h
	ld e,l
	ld hl,#diskBuff
	ld bc,#128
	ldir
	READ_SKIP:
	pop de
	pop bc
	pop hl
	ld sp,(#storeSP)
	ret
WRITE:
	ld (#storeSP),sp
	ld sp,#biosStack
	push hl
	push bc
	push de
	; Transfer writing data from dm Address to diskBuff
	ld hl,(dmAddress)
	ld de,#diskBuff
	ld bc,#128
	ldir
	; Call main routine
	; Pass HL as disk position # in total and get result in A
	; To calculate HL, get trackNum, shift to left 6 times, then add sectorNum
	ld hl,(sectorNum)
	ld d,h
	ld e,l
	ld hl,(trackNum)
	sla l
	rl h
	sla l
	rl h
	sla l
	rl h
	sla l
	rl h
	sla l
	rl h
	sla l
	rl h
	add hl,de
	call SELECTROM
	call romWRITE
	call SELECTRAM
	pop de
	pop bc
	pop hl
	ld sp,(#storeSP)
	ret
LISTST:
	xor a
	ret
SECTRAN:
	ld h,b
	ld l,c
	ret
ret

PRINTSTR:
	ld c,(hl)
	xor a
	cp c
	ret z
	call CONOUT
	inc hl
	jr PRINTSTR

SELECTRAM:
	push af
	ld a,#0x02
	out (3),a
	pop af
	ret

SELECTROM:
	push af
	ld a,#0x03
	out (3),a
	pop af
	ret
*/
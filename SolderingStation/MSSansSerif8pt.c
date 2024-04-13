﻿#include <avr/pgmspace.h>

extern const char fontMSSansSerif8pt[];

const PROGMEM char fontMSSansSerif8pt[] =
{
    /**** Font Header ****/
    0x0D,0x00, /* font height in pixels */
    0x0B,0x00, /* font ascent (baseline) in pixels */
    0x18,0x00, /* number of character ranges */

    /**** Character Ranges ****/
    0x20,0x00,0x7F,0x00, /* First Character ID, Last Character ID */
    0xA0,0x00,0xA0,0x00,
    0xA4,0x00,0xA4,0x00,
    0xA6,0x00,0xA7,0x00,
    0xA9,0x00,0xA9,0x00,
    0xAB,0x00,0xAE,0x00,
    0xB0,0x00,0xB1,0x00,
    0xB5,0x00,0xB7,0x00,
    0xBB,0x00,0xBB,0x00,
    0x01,0x04,0x0C,0x04,
    0x0E,0x04,0x4F,0x04,
    0x51,0x04,0x5C,0x04,
    0x5E,0x04,0x5F,0x04,
    0x90,0x04,0x91,0x04,
    0x13,0x20,0x14,0x20,
    0x18,0x20,0x1A,0x20,
    0x1C,0x20,0x1E,0x20,
    0x20,0x20,0x22,0x20,
    0x26,0x20,0x26,0x20,
    0x30,0x20,0x30,0x20,
    0x39,0x20,0x3A,0x20,
    0xAC,0x20,0xAC,0x20,
    0x16,0x21,0x16,0x21,
    0x22,0x21,0x22,0x21,

    /**** Character Table ****/
    0x03,0x00,0x06,0x00,0xA0,0x05,
    0x03,0x00,0x06,0x00,0xA6,0x05,
    0x05,0x00,0x0A,0x00,0xAC,0x05,
    0x07,0x00,0x0E,0x00,0xB6,0x05,
    0x06,0x00,0x0C,0x00,0xC4,0x05,
    0x08,0x00,0x10,0x00,0xD0,0x05,
    0x06,0x00,0x0C,0x00,0xE0,0x05,
    0x02,0x00,0x04,0x00,0xEC,0x05,
    0x03,0x00,0x06,0x00,0xF0,0x05,
    0x03,0x00,0x06,0x00,0xF6,0x05,
    0x04,0x00,0x08,0x00,0xFC,0x05,
    0x06,0x00,0x0C,0x00,0x04,0x06,
    0x03,0x00,0x06,0x00,0x10,0x06,
    0x03,0x00,0x06,0x00,0x16,0x06,
    0x03,0x00,0x06,0x00,0x1C,0x06,
    0x05,0x00,0x0A,0x00,0x22,0x06,
    0x06,0x00,0x0C,0x00,0x2C,0x06,
    0x06,0x00,0x0C,0x00,0x38,0x06,
    0x06,0x00,0x0C,0x00,0x44,0x06,
    0x06,0x00,0x0C,0x00,0x50,0x06,
    0x06,0x00,0x0C,0x00,0x5C,0x06,
    0x06,0x00,0x0C,0x00,0x68,0x06,
    0x06,0x00,0x0C,0x00,0x74,0x06,
    0x06,0x00,0x0C,0x00,0x80,0x06,
    0x06,0x00,0x0C,0x00,0x8C,0x06,
    0x06,0x00,0x0C,0x00,0x98,0x06,
    0x03,0x00,0x06,0x00,0xA4,0x06,
    0x03,0x00,0x06,0x00,0xAA,0x06,
    0x06,0x00,0x0C,0x00,0xB0,0x06,
    0x06,0x00,0x0C,0x00,0xBC,0x06,
    0x06,0x00,0x0C,0x00,0xC8,0x06,
    0x06,0x00,0x0C,0x00,0xD4,0x06,
    0x0B,0x00,0x16,0x00,0xE0,0x06,
    0x07,0x00,0x0E,0x00,0xF6,0x06,
    0x07,0x00,0x0E,0x00,0x04,0x07,
    0x07,0x00,0x0E,0x00,0x12,0x07,
    0x08,0x00,0x10,0x00,0x20,0x07,
    0x07,0x00,0x0E,0x00,0x30,0x07,
    0x06,0x00,0x0C,0x00,0x3E,0x07,
    0x08,0x00,0x10,0x00,0x4A,0x07,
    0x08,0x00,0x10,0x00,0x5A,0x07,
    0x03,0x00,0x06,0x00,0x6A,0x07,
    0x05,0x00,0x0A,0x00,0x70,0x07,
    0x07,0x00,0x0E,0x00,0x7A,0x07,
    0x06,0x00,0x0C,0x00,0x88,0x07,
    0x09,0x00,0x12,0x00,0x94,0x07,
    0x08,0x00,0x10,0x00,0xA6,0x07,
    0x08,0x00,0x10,0x00,0xB6,0x07,
    0x07,0x00,0x0E,0x00,0xC6,0x07,
    0x08,0x00,0x10,0x00,0xD4,0x07,
    0x08,0x00,0x10,0x00,0xE4,0x07,
    0x07,0x00,0x0E,0x00,0xF4,0x07,
    0x07,0x00,0x0E,0x00,0x02,0x08,
    0x08,0x00,0x10,0x00,0x10,0x08,
    0x07,0x00,0x0E,0x00,0x20,0x08,
    0x0B,0x00,0x16,0x00,0x2E,0x08,
    0x07,0x00,0x0E,0x00,0x44,0x08,
    0x07,0x00,0x0E,0x00,0x52,0x08,
    0x07,0x00,0x0E,0x00,0x60,0x08,
    0x03,0x00,0x06,0x00,0x6E,0x08,
    0x05,0x00,0x0A,0x00,0x74,0x08,
    0x03,0x00,0x06,0x00,0x7E,0x08,
    0x06,0x00,0x0C,0x00,0x84,0x08,
    0x06,0x00,0x0C,0x00,0x90,0x08,
    0x03,0x00,0x06,0x00,0x9C,0x08,
    0x06,0x00,0x0C,0x00,0xA2,0x08,
    0x06,0x00,0x0C,0x00,0xAE,0x08,
    0x06,0x00,0x0C,0x00,0xBA,0x08,
    0x06,0x00,0x0C,0x00,0xC6,0x08,
    0x06,0x00,0x0C,0x00,0xD2,0x08,
    0x03,0x00,0x06,0x00,0xDE,0x08,
    0x06,0x00,0x0C,0x00,0xE4,0x08,
    0x06,0x00,0x0C,0x00,0xF0,0x08,
    0x02,0x00,0x04,0x00,0xFC,0x08,
    0x02,0x00,0x04,0x00,0x00,0x09,
    0x06,0x00,0x0C,0x00,0x04,0x09,
    0x02,0x00,0x04,0x00,0x10,0x09,
    0x08,0x00,0x10,0x00,0x14,0x09,
    0x06,0x00,0x0C,0x00,0x24,0x09,
    0x06,0x00,0x0C,0x00,0x30,0x09,
    0x06,0x00,0x0C,0x00,0x3C,0x09,
    0x06,0x00,0x0C,0x00,0x48,0x09,
    0x03,0x00,0x06,0x00,0x54,0x09,
    0x05,0x00,0x0A,0x00,0x5A,0x09,
    0x03,0x00,0x06,0x00,0x64,0x09,
    0x06,0x00,0x0C,0x00,0x6A,0x09,
    0x06,0x00,0x0C,0x00,0x76,0x09,
    0x08,0x00,0x10,0x00,0x82,0x09,
    0x05,0x00,0x0A,0x00,0x92,0x09,
    0x05,0x00,0x0A,0x00,0x9C,0x09,
    0x05,0x00,0x0A,0x00,0xA6,0x09,
    0x04,0x00,0x08,0x00,0xB0,0x09,
    0x02,0x00,0x04,0x00,0xB8,0x09,
    0x04,0x00,0x08,0x00,0xBC,0x09,
    0x07,0x00,0x0E,0x00,0xC4,0x09,
    0x03,0x00,0x06,0x00,0xD2,0x09,
    0x03,0x00,0x06,0x00,0xD8,0x09,
    0x06,0x00,0x0C,0x00,0xDE,0x09,
    0x02,0x00,0x04,0x00,0xEA,0x09,
    0x06,0x00,0x0C,0x00,0xEE,0x09,
    0x09,0x00,0x12,0x00,0xFA,0x09,
    0x06,0x00,0x0C,0x00,0x0C,0x0A,
    0x06,0x00,0x0C,0x00,0x18,0x0A,
    0x03,0x00,0x06,0x00,0x24,0x0A,
    0x09,0x00,0x12,0x00,0x2A,0x0A,
    0x04,0x00,0x08,0x00,0x3C,0x0A,
    0x06,0x00,0x0C,0x00,0x44,0x0A,
    0x06,0x00,0x0C,0x00,0x50,0x0A,
    0x06,0x00,0x0C,0x00,0x5C,0x0A,
    0x03,0x00,0x06,0x00,0x68,0x0A,
    0x06,0x00,0x0C,0x00,0x6E,0x0A,
    0x07,0x00,0x0E,0x00,0x7A,0x0A,
    0x09,0x00,0x12,0x00,0x88,0x0A,
    0x06,0x00,0x0C,0x00,0x9A,0x0A,
    0x07,0x00,0x0E,0x00,0xA6,0x0A,
    0x07,0x00,0x0E,0x00,0xB4,0x0A,
    0x03,0x00,0x06,0x00,0xC2,0x0A,
    0x03,0x00,0x06,0x00,0xC8,0x0A,
    0x05,0x00,0x0A,0x00,0xCE,0x0A,
    0x0B,0x00,0x16,0x00,0xD8,0x0A,
    0x0B,0x00,0x16,0x00,0xEE,0x0A,
    0x09,0x00,0x12,0x00,0x04,0x0B,
    0x07,0x00,0x0E,0x00,0x16,0x0B,
    0x08,0x00,0x10,0x00,0x24,0x0B,
    0x07,0x00,0x0E,0x00,0x34,0x0B,
    0x07,0x00,0x0E,0x00,0x42,0x0B,
    0x07,0x00,0x0E,0x00,0x50,0x0B,
    0x07,0x00,0x0E,0x00,0x5E,0x0B,
    0x06,0x00,0x0C,0x00,0x6C,0x0B,
    0x09,0x00,0x12,0x00,0x78,0x0B,
    0x07,0x00,0x0E,0x00,0x8A,0x0B,
    0x0B,0x00,0x16,0x00,0x98,0x0B,
    0x07,0x00,0x0E,0x00,0xAE,0x0B,
    0x08,0x00,0x10,0x00,0xBC,0x0B,
    0x08,0x00,0x10,0x00,0xCC,0x0B,
    0x07,0x00,0x0E,0x00,0xDC,0x0B,
    0x08,0x00,0x10,0x00,0xEA,0x0B,
    0x09,0x00,0x12,0x00,0xFA,0x0B,
    0x08,0x00,0x10,0x00,0x0C,0x0C,
    0x08,0x00,0x10,0x00,0x1C,0x0C,
    0x08,0x00,0x10,0x00,0x2C,0x0C,
    0x07,0x00,0x0E,0x00,0x3C,0x0C,
    0x07,0x00,0x0E,0x00,0x4A,0x0C,
    0x07,0x00,0x0E,0x00,0x58,0x0C,
    0x08,0x00,0x10,0x00,0x66,0x0C,
    0x0B,0x00,0x16,0x00,0x76,0x0C,
    0x07,0x00,0x0E,0x00,0x8C,0x0C,
    0x08,0x00,0x10,0x00,0x9A,0x0C,
    0x08,0x00,0x10,0x00,0xAA,0x0C,
    0x09,0x00,0x12,0x00,0xBA,0x0C,
    0x0A,0x00,0x14,0x00,0xCC,0x0C,
    0x08,0x00,0x10,0x00,0xE0,0x0C,
    0x0A,0x00,0x14,0x00,0xF0,0x0C,
    0x07,0x00,0x0E,0x00,0x04,0x0D,
    0x07,0x00,0x0E,0x00,0x12,0x0D,
    0x09,0x00,0x12,0x00,0x20,0x0D,
    0x08,0x00,0x10,0x00,0x32,0x0D,
    0x06,0x00,0x0C,0x00,0x42,0x0D,
    0x06,0x00,0x0C,0x00,0x4E,0x0D,
    0x06,0x00,0x0C,0x00,0x5A,0x0D,
    0x05,0x00,0x0A,0x00,0x66,0x0D,
    0x06,0x00,0x0C,0x00,0x70,0x0D,
    0x06,0x00,0x0C,0x00,0x7C,0x0D,
    0x08,0x00,0x10,0x00,0x88,0x0D,
    0x06,0x00,0x0C,0x00,0x98,0x0D,
    0x06,0x00,0x0C,0x00,0xA4,0x0D,
    0x06,0x00,0x0C,0x00,0xB0,0x0D,
    0x06,0x00,0x0C,0x00,0xBC,0x0D,
    0x06,0x00,0x0C,0x00,0xC8,0x0D,
    0x08,0x00,0x10,0x00,0xD4,0x0D,
    0x06,0x00,0x0C,0x00,0xE4,0x0D,
    0x06,0x00,0x0C,0x00,0xF0,0x0D,
    0x06,0x00,0x0C,0x00,0xFC,0x0D,
    0x06,0x00,0x0C,0x00,0x08,0x0E,
    0x06,0x00,0x0C,0x00,0x14,0x0E,
    0x05,0x00,0x0A,0x00,0x20,0x0E,
    0x05,0x00,0x0A,0x00,0x2A,0x0E,
    0x08,0x00,0x10,0x00,0x34,0x0E,
    0x05,0x00,0x0A,0x00,0x44,0x0E,
    0x06,0x00,0x0C,0x00,0x4E,0x0E,
    0x05,0x00,0x0A,0x00,0x5A,0x0E,
    0x08,0x00,0x10,0x00,0x64,0x0E,
    0x09,0x00,0x12,0x00,0x74,0x0E,
    0x07,0x00,0x0E,0x00,0x86,0x0E,
    0x08,0x00,0x10,0x00,0x94,0x0E,
    0x06,0x00,0x0C,0x00,0xA4,0x0E,
    0x06,0x00,0x0C,0x00,0xB0,0x0E,
    0x08,0x00,0x10,0x00,0xBC,0x0E,
    0x06,0x00,0x0C,0x00,0xCC,0x0E,
    0x06,0x00,0x0C,0x00,0xD8,0x0E,
    0x06,0x00,0x0C,0x00,0xE4,0x0E,
    0x05,0x00,0x0A,0x00,0xF0,0x0E,
    0x06,0x00,0x0C,0x00,0xFA,0x0E,
    0x05,0x00,0x0A,0x00,0x06,0x0F,
    0x02,0x00,0x04,0x00,0x10,0x0F,
    0x03,0x00,0x06,0x00,0x14,0x0F,
    0x02,0x00,0x04,0x00,0x1A,0x0F,
    0x0A,0x00,0x14,0x00,0x1E,0x0F,
    0x0A,0x00,0x14,0x00,0x32,0x0F,
    0x06,0x00,0x0C,0x00,0x46,0x0F,
    0x06,0x00,0x0C,0x00,0x52,0x0F,
    0x05,0x00,0x0A,0x00,0x5E,0x0F,
    0x06,0x00,0x0C,0x00,0x68,0x0F,
    0x06,0x00,0x0C,0x00,0x74,0x0F,
    0x05,0x00,0x0A,0x00,0x80,0x0F,
    0x05,0x00,0x0A,0x00,0x8A,0x0F,
    0x06,0x00,0x0C,0x00,0x94,0x0F,
    0x03,0x00,0x06,0x00,0xA0,0x0F,
    0x03,0x00,0x06,0x00,0xA6,0x0F,
    0x03,0x00,0x06,0x00,0xAC,0x0F,
    0x04,0x00,0x08,0x00,0xB2,0x0F,
    0x04,0x00,0x08,0x00,0xBA,0x0F,
    0x05,0x00,0x0A,0x00,0xC2,0x0F,
    0x05,0x00,0x0A,0x00,0xCC,0x0F,
    0x05,0x00,0x0A,0x00,0xD6,0x0F,
    0x06,0x00,0x0C,0x00,0xE0,0x0F,
    0x06,0x00,0x0C,0x00,0xEC,0x0F,
    0x0B,0x00,0x16,0x00,0xF8,0x0F,
    0x06,0x00,0x0C,0x00,0x0E,0x10,
    0x06,0x00,0x0C,0x00,0x1A,0x10,
    0x06,0x00,0x0C,0x00,0x26,0x10,
    0x0B,0x00,0x16,0x00,0x32,0x10,
    0x09,0x00,0x12,0x00,0x48,0x10,

    /**** Bitmap Data ****/
    // Character: 0x0020
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    // Character: 0x0021
    0x00, 0xFC, 0x00, 0x00, 0x05, 0x00,

    // Character: 0x0022
    0x00, 0x1C, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00,
    0x00, 0x00,

    // Character: 0x0023
    0x00, 0x10, 0xFC, 0x10, 0x10, 0xFC, 0x10, 0x00,
    0x01, 0x07, 0x01, 0x01, 0x07, 0x01,

    // Character: 0x0024
    0x00, 0x30, 0x48, 0xFC, 0x88, 0x10, 0x00, 0x02,
    0x04, 0x0F, 0x04, 0x03,

    // Character: 0x0025
    0x00, 0x08, 0x14, 0x94, 0x48, 0x20, 0x10, 0x08,
    0x00, 0x02, 0x01, 0x00, 0x02, 0x05, 0x05, 0x02,

    // Character: 0x0026
    0x00, 0x98, 0x64, 0x98, 0x00, 0x80, 0x00, 0x03,
    0x04, 0x04, 0x03, 0x04,

    // Character: 0x0027
    0x00, 0x1C, 0x00, 0x00,

    // Character: 0x0028
    0x00, 0xF8, 0x04, 0x00, 0x0F, 0x10,

    // Character: 0x0029
    0x00, 0x04, 0xF8, 0x00, 0x10, 0x0F,

    // Character: 0x002A
    0x00, 0x28, 0x10, 0x28, 0x00, 0x00, 0x00, 0x00,

    // Character: 0x002B
    0x00, 0x80, 0x80, 0xE0, 0x80, 0x80, 0x00, 0x00,
    0x00, 0x03, 0x00, 0x00,

    // Character: 0x002C
    0x00, 0x00, 0x00, 0x00, 0x08, 0x04,

    // Character: 0x002D
    0x00, 0x80, 0x80, 0x00, 0x00, 0x00,

    // Character: 0x002E
    0x00, 0x00, 0x00, 0x00, 0x04, 0x00,

    // Character: 0x002F
    0x00, 0x00, 0x80, 0x60, 0x1C, 0x00, 0x06, 0x01,
    0x00, 0x00,

    // Character: 0x0030
    0x00, 0xF8, 0x04, 0x04, 0x04, 0xF8, 0x00, 0x03,
    0x04, 0x04, 0x04, 0x03,

    // Character: 0x0031
    0x00, 0x08, 0x08, 0xFC, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x07, 0x00, 0x00,

    // Character: 0x0032
    0x00, 0x08, 0x04, 0x84, 0x44, 0x38, 0x00, 0x06,
    0x05, 0x04, 0x04, 0x04,

    // Character: 0x0033
    0x00, 0x08, 0x04, 0x44, 0x44, 0xB8, 0x00, 0x02,
    0x04, 0x04, 0x04, 0x03,

    // Character: 0x0034
    0x00, 0x80, 0x60, 0x18, 0xFC, 0x00, 0x00, 0x01,
    0x01, 0x01, 0x07, 0x01,

    // Character: 0x0035
    0x00, 0x7C, 0x24, 0x24, 0x24, 0xC4, 0x00, 0x02,
    0x04, 0x04, 0x04, 0x03,

    // Character: 0x0036
    0x00, 0xF8, 0x44, 0x44, 0x44, 0x88, 0x00, 0x03,
    0x04, 0x04, 0x04, 0x03,

    // Character: 0x0037
    0x00, 0x04, 0x04, 0xC4, 0x34, 0x0C, 0x00, 0x00,
    0x07, 0x00, 0x00, 0x00,

    // Character: 0x0038
    0x00, 0xB8, 0x44, 0x44, 0x44, 0xB8, 0x00, 0x03,
    0x04, 0x04, 0x04, 0x03,

    // Character: 0x0039
    0x00, 0x38, 0x44, 0x44, 0x44, 0xF8, 0x00, 0x02,
    0x04, 0x04, 0x04, 0x03,

    // Character: 0x003A
    0x00, 0x20, 0x00, 0x00, 0x04, 0x00,

    // Character: 0x003B
    0x00, 0x00, 0x20, 0x00, 0x08, 0x04,

    // Character: 0x003C
    0x00, 0x80, 0x40, 0x20, 0x10, 0x00, 0x00, 0x00,
    0x01, 0x02, 0x04, 0x00,

    // Character: 0x003D
    0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x01,
    0x01, 0x01, 0x01, 0x01,

    // Character: 0x003E
    0x00, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x04,
    0x02, 0x01, 0x00, 0x00,

    // Character: 0x003F
    0x00, 0x08, 0x04, 0x84, 0x44, 0x38, 0x00, 0x00,
    0x00, 0x05, 0x00, 0x00,

    // Character: 0x0040
    0x00, 0xE0, 0x18, 0x08, 0xC4, 0x24, 0x24, 0xE4,
    0x08, 0x18, 0xE0, 0x00, 0x01, 0x06, 0x04, 0x08,
    0x09, 0x09, 0x08, 0x09, 0x01, 0x01,

    // Character: 0x0041
    0x00, 0xC0, 0x30, 0x0C, 0x30, 0xC0, 0x00, 0x06,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x06,

    // Character: 0x0042
    0x00, 0xFC, 0x44, 0x44, 0x44, 0xB8, 0x00, 0x00,
    0x07, 0x04, 0x04, 0x04, 0x03, 0x00,

    // Character: 0x0043
    0x00, 0xF8, 0x04, 0x04, 0x04, 0x04, 0x08, 0x00,
    0x03, 0x04, 0x04, 0x04, 0x04, 0x02,

    // Character: 0x0044
    0x00, 0xFC, 0x04, 0x04, 0x04, 0x08, 0xF0, 0x00,
    0x00, 0x07, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00,

    // Character: 0x0045
    0x00, 0xFC, 0x44, 0x44, 0x44, 0x04, 0x00, 0x00,
    0x07, 0x04, 0x04, 0x04, 0x04, 0x00,

    // Character: 0x0046
    0x00, 0xFC, 0x44, 0x44, 0x44, 0x04, 0x00, 0x07,
    0x00, 0x00, 0x00, 0x00,

    // Character: 0x0047
    0x00, 0xF8, 0x04, 0x04, 0x44, 0x44, 0xC8, 0x00,
    0x00, 0x03, 0x04, 0x04, 0x04, 0x02, 0x07, 0x00,

    // Character: 0x0048
    0x00, 0xFC, 0x40, 0x40, 0x40, 0x40, 0xFC, 0x00,
    0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00,

    // Character: 0x0049
    0x00, 0xFC, 0x00, 0x00, 0x07, 0x00,

    // Character: 0x004A
    0x00, 0x00, 0x00, 0xFC, 0x00, 0x03, 0x04, 0x04,
    0x03, 0x00,

    // Character: 0x004B
    0x00, 0xFC, 0x60, 0x90, 0x08, 0x04, 0x00, 0x00,
    0x07, 0x00, 0x00, 0x01, 0x02, 0x04,

    // Character: 0x004C
    0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
    0x04, 0x04, 0x04, 0x04,

    // Character: 0x004D
    0x00, 0xFC, 0x30, 0xC0, 0x00, 0xC0, 0x30, 0xFC,
    0x00, 0x00, 0x07, 0x00, 0x00, 0x03, 0x00, 0x00,
    0x07, 0x00,

    // Character: 0x004E
    0x00, 0xFC, 0x18, 0x60, 0x80, 0x00, 0xFC, 0x00,
    0x00, 0x07, 0x00, 0x00, 0x00, 0x03, 0x07, 0x00,

    // Character: 0x004F
    0x00, 0xF8, 0x04, 0x04, 0x04, 0x04, 0xF8, 0x00,
    0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00,

    // Character: 0x0050
    0x00, 0xFC, 0x44, 0x44, 0x44, 0x44, 0x38, 0x00,
    0x07, 0x00, 0x00, 0x00, 0x00, 0x00,

    // Character: 0x0051
    0x00, 0xF8, 0x04, 0x04, 0x04, 0x04, 0xF8, 0x00,
    0x00, 0x03, 0x04, 0x04, 0x05, 0x06, 0x0B, 0x00,

    // Character: 0x0052
    0x00, 0xFC, 0x44, 0x44, 0x44, 0x44, 0xB8, 0x00,
    0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00,

    // Character: 0x0053
    0x00, 0x38, 0x44, 0x44, 0x44, 0x88, 0x00, 0x00,
    0x02, 0x04, 0x04, 0x04, 0x03, 0x00,

    // Character: 0x0054
    0x00, 0x04, 0x04, 0xFC, 0x04, 0x04, 0x00, 0x00,
    0x00, 0x00, 0x07, 0x00, 0x00, 0x00,

    // Character: 0x0055
    0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00,
    0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00,

    // Character: 0x0056
    0x0C, 0x70, 0x80, 0x00, 0x80, 0x70, 0x0C, 0x00,
    0x00, 0x01, 0x06, 0x01, 0x00, 0x00,

    // Character: 0x0057
    0x0C, 0x70, 0x80, 0x00, 0x80, 0x70, 0x80, 0x00,
    0x80, 0x70, 0x0C, 0x00, 0x00, 0x01, 0x06, 0x01,
    0x00, 0x01, 0x06, 0x01, 0x00, 0x00,

    // Character: 0x0058
    0x0C, 0x10, 0xA0, 0x40, 0xA0, 0x10, 0x0C, 0x06,
    0x01, 0x00, 0x00, 0x00, 0x01, 0x06,

    // Character: 0x0059
    0x0C, 0x10, 0x20, 0xC0, 0x20, 0x10, 0x0C, 0x00,
    0x00, 0x00, 0x07, 0x00, 0x00, 0x00,

    // Character: 0x005A
    0x04, 0x04, 0x84, 0x44, 0x24, 0x14, 0x0C, 0x06,
    0x05, 0x04, 0x04, 0x04, 0x04, 0x04,

    // Character: 0x005B
    0x00, 0xFC, 0x04, 0x00, 0x1F, 0x10,

    // Character: 0x005C
    0x00, 0x1C, 0x60, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x06,

    // Character: 0x005D
    0x00, 0x04, 0xFC, 0x00, 0x10, 0x1F,

    // Character: 0x005E
    0x00, 0x08, 0x04, 0x02, 0x04, 0x08, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,

    // Character: 0x005F
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10,
    0x10, 0x10, 0x10, 0x10,

    // Character: 0x0060
    0x00, 0x04, 0x08, 0x00, 0x00, 0x00,

    // Character: 0x0061
    0x00, 0x00, 0xA0, 0xA0, 0xA0, 0xC0, 0x00, 0x03,
    0x04, 0x04, 0x04, 0x07,

    // Character: 0x0062
    0x00, 0xFC, 0x20, 0x20, 0x20, 0xC0, 0x00, 0x07,
    0x04, 0x04, 0x04, 0x03,

    // Character: 0x0063
    0x00, 0xC0, 0x20, 0x20, 0x20, 0x40, 0x00, 0x03,
    0x04, 0x04, 0x04, 0x02,

    // Character: 0x0064
    0x00, 0xC0, 0x20, 0x20, 0x20, 0xFC, 0x00, 0x03,
    0x04, 0x04, 0x04, 0x07,

    // Character: 0x0065
    0x00, 0xC0, 0xA0, 0xA0, 0xA0, 0xC0, 0x00, 0x03,
    0x04, 0x04, 0x04, 0x02,

    // Character: 0x0066
    0x00, 0xF8, 0x24, 0x00, 0x07, 0x00,

    // Character: 0x0067
    0x00, 0xC0, 0x20, 0x20, 0x20, 0xE0, 0x00, 0x13,
    0x14, 0x14, 0x14, 0x0F,

    // Character: 0x0068
    0x00, 0xFC, 0x40, 0x20, 0x20, 0xC0, 0x00, 0x07,
    0x00, 0x00, 0x00, 0x07,

    // Character: 0x0069
    0x00, 0xE4, 0x00, 0x07,

    // Character: 0x006A
    0x00, 0xE4, 0x00, 0x1F,

    // Character: 0x006B
    0x00, 0xFC, 0x80, 0x40, 0x20, 0x00, 0x00, 0x07,
    0x00, 0x01, 0x02, 0x04,

    // Character: 0x006C
    0x00, 0xFC, 0x00, 0x07,

    // Character: 0x006D
    0x00, 0xE0, 0x20, 0x20, 0xC0, 0x20, 0x20, 0xC0,
    0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07,

    // Character: 0x006E
    0x00, 0xE0, 0x40, 0x20, 0x20, 0xC0, 0x00, 0x07,
    0x00, 0x00, 0x00, 0x07,

    // Character: 0x006F
    0x00, 0xC0, 0x20, 0x20, 0x20, 0xC0, 0x00, 0x03,
    0x04, 0x04, 0x04, 0x03,

    // Character: 0x0070
    0x00, 0xE0, 0x20, 0x20, 0x20, 0xC0, 0x00, 0x1F,
    0x04, 0x04, 0x04, 0x03,

    // Character: 0x0071
    0x00, 0xC0, 0x20, 0x20, 0x20, 0xE0, 0x00, 0x03,
    0x04, 0x04, 0x04, 0x1F,

    // Character: 0x0072
    0x00, 0xE0, 0x20, 0x00, 0x07, 0x00,

    // Character: 0x0073
    0x00, 0x40, 0xA0, 0x20, 0x40, 0x00, 0x02, 0x04,
    0x05, 0x02,

    // Character: 0x0074
    0x00, 0xF8, 0x20, 0x00, 0x03, 0x04,

    // Character: 0x0075
    0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x03,
    0x04, 0x04, 0x02, 0x07,

    // Character: 0x0076
    0x00, 0x60, 0x80, 0x00, 0x80, 0x60, 0x00, 0x00,
    0x01, 0x06, 0x01, 0x00,

    // Character: 0x0077
    0x00, 0xE0, 0x00, 0x80, 0x60, 0x80, 0x00, 0xE0,
    0x00, 0x01, 0x06, 0x01, 0x00, 0x01, 0x06, 0x01,

    // Character: 0x0078
    0x00, 0x60, 0x80, 0x80, 0x60, 0x00, 0x06, 0x01,
    0x01, 0x06,

    // Character: 0x0079
    0x00, 0xE0, 0x00, 0x00, 0xE0, 0x10, 0x11, 0x0E,
    0x02, 0x01,

    // Character: 0x007A
    0x00, 0x20, 0x20, 0xA0, 0x60, 0x00, 0x06, 0x05,
    0x04, 0x04,

    // Character: 0x007B
    0x00, 0x40, 0xBC, 0x02, 0x00, 0x00, 0x07, 0x08,

    // Character: 0x007C
    0x00, 0xFC, 0x00, 0x0F,

    // Character: 0x007D
    0x00, 0x02, 0xBC, 0x40, 0x00, 0x08, 0x07, 0x00,

    // Character: 0x007E
    0x00, 0x10, 0x08, 0x08, 0x10, 0x10, 0x08, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    // Character: 0x007F
    0xF8, 0x08, 0xF8, 0x07, 0x04, 0x07,

    // Character: 0x00A0
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    // Character: 0x00A4
    0x00, 0x74, 0x88, 0x88, 0x88, 0x74, 0x00, 0x01,
    0x00, 0x00, 0x00, 0x01,

    // Character: 0x00A6
    0x00, 0x7C, 0x00, 0x1F,

    // Character: 0x00A7
    0x00, 0x68, 0x94, 0x24, 0x44, 0x88, 0x00, 0x04,
    0x08, 0x09, 0x0A, 0x05,

    // Character: 0x00A9
    0x00, 0x70, 0x88, 0x24, 0x54, 0x54, 0x04, 0x88,
    0x70, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
    0x00, 0x00,

    // Character: 0x00AB
    0x00, 0x00, 0x80, 0x40, 0x80, 0x40, 0x00, 0x01,
    0x02, 0x05, 0x02, 0x04,

    // Character: 0x00AC
    0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01,

    // Character: 0x00AD
    0x00, 0x40, 0x40, 0x00, 0x00, 0x00,

    // Character: 0x00AE
    0x00, 0xFC, 0x02, 0x7A, 0x2A, 0x2A, 0x52, 0x02,
    0xFC, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x00,

    // Character: 0x00B0
    0x00, 0x08, 0x14, 0x08, 0x00, 0x00, 0x00, 0x00,

    // Character: 0x00B1
    0x00, 0x40, 0x40, 0xF0, 0x40, 0x40, 0x00, 0x04,
    0x04, 0x05, 0x04, 0x04,

    // Character: 0x00B5
    0x20, 0xE0, 0x00, 0x20, 0xE0, 0x00, 0x00, 0x0F,
    0x04, 0x04, 0x07, 0x02,

    // Character: 0x00B6
    0x00, 0x38, 0x7C, 0xFC, 0x04, 0xFC, 0x00, 0x00,
    0x00, 0x0F, 0x00, 0x0F,

    // Character: 0x00B7
    0x00, 0x40, 0x00, 0x00, 0x00, 0x00,

    // Character: 0x00BB
    0x00, 0x40, 0x80, 0x40, 0x80, 0x00, 0x00, 0x04,
    0x02, 0x05, 0x02, 0x01,

    // Character: 0x0401
    0x00, 0xFC, 0x45, 0x44, 0x45, 0x04, 0x00, 0x00,
    0x07, 0x04, 0x04, 0x04, 0x04, 0x00,

    // Character: 0x0402
    0x04, 0x04, 0x04, 0xFC, 0x44, 0x44, 0x44, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x06, 0x04,
    0x03, 0x00,

    // Character: 0x0403
    0x00, 0xFC, 0x04, 0x06, 0x05, 0x04, 0x00, 0x07,
    0x00, 0x00, 0x00, 0x00,

    // Character: 0x0404
    0x00, 0xF8, 0x44, 0x44, 0x44, 0x04, 0x08, 0x00,
    0x03, 0x04, 0x04, 0x04, 0x04, 0x02,

    // Character: 0x0405
    0x00, 0x38, 0x44, 0x44, 0x44, 0x88, 0x00, 0x00,
    0x02, 0x04, 0x04, 0x04, 0x03, 0x00,

    // Character: 0x0406
    0x00, 0xFC, 0x00, 0x00, 0x07, 0x00,

    // Character: 0x0407
    0x01, 0xFC, 0x01, 0x00, 0x07, 0x00,

    // Character: 0x0408
    0x00, 0x00, 0x00, 0xFC, 0x00, 0x03, 0x04, 0x04,
    0x03, 0x00,

    // Character: 0x0409
    0x00, 0x00, 0xF8, 0x04, 0x04, 0x04, 0xFC, 0x40,
    0x40, 0x40, 0x80, 0x00, 0x04, 0x03, 0x00, 0x00,
    0x00, 0x07, 0x04, 0x04, 0x04, 0x03,

    // Character: 0x040A
    0x00, 0xFC, 0x40, 0x40, 0x40, 0x40, 0xFC, 0x40,
    0x40, 0x40, 0x80, 0x00, 0x07, 0x00, 0x00, 0x00,
    0x00, 0x07, 0x04, 0x04, 0x04, 0x03,

    // Character: 0x040B
    0x04, 0x04, 0x04, 0xFC, 0x84, 0x44, 0x44, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
    0x07, 0x00,

    // Character: 0x040C
    0x00, 0xFC, 0x60, 0x92, 0x09, 0x04, 0x00, 0x00,
    0x07, 0x00, 0x00, 0x01, 0x02, 0x04,

    // Character: 0x040E
    0x00, 0x7C, 0x81, 0x82, 0x82, 0x81, 0xFC, 0x00,
    0x00, 0x02, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00,

    // Character: 0x040F
    0x00, 0xFC, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00,
    0x07, 0x04, 0x1C, 0x04, 0x07, 0x00,

    // Character: 0x0410
    0x00, 0xC0, 0x30, 0x0C, 0x30, 0xC0, 0x00, 0x06,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x06,

    // Character: 0x0411
    0x00, 0xFC, 0x44, 0x44, 0x44, 0x84, 0x00, 0x00,
    0x07, 0x04, 0x04, 0x04, 0x03, 0x00,

    // Character: 0x0412
    0x00, 0xFC, 0x44, 0x44, 0x44, 0xB8, 0x00, 0x00,
    0x07, 0x04, 0x04, 0x04, 0x03, 0x00,

    // Character: 0x0413
    0x00, 0xFC, 0x04, 0x04, 0x04, 0x04, 0x00, 0x07,
    0x00, 0x00, 0x00, 0x00,

    // Character: 0x0414
    0x00, 0x00, 0x00, 0xFC, 0x04, 0x04, 0x04, 0xFC,
    0x00, 0x00, 0x0C, 0x06, 0x05, 0x04, 0x04, 0x04,
    0x07, 0x0C,

    // Character: 0x0415
    0x00, 0xFC, 0x44, 0x44, 0x44, 0x04, 0x00, 0x00,
    0x07, 0x04, 0x04, 0x04, 0x04, 0x00,

    // Character: 0x0416
    0x00, 0x04, 0x08, 0x90, 0x60, 0xFC, 0x60, 0x90,
    0x08, 0x04, 0x00, 0x04, 0x02, 0x01, 0x00, 0x00,
    0x07, 0x00, 0x00, 0x01, 0x02, 0x04,

    // Character: 0x0417
    0x00, 0x00, 0x08, 0x04, 0x44, 0x44, 0xB8, 0x00,
    0x02, 0x04, 0x04, 0x04, 0x04, 0x03,

    // Character: 0x0418
    0x00, 0xFC, 0x00, 0x80, 0x60, 0x18, 0xFC, 0x00,
    0x00, 0x07, 0x03, 0x00, 0x00, 0x00, 0x07, 0x00,

    // Character: 0x0419
    0x00, 0xFC, 0x01, 0x82, 0x62, 0x19, 0xFC, 0x00,
    0x00, 0x07, 0x03, 0x00, 0x00, 0x00, 0x07, 0x00,

    // Character: 0x041A
    0x00, 0xFC, 0x60, 0x90, 0x08, 0x04, 0x00, 0x00,
    0x07, 0x00, 0x00, 0x01, 0x02, 0x04,

    // Character: 0x041B
    0x00, 0x00, 0xF8, 0x04, 0x04, 0x04, 0xFC, 0x00,
    0x00, 0x04, 0x03, 0x00, 0x00, 0x00, 0x07, 0x00,

    // Character: 0x041C
    0x00, 0xFC, 0x30, 0xC0, 0x00, 0xC0, 0x30, 0xFC,
    0x00, 0x00, 0x07, 0x00, 0x00, 0x03, 0x00, 0x00,
    0x07, 0x00,

    // Character: 0x041D
    0x00, 0xFC, 0x40, 0x40, 0x40, 0x40, 0xFC, 0x00,
    0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00,

    // Character: 0x041E
    0x00, 0xF8, 0x04, 0x04, 0x04, 0x04, 0xF8, 0x00,
    0x00, 0x03, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00,

    // Character: 0x041F
    0x00, 0xFC, 0x04, 0x04, 0x04, 0x04, 0xFC, 0x00,
    0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00,

    // Character: 0x0420
    0x00, 0xFC, 0x44, 0x44, 0x44, 0x44, 0x38, 0x00,
    0x07, 0x00, 0x00, 0x00, 0x00, 0x00,

    // Character: 0x0421
    0x00, 0xF8, 0x04, 0x04, 0x04, 0x04, 0x08, 0x00,
    0x03, 0x04, 0x04, 0x04, 0x04, 0x02,

    // Character: 0x0422
    0x00, 0x04, 0x04, 0xFC, 0x04, 0x04, 0x00, 0x00,
    0x00, 0x00, 0x07, 0x00, 0x00, 0x00,

    // Character: 0x0423
    0x00, 0x7C, 0x80, 0x80, 0x80, 0x80, 0xFC, 0x00,
    0x00, 0x02, 0x04, 0x04, 0x04, 0x04, 0x03, 0x00,

    // Character: 0x0424
    0x00, 0x70, 0x88, 0x88, 0x88, 0xFC, 0x88, 0x88,
    0x88, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x07, 0x00, 0x00, 0x00, 0x00, 0x00,

    // Character: 0x0425
    0x0C, 0x10, 0xA0, 0x40, 0xA0, 0x10, 0x0C, 0x06,
    0x01, 0x00, 0x00, 0x00, 0x01, 0x06,

    // Character: 0x0426
    0x00, 0xFC, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00,
    0x00, 0x07, 0x04, 0x04, 0x04, 0x07, 0x0C, 0x00,

    // Character: 0x0427
    0x00, 0x7C, 0x80, 0x80, 0x80, 0x80, 0xFC, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00,

    // Character: 0x0428
    0x00, 0xFC, 0x00, 0x00, 0xFC, 0x00, 0x00, 0xFC,
    0x00, 0x00, 0x07, 0x04, 0x04, 0x07, 0x04, 0x04,
    0x07, 0x00,

    // Character: 0x0429
    0x00, 0xFC, 0x00, 0x00, 0xFC, 0x00, 0x00, 0xFC,
    0x00, 0x00, 0x00, 0x07, 0x04, 0x04, 0x07, 0x04,
    0x04, 0x07, 0x0C, 0x00,

    // Character: 0x042A
    0x0C, 0x04, 0xFC, 0x40, 0x40, 0x40, 0x40, 0x80,
    0x00, 0x00, 0x07, 0x04, 0x04, 0x04, 0x04, 0x03,

    // Character: 0x042B
    0x00, 0xFC, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00,
    0xFC, 0x00, 0x00, 0x07, 0x04, 0x04, 0x04, 0x04,
    0x03, 0x00, 0x07, 0x00,

    // Character: 0x042C
    0x00, 0xFC, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00,
    0x07, 0x04, 0x04, 0x04, 0x04, 0x03,

    // Character: 0x042D
    0x08, 0x04, 0x44, 0x44, 0x44, 0xF8, 0x00, 0x02,
    0x04, 0x04, 0x04, 0x04, 0x03, 0x00,

    // Character: 0x042E
    0x00, 0xFC, 0x40, 0xF8, 0x04, 0x04, 0x04, 0xF8,
    0x00, 0x00, 0x07, 0x00, 0x03, 0x04, 0x04, 0x04,
    0x03, 0x00,

    // Character: 0x042F
    0x00, 0x38, 0xC4, 0x44, 0x44, 0x44, 0xFC, 0x00,
    0x00, 0x06, 0x01, 0x00, 0x00, 0x00, 0x07, 0x00,

    // Character: 0x0430
    0x00, 0x00, 0xA0, 0xA0, 0xA0, 0xC0, 0x00, 0x03,
    0x04, 0x04, 0x04, 0x07,

    // Character: 0x0431
    0x00, 0xE0, 0x30, 0x28, 0x28, 0xC4, 0x00, 0x03,
    0x04, 0x04, 0x04, 0x03,

    // Character: 0x0432
    0x00, 0xE0, 0xA0, 0xA0, 0xA0, 0x40, 0x00, 0x07,
    0x04, 0x04, 0x04, 0x03,

    // Character: 0x0433
    0x00, 0xE0, 0x20, 0x20, 0x20, 0x00, 0x07, 0x00,
    0x00, 0x00,

    // Character: 0x0434
    0x00, 0xC0, 0x20, 0x20, 0xE0, 0x00, 0x0C, 0x07,
    0x04, 0x04, 0x07, 0x0C,

    // Character: 0x0435
    0x00, 0xC0, 0xA0, 0xA0, 0xA0, 0xC0, 0x00, 0x03,
    0x04, 0x04, 0x04, 0x02,

    // Character: 0x0436
    0x00, 0x20, 0x40, 0x80, 0xE0, 0x80, 0x40, 0x20,
    0x00, 0x04, 0x03, 0x00, 0x07, 0x00, 0x03, 0x04,

    // Character: 0x0437
    0x00, 0x40, 0x20, 0xA0, 0xA0, 0x40, 0x00, 0x02,
    0x04, 0x04, 0x04, 0x03,

    // Character: 0x0438
    0x00, 0xE0, 0x00, 0x00, 0x80, 0xE0, 0x00, 0x07,
    0x02, 0x01, 0x00, 0x07,

    // Character: 0x0439
    0x00, 0xE0, 0x08, 0x10, 0x88, 0xE0, 0x00, 0x07,
    0x02, 0x01, 0x00, 0x07,

    // Character: 0x043A
    0x00, 0xE0, 0x80, 0x40, 0x20, 0x00, 0x00, 0x07,
    0x00, 0x01, 0x02, 0x04,

    // Character: 0x043B
    0x00, 0x00, 0xC0, 0x20, 0x20, 0xE0, 0x00, 0x04,
    0x03, 0x00, 0x00, 0x07,

    // Character: 0x043C
    0x00, 0xE0, 0x40, 0x80, 0x00, 0x80, 0x40, 0xE0,
    0x00, 0x07, 0x00, 0x00, 0x03, 0x00, 0x00, 0x07,

    // Character: 0x043D
    0x00, 0xE0, 0x80, 0x80, 0x80, 0xE0, 0x00, 0x07,
    0x00, 0x00, 0x00, 0x07,

    // Character: 0x043E
    0x00, 0xC0, 0x20, 0x20, 0x20, 0xC0, 0x00, 0x03,
    0x04, 0x04, 0x04, 0x03,

    // Character: 0x043F
    0x00, 0xE0, 0x20, 0x20, 0x20, 0xE0, 0x00, 0x07,
    0x00, 0x00, 0x00, 0x07,

    // Character: 0x0440
    0x00, 0xE0, 0x20, 0x20, 0x20, 0xC0, 0x00, 0x1F,
    0x04, 0x04, 0x04, 0x03,

    // Character: 0x0441
    0x00, 0xC0, 0x20, 0x20, 0x20, 0x40, 0x00, 0x03,
    0x04, 0x04, 0x04, 0x02,

    // Character: 0x0442
    0x20, 0x20, 0xE0, 0x20, 0x20, 0x00, 0x00, 0x07,
    0x00, 0x00,

    // Character: 0x0443
    0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0x11, 0x12,
    0x12, 0x0F,

    // Character: 0x0444
    0x00, 0xC0, 0x20, 0x20, 0xF0, 0x20, 0x20, 0xC0,
    0x00, 0x01, 0x02, 0x02, 0x0F, 0x02, 0x02, 0x01,

    // Character: 0x0445
    0x00, 0x60, 0x80, 0x80, 0x60, 0x00, 0x06, 0x01,
    0x01, 0x06,

    // Character: 0x0446
    0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x07,
    0x04, 0x04, 0x07, 0x0C,

    // Character: 0x0447
    0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x01,
    0x01, 0x07,

    // Character: 0x0448
    0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0x00, 0xE0,
    0x00, 0x07, 0x04, 0x04, 0x07, 0x04, 0x04, 0x07,

    // Character: 0x0449
    0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0x00, 0xE0,
    0x00, 0x00, 0x07, 0x04, 0x04, 0x07, 0x04, 0x04,
    0x07, 0x08,

    // Character: 0x044A
    0x60, 0x20, 0xE0, 0x80, 0x80, 0x80, 0x00, 0x00,
    0x00, 0x07, 0x04, 0x04, 0x04, 0x03,

    // Character: 0x044B
    0x00, 0xE0, 0x80, 0x80, 0x80, 0x00, 0x00, 0xE0,
    0x00, 0x07, 0x04, 0x04, 0x04, 0x03, 0x00, 0x07,

    // Character: 0x044C
    0x00, 0xE0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x07,
    0x04, 0x04, 0x04, 0x03,

    // Character: 0x044D
    0x40, 0x20, 0xA0, 0xA0, 0xC0, 0x00, 0x02, 0x04,
    0x04, 0x04, 0x03, 0x00,

    // Character: 0x044E
    0x00, 0xE0, 0x80, 0xC0, 0x20, 0x20, 0x20, 0xC0,
    0x00, 0x07, 0x00, 0x03, 0x04, 0x04, 0x04, 0x03,

    // Character: 0x044F
    0x00, 0xC0, 0x20, 0x20, 0x20, 0xE0, 0x00, 0x04,
    0x03, 0x01, 0x01, 0x07,

    // Character: 0x0451
    0x00, 0xC0, 0xA8, 0xA0, 0xA8, 0xC0, 0x00, 0x03,
    0x04, 0x04, 0x04, 0x02,

    // Character: 0x0452
    0x08, 0xFC, 0x48, 0x28, 0x20, 0xC0, 0x00, 0x07,
    0x00, 0x10, 0x10, 0x0F,

    // Character: 0x0453
    0x00, 0xE0, 0x20, 0x28, 0x24, 0x00, 0x07, 0x00,
    0x00, 0x00,

    // Character: 0x0454
    0x00, 0xC0, 0xA0, 0xA0, 0x20, 0x40, 0x00, 0x03,
    0x04, 0x04, 0x04, 0x02,

    // Character: 0x0455
    0x00, 0x40, 0xA0, 0x20, 0x40, 0x00, 0x02, 0x04,
    0x05, 0x02,

    // Character: 0x0456
    0x00, 0xE4, 0x00, 0x07,

    // Character: 0x0457
    0x04, 0xE0, 0x04, 0x00, 0x07, 0x00,

    // Character: 0x0458
    0x00, 0xE4, 0x00, 0x1F,

    // Character: 0x0459
    0x00, 0x00, 0xC0, 0x20, 0x20, 0xE0, 0x80, 0x80,
    0x80, 0x00, 0x00, 0x04, 0x03, 0x00, 0x00, 0x07,
    0x04, 0x04, 0x04, 0x03,

    // Character: 0x045A
    0x00, 0xE0, 0x80, 0x80, 0x80, 0xE0, 0x80, 0x80,
    0x80, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07,
    0x04, 0x04, 0x04, 0x03,

    // Character: 0x045B
    0x08, 0xFC, 0x48, 0x28, 0x28, 0xC0, 0x00, 0x07,
    0x00, 0x00, 0x00, 0x07,

    // Character: 0x045C
    0x00, 0xE0, 0x80, 0x48, 0x24, 0x00, 0x00, 0x07,
    0x00, 0x01, 0x02, 0x04,

    // Character: 0x045E
    0x00, 0xE4, 0x08, 0x08, 0xE4, 0x00, 0x11, 0x12,
    0x12, 0x0F,

    // Character: 0x045F
    0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x07,
    0x04, 0x1C, 0x04, 0x07,

    // Character: 0x0490
    0x00, 0xFC, 0x04, 0x04, 0x04, 0x06, 0x00, 0x07,
    0x00, 0x00, 0x00, 0x00,

    // Character: 0x0491
    0x00, 0xE0, 0x20, 0x20, 0x30, 0x00, 0x07, 0x00,
    0x00, 0x00,

    // Character: 0x2013
    0x00, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00,

    // Character: 0x2014
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,

    // Character: 0x2018
    0x08, 0x10, 0x00, 0x00, 0x00, 0x00,

    // Character: 0x2019
    0x00, 0x10, 0x08, 0x00, 0x00, 0x00,

    // Character: 0x201A
    0x00, 0x00, 0x00, 0x00, 0x08, 0x04,

    // Character: 0x201C
    0x04, 0x08, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00,

    // Character: 0x201D
    0x08, 0x04, 0x08, 0x04, 0x00, 0x00, 0x00, 0x00,

    // Character: 0x201E
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x04,
    0x08, 0x04,

    // Character: 0x2020
    0x20, 0x20, 0xF8, 0x20, 0x20, 0x00, 0x00, 0x07,
    0x00, 0x00,

    // Character: 0x2021
    0x20, 0x20, 0xF8, 0x20, 0x20, 0x02, 0x02, 0x07,
    0x02, 0x02,

    // Character: 0x2022
    0x00, 0x40, 0xE0, 0xE0, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,

    // Character: 0x2026
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
    0x00, 0x04, 0x00, 0x04,

    // Character: 0x2030
    0x08, 0x14, 0x94, 0x48, 0x20, 0x10, 0x08, 0x04,
    0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0x02, 0x05,
    0x05, 0x02, 0x02, 0x05, 0x05, 0x02,

    // Character: 0x2039
    0x00, 0x00, 0x80, 0x40, 0x00, 0x00, 0x00, 0x01,
    0x02, 0x04, 0x00, 0x00,

    // Character: 0x203A
    0x00, 0x00, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x04, 0x02, 0x01, 0x00,

    // Character: 0x20AC
    0xA0, 0xF8, 0xA4, 0x24, 0x04, 0x18, 0x00, 0x03,
    0x04, 0x04, 0x04, 0x03,

    // Character: 0x2116
    0x00, 0xFC, 0x18, 0x60, 0x80, 0x00, 0xFC, 0x00,
    0x90, 0xA8, 0x90, 0x00, 0x07, 0x00, 0x00, 0x00,
    0x03, 0x07, 0x00, 0x00, 0x00, 0x00,

    // Character: 0x2122
    0x04, 0x1C, 0x04, 0x00, 0x1C, 0x04, 0x08, 0x04,
    0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00
};
#pragma bank 255

// Avatar Font

#include "gbs_types.h"

static const UBYTE font_avatars_table[] = {
    0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07
};

static const UBYTE font_avatars_bitmaps[] = {
    0x00,0x40,0x40,0xE0,0x60,0xFB,0x5B,0xFF,0x7F,0xFF,0x3F,0xEE,0x7F,0xEE,0x7B,0xFF,
    0x3F,0x7F,0x0E,0x3F,0x1F,0x3F,0x1F,0x3F,0x1F,0x3F,0x3F,0x7F,0x3F,0x7F,0x37,0x7F,
    0x00,0x40,0x40,0xE0,0xC0,0xE0,0x40,0xE0,0xC0,0xE0,0x80,0xE6,0xC6,0xEF,0xCF,0xFF,
    0x99,0xFF,0x10,0xB9,0x18,0xBC,0x8C,0xFE,0xC4,0xEE,0xEC,0xFE,0xF8,0xFC,0xF0,0xF8,
    0x00,0x00,0x1C,0x1C,0x37,0x2F,0x28,0x3F,0x3B,0x3E,0x30,0x3F,0x13,0x1F,0x1F,0x11,
    0x0E,0x09,0x0F,0x0F,0x1F,0x18,0x17,0x1C,0x17,0x1C,0x17,0x1C,0x3F,0x22,0x3F,0x3F,
    0x00,0x00,0x70,0x70,0xD8,0xE8,0x28,0xF8,0xB8,0xF8,0x18,0xF8,0x90,0xF0,0xF0,0x10,
    0xE0,0x20,0xE2,0xE2,0xF6,0x36,0xDE,0x7A,0xDC,0x74,0xD8,0x78,0xF8,0x88,0xF8,0xF8
};

const void __at(255) __bank_vwf_font_avatars;
const font_desc_t vwf_font_avatars = {
    FONT_RECODE, 
    0x07,
    font_avatars_table,
    NULL,
    font_avatars_bitmaps
};
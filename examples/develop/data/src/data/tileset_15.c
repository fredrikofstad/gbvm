#pragma bank 255

// Tileset: 15

#include "gbs_types.h"

const void __at(255) __bank_tileset_15;

const struct tileset_t tileset_15 = {
    .n_tiles = 4,
    .tiles = {
        0x80, 0x80, 0xC0, 0x40, 0xA0, 0x60, 0x90, 0x70, 0x98, 0x68, 0xE8, 0x18, 0x90, 0x70, 0x90, 0x70,
        0xA0, 0x60, 0xA0, 0x60, 0xC0, 0x40, 0xC0, 0x40, 0x80, 0x80, 0x80, 0xC0, 0x00, 0xF0, 0x00, 0xC0,
        0x00, 0x00, 0x80, 0x80, 0xC0, 0x40, 0xA0, 0x60, 0x90, 0x70, 0x98, 0x68, 0xE8, 0x18, 0x90, 0x70,
        0x90, 0x70, 0xA0, 0x60, 0xA0, 0x60, 0xC0, 0x40, 0xC0, 0x40, 0x80, 0xC0, 0x80, 0xF0, 0x00, 0xC0
    }
};

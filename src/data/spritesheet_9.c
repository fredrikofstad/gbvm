#pragma bank 255

// SpriteSheet: npc003

#include "gbs_types.h"

const void __at(255) __bank_spritesheet_9;

const metasprite_t spritesheet_9_metasprite_0  = {
    .count = 2,
    .items = {{0, 0, 0, 0}, {0, 8, 2, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_9_metasprite_1  = {
    .count = 2,
    .items = {{0, 0, 4, 0}, {0, 8, 6, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_9_metasprite_2  = {
    .count = 2,
    .items = {{0, 0, 8,  0}, {0, 8, 10, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_9_metasprite_3  = {
    .count = 2,
    .items = {{0, 0, 12, 0}, {0, 8, 14, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_9_metasprite_4  = {
    .count = 2,
    .items = {{0, 0, 16, 0}, {0, 8, 18, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_9_metasprite_5  = {
    .count = 2,
    .items = {{0, 0, 20, 0}, {0, 8, 22, 0}, {metasprite_end}}
};

const metasprite_t spritesheet_9_metasprite_6  = {
    .count = 2,
    .items = {{0, 0, 18, 32}, {0, 8, 16, 32}, {metasprite_end}}
};

const metasprite_t spritesheet_9_metasprite_7  = {
    .count = 2,
    .items = {{0, 0, 22, 32}, {0, 8, 20, 32}, {metasprite_end}}
};

const metasprite_t * const spritesheet_9_metasprites[] = {
    &spritesheet_9_metasprite_0,
    &spritesheet_9_metasprite_1,
    &spritesheet_9_metasprite_2,
    &spritesheet_9_metasprite_3,
    &spritesheet_9_metasprite_4,
    &spritesheet_9_metasprite_5,
    &spritesheet_9_metasprite_6,
    &spritesheet_9_metasprite_7
};

const struct spritesheet_t spritesheet_9 = {
  .n_tiles = 24,
  .n_metasprites = 6,
  .metasprites = spritesheet_9_metasprites,  
  .tiles = {
    7,7,24,31,48,47,109,83,82,111,77,126,83,124,91,118,95,114,127,88,207,188,159,255,127,127,57,63,29,27,14,14,
    224,224,24,248,52,204,91,167,169,215,70,254,186,126,218,110,250,78,251,29,241,63,254,254,60,228,252,228,248,
    248,112,112,7,7,24,31,48,47,109,83,82,111,77,126,83,124,91,118,95,114,255,216,207,188,95,127,60,39,63,39,31,
    31,14,14,224,224,24,248,52,204,90,166,170,214,65,255,191,127,218,110,250,78,251,29,243,61,249,255,254,254,156,
    252,184,216,112,112,7,7,24,31,40,55,70,121,193,254,64,127,64,127,64,127,75,116,219,182,219,182,183,234,126,
    125,63,39,31,31,0,0,224,224,24,248,20,236,98,158,130,126,2,254,2,254,6,250,38,218,38,218,51,221,177,223,158,
    254,252,252,176,208,112,112,7,7,24,31,40,55,70,121,65,126,192,255,64,127,64,127,75,116,201,182,219,182,154,
    247,114,127,63,63,13,11,14,14,224,224,24,248,20,236,98,158,130,126,2,254,2,254,6,250,38,218,38,218,111,185,
    237,187,158,254,252,228,248,248,0,0,7,7,24,31,34,61,108,83,84,111,72,127,73,126,95,127,70,125,103,92,115,
    79,212,191,121,127,31,19,15,15,6,6,240,240,12,252,26,230,7,249,177,95,233,63,215,239,29,245,252,20,254,2,124,
    132,248,248,48,208,248,232,92,100,56,56,7,7,24,31,34,61,108,83,84,111,72,127,81,126,79,127,70,125,103,92,115,
    79,212,191,126,127,55,63,23,25,14,14,240,240,12,252,26,230,7,249,177,95,233,63,214,238,30,246,252,20,254,2,
    124,132,248,248,80,240,252,60,252,252,48,48
  }
};

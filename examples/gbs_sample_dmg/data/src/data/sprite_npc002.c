#pragma bank 255
// SpriteSheet: npc002
  
#include "gbs_types.h"
#include "data/tileset_npc002.h"

BANKREF(sprite_npc002)

#define SPRITE_12_STATE_DEFAULT 0

const metasprite_t sprite_npc002_metasprite_0[]  = {
    { 0, 8, 8, 0 }, { 0, -8, 10, 0 },
    {metasprite_end}
};

const metasprite_t sprite_npc002_metasprite_1[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t sprite_npc002_metasprite_2[]  = {
    { 0, 8, 4, 0 }, { 0, -8, 6, 0 },
    {metasprite_end}
};

const metasprite_t sprite_npc002_metasprite_3[]  = {
    { 0, 0, 0, 32 }, { 0, 8, 2, 32 },
    {metasprite_end}
};

const metasprite_t * const sprite_npc002_metasprites[] = {
    sprite_npc002_metasprite_0,
    sprite_npc002_metasprite_1,
    sprite_npc002_metasprite_2,
    sprite_npc002_metasprite_3
};

const struct animation_t sprite_npc002_animations[] = {
    {
        .start = 0,
        .end = 0
    },
    {
        .start = 1,
        .end = 1
    },
    {
        .start = 2,
        .end = 2
    },
    {
        .start = 3,
        .end = 3
    },
    {
        .start = 0,
        .end = 0
    },
    {
        .start = 1,
        .end = 1
    },
    {
        .start = 2,
        .end = 2
    },
    {
        .start = 3,
        .end = 3
    }
};

const UWORD sprite_npc002_animations_lookup[] = {
    SPRITE_12_STATE_DEFAULT
};

const struct spritesheet_t sprite_npc002 = {
    .n_metasprites = 4,
    .emote_origin = {
        .x = 0,
        .y = -16
    },
    .metasprites = sprite_npc002_metasprites,
    .animations = sprite_npc002_animations,
    .animations_lookup = sprite_npc002_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_npc002),
    .cgb_tileset = { NULL, NULL }
};

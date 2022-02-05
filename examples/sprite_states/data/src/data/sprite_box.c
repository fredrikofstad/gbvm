#pragma bank 255
// SpriteSheet: box
  
#include "gbs_types.h"
#include "data/tileset_box.h"

BANKREF(sprite_box)

#define SPRITE_1_STATE_DEFAULT 0
#define SPRITE_1_STATE_IN_GRASS 0
#define SPRITE_1_STATE_SURPRISED 0

const metasprite_t sprite_box_metasprite_0[]  = {
    { 0, 8, 0, 0 }, { 0, -8, 2, 0 },
    {metasprite_end}
};

const metasprite_t * const sprite_box_metasprites[] = {
    sprite_box_metasprite_0
};

const struct animation_t sprite_box_animations[] = {
    {
        .start = 0,
        .end = 0
    },
    {
        .start = 0,
        .end = 0
    },
    {
        .start = 0,
        .end = 0
    },
    {
        .start = 0,
        .end = 0
    },
    {
        .start = 0,
        .end = 0
    },
    {
        .start = 0,
        .end = 0
    },
    {
        .start = 0,
        .end = 0
    },
    {
        .start = 0,
        .end = 0
    }
};

const UWORD sprite_box_animations_lookup[] = {
    SPRITE_1_STATE_DEFAULT
};

const struct spritesheet_t sprite_box = {
    .n_metasprites = 1,
    .emote_origin = {
        .x = 0,
        .y = -16
    },
    .metasprites = sprite_box_metasprites,
    .animations = sprite_box_animations,
    .animations_lookup = sprite_box_animations_lookup,
    .bounds = {
        .left = 0,
        .bottom = 7,
        .right = 15,
        .top = -8
    },
    .tileset = TO_FAR_PTR_T(tileset_box),
    .cgb_tileset = { NULL, NULL }
};

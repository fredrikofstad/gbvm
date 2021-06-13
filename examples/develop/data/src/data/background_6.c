#pragma bank 255

// Background: parallax

#include "gbs_types.h"
#include "data/tileset_5.h"
#include "data/tilemap_6.h"
#include "data/tilemap_attr_6.h"

const void __at(255) __bank_background_6;

const struct background_t background_6 = {
    .width = 80,
    .height = 18,
    .tileset = TO_FAR_PTR_T(tileset_5),
    .cgb_tileset = { NULL, NULL },
    .tilemap = TO_FAR_PTR_T(tilemap_6),
    .cgb_tilemap_attr = TO_FAR_PTR_T(tilemap_attr_6)
};

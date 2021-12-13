#pragma bank 255

// Scene: RTC

#include "gbs_types.h"
#include "data/background_1.h"
#include "data/scene_1_collisions.h"
#include "data/palette_0.h"
#include "data/palette_1.h"
#include "data/spritesheet_5.h"
#include "data/scene_1_actors.h"
#include "data/scene_1_sprites.h"
#include "data/script_s1_init.h"

BANKREF(scene_1)

const struct scene_t scene_1 = {
    .width = 20,
    .height = 18,
    .type = SCENE_TYPE_TOPDOWN,
    .background = TO_FAR_PTR_T(background_1),
    .collisions = TO_FAR_PTR_T(scene_1_collisions),
    .parallax_rows = {
        PARALLAX_STEP(0,0,0)
    },
    .palette = TO_FAR_PTR_T(palette_0),
    .sprite_palette = TO_FAR_PTR_T(palette_1),
    .player_sprite = TO_FAR_PTR_T(spritesheet_5),
    .n_actors = 1,
    .n_triggers = 0,
    .n_sprites = 1,
    .n_projectiles = 0,
    .actors = TO_FAR_PTR_T(scene_1_actors),
    .sprites = TO_FAR_PTR_T(scene_1_sprites),
    .script_init = TO_FAR_PTR_T(script_s1_init)
};

#pragma bank 255

// Scene: Scene 3
// Actors

#include "gbs_types.h"
#include "data/spritesheet_9.h"
#include "data/script_s2a0_interact.h"
#include "data/script_s2a0_update.h"

const void __at(255) __bank_scene_2_actors;

const struct actor_t scene_2_actors[] = {
  {
    // Actor 1,
    .x = 168 * 16,
    .y = 104 * 16,
    .dir_x = 0,
    .dir_y = 1,
    .bounds = {
      .left = 0,
      .right = 16,
      .top = -16,
      .bottom = 0
    },
    .sprite = TO_FAR_PTR_T(spritesheet_9),
    .sprite_type = SPRITE_TYPE_ACTOR,
    .base_tile = 24,
    .palette = 0,
    .n_frames = 2,
    .animate = FALSE,
    .move_speed = 8,
    .anim_tick = 7,
    .frame = 0,
    .frame_start = 0,
    .frame_end = 2,
    .pinned = FALSE,
    .collision_group = COLLISION_GROUP_1,
    .collision_enabled = TRUE,
    .script = TO_FAR_PTR_T(script_s2a0_interact),
    .script_update = TO_FAR_PTR_T(script_s2a0_update)
  }
};

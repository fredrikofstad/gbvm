#pragma bank 255

// Scene: Cave
// Actors

#include "data/gbs_types.h"
#include "data/script_s0a2_interact.h"

const void __at(255) __bank_scene_0_actors;

const struct actor_t scene_0_actors[] = {
  {
    // Actor 1,
    .x = 32,
    .y = 48,
    .dir_x = 0,
    .dir_y = 1,
    .sprite_no = 0,
    .sprite = 6,
    .sprite_type = 0,
    .palette = 1,
    .n_frames = 1,
    .initial_frame = 0,
    .animate = FALSE,
    .move_speed = 1,
    .anim_tick = 7,
    .frame = 24,
    .frame_start = 24,
    .frame_end = 28,
    .pinned = FALSE,
    .collision_group = 0
  },
  {
    // Fire,
    .x = 32,
    .y = 32,
    .dir_x = 0,
    .dir_y = 1,
    .sprite_no = 0,
    .sprite = 7,
    .sprite_type = 0,
    .palette = 0,
    .n_frames = 4,
    .initial_frame = 0,
    .animate = TRUE,
    .move_speed = 1,
    .anim_tick = 7,
    .frame = 28,
    .frame_start = 28,
    .frame_end = 44,
    .pinned = FALSE,
    .collision_group = 0
  },
  {
    // Sage,
    .x = 72,
    .y = 56,
    .dir_x = 0,
    .dir_y = 1,
    .sprite_no = 0,
    .sprite = 11,
    .sprite_type = 0,
    .palette = 1,
    .n_frames = 1,
    .initial_frame = 0,
    .animate = FALSE,
    .move_speed = 1,
    .anim_tick = 7,
    .frame = 44,
    .frame_start = 44,
    .frame_end = 48,
    .pinned = FALSE,
    .collision_group = 0,
    .script = TO_FAR_PTR_T(script_s0a2_interact)
  },
  {
    // Actor 4,
    .x = 112,
    .y = 48,
    .dir_x = 0,
    .dir_y = 1,
    .sprite_no = 0,
    .sprite = 6,
    .sprite_type = 0,
    .palette = 1,
    .n_frames = 1,
    .initial_frame = 0,
    .animate = FALSE,
    .move_speed = 1,
    .anim_tick = 7,
    .frame = 24,
    .frame_start = 24,
    .frame_end = 28,
    .pinned = FALSE,
    .collision_group = 0
  },
  {
    // Fire,
    .x = 112,
    .y = 32,
    .dir_x = 0,
    .dir_y = 1,
    .sprite_no = 0,
    .sprite = 7,
    .sprite_type = 0,
    .palette = 0,
    .n_frames = 4,
    .initial_frame = 2,
    .animate = TRUE,
    .move_speed = 1,
    .anim_tick = 7,
    .frame = 28,
    .frame_start = 28,
    .frame_end = 44,
    .pinned = FALSE,
    .collision_group = 0
  }
};

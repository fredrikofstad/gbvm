#pragma bank 255

// Scene: Scene 1
// Sprites

#include "gbs_types.h"
#include "data/spritesheet_2.h"
#include "data/spritesheet_3.h"
#include "data/spritesheet_4.h"

BANKREF(scene_0_sprites)

const far_ptr_t scene_0_sprites[] = {
    TO_FAR_PTR_T(spritesheet_2),
    TO_FAR_PTR_T(spritesheet_3),
    TO_FAR_PTR_T(spritesheet_4)
};

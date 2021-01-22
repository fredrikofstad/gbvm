#ifndef _SHADOW_H_INCLUDE
#define _SHADOW_H_INCLUDE

#include "Actor.h"

inline void toggle_shadow_OAM() {
    if (_shadow_OAM_base == (UBYTE)((UWORD)&shadow_OAM >> 8)) { 
        __render_shadow_OAM = (UBYTE)((UWORD)&shadow_OAM2 >> 8); 
    } else { 
        __render_shadow_OAM = (UBYTE)((UWORD)&shadow_OAM >> 8);
    }
    allocated_hardware_sprites = 0;
}
inline void activate_shadow_OAM() {
    hide_hardware_sprites(allocated_hardware_sprites, 40);
    _shadow_OAM_base = __render_shadow_OAM;
}

#endif
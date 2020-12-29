#ifndef _VM_MUSIC_H_INCLUDE
#define _VM_MUSIC_H_INCLUDE

#include "vm.h"

void vm_music_play(SCRIPT_CTX * THIS, UBYTE track, UBYTE loop) __banked;
void vm_music_stop() __banked;
void vm_music_mute(SCRIPT_CTX * THIS, UBYTE channels) __banked;

void vm_sound_mastervol(SCRIPT_CTX * THIS, UBYTE volume) __banked;
void vm_sound_play(SCRIPT_CTX * THIS, UBYTE frames, UBYTE channel, ...) __banked;

#endif
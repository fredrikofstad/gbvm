.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255

___bank_script_s4_init = 255
.globl ___bank_script_s4_init
.globl ___bank_script_s4_timer1, _script_s4_timer1 

_script_s4_init::
        VM_LOCK

        ; Fade in
        VM_FADE_IN              .UI_MODAL

        VM_TIMER_PREPARE        1, ___bank_script_s4_timer1, _script_s4_timer1
        VM_TIMER_SET            1, 2

        ; Stop Script
        VM_STOP

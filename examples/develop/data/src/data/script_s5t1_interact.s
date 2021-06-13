.include "vm.i"
.include "data/game_globals.i"
.include "macro.i"

.globl ___bank_scene_8, _scene_8

.area _CODE_255

ACTOR = -4

___bank_script_s5t1_interact = 255
.globl ___bank_script_s5t1_interact

_script_s5t1_interact::
        VM_LOCK

        ; Local Actor
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0
        VM_PUSH_CONST           0

        ; Actor Set Active
        VM_SET_CONST            ACTOR, 0

        ; Actor Move To
        VM_SET_CONST            ^/(ACTOR + 1)/, 20352
        VM_SET_CONST            ^/(ACTOR + 2)/, 1664
        VM_SET_CONST            ^/(ACTOR + 3)/, ^/(.ACTOR_ATTR_H_FIRST)/
        VM_ACTOR_MOVE_TO        ACTOR

        ; Load Scene
        VM_FADE_OUT             4
        VM_SET_CONST            ACTOR, 0
        VM_SET_CONST            ^/(ACTOR + 1)/, 256
        VM_SET_CONST            ^/(ACTOR + 2)/, 1664
        VM_ACTOR_SET_POS        ACTOR
        VM_ACTOR_SET_DIR        ACTOR, .DIR_RIGHT
        VM_RAISE                EXCEPTION_CHANGE_SCENE, 3
            IMPORT_FAR_PTR_DATA _scene_8

        ; Stop Script
        VM_STOP

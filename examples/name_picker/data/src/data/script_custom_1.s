.include "vm.i"
.include "data/game_globals.i"

.area _CODE_255



___bank_script_custom_1 = 255
.globl ___bank_script_custom_1

_script_custom_1::
        VM_REPLACE_TILE_XY      7, 12, ___bank_tileset_0, _tileset_0, VAR_STRING_0_
        VM_REPLACE_TILE_XY      8, 12, ___bank_tileset_0, _tileset_0, VAR_STRING_1_
        VM_REPLACE_TILE_XY      9, 12, ___bank_tileset_0, _tileset_0, VAR_STRING_2_
        VM_REPLACE_TILE_XY      10, 12, ___bank_tileset_0, _tileset_0, VAR_STRING_3_
        VM_REPLACE_TILE_XY      11, 12, ___bank_tileset_0, _tileset_0, VAR_STRING_4_
        

        VM_RET_FAR

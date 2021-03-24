#pragma bank 1

#include <string.h>

#include "ui.h"
#include "game_time.h"
#include "data/data_bootstrap.h"
#include "data/frame_image.h"
#include "data/cursor_image.h"
#include "bankdata.h"
#include "scroll.h"
#include "input.h"
#include "math.h"
#include "actor.h"
#include "projectiles.h"
#include "shadow.h"

#define ui_frame_tl_tiles 0xC0u
#define ui_frame_bl_tiles 0xC6u
#define ui_frame_tr_tiles 0xC2u
#define ui_frame_br_tiles 0xC8u
#define ui_frame_t_tiles  0xC1u
#define ui_frame_b_tiles  0xC7u
#define ui_frame_l_tiles  0xC3u
#define ui_frame_r_tiles  0xC5u
#define ui_frame_bg_tiles 0xC4u

const unsigned char avatar_tiles[4] = {TEXT_BUFFER_START, TEXT_BUFFER_START + 2U, TEXT_BUFFER_START + 1U, TEXT_BUFFER_START + 3U};

UBYTE win_pos_x, win_dest_pos_x;
UBYTE win_pos_y, win_dest_pos_y;
UBYTE win_speed;

UBYTE text_drawn;
UBYTE current_text_speed;
UBYTE text_wait;

UBYTE text_in_speed;
UBYTE text_out_speed;
UBYTE text_draw_speed;
UBYTE text_ff_joypad;
UBYTE text_ff; 
UBYTE text_bkg_fill;

unsigned char ui_text_data[TEXT_MAX_LENGTH];

// char printer internals
static UBYTE * ui_text_ptr;
static UBYTE * ui_dest_ptr;
static UBYTE * ui_dest_base;
static UBYTE ui_current_tile;
static UBYTE vwf_current_offset;
static UBYTE vwf_tile_data[16 * 2];
UBYTE vwf_current_mask;
UBYTE vwf_current_rotate;
UBYTE vwf_inverse_map;
UBYTE vwf_direction;

font_desc_t vwf_current_font_desc;
UBYTE vwf_current_font_bank;
UBYTE vwf_current_font_idx;

extern const UBYTE ui_time_masks[];

void ui_init() __banked {
    vwf_direction               = UI_PRINT_LEFTTORIGHT;
    vwf_current_font_idx        = 0;
    vwf_current_font_bank       = ui_fonts[0].bank;
    MemcpyBanked(&vwf_current_font_desc, ui_fonts[0].ptr, sizeof(font_desc_t), vwf_current_font_bank);

    text_in_speed               = 1;
    text_out_speed              = 1;
    text_draw_speed             = 1;
    text_ff_joypad              = 1;
    text_bkg_fill               = TEXT_BKG_FILL_W;

    ui_text_ptr                 = 0;
    ui_dest_ptr                 = 0;
    ui_dest_base                = 0;

    ui_set_pos(0, MENU_CLOSED_Y);

    win_speed                   = 1;
    text_drawn                  = TRUE;
    text_draw_speed             = 1;

    ui_load_tiles();
}

void ui_load_tiles() __banked {
    ui_load_frame_tiles(frame_image, BANK(frame_image));
    ui_load_cursor_tile(cursor_image, BANK(cursor_image));

    memset(vwf_tile_data, TEXT_BKG_FILL_W, 16);
    set_bkg_data(ui_while_tile, 1, vwf_tile_data);
    memset(vwf_tile_data, TEXT_BKG_FILL_B, 16);
    set_bkg_data(ui_black_tile, 1, vwf_tile_data);
}

void ui_draw_frame(UBYTE x, UBYTE y, UBYTE width, UBYTE height) __banked {
    set_win_tile_xy (x,               y,                                         ui_frame_tl_tiles);
    fill_win_rect   (x + 1u,          y,               width - 2u, 1u,           ui_frame_t_tiles );   // top
    set_win_tile_xy (x + width - 1u,  y,                                         ui_frame_tr_tiles);
    fill_win_rect   (x,               y + 1u,          1u,         height - 2u,  ui_frame_l_tiles );   // left
    fill_win_rect   (x + width - 1u,  y + 1u,          1u,         height - 2u,  ui_frame_r_tiles );   // right
    set_win_tile_xy (x,               y + height - 1u,                           ui_frame_bl_tiles);
    fill_win_rect   (x + 1u,          y + height - 1u, width - 2u, 1u,           ui_frame_b_tiles );   // bottom
    set_win_tile_xy (x + width - 1u,  y + height - 1u,                           ui_frame_br_tiles);
    fill_win_rect   (x + 1u,          y + 1u,          width - 2u, height - 2u,  ui_frame_bg_tiles);  // background
}

void ui_print_reset(UBYTE tile) {
    ui_current_tile = tile;
    vwf_current_offset = 0;
    memset(vwf_tile_data, text_bkg_fill, sizeof(vwf_tile_data));
}

void ui_print_shift_char(void * dest, const void * src, UBYTE bank) __nonbanked;
UWORD ui_print_make_mask_lr(UBYTE width, UBYTE ofs);
UWORD ui_print_make_mask_rl(UBYTE width, UBYTE ofs);

UBYTE ui_print_render(const unsigned char ch) {
    UBYTE letter = (vwf_current_font_desc.attr & FONT_RECODE) ? ReadBankedUBYTE(vwf_current_font_desc.recode_table + (ch & vwf_current_font_desc.mask), vwf_current_font_bank) : ch;
    const UBYTE * bitmap = vwf_current_font_desc.bitmaps + letter * 16u;
    if (vwf_current_font_desc.attr & FONT_VWF) {
        vwf_inverse_map = (vwf_current_font_desc.attr & FONT_VWF_1BIT) ? text_bkg_fill : 0u;
        UBYTE width = ReadBankedUBYTE(vwf_current_font_desc.widths + letter, vwf_current_font_bank);
        if (vwf_direction == UI_PRINT_LEFTTORIGHT) {
            vwf_current_rotate = vwf_current_offset;
            UWORD masks = ui_print_make_mask_lr(width, vwf_current_offset);
            vwf_current_mask = (UBYTE)masks;
            ui_print_shift_char(vwf_tile_data, bitmap, vwf_current_font_bank);

            if ((UBYTE)(vwf_current_offset + width) > 8u) {
                vwf_current_rotate = (8u - vwf_current_offset) | 0x80u;
                vwf_current_mask = (UBYTE)(masks >> 8u);
                ui_print_shift_char(vwf_tile_data + 16u, bitmap, vwf_current_font_bank);
            }
        } else {
            UBYTE dx = (8u - vwf_current_offset);      
            vwf_current_rotate =  (width < dx) ? (dx - width) : (width - dx) | 0x80u;
            UWORD masks = ui_print_make_mask_rl(width, vwf_current_offset);
            vwf_current_mask = (UBYTE)masks;
            ui_print_shift_char(vwf_tile_data, bitmap, vwf_current_font_bank);

            if ((UBYTE)(vwf_current_offset + width) > 8u) {
                vwf_current_rotate = 16u - (UBYTE)(vwf_current_offset + width);
                vwf_current_mask = (UBYTE)(masks >> 8u);
                ui_print_shift_char(vwf_tile_data + 16u, bitmap, vwf_current_font_bank);
            }
        }
        vwf_current_offset += width;

        set_bkg_data(ui_current_tile, 1, vwf_tile_data);
        if (vwf_current_offset > 7u) {
            memcpy(vwf_tile_data, vwf_tile_data + 16u, 16);
            memset(vwf_tile_data + 16u, text_bkg_fill, 16);
            vwf_current_offset -= 8u;
            ui_current_tile++;
            if (vwf_current_offset) set_bkg_data(ui_current_tile, 1, vwf_tile_data);
            return TRUE;
        } 
        return FALSE;
    } else {
        SetBankedBkgData(ui_current_tile++, 1, bitmap, vwf_current_font_bank);
        vwf_current_offset = 0u;
        return TRUE;
    }
}

void ui_draw_text_buffer_char() __banked {
    static UBYTE current_font_idx, current_text_bkg_fill, current_vwf_direction;

    if ((text_ff_joypad) && (INPUT_A_OR_B_PRESSED)) text_ff = TRUE;

    if ((!text_ff) && (text_wait)) {
        text_wait--;
        return;
    }

    if (ui_text_ptr == 0) {
        // save font and color global properties
        current_font_idx = vwf_current_font_idx;
        current_text_bkg_fill = text_bkg_fill;
        current_vwf_direction = vwf_direction;
        // reset to first line
        // current char pointer
        ui_text_ptr = ui_text_data;
        // VRAM destination
        ui_dest_base = GetWinAddr() + 32 + 1; // gotoxy(1,1)
        if (vwf_direction == UI_PRINT_RIGHTTOLEFT) ui_dest_base += 17;
        // with and initial pos correction
        // initialize current pointer with corrected base value
        ui_dest_ptr = ui_dest_base;
        // tileno destination
        ui_print_reset(TEXT_BUFFER_START);
    }

    switch (*ui_text_ptr) {
        case 0x00: {
            ui_text_ptr = 0; 
            text_drawn = TRUE;
            if (vwf_current_font_idx != current_font_idx) {
                const far_ptr_t * font = ui_fonts + vwf_current_font_idx;
                MemcpyBanked(&vwf_current_font_desc, font->ptr, sizeof(font_desc_t), vwf_current_font_bank = font->bank);
            }
            text_bkg_fill = current_text_bkg_fill;
            vwf_direction = current_vwf_direction;
            return;
        }
        case 0x01:
            // set text speed
            current_text_speed = ui_time_masks[*++ui_text_ptr] & 0x1fu;
            break;
        case 0x02: {
            // set current font
            current_font_idx = *(++ui_text_ptr) - 1u;
            const far_ptr_t * font = ui_fonts + current_font_idx;
            MemcpyBanked(&vwf_current_font_desc, font->ptr, sizeof(font_desc_t), vwf_current_font_bank = font->bank);
            break;
        }
        case 0x03:
            // gotoxy 
            ui_dest_ptr = ui_dest_base = GetWinAddr() + (*++ui_text_ptr - 1u) + (*++ui_text_ptr - 1u) * 32u;
            if (vwf_current_offset) ui_print_reset(ui_current_tile + 1u);
            break;
        case 0x04: {
            // relative gotoxy
            BYTE dx = (BYTE)(*++ui_text_ptr);
            if (dx > 0) dx--;
            BYTE dy = (BYTE)(*++ui_text_ptr);
            if (dy > 0) dy--;
            ui_dest_base = ui_dest_ptr += dx + dy * 32u;
            if (vwf_current_offset) ui_print_reset(ui_current_tile + 1u);
            break;
        }
        case 0x06:
            // if fast forward
            if (text_ff) {
                ++ui_text_ptr; 
                break;
            }
            // if high speed then ckeck for input 
            if (current_text_speed == 0) {
                wait_vbl_done();
                input_update();
            }
            // wait for key press (parameter is a mask)
            if ((joy & *++ui_text_ptr) && (joy && !last_joy)) break;
            ui_text_ptr--;
            return;
        case 0x07:
            // set text color
            text_bkg_fill = (*++ui_text_ptr & 1u) ? TEXT_BKG_FILL_W : TEXT_BKG_FILL_B;
            break;
        case 0x08:
            // text direction (left-to-right or right-to-left)
            vwf_direction = (*++ui_text_ptr & 1u) ? UI_PRINT_LEFTTORIGHT : UI_PRINT_RIGHTTOLEFT;
            break;
        case '\n':
            // carriage return
            ui_dest_ptr = ui_dest_base += 32u;
            if (vwf_current_offset) ui_print_reset(ui_current_tile + 1u);
            break;
        case 0x05:
            // escape symbol
            ui_text_ptr++; 
            // fall down to default
        default:
            if (ui_print_render(*ui_text_ptr)) {
                SetTile(ui_dest_ptr, ui_current_tile - 1u);
                if (vwf_direction == UI_PRINT_LEFTTORIGHT)  ui_dest_ptr++; else ui_dest_ptr--;
            }
            if (vwf_current_offset) SetTile(ui_dest_ptr, ui_current_tile);
            break;
    }
    ui_text_ptr++;
}

void ui_update() __nonbanked {
    UBYTE is_moving = FALSE;

    if (game_time & ui_time_masks[win_speed]) return;

    // y should always move first
    if (win_pos_y != win_dest_pos_y) {
        UBYTE interval = (win_speed == 1u) ? 2u : 1u;
        // move window up/down
        if (win_pos_y < win_dest_pos_y) win_pos_y += interval; else win_pos_y -= interval;
        is_moving = TRUE;
    }
    if (win_pos_x != win_dest_pos_x) {
        UBYTE interval = (win_speed == 1u) ? 2u : 1u;
        // move window left/right
        if (win_pos_x < win_dest_pos_x) win_pos_x += interval; else win_pos_x -= interval;
        is_moving = TRUE;
    }

    // don't draw text while moving
    if (is_moving) return;
    // all drawn - nothing to do
    if (text_drawn) return;
    // too fast - wait
    if ((!INPUT_A_OR_B_PRESSED) && (game_time & current_text_speed)) return;
    // render next char
    do {
        ui_draw_text_buffer_char();
    } while (((text_ff) || (current_text_speed == 0)) && (!text_drawn));
}

UBYTE ui_run_menu(menu_item_t * start_item, UBYTE bank, UBYTE options, UBYTE count) __banked {
    menu_item_t current_menu_item;
    UBYTE current_index = 1u, next_index = 0u;
    // copy first menu item
    MemcpyBanked(&current_menu_item, start_item, sizeof(menu_item_t), bank);
    // draw menu cursor
    set_win_tile_xy(current_menu_item.X, current_menu_item.Y, ui_cursor_tile);
    while (TRUE) {
        input_update();
        ui_update();
        
        toggle_shadow_OAM();
        actors_update();
        projectiles_render();
        activate_shadow_OAM();

        game_time++;
        wait_vbl_done();

        if (INPUT_UP_PRESSED) {
            next_index = current_menu_item.iU;
        } else if (INPUT_DOWN_PRESSED) {
            next_index = current_menu_item.iD;
        } else if (INPUT_LEFT_PRESSED) {
            next_index = current_menu_item.iL;
        } else if (INPUT_RIGHT_PRESSED) {
            next_index = current_menu_item.iR;
        } else if (INPUT_A_PRESSED) {
            return ((current_index == count) && (options & MENU_CANCEL_LAST)) ? 0u : current_index;
        } else if ((INPUT_B_PRESSED) && (options & MENU_CANCEL_B))  {
            return 0u;
        } else {
            continue;
        }

        if (!next_index) continue;

        // update current index
        current_index = next_index;
        // erase old cursor
        set_win_tile_xy(current_menu_item.X, current_menu_item.Y, ui_bg_tile);
        // read menu data
        MemcpyBanked(&current_menu_item, start_item + next_index - 1u, sizeof(menu_item_t), bank);
        // put new cursor
        set_win_tile_xy(current_menu_item.X, current_menu_item.Y, ui_cursor_tile);
        // reset next index
        next_index = 0;
    };
}

void ui_run_modal(UBYTE wait_flags) __banked {
    UBYTE fail;
    do {
        fail = FALSE;
    
        if (wait_flags & UI_WAIT_WINDOW)
            if ((win_pos_x != win_dest_pos_x) || (win_pos_y != win_dest_pos_y)) fail = TRUE;
        if (wait_flags & UI_WAIT_TEXT)
            if (!text_drawn) fail = TRUE;
        if (wait_flags & UI_WAIT_BTN_A)
            if (!INPUT_A_PRESSED) fail = TRUE;
        if (wait_flags & UI_WAIT_BTN_B)
            if (!INPUT_B_PRESSED) fail = TRUE;
        if (wait_flags & UI_WAIT_BTN_ANY)
            if (!INPUT_ANY_PRESSED) fail = TRUE;

        if (!fail) return;
        
        ui_update();

        toggle_shadow_OAM();
        actors_update();
        projectiles_render();
        activate_shadow_OAM();

        game_time++;
        wait_vbl_done();
        input_update();
    } while (fail);    
}

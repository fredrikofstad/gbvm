#ifndef UI_H
#define UI_H

#include <gb/gb.h>

#define TEXT_BUFFER_START 0xCCU
#define AVATAR_WIDTH 2
#define SELECTOR_WIDTH 1

#define MENU_OPEN_Y 112
#define WIN_LEFT_X 7
#define MENU_CLOSED_Y (MAXWNDPOSY + 1U)
#define TEXT_BUFFER_START 0xCCU
#define MENU_LAYOUT_INITIAL_X 88
#define MENU_CANCEL_ON_LAST_OPTION 0x01U
#define MENU_CANCEL_ON_B_PRESSED 0x02U

extern UBYTE win_pos_x;
extern UBYTE win_pos_y;
extern UBYTE win_dest_pos_x;
extern UBYTE win_dest_pos_y;
extern UBYTE win_speed;

extern UBYTE text_drawn;
extern UBYTE text_wait;
extern UBYTE text_num_lines;
extern UBYTE avatar_enabled;

extern unsigned char ui_text_data[80];

void ui_init() __banked;
void ui_update() __nonbanked; // critical path, __nonbanked for speed

inline void ui_set_pos(UBYTE x, UBYTE y) {
    win_pos_x = win_dest_pos_x = x;
    win_pos_y = win_dest_pos_y = y;
}

inline void ui_move_to(UBYTE x, UBYTE y, UBYTE speed) {
    win_dest_pos_x = x;
    win_dest_pos_y = y;
    if (speed == 0) win_pos_x = x, win_pos_y = y; else win_speed = speed;
}

#endif

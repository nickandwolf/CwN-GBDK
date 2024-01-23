#include <gb/gb.h>
#include <stdint.h>
#include <stdio.h>
#include "inc/Font.h"
#include "inc/main.h"

bool paused;

void InitPause() {
    pause = true;
	set_bkg_data(0,Level1_1_sprite_size,Level1_1_sprite);
    set_bkg_tiles(0,0,MAP_WIDTH,MAP_HEIGHT,Level1_1_map);
	set_sprite_data(32,8,Level1_Door_sprite);
	set_sprite_tile(10,32);
	set_sprite_tile(11,34);
	move_sprite(10,7*TILES,2*TILES+4);
	move_sprite(11,8*TILES,2*TILES+4);
}

void ExitPause() {
	pause = false;
}

int CheckCursor(uint8_t type) {
    int8_t x = 0;
    int8_t y = 0;

    switch (facing) {
        case 0:
            y = -1;
        break;

        case 1:
            y = 1;
        break;

        case 2:
            x = -1;
        break;

        case 3:
            x = 1;
        break;
    }
	
	/*
	if (map[playerMapX+x][playerMapY+y]) return map[playerMapX+x][playerMapY+y];
	
    else if (((playerMapX + x) > MAP_WIDTH-2) || ((playerMapX + x) < 0)) return 1;
	
    else if (((playerMapY + y) > MAP_HEIGHT-3) || ((playerMapY + y) < 1)) return 1;
	*/
    return 0;
}

void MoveCursor() {
	

    if (playerMoving == 1) {
        switch(facing) {
            case 0:
                playerY -= 1;
            break;
            case 1:
                playerY += 1;
            break;
            case 2:
                playerX -= 1;
            break;
            case 3:
                playerX += 1;
            break;
        }
    }
    else {
        if (KEY_PRESSED(J_UP)) {
            if (!CheckCollision()) {
                playerY -= 1;
                playerMapY -= 1;
            }
        }
        else if (KEY_PRESSED(J_DOWN)) {
            if (!CheckCollision()) {
                playerY += 1;
                playerMapY += 1;
            }
        }
        else if (KEY_PRESSED(J_LEFT)) {
            if (!CheckCollision()) {
                playerX -= 1;
                playerMapX -= 1;
            }
        }
        else if (KEY_PRESSED(J_RIGHT)) {
            if (!CheckCollision()) {
                playerX += 1;
                playerMapX += 1;
            }
        }

        if (KEY_TICKED(J_A)) {
            action_func();
        }
    }
}

void main(void)
{	
	init_win(0xCC);
	set_win_data(Font_sprite_start,Font_sprite_size,Font_tiles);
	set_win_data(0xC4,8,Dialog_Border_sprite);
	set_win_tiles(0,0,20,6,Dialog_Border_map);
    
	init_bkg(0x00);
	InitLevel1_1();
    SHOW_BKG;
	
    SPRITES_8x16;
    set_sprite_data(0, 32, MainCharacter_sprite);
    SHOW_SPRITES;

    DISPLAY_ON;
	
	pause = false;
    // Loop forever
    while(1) {
        Move_MainCharacter();
        move_sprite(0, playerX+8, playerY+16);
        move_sprite(2, playerX+16, playerY+16);

        UPDATE_KEYS();
        // Done processing, yield CPU and wait for start of next frame
        vsync();
    }
}

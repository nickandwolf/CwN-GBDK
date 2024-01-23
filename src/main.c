#include <gb/gb.h>
#include <stdint.h>
#include <stdio.h>
//#include <stdbool.h>
#include "inc/Font.h"
#include "inc/main.h"
#include "inc/MainCharacter.h"
#include "inc/diceRoll.h"
#include "../res/dialog_frame.h"
#include "inc/textFunctions.h"

//So we may need to struct for the main character. Other people don't really move...

void (*action_func)(void);

uint8_t map[MAP_WIDTH][MAP_HEIGHT];// all maps are only 1 screen big (dunno how to camera yet)

void PlacePlayer() {//stays here because of TILES
    playerX = playerMapX * TILES;
    playerY = playerMapY * TILES;
}


int8_t CheckCollision() {
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
	
	if (map[playerMapX+x][playerMapY+y]) return map[playerMapX+x][playerMapY+y];
	
    else if (((playerMapX + x) > MAP_WIDTH-11) || ((playerMapX + x) < 0)) return 1;
	
    else if (((playerMapY + y) > MAP_HEIGHT-9) || ((playerMapY + y) < 1)) return 1;
	
    return 0;
}

void MainCharacterUpdate() {
	//check what state we are in
	
	if ((((playerX) % TILES) == 0) && (((playerY) % TILES) == 0)) {
		playerState = OVERWORLD;
		AnimateCharacterSprite(); //simplify this?
	}
	else {
		playerState = PLAYER_MOVING;
		AnimateCharacterSprite();
	}
	
	switch (playerState) {
		case OVERWORLD:
		case PLAYER_MOVING:
			Move_MainCharacter(); //break shit out later
		break;
	}
	
	move_sprite(0, playerX+8, playerY);
	move_sprite(1, playerX+8, playerY+8);
	move_sprite(2, playerX+16, playerY);
	move_sprite(3, playerX+16, playerY+8);
	
	
}

void Move_MainCharacter() {
	if (playerState == PLAYER_MOVING) {
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
	else { //playerState == OVERWORLD
		if (KEY_PRESSED(J_UP)) {
			facing = 0;
			if (!CheckCollision()) {
				playerY -= 1;
				playerMapY -= 1;
			}
		}
		else if (KEY_PRESSED(J_DOWN)) {
			facing = 1;
			if (!CheckCollision()) {
				playerY += 1;
				playerMapY += 1;
			}
		}
		else if (KEY_PRESSED(J_LEFT)) {
			facing = 2;
			if (!CheckCollision()) {
				playerX -= 1;
				playerMapX -= 1;
			}
		}
		else if (KEY_PRESSED(J_RIGHT)) {
			facing = 3;
			if (!CheckCollision()) {
				playerX += 1;
				playerMapX += 1;
			}
		}

		if (KEY_TICKED(J_A)) {
			//action_func();
		}
	}
}

void main(void)
{	
	//TEST
	playerMapX = 3;
	playerMapY = 3;
	PlacePlayer();
	
    InitDiceData();
	InitCharacterSprite();
    SHOW_SPRITES;
	
    DISPLAY_ON;
	while(1)
	{
		//update
		MainCharacterUpdate();
		
		UPDATE_KEYS();
		
		//doodle
		vsync();
	}
    // Loop forever
/*    while(1) {
		//char text1[] = "bonk!";
		//dialog_print(text1, sizeof(text1));
		
        //Move_MainCharacter();
        //move_sprite(0, playerX+8, playerY+16);
        //move_sprite(2, playerX+16, playerY+16);

        UPDATE_KEYS();
        vsync();
    }*/
}

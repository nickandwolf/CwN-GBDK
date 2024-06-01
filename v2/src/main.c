#include <gb/gb.h>
#include <stdint.h>

#include "inc/main.h"
#include "inc/gameStatesEnum.h"
#include "inc/textFunctions.h"
#include "inc/Font.h"

//Levels and stuff
#include "inc/splashscreen.h"
#include "../data/inc/title_1.h"
#include "inc/CharacterSheet.h"
#include "../data/inc/hospital_1.h"

#include "inc/MainCharacter.h"
//#include "inc/CharacterCreation.h" //none yet, premade for first game
#include "../data/inc/MikeHall.h"

//#include "inc/diceRoll.h"

uint8_t previous_keys;
uint8_t keys;

uint8_t mission = 0;

uint8_t game_state = TITLE_SCREEN_STATE;

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
	
	//if ((((playerX) % TILES) == 0) && (((playerY) % TILES) == 0)) {
	//	playerState = OVERWORLD;
	//	AnimateCharacterSprite(); //simplify this?
	//}
	//else {
	//	playerState = PLAYER_MOVING;
	//	AnimateCharacterSprite();
	//}
	
	switch (playerState) {
		case OVERWORLD:
		case PLAYER_MOVING:
			Move_MainCharacter(); //break shit out later
		break;
	}
	
	//move_sprite(0, playerX+8, playerY);
	//move_sprite(1, playerX+8, playerY+8);
	//move_sprite(2, playerX+16, playerY);
	//move_sprite(3, playerX+16, playerY+8);
	
	
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
	//InitSplashScreen(); //KEEP
	InitTitle_1();
	MikeHall_Init();
	
	//DEBUG
	//game_state = CHAR_SHEET_STATE;
	
	uint8_t prev_game_state = game_state;
	
	while(1)
	{
		//update
		if ((prev_game_state != game_state) && (game_state != CHAR_SHEET_STATE || game_state != BRIEFING_SHEET_STATE || game_state != NOTES_SHEET_STATE || game_state != HELP_SHEET_STATE)) prev_game_state = game_state;
			
		switch (game_state) {
			case CHAR_SHEET_STATE: //pause screen
				game_state = CharacterSheetUpdate();
				if (game_state == BRIEFING_SHEET_STATE || game_state == NOTES_SHEET_STATE || game_state == HELP_SHEET_STATE) NULL;
				else if (game_state != CHAR_SHEET_STATE) game_state = prev_game_state;
			break;
			
			case BRIEFING_SHEET_STATE:
				game_state = BriefingUpdate();
				if (game_state == CHAR_SHEET_STATE || game_state == NOTES_SHEET_STATE || game_state == HELP_SHEET_STATE) NULL;
				else if (game_state != BRIEFING_SHEET_STATE) game_state = prev_game_state;
			break;
			
			case NOTES_SHEET_STATE:
				game_state = BriefingUpdate();
				if (game_state == CHAR_SHEET_STATE || game_state == BRIEFING_SHEET_STATE || game_state == HELP_SHEET_STATE) NULL;
				else if (game_state != NOTES_SHEET_STATE) game_state = prev_game_state;
			break;
			
			case HELP_SHEET_STATE:
				game_state = BriefingUpdate();
				if (game_state == CHAR_SHEET_STATE || game_state == NOTES_SHEET_STATE || game_state == BRIEFING_SHEET_STATE) NULL;
				else if (game_state != HELP_SHEET_STATE) game_state = prev_game_state;
			break;
			
			
			case TITLE_SCREEN_STATE: //Title Screen
				game_state = Title_1_Update();
			break;
			
			case HOSPITAL_1_STATE: //Load Hospital TODO: make hospital handle this
				game_state = Hospital_1_Update();
				prev_game_state == game_state;
			break;
			
			case APARTMENT_1_STATE:
				game_state = TITLE_SCREEN_STATE;
			break;
			
			case 5: //Load game (somehow, wtf)
			break;
		} 
		
		
		
		//doodle
		UPDATE_KEYS();
		vsync();
	}
}

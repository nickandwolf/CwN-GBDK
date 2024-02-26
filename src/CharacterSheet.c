#include <gbdk/emu_debug.h>

#include <stdint.h>
#include <gb/gb.h>

#include "inc/CharacterSheet.h"
#include "inc/gameStatesEnum.h"
#include "inc/textFunctions.h"
#include "inc/MainCharacter.h"

//include player data here

#include "../res/CharacterSheet_tiles.h"
#include "../res/CharacterSheet_map.h"
#include "../res/CustomFont_white.h"

uint8_t pointerCS = 0;
uint8_t charSheetPointerCS = 0;

void InitCharacterSheet() {
	HIDE_BKG;
	HIDE_WIN;
	HIDE_SPRITES;
	
	//Character Sheet BKG
	set_bkg_data(0,170,CharacterSheet_tiles);
	set_bkg_tiles(0,0,20,18,CharacterSheet_map);
	
	//Actual Stats
	set_sprite_data(0,79,CustomFont_white);
	
	set_bkg_tile_xy(3,2,70);
	
	//box sprite
	//set_sprite_tile(0, 53);
	//set_sprite_tile(1, 54);
	
	//move_sprite(0,8,12);
	//move_sprite(1,8,20);
	
	SHOW_BKG;
	//SHOW_SPRITES;
}

uint8_t CharacterSheetUpdate(void) {
	switch(pointerCS) {
		case 0:
			InitCharacterSheet();
			pointerCS = 1;
		break;
		
		case 1:
			if (KEY_PRESSED(J_A)) pointerCS = 2;
		break;
		
		case 2:
			pointerCS = 0;
			return HOSPITAL_1_STATE;
			
	}
	
	return CHAR_SHEET_STATE;
}
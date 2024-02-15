#include <stdio.h>

#include <stdint.h>
#include <gb/gb.h>

#include "../src/inc/main.h"

#include "../res/CharacterSheet_tiles.h"
#include "../res/CharacterSheet_map.h"

#include "inc/textFunctions.h"
#include "inc/CharacterSheet.h"

uint8_t pointerCS = 0;

void InitCharacterSheet() {
	HIDE_BKG;
	HIDE_WIN;
	HIDE_SPRITES;
	
	set_bkg_data(0,105,CharacterSheet_tiles);
	set_bkg_tiles(0,0,20,18,CharacterSheet_map);
	
	//move_win(0,0);
	
	SHOW_BKG;
}

uint8_t CharacterSheetUpdate(void) {
	switch(pointerCS) {
		case 0:
			InitCharacterSheet();
			pointerCS = 1;
		break;
		
		case 1:
			pointerCS = 2;
			return HOSPITAL_1_STATE;
			
		break;
		
		case 2:
			return HOSPITAL_1_STATE;
	}
	
	return 0;
}
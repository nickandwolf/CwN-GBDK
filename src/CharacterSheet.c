#include <stdint.h>
#include <gb/gb.h>

#include "../src/inc/main.h"

#include "../res/CharacterSheet_tiles.h"
#include "../res/CharacterSheet_map.h"

#include "inc/textFunctions.h"
#include "inc/CharacterSheet.h"

char pointerCS = 0;

void InitCharacterSheet() {
	set_bkg_data(0,105,CharacterSheet_tiles);
	set_bkg_tiles(0,0,20,18,CharacterSheet_map);
	SHOW_BKG;	
}

uint8_t CharacterSheetUpdate(void) {
	switch(pointerCS) {
		case 0:
			InitCharacterSheet();
			pointerCS = 1;
		break;
		
		case 1:
			waitpadup();
			waitpad(J_A);
			pointerCS = 2;
		break;
		
		case 2:
			return HOSPITAL_1_STATE;
	}
	
	return 0;
}
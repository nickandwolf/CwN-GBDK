#include <gbdk/emu_debug.h>

#include <stdint.h>
#include <gb/gb.h>

#include "inc/CharacterSheet.h"
#include "inc/gameStatesEnum.h"
#include "inc/textFunctions.h"


#include "../res/CharacterSheet_tiles.h"
#include "../res/CharacterSheet_map.h"

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
			EMU_printf("pointerCS:%i",pointerCS);
			pointerCS = 1;
			EMU_printf("pointerCS:%i",pointerCS);
		break;
		
		case 1:
			EMU_printf("pointerCS:%i",pointerCS);
			if (KEY_PRESSED(J_A)) EMU_printf("POOP");
		break;
		
		case 2:
			return HOSPITAL_1_STATE;
	}
	
	return CHAR_SHEET_STATE;
}
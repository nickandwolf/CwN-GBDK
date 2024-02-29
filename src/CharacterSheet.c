#include <gbdk/emu_debug.h>

#include <stdio.h>

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
	UpdateCharacterSheetStats();
	
	//box sprite
	//set_sprite_tile(0, 53);
	//set_sprite_tile(1, 54);
	
	//move_sprite(0,8,12);
	//move_sprite(1,8,20);
	
	SHOW_BKG;
	//SHOW_SPRITES;
}

void UpdateCharacterSheetStats(void) {
	SetPlayerAttribute(0,DEXTERITY,18);
	int8_t dex = GetPlayerAttributeBonus(0,DEXTERITY);
    set_bkg_tile_xy(3,2,MINUS_ONE);//str
    set_bkg_tile_xy(3,3,PLUS_MINUS_ZERO+dex);//dex
    set_bkg_tile_xy(3,4,PLUS_MINUS_ZERO+GetPlayerAttributeBonus(0,CONSTITUTION));//con
    set_bkg_tile_xy(7,2,PLUS_MINUS_ZERO+GetPlayerAttributeBonus(0,INTELLIGENCE));//int
    set_bkg_tile_xy(7,3,PLUS_MINUS_ZERO+GetPlayerAttributeBonus(0,WISDOM));//wis
    set_bkg_tile_xy(7,4,PLUS_MINUS_ZERO+GetPlayerAttributeBonus(0,CHARISMA));//cha

    /*
    set_bkg_tile_xy(11,1,PLUS_ONE);//attack
    set_bkg_tile_xy(11,2,PLUS_ONE);//ranged def
    set_bkg_tile_xy(11,3,PLUS_ONE);//melee def
    set_bkg_tile_xy(11,4,PLUS_ONE);//trauma
    set_bkg_tile_xy(15,1,PLUS_ONE);//fort
    set_bkg_tile_xy(15,2,PLUS_ONE);//ref
    set_bkg_tile_xy(15,3,PLUS_ONE);//will
    set_bkg_tile_xy(15,4,PLUS_ONE);//luck

    set_bkg_tile_xy(3,4,PLUS_ONE);//hp1
    set_bkg_tile_xy(3,4,PLUS_ONE);//hp2
    set_bkg_tile_xy(3,4,PLUS_ONE);//totalhp1
    set_bkg_tile_xy(3,4,PLUS_ONE);//totalhp2
    set_bkg_tile_xy(3,4,PLUS_ONE);//ss1
    set_bkg_tile_xy(3,4,PLUS_ONE);//ss2
    set_bkg_tile_xy(3,4,PLUS_ONE);//totalss1
    set_bkg_tile_xy(3,4,PLUS_ONE);//totalss2
    set_bkg_tile_xy(3,4,PLUS_ONE);//euro1
    set_bkg_tile_xy(3,4,PLUS_ONE);//euro2
    set_bkg_tile_xy(3,4,PLUS_ONE);//euro3
    */
    
}

uint8_t CharacterSheetUpdate(void) {
	switch(pointerCS) {
		case 0:
			InitCharacterSheet();
			pointerCS = 1;
		break;
		
		case 1:
            
			if (KEY_PRESSED(J_SELECT)) pointerCS = 2;
		break;
		
		case 2:
			pointerCS = 0;
			return HOSPITAL_1_STATE;
			
	}
	
	return CHAR_SHEET_STATE;
}

uint8_t CharacterSheetPointerUpdate(void) {
    
}

uint8_t CharacterSheetInventoryPointerUpdate(void) {
    
}

void DefineSheetStat(void) {
    
}
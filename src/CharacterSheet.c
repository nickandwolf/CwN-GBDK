#include <gbdk/emu_debug.h>

//MAY HAVE TO REDO SOME CHARACTER SHEET STUFF! HOW THE FUCK ARE WE GOING TO DO TEXT?!

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
	
	set_sprite_data(0,59,CustomFont_white);
	//box sprite
	set_sprite_tile(0, 0x36);
	set_sprite_tile(1, 0x35);
	set_sprite_tile(2, 0x34);
	set_sprite_tile(3, 0x33);
	
	//move_sprite(0,15,32);
	//move_sprite(1,15,31);
	//move_sprite(2,37,32);
	//move_sprite(3,37,31);
	
	SHOW_BKG;
	SHOW_SPRITES;
}

void UpdateCharacterSheetStats(void) {
    set_bkg_tile_xy(3,2,PLUS_MINUS_ZERO+GetPlayerAttributeBonus(STRENGTH));
    set_bkg_tile_xy(3,3,PLUS_MINUS_ZERO+GetPlayerAttributeBonus(DEXTERITY));
    set_bkg_tile_xy(3,4,PLUS_MINUS_ZERO+GetPlayerAttributeBonus(CONSTITUTION));
	
    set_bkg_tile_xy(7,2,PLUS_MINUS_ZERO+GetPlayerAttributeBonus(INTELLIGENCE));
    set_bkg_tile_xy(7,3,PLUS_MINUS_ZERO+GetPlayerAttributeBonus(WISDOM));
    set_bkg_tile_xy(7,4,PLUS_MINUS_ZERO+GetPlayerAttributeBonus(CHARISMA));

    //TODO: Make Zero Sprite!!!
    set_bkg_tile_xy(11,1,ZERO + GetPlayerAttack());//attack
    set_bkg_tile_xy(11,2,ZERO + GetPlayerRangedDefense());//ranged def
    set_bkg_tile_xy(11,3,ZERO + GetPlayerMeleeDefense());//melee def
    set_bkg_tile_xy(11,4,ZERO + GetPlayerTraumaTarget());//trauma
	
    set_bkg_tile_xy(15,1,ZERO + GetPlayerFort());//fort
    set_bkg_tile_xy(15,2,ZERO + GetPlayerReflex());//ref
    set_bkg_tile_xy(15,3,ZERO + GetPlayerWill());//will
    set_bkg_tile_xy(15,4,ZERO + GetPlayerLuck());//luck

    set_bkg_tile_xy(2,5,ZERO + 0);//hp1
    set_bkg_tile_xy(3,5,ZERO + 0);//hp2
    set_bkg_tile_xy(5,5,ZERO + 0);//totalhp1
    set_bkg_tile_xy(6,5,ZERO + 0);//totalhp2
	
    set_bkg_tile_xy(9,5,ZERO);//ss1
    set_bkg_tile_xy(10,5,ZERO);//ss2
    set_bkg_tile_xy(12,5,ZERO);//totalss1
    set_bkg_tile_xy(13,5,ZERO);//totalss2
	
    set_bkg_tile_xy(16,5,ZERO);//euro1
    set_bkg_tile_xy(17,5,ZERO);//euro2
    set_bkg_tile_xy(18,5,ZERO);//euro3
	
	set_bkg_tile_xy(3,6,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(ADMIN));//adm
	set_bkg_tile_xy(3,7,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(CONNECT));//con
	set_bkg_tile_xy(3,8,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(DRIVE));//drv
	
	set_bkg_tile_xy(6,6,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(EXERT));//exr
	set_bkg_tile_xy(6,7,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(FIX));//fix
	set_bkg_tile_xy(6,8,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(HEAL));//hea
	
	set_bkg_tile_xy(9,6,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(KNOW));//kno
	set_bkg_tile_xy(9,7,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(LEAD));//lea
	set_bkg_tile_xy(9,8,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(NOTICE));//ntc
	
	set_bkg_tile_xy(12,6,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(PERFORM));//prf
	set_bkg_tile_xy(12,7,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(PROGRAM));//prg
	set_bkg_tile_xy(12,8,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(PUNCH));//pnc
	
	set_bkg_tile_xy(15,6,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(SHOOT));//sht
	set_bkg_tile_xy(15,7,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(SNEAK));//snk
	set_bkg_tile_xy(15,8,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(STAB));//stb
	
	set_bkg_tile_xy(18,6,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(SURVIVE));//srv
	set_bkg_tile_xy(18,7,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(TALK));//tlk
	set_bkg_tile_xy(18,8,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(TRADE));//trd
    
}

uint8_t CharacterSheetUpdate(void) {
	switch(pointerCS) {
		case 0:
			InitCharacterSheet();
			pointerCS = 1;
		break;
		
		case 1:
            switch (charSheetPointerCS) {
				case STRENGTH_CS:
					move_sprite(0,15,32);
					move_sprite(1,15,31);
					move_sprite(2,37,32);
					move_sprite(3,37,31);
				break;
			}
			
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
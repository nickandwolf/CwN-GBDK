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
int8_t charSheetPointerCS = 0;
extern uint8_t charSheetIntro = 1;

void InitCharacterSheet() {
	charSheetPointerCS = 0;
    
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
            if (KEY_PRESSED(J_UP)) {
                if (charSheetPointerCS < 20) {
                    charSheetPointerCS -= 4;
                    if (charSheetPointerCS < 0) charSheetPointer = DRIVE_CS;//move to inventory
                    else if (charSheetPointerCS == -3) charSheetPointer = HEAL_CS;
                    else if (charSheetPointerCS == -2) charSheetPointer = PUNCH_CS;
                    else charSheetPointer = STAB_CS;
                }
                else {
                    charSheetPointerCS -= 6;
                    if (charSheetPointerCS == 14) charSheetPointer = HP_CS;//move to inventory
                    else if (charSheetPointerCS == 15) charSheetPointer = SS_CS;
                    else if (charSheetPointerCS == 16) charSheetPointer = SS_CS;
                    else if (charSheetPointerCS == 17) charSheetPointer = EURODOLLARS_CS;
                    //else if (charSheetPointerCS == 18) charSheetPointer = EURODOLLARS_CS;
                    //else if (charSheetPointerCS == 19) charSheetPointer = HEAT_CS;
                }
            }
            else if (KEY_PRESSED(J_DOWN)) {
                if (charSheetPointerCS < 20) {
                    charSheetPointerCS += 4;
                    if (charSheetPointerCS == 20) charSheetPointer = ADMIN_CS;//move to inventory
                    else if (charSheetPointerCS == 21) charSheetPointer = EXERT_CS;
                    else if (charSheetPointerCS == 22) charSheetPointer = PERFORM_CS;
                    else if (charSheetPointerCS == 23) charSheetPointer = SHOOT_CS;
                }
                else {
                    charSheetPointerCS += 6;
                    if (charSheetPointerCS == 38) charSheetPointer = LEVEL_CS;//move to inventory
                    else if (charSheetPointerCS == 39) charSheetPointer = SP_CS;
                    else if (charSheetPointerCS == 40) charSheetPointer = SP_CS;
                    else if (charSheetPointerCS == 41) charSheetPointer = ATTACK_BONUS_CS;
                    else if (charSheetPointerCS == 42) charSheetPointer = FORT_CS;
                    else if (charSheetPointerCS == 43) charSheetPointer = FORT_CS;
                }
            }
            else if (KEY_PRESSED(J_LEFT)) {
                charSheetPointerCS -= 1;
                if (charSheetPointerCS < 20) {//Shit forgot how to do this
                    if (charSheetPointerCS % 4 == 3) charSheetPointer += 4;
                }
                else {
                    if (charSheetPointerCS % 6 == 1) charSheetPointer += 6;
                }
            }
            else if (KEY_PRESSED(J_RIGHT)) {
                charSheetPointerCS += 1;
                if (charSheetPointerCS < 20) {
                    if (charSheetPointerCS % 4 == 0) charSheetPointer -= 4;
                }
                else {
                    if (charSheetPointerCS % 6 == 2) charSheetPointer -= 6;
                }
            }
            else if (KEY_PRESSED(J_A)) NULL;//try to level
            else if (KEY_PRESSED(J_SELECT)) NULL;//display explanation
            else if (KEY_PRESSED(J_B || J_START)) {
                pointerCS = 0;
                if (charSheetIntro == 0) return GAME_STATE_OVERWORLD;//TODO: GAMESTATESENUM
                else {
                    charSheetIntro = 0;
                    return HOSPITAL;
                }
            }
            
            //move sprites
            switch (charSheetPointerCS) {
                //Attributes
				case STRENGTH_CS:
					move_sprite(0,15,16);
					move_sprite(1,15,15);
					move_sprite(2,37,16);
					move_sprite(3,37,15);
				break;

                case DEXTERITY_CS:
                    move_sprite(0,15,32);
                    move_sprite(1,15,31);
                    move_sprite(2,37,32);
                    move_sprite(3,37,31);
                break;

                case CONSTITUTION_CS:
                    move_sprite(0,15,48);
                    move_sprite(1,15,47);
                    move_sprite(2,37,48);
                    move_sprite(3,37,47);
                break;

                case INTELLIGENCE_CS:
                    move_sprite(0,31,16);
                    move_sprite(1,31,15);
                    move_sprite(2,53,16);
                    move_sprite(3,53,15);
                break;

                case WISDOM_CS:
                    move_sprite(0,31,32);
                    move_sprite(1,31,31);
                    move_sprite(2,53,32);
                    move_sprite(3,53,31);
                break;

                case CHARISMA_CS:
                    move_sprite(0,31,48);
                    move_sprite(1,31,47);
                    move_sprite(2,53,48);
                    move_sprite(3,53,47);
                break;

                //Combat
                case ATTACK_BONUS_CS:
                    move_sprite(0,15,32);
                    move_sprite(1,15,31);
                    move_sprite(2,37,32);
                    move_sprite(3,37,31);
                break;

                case RANGED_DEFENSE_CS:
                    move_sprite(0,15,32);
                    move_sprite(1,15,31);
                    move_sprite(2,37,32);
                    move_sprite(3,37,31);
                break;

                case MELEE_DEFENSE_CS:
                    move_sprite(0,15,32);
                    move_sprite(1,15,31);
                    move_sprite(2,37,32);
                    move_sprite(3,37,31);
                break;

                case TRAUMA_CS:
                    move_sprite(0,15,32);
                    move_sprite(1,15,31);
                    move_sprite(2,37,32);
                    move_sprite(3,37,31);
                break;

                //Saves
                case FORT_CS:
                    move_sprite(0,15,32);
                    move_sprite(1,15,31);
                    move_sprite(2,37,32);
                    move_sprite(3,37,31);
                break;

                case REFLEX_CS:
                    move_sprite(0,15,32);
                    move_sprite(1,15,31);
                    move_sprite(2,37,32);
                    move_sprite(3,37,31);
                break;

                case WILLPOWER_CS:
                    move_sprite(0,15,32);
                    move_sprite(1,15,31);
                    move_sprite(2,37,32);
                    move_sprite(3,37,31);
                break;

                case LUCK_CS:
                    move_sprite(0,15,32);
                    move_sprite(1,15,31);
                    move_sprite(2,37,32);
                    move_sprite(3,37,31);
                break;

                //HP/SS/Euro/Heat
                case HP_CS:
                    move_sprite(0,15,32);
                    move_sprite(1,15,31);
                    move_sprite(2,37,32);
                    move_sprite(3,37,31);
                break;

                case SS_CS:
                    move_sprite(0,15,32);
                    move_sprite(1,15,31);
                    move_sprite(2,37,32);
                    move_sprite(3,37,31);
                break;

                case EURODOLLARS_CS:
                    move_sprite(0,15,32);
                    move_sprite(1,15,31);
                    move_sprite(2,37,32);
                    move_sprite(3,37,31);
                break;

                case HEAT_CS:
                    move_sprite(0,15,32);
                    move_sprite(1,15,31);
                    move_sprite(2,37,32);
                    move_sprite(3,37,31);
                break;
                
                //Skills
                case ADMIN_CS:
                
                break;

                case CONNECT_CS:

                break;

                case DRIVE_CS:

                break;

                case EXERT_CS:

                break;

                case FIX_CS:

                break;

                case HEAL_CS:

                break;

                case KNOW_CS:

                break;

                case LEAD_CS:

                break;

                case NOTICE_CS:

                break;

                case PERFORM_CS:

                break;

                case PROGRAM_CS:

                break;

                case PUNCH_CS:

                break;

                case SHOOT_CS:

                break;
                
                case SNEAK_CS:

                break;

                case STAB_CS:

                break;

                case SURVIVE_CS:

                break;

                case TALK_CS:

                break;

                case TRADE_CS:

                break;

                //Inventory
                case INVENTORY_CS:

                break;
			}
		break;
	}
	
	return CHAR_SHEET_STATE;
}

uint8_t CharacterSheetPointerUpdate(void) {
    
}

uint8_t CharacterSheetInventoryPointerUpdate(void) {
    
}

void DefineSheetStat(void) {
    
}
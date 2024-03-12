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
	charSheetPointerCS = LEVEL_CS;
    
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
	
    set_bkg_tile_xy(6,5,ZERO);//ss1
    set_bkg_tile_xy(7,5,ZERO);//ss2
	
    set_bkg_tile_xy(10,5,ZERO);//euro1
    set_bkg_tile_xy(11,5,ZERO);//euro2
    set_bkg_tile_xy(12,5,ZERO);//euro3
	set_bkg_tile_xy(13,5,ZERO);//euro4
	set_bkg_tile_xy(14,5,ZERO);//euro5
	set_bkg_tile_xy(15,5,ZERO);//euro6
	
	set_bkg_tile_xy(18,5,ZERO);//heat
	
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
	
	set_bkg_tile_xy(2,12,ZERO + charSheetPointerCS);
    
}

uint8_t CharacterSheetUpdate(void) {
	switch(pointerCS) {
		case 0:
			InitCharacterSheet();
            pointerCS = 1;
		break;
		
		case 1:
			//DEBUG
			UpdateCharacterSheetStats();
			
            if (KEY_TICKED(J_UP)) {
                if (charSheetPointerCS < 20) {
                    charSheetPointerCS -= 4;
                    if (charSheetPointerCS < 0) charSheetPointerCS = DRIVE_CS;//move to inventory
                    else if (charSheetPointerCS == -3) charSheetPointerCS = HEAL_CS;
                    else if (charSheetPointerCS == -2) charSheetPointerCS = PUNCH_CS;
                    else charSheetPointerCS = STAB_CS;
                }
                else {
                    charSheetPointerCS -= 6;
                    if (charSheetPointerCS == 14) charSheetPointerCS = HP_CS;//move to inventory
                    else if (charSheetPointerCS == 15) charSheetPointerCS = SS_CS;
                    else if (charSheetPointerCS == 16) charSheetPointerCS = SS_CS;
                    else if (charSheetPointerCS == 17) charSheetPointerCS = EURODOLLARS_CS;
                    //else if (charSheetPointerCS == 18) charSheetPointer = EURODOLLARS_CS;
                    //else if (charSheetPointerCS == 19) charSheetPointer = HEAT_CS;
                }
            }
            else if (KEY_TICKED(J_DOWN)) {
                if (charSheetPointerCS < 20) {
                    charSheetPointerCS += 4;
                    if (charSheetPointerCS == 20) charSheetPointerCS = ADMIN_CS;//move to inventory
                    else if (charSheetPointerCS == 21) charSheetPointerCS = EXERT_CS;
                    else if (charSheetPointerCS == 22) charSheetPointerCS = PERFORM_CS;
                    else if (charSheetPointerCS == 23) charSheetPointerCS = SHOOT_CS;
                }
                else {
                    charSheetPointerCS += 6;
                    if (charSheetPointerCS == 38) charSheetPointerCS = LEVEL_CS;//move to inventory
                    else if (charSheetPointerCS == 39) charSheetPointerCS = SP_CS;
                    else if (charSheetPointerCS == 40) charSheetPointerCS = SP_CS;
                    else if (charSheetPointerCS == 41) charSheetPointerCS = ATTACK_BONUS_CS;
                    else if (charSheetPointerCS == 42) charSheetPointerCS = FORT_CS;
                    else if (charSheetPointerCS == 43) charSheetPointerCS = FORT_CS;
                }
            }
            else if (KEY_TICKED(J_LEFT)) {
                charSheetPointerCS -= 1;
                if (charSheetPointerCS < 20) {//Shit forgot how to do this
                    if (charSheetPointerCS % 4 == 3) charSheetPointerCS += 4;
                }
                else {
                    if (charSheetPointerCS % 6 == 1) charSheetPointerCS += 6;
                }
            }
            else if (KEY_TICKED(J_RIGHT)) {
                charSheetPointerCS += 1;
                if (charSheetPointerCS < 20) {
                    if (charSheetPointerCS % 4 == 0) charSheetPointerCS -= 4;
                }
                else {
                    if (charSheetPointerCS % 6 == 2) charSheetPointerCS -= 6;
                }
            }
            else if (KEY_TICKED(J_A)) NULL;//try to level
            else if (KEY_TICKED(J_SELECT)) NULL;//display explanation
            else if (KEY_TICKED(J_B || J_START)) {
                pointerCS = 0;
                if (charSheetIntro == 0) return PLAYING_STATE;//TODO: GAMESTATESENUM
                else {
                    charSheetIntro = 0;
                    return HOSPITAL_1_STATE;
                }
            }
            
            //move sprites
            switch (charSheetPointerCS) {
                //Attributes
				case LEVEL_CS:
					move_sprite(0,14,25);
					move_sprite(1,14,24);
					move_sprite(2,37,25);
					move_sprite(3,37,24);
				break;
				
				case STRENGTH_CS:
					move_sprite(0,14,33);
					move_sprite(1,14,32);
					move_sprite(2,37,33);
					move_sprite(3,37,32);
				break;

                case DEXTERITY_CS:
                    move_sprite(0,14,41);
                    move_sprite(1,14,40);
                    move_sprite(2,37,41);
                    move_sprite(3,37,40);
                break;

                case CONSTITUTION_CS:
                    move_sprite(0,14,49);
                    move_sprite(1,14,48);
                    move_sprite(2,37,49);
                    move_sprite(3,37,48);
                break;
				
				case SP_CS:
					move_sprite(0,46,25);
					move_sprite(1,46,24);
					move_sprite(2,69,25);
					move_sprite(3,69,24);
				break;
				
                case INTELLIGENCE_CS:
                    move_sprite(0,46,33);
                    move_sprite(1,46,32);
                    move_sprite(2,69,33);
                    move_sprite(3,69,32);
                break;

                case WISDOM_CS:
                    move_sprite(0,46,41);
                    move_sprite(1,46,40);
                    move_sprite(2,69,41);
                    move_sprite(3,69,40);
                break;

                case CHARISMA_CS:
                    move_sprite(0,46,49);
                    move_sprite(1,46,48);
                    move_sprite(2,69,49);
                    move_sprite(3,69,48);
                break;

                //Combat
                case ATTACK_BONUS_CS:
                    move_sprite(0,78,25);
                    move_sprite(1,78,24);
                    move_sprite(2,101,25);
                    move_sprite(3,101,24);
                break;

                case RANGED_DEFENSE_CS:
                    move_sprite(0,78,33);
                    move_sprite(1,78,32);
                    move_sprite(2,101,33);
                    move_sprite(3,101,32);
                break;

                case MELEE_DEFENSE_CS:
                    move_sprite(0,78,41);
                    move_sprite(1,78,40);
                    move_sprite(2,101,41);
                    move_sprite(3,101,40);
                break;

                case TRAUMA_CS:
                    move_sprite(0,78,49);
                    move_sprite(1,78,48);
                    move_sprite(2,101,49);
                    move_sprite(3,101,48);
                break;

                //Saves
                case FORT_CS:
                    move_sprite(0,110,25);
                    move_sprite(1,110,24);
                    move_sprite(2,133,25);
                    move_sprite(3,133,24);
                break;

                case REFLEX_CS:
                    move_sprite(0,110,33);
                    move_sprite(1,110,32);
                    move_sprite(2,133,33);
                    move_sprite(3,133,32);
                break;

                case WILLPOWER_CS:
                    move_sprite(0,110,41);
                    move_sprite(1,110,40);
                    move_sprite(2,133,41);
                    move_sprite(3,133,40);
                break;

                case LUCK_CS:
                    move_sprite(0,110,49);
                    move_sprite(1,110,48);
                    move_sprite(2,133,49);
                    move_sprite(3,133,48);
                break;

                //HP/SS/Euro/Heat
                case HP_CS:
                    move_sprite(0,14,57);
                    move_sprite(1,14,56);
                    move_sprite(2,37,57);
                    move_sprite(3,37,56);
                break;

                case SS_CS:
                    move_sprite(0,46,57);
                    move_sprite(1,46,56);
                    move_sprite(2,69,57);
                    move_sprite(3,69,56);
                break;

                case EURODOLLARS_CS:
                    move_sprite(0,78,57);
                    move_sprite(1,78,56);
                    move_sprite(2,133,57);
                    move_sprite(3,133,56);
                break;

                case HEAT_CS:
                    move_sprite(0,142,57);
                    move_sprite(1,142,56);
                    move_sprite(2,157,57);
                    move_sprite(3,157,56);
                break;
                
                //Skills
                case ADMIN_CS:
					move_sprite(0,16,65);
                    move_sprite(1,16,63);
                    move_sprite(2,35,65);
                    move_sprite(3,35,63);
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
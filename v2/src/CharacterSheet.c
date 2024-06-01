#include <stdint.h>
#include <gb/gb.h>

#include "inc/main.h"
#include "inc/CharacterSheet.h"
#include "inc/gameStatesEnum.h"
#include "inc/textFunctions.h"
#include "inc/MainCharacter.h"
#include "inc/Font.h"

//include player data here

#include "../res/CharacterSheet_tiles.h"
#include "../res/CharacterSheet_map.h"
#include "../res/CustomFont_grey.h"
#include "../res/CustomFont.h"

uint8_t pointerCS = 0;
int8_t charSheetPointerCS = 0;

void InitCharacterSheet() {
	charSheetPointerCS = LEVEL_CS;
    
    HIDE_BKG;
	HIDE_WIN;
	HIDE_SPRITES;
	
	//Character Sheet BKG
	set_bkg_data(0,186,CharacterSheet_tiles);
	set_bkg_tiles(0,0,20,18,CharacterSheet_map);
	
	//Actual Stats
	UpdateCharacterSheetStats();
	
	set_sprite_data(0,10,CustomFont_grey);
	set_win_data(0xBF,65,CustomFont);
	
	set_sprite_tile(0, _POINTER_);
	set_sprite_prop(0, S_FLIPY);
	
	set_sprite_tile(1, 190);
	set_sprite_tile(2, 190);
	
	move_sprite(0,15,32);
	move_sprite(0,-64,-64);
	move_sprite(0,-64,-64);
	
	SHOW_BKG;
	SHOW_SPRITES;
}

void UpdateCharacterSheetStats(void) {//TODO:Redo all of this
	
	//LEVEL
	if (GetPlayerLevel()/10 == 1) set_bkg_tile_xy(2,1,LEFT_ONE);
	else set_bkg_tile_xy(2,1,LEFT_BLANK);
	set_bkg_tile_xy(3,1,GetPlayerLevel()%10+RIGHT_ZERO);
	
	//SP
	if (GetPlayerSP()/10 == 0) set_bkg_tile_xy(2,2,LEFT_BLANK);
	else set_bkg_tile_xy(2,2,GetPlayerSP()/10+LEFT_PLUS_MINUS);
	set_bkg_tile_xy(3,2,GetPlayerSP()%10+RIGHT_ZERO);
	
	//HP
    if (GetPlayerHP_Current()/10 == 0) set_bkg_tile_xy(2,3,LEFT_BLANK);
    else set_bkg_tile_xy(2,3,GetPlayerHP_Current()/10+LEFT_PLUS_MINUS);
    set_bkg_tile_xy(3,3,GetPlayerHP_Current()%10+RIGHT_ZERO);

    //SS
    if (GetPlayerSS_Current()/10 == 0) set_bkg_tile_xy(2,4,LEFT_BLANK);
    else set_bkg_tile_xy(2,4,GetPlayerSS_Current()/10+LEFT_PLUS_MINUS);
    set_bkg_tile_xy(3,4,GetPlayerSS_Current()%10+RIGHT_ZERO);

    //Attributes
    switch (GetPlayerAttributeBoosts()-1) {
        case 0:
            set_bkg_tile_xy(10,1,ATTRIBUTE_ZERO);
        break;

        case 1:
            set_bkg_tile_xy(10,1,ATTRIBUTE_ONE);
        break;

        case 2:
            set_bkg_tile_xy(10,1,ATTRIBUTE_TWO);
        break;

        case 3:
            set_bkg_tile_xy(10,1,ATTRIBUTE_THREE);
        break;

        case 4:
            set_bkg_tile_xy(10,1,ATTRIBUTE_FOUR);
        break;

        case 5:
            set_bkg_tile_xy(10,1,ATTRIBUTE_FIVE);
        break;
    }

    //Strength
    if (GetPlayerAttributeBonus(STRENGTH) > 0) {
        set_bkg_tile_xy(6,2,LEFT_PLUS);
        set_bkg_tile_xy(7,2,RIGHT_ZERO + GetPlayerAttributeBonus(STRENGTH));
    }
    else if (GetPlayerAttributeBonus(STRENGTH) < 0) {
        set_bkg_tile_xy(6,2,LEFT_MINUS);
        set_bkg_tile_xy(7,2,RIGHT_ZERO + (GetPlayerAttributeBonus(STRENGTH) * -1));
    }
    else {
        set_bkg_tile_xy(6,2,LEFT_PLUS_MINUS);
        set_bkg_tile_xy(7,2,RIGHT_ZERO);
    }

    //Dexterity
    if (GetPlayerAttributeBonus(DEXTERITY) > 0) {
        set_bkg_tile_xy(6,3,LEFT_PLUS);
        set_bkg_tile_xy(7,3,RIGHT_ZERO + GetPlayerAttributeBonus(DEXTERITY));
    }
    else if (GetPlayerAttributeBonus(DEXTERITY) < 0) {
        set_bkg_tile_xy(6,3,LEFT_MINUS);
        set_bkg_tile_xy(7,3,RIGHT_ZERO + (GetPlayerAttributeBonus(DEXTERITY) * -1));
    }
    else {
        set_bkg_tile_xy(6,3,LEFT_PLUS_MINUS);
        set_bkg_tile_xy(7,3,RIGHT_ZERO);
    }

    //Constitution
    if (GetPlayerAttributeBonus(CONSTITUTION) > 0) {
        set_bkg_tile_xy(6,4,LEFT_PLUS);
        set_bkg_tile_xy(7,4,RIGHT_ZERO + GetPlayerAttributeBonus(CONSTITUTION));
    }
    else if (GetPlayerAttributeBonus(CONSTITUTION) < 0) {
        set_bkg_tile_xy(6,4,LEFT_MINUS);
        set_bkg_tile_xy(7,4,RIGHT_ZERO + (GetPlayerAttributeBonus(CONSTITUTION) * -1));
    }
    else {
        set_bkg_tile_xy(6,4,LEFT_PLUS_MINUS);
        set_bkg_tile_xy(7,4,RIGHT_ZERO);
    }

    //Intelligence
    if (GetPlayerAttributeBonus(INTELLIGENCE) > 0) {
        set_bkg_tile_xy(9,2,LEFT_PLUS);
        set_bkg_tile_xy(10,2,RIGHT_ZERO + GetPlayerAttributeBonus(INTELLIGENCE));
    }
    else if (GetPlayerAttributeBonus(INTELLIGENCE) < 0) {
        set_bkg_tile_xy(9,2,LEFT_MINUS);
        set_bkg_tile_xy(10,2,RIGHT_ZERO + (GetPlayerAttributeBonus(INTELLIGENCE) * -1));
    }
    else {
        set_bkg_tile_xy(9,2,LEFT_PLUS_MINUS);
        set_bkg_tile_xy(10,2,RIGHT_ZERO);
    }

    //Wisdom
    if (GetPlayerAttributeBonus(WISDOM) > 0) {
        set_bkg_tile_xy(9,3,LEFT_PLUS);
        set_bkg_tile_xy(10,3,RIGHT_ZERO + GetPlayerAttributeBonus(WISDOM));
    }
    else if (GetPlayerAttributeBonus(WISDOM) < 0) {
        set_bkg_tile_xy(9,3,LEFT_MINUS);
        set_bkg_tile_xy(10,3,RIGHT_ZERO + (GetPlayerAttributeBonus(WISDOM) * -1));
    }
    else {
        set_bkg_tile_xy(9,3,LEFT_PLUS_MINUS);
        set_bkg_tile_xy(10,3,RIGHT_ZERO);
    }

    //Charisma
    if (GetPlayerAttributeBonus(CHARISMA) > 0) {
        set_bkg_tile_xy(9,4,LEFT_PLUS);
        set_bkg_tile_xy(10,4,RIGHT_ZERO + GetPlayerAttributeBonus(CHARISMA));
    }
    else if (GetPlayerAttributeBonus(CHARISMA) < 0) {
        set_bkg_tile_xy(9,4,LEFT_MINUS);
        set_bkg_tile_xy(10,4,RIGHT_ZERO + (GetPlayerAttributeBonus(CHARISMA) * -1));
    }
    else {
        set_bkg_tile_xy(9,4,LEFT_PLUS_MINUS);
        set_bkg_tile_xy(10,4,RIGHT_ZERO);
    }

    //saves
    if (GetPlayerFort() > 10) {
        set_bkg_tile_xy(12,1,ALT_LEFT_ONE);
        set_bkg_tile_xy(13,1,ALT_RIGHT_ONE + ((GetPlayerFort()%10)-1));
    }
    else if (GetPlayerFort() < 10) {
        set_bkg_tile_xy(12,1,ALT_LEFT_BLANK);
        set_bkg_tile_xy(13,1,ALT_RIGHT_ONE + ((GetPlayerFort()%10)-1));
    }
    else {
        set_bkg_tile_xy(12,1,ALT_LEFT_ONE);
        set_bkg_tile_xy(13,1,ALT_RIGHT_ZERO);
    }

    if (GetPlayerReflex() > 10) {
        set_bkg_tile_xy(12,2,ALT_LEFT_ONE);
        set_bkg_tile_xy(13,2,ALT_RIGHT_ONE + ((GetPlayerReflex()%10)-1));
    }
    else if (GetPlayerReflex() < 10) {
        set_bkg_tile_xy(12,2,ALT_LEFT_BLANK);
        set_bkg_tile_xy(13,2,ALT_RIGHT_ONE + ((GetPlayerReflex()%10)-1));
    }
    else {
        set_bkg_tile_xy(12,2,ALT_LEFT_ONE);
        set_bkg_tile_xy(13,2,ALT_RIGHT_ZERO);
    }
    
    if (GetPlayerWill() > 10) {
        set_bkg_tile_xy(12,3,ALT_LEFT_ONE);
        set_bkg_tile_xy(13,3,ALT_RIGHT_ONE + ((GetPlayerWill()%10)-1));
    }
    else if (GetPlayerWill() < 10) {
        set_bkg_tile_xy(12,3,ALT_LEFT_BLANK);
        set_bkg_tile_xy(13,3,ALT_RIGHT_ONE + ((GetPlayerWill()%10)-1));
    }
    else {
        set_bkg_tile_xy(12,3,ALT_LEFT_ONE);
        set_bkg_tile_xy(13,3,ALT_RIGHT_ZERO);
    }

    if (GetPlayerLuck() > 10) {
        set_bkg_tile_xy(12,4,ALT_LEFT_ONE);
        set_bkg_tile_xy(13,4,ALT_RIGHT_ONE + ((GetPlayerLuck()%10)-1));
    }
    else if (GetPlayerLuck() < 10) {
        set_bkg_tile_xy(12,4,ALT_LEFT_BLANK);
        set_bkg_tile_xy(13,4,ALT_RIGHT_ONE + ((GetPlayerLuck()%10)-1));
    }
    else {
        set_bkg_tile_xy(12,4,ALT_LEFT_ONE);
        set_bkg_tile_xy(13,4,ALT_RIGHT_ZERO);
    }

    //combat stuff
    if (GetPlayerAttack()/10 > 0) set_bkg_tile_xy(17,1,LEFT_PLUS_MINUS+(GetPlayerAttack()/10));
    else set_bkg_tile_xy(17,1,LEFT_BLANK);
    set_bkg_tile_xy(18,1,GetPlayerAttack()%10+RIGHT_ZERO);

    if (GetPlayerRangedDefense()/10 > 0) set_bkg_tile_xy(17,2,LEFT_PLUS_MINUS+(GetPlayerRangedDefense()/10));
    else set_bkg_tile_xy(17,2,LEFT_BLANK);
    set_bkg_tile_xy(18,2,GetPlayerRangedDefense()%10+RIGHT_ZERO);

    if (GetPlayerMeleeDefense()/10 > 0) set_bkg_tile_xy(17,3,LEFT_PLUS_MINUS+(GetPlayerMeleeDefense()/10));
    else set_bkg_tile_xy(17,3,LEFT_BLANK);
    set_bkg_tile_xy(18,3,GetPlayerMeleeDefense()%10+RIGHT_ZERO);

    if (GetPlayerTraumaTarget()/10 > 0) set_bkg_tile_xy(17,4,LEFT_PLUS_MINUS+(GetPlayerTraumaTarget()/10));
    else set_bkg_tile_xy(17,4,LEFT_BLANK);
    set_bkg_tile_xy(18,4,GetPlayerTraumaTarget()%10+RIGHT_ZERO);

    //eurodollars TODO:Maybe make eurodollars use custom size?--nope, gotta do custom math operators
	uint32_t tempBucks = GetPlayerEuroDollars();
	uint8_t ones = tempBucks%10;
	uint8_t tens = tempBucks/10%10;
	uint8_t hundreds = tempBucks/100%10;
	uint8_t thousands = tempBucks/1000%10;
	uint8_t ten_thousands = tempBucks/10000;
	
	set_bkg_tile_xy(6,5, ones + RIGHT_ZERO);//ones
	
	if ((tens == 0) && (hundreds == 0) && (thousands == 0) && (ten_thousands == 0)) set_bkg_tile_xy(5,5, EURODOLLAR_BLANK);
	else set_bkg_tile_xy(5,5, tens + EURODOLLAR_ZERO);//tens
	
	if ((hundreds == 0) && (thousands == 0) && (ten_thousands == 0)) set_bkg_tile_xy(4,5, EURODOLLAR_BLANK);
	else set_bkg_tile_xy(4,5, hundreds + EURODOLLAR_ZERO);//hundreds
	
	if ((thousands == 0) && (ten_thousands == 0)) set_bkg_tile_xy(3,5, EURODOLLAR_BLANK);
	else set_bkg_tile_xy(3,5, thousands + EURODOLLAR_ZERO);//thousands
	
	if (ten_thousands == 0) set_bkg_tile_xy(2,5, EURODOLLAR_BLANK);
    else set_bkg_tile_xy(2,5, ten_thousands + EURODOLLAR_ZERO);//ten-thousands
	
	set_bkg_tile_xy(4,16,GetPlayerHeat() + RIGHT_ZERO);//heat
	
	set_bkg_tile_xy(3,6,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(ADMIN));//adm
	set_bkg_tile_xy(3,7,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(CONNECT));//con
	set_bkg_tile_xy(3,8,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(DRIVE));//drv
	set_bkg_tile_xy(3,9,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(EXERT));//exr
	set_bkg_tile_xy(3,10,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(FIX));//fix
	set_bkg_tile_xy(3,11,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(HEAL));//hea
	set_bkg_tile_xy(3,12,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(KNOW));//kno
	set_bkg_tile_xy(3,13,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(LEAD));//lea
	set_bkg_tile_xy(3,14,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(NOTICE));//ntc
	
	set_bkg_tile_xy(6,6,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(PERFORM));//prf
	set_bkg_tile_xy(6,7,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(PROGRAM));//prg
	set_bkg_tile_xy(6,8,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(PUNCH));//pnc
	set_bkg_tile_xy(6,9,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(SHOOT));//sht
	set_bkg_tile_xy(6,10,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(SNEAK));//snk
	set_bkg_tile_xy(6,11,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(STAB));//stb
	set_bkg_tile_xy(6,12,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(SURVIVE));//srv
	set_bkg_tile_xy(6,13,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(TALK));//tlk
	set_bkg_tile_xy(6,14,SKILL_PLUS_MINUS_ZERO+GetPlayerSkill(TRADE));//trd
	
	//debug for pointer 1/2
	//set_bkg_tile_xy(2,12,ZERO + charSheetPointerCS);
	
	//TODO:INSERT INVENTORY STUFF HERE
}

uint8_t CharacterSheetUpdate(void) {
	uint8_t stat = 0;
	uint8_t tens = 0;
	uint8_t ones = 0;
	switch(pointerCS) {
		case 0:
			InitCharacterSheet();
            pointerCS = 1;
		break;
		
		case 1:
            if (KEY_TICKED(J_UP)) {
                if (charSheetPointerCS < 25) {
                    charSheetPointerCS -= 5;
                    if (charSheetPointerCS < -3) charSheetPointerCS = HEAT_CS;
                    else if (charSheetPointerCS < 0) charSheetPointerCS = INVENTORY_CS;
                }
                else {
                    charSheetPointerCS -= 2;
                    if (charSheetPointerCS == EURODOLLARS_again_CS) charSheetPointerCS = EURODOLLARS_CS;
					else if (charSheetPointerCS < 25) charSheetPointerCS = SS_CS;
					else if (charSheetPointerCS == TRADE_CS) charSheetPointerCS = CHARISMA_CS;
                }
            }

            else if (KEY_TICKED(J_DOWN)) {
                if (charSheetPointerCS < 25) {
                    charSheetPointerCS += 5;
                    if (charSheetPointerCS > 26) charSheetPointerCS = 46;
                    else if (charSheetPointerCS == 26) charSheetPointerCS = 25;
                }
                else {
                    charSheetPointerCS += 2;
                    if (charSheetPointerCS == EURODOLLARS_again_CS) charSheetPointerCS = EURODOLLARS_CS;
					else if (charSheetPointerCS == 46) charSheetPointerCS = HEAT_CS;
					else if (charSheetPointerCS == 47) charSheetPointerCS = CHARACTER_CS;
					else if (charSheetPointerCS == 48) charSheetPointerCS = BRIEFING_CS;
                }
            }
			
			else if (KEY_TICKED(J_LEFT)) {
                charSheetPointerCS -= 1;
                if (charSheetPointerCS < 25) {
					if (charSheetPointerCS == -1) charSheetPointerCS = HELP_CS;
					else if (charSheetPointerCS == BRIEFING_again_CS) charSheetPointerCS = BRIEFING_CS;
					else if (charSheetPointerCS == ATTRIBUTES_again_CS) charSheetPointerCS = ATTRIBUTES_CS;
					else if (charSheetPointerCS == 24) charSheetPointerCS = INVENTORY_CS;
					else if (charSheetPointerCS % 5 == 4) charSheetPointerCS += 5;
                }
				else {
                    if (charSheetPointerCS % 2 == 0) charSheetPointerCS += 2;
					else if (charSheetPointerCS == 45) charSheetPointerCS = EURODOLLARS_CS;
                }
            }
			
			else if (KEY_TICKED(J_RIGHT)) {
                charSheetPointerCS += 1;
                if (charSheetPointerCS < 25) {
					if (charSheetPointerCS % 5 == 0) charSheetPointerCS -= 5;
					else if (charSheetPointerCS == ATTRIBUTES_again_CS) charSheetPointerCS = FORT_CS;
					else if (charSheetPointerCS == BRIEFING_again_CS) charSheetPointerCS = NOTES_CS;
                }
                else {
                    if (charSheetPointerCS == 25) charSheetPointerCS = SS_CS;
					else if (charSheetPointerCS == EURODOLLARS_again_CS) charSheetPointerCS = INVENTORY_CS;
					else if (charSheetPointerCS == 47) charSheetPointerCS = EURODOLLARS_CS;
					else if (charSheetPointerCS % 2 == 1) charSheetPointerCS -= 2;
                }
            }
			
            else if (KEY_TICKED(J_A)) {
				//make sure to check if we are doing inventory or not
				uint8_t stat_CS = 0;
				int8_t value_CS = 0;
				uint8_t cost_CS = 0;
				uint8_t didWeLevel = 0;
				uint8_t stat_type_CS = 10;
				uint8_t stat__CS = 0;
				
				switch (charSheetPointerCS) {
					//Attributes
					case STRENGTH_CS:
						stat_CS = 1;
						value_CS = GetPlayerAttribute(STRENGTH);
						cost_CS = GetPlayerSP_Cost(1,0);
						stat__CS = STRENGTH;
					break;

					case DEXTERITY_CS:
						stat_CS = 2;
						value_CS = GetPlayerAttribute(DEXTERITY);
						cost_CS = GetPlayerSP_Cost(1,0);
						stat__CS = DEXTERITY;
					break;

					case CONSTITUTION_CS:
						stat_CS = 3;
						value_CS = GetPlayerAttribute(CONSTITUTION);
						cost_CS = GetPlayerSP_Cost(1,0);
						stat__CS = CONSTITUTION;
					break;
					
					case INTELLIGENCE_CS:
						stat_CS = 4;
						value_CS = GetPlayerAttribute(INTELLIGENCE);
						cost_CS = GetPlayerSP_Cost(1,0);
						stat__CS = INTELLIGENCE;
					break;

					case WISDOM_CS:
						stat_CS = 5;
						value_CS = GetPlayerAttribute(WISDOM);
						cost_CS = GetPlayerSP_Cost(1,0);
						stat__CS = WISDOM;
					break;

					case CHARISMA_CS:
						stat_CS = 6;
						value_CS = GetPlayerAttribute(CHARISMA);
						cost_CS = GetPlayerSP_Cost(1,0);
						stat__CS = CHARISMA;
					break;
					
					//Skills
					case ADMIN_CS:
						stat_CS = 7;
						value_CS = GetPlayerSkill(ADMIN);
						cost_CS = GetPlayerSP_Cost(0,ADMIN);
						stat__CS = ADMIN;
					break;

					case CONNECT_CS:
						stat_CS = 8;
						value_CS = GetPlayerSkill(CONNECT);
						cost_CS = GetPlayerSP_Cost(0,CONNECT);
						stat__CS = CONNECT;
					break;

					case DRIVE_CS:
						stat_CS = 9;
						value_CS = GetPlayerSkill(DRIVE);
						cost_CS = GetPlayerSP_Cost(0,DRIVE);
						stat__CS = DRIVE;
					break;

					case EXERT_CS:
						stat_CS = 10;
						value_CS = GetPlayerSkill(EXERT);
						cost_CS = GetPlayerSP_Cost(0,EXERT);
						stat__CS = EXERT;
					break;

					case FIX_CS:
						stat_CS = 11;
						value_CS = GetPlayerSkill(FIX);
						cost_CS = GetPlayerSP_Cost(0,FIX);
						stat__CS = FIX;
					break;

					case HEAL_CS:
						stat_CS = 12;
						value_CS = GetPlayerSkill(HEAL);
						cost_CS = GetPlayerSP_Cost(0,HEAL);
						stat__CS = HEAL;
					break;

					case KNOW_CS:
						stat_CS = 13;
						value_CS = GetPlayerSkill(KNOW);
						cost_CS = GetPlayerSP_Cost(0,KNOW);
						stat__CS = KNOW;
					break;

					case LEAD_CS:
						stat_CS = 14;
						value_CS = GetPlayerSkill(LEAD);
						cost_CS = GetPlayerSP_Cost(0,LEAD);
						stat__CS = LEAD;
					break;

					case NOTICE_CS:
						stat_CS = 15;
						value_CS = GetPlayerSkill(NOTICE);
						cost_CS = GetPlayerSP_Cost(0,NOTICE);
						stat__CS = NOTICE;
					break;

					case PERFORM_CS:
						stat_CS = 16;
						value_CS = GetPlayerSkill(PERFORM);
						cost_CS = GetPlayerSP_Cost(0,PERFORM);
						stat__CS = PERFORM;
					break;

					case PROGRAM_CS:
						stat_CS = 17;
						value_CS = GetPlayerSkill(PROGRAM);
						cost_CS = GetPlayerSP_Cost(0,PROGRAM);
						stat__CS = PROGRAM;
					break;

					case PUNCH_CS:
						stat_CS = 18;
						value_CS = GetPlayerSkill(PUNCH);
						cost_CS = GetPlayerSP_Cost(0,PUNCH);
						stat__CS = PUNCH;
					break;

					case SHOOT_CS:
						stat_CS = 19;
						value_CS = GetPlayerSkill(SHOOT);
						cost_CS = GetPlayerSP_Cost(0,SHOOT);
						stat__CS = SHOOT;
					break;
					
					case SNEAK_CS:
						stat_CS = 20;
						value_CS = GetPlayerSkill(SNEAK);
						cost_CS = GetPlayerSP_Cost(0,SNEAK);
						stat__CS = SNEAK;
					break;

					case STAB_CS:
						stat_CS = 21;
						value_CS = GetPlayerSkill(STAB);
						cost_CS = GetPlayerSP_Cost(0,STAB);
						stat__CS = STAB;
					break;

					case SURVIVE_CS:
						stat_CS = 22;
						value_CS = GetPlayerSkill(SURVIVE);
						cost_CS = GetPlayerSP_Cost(0,SURVIVE);
						stat__CS = SURVIVE;
					break;

					case TALK_CS:
						stat_CS = 23;
						value_CS = GetPlayerSkill(TALK);
						cost_CS = GetPlayerSP_Cost(0,TALK);
						stat__CS = TALK;
					break;

					case TRADE_CS:
						stat_CS = 24;
						value_CS = GetPlayerSkill(TRADE);
						cost_CS = GetPlayerSP_Cost(0,TRADE);
						stat__CS = TRADE;
					break;
					
					case BRIEFING_CS:
						pointerCS = 0;
						return BRIEFING_SHEET_STATE;
						
					break;
					
					case BRIEFING_again_CS:
						pointerCS = 0;
						return BRIEFING_SHEET_STATE;
					break;
					
					case NOTES_CS:
						pointerCS = 0;
						return NOTES_SHEET_STATE;
					break;
					
					case HELP_CS:
						pointerCS = 0;
						return HELP_SHEET_STATE;
					break;
				}
				
				if (stat_CS < 7) stat_type_CS = 0;
				else stat_type_CS = 1;
				
				if (stat_CS < 7 && GetPlayerAttributeBoosts() > 5) dialog_print("there are no more attribute boosts left.", sizeof("there are no more attribute boosts left."));
				else if (cost_CS > GetPlayerSP()) dialog_print("not enough sp#",sizeof("not enough sp#"));
				else  didWeLevel = dialog_level_up_print(stat_CS, value_CS, cost_CS);
				
				if (didWeLevel) {//TODO: THIS IS WHERE SHIT IS BROKEN
					SpendPlayerSP(stat_type_CS, stat__CS);
					UpdateCharacterSheetStats();
				}
			}
            else if (KEY_TICKED(J_SELECT)) NULL;// CharacterSheetGetInfo();//display explanation -> make this pull up inventory fast or move to HELP.
            else if (KEY_TICKED(J_B)) {
				charSheetPointerCS = CHARACTER_CS;
			}
			else if (KEY_TICKED(J_START)) {
                pointerCS = 0;
                return 255;
            }
            
			
            //move sprites
			move_sprite(1,-64,-64);
			move_sprite(2,-64,-64);
            switch (charSheetPointerCS) {
                //Top Tabs
				case CHARACTER_CS:
					move_sprite(0,8,21);
				break;
				
				case BRIEFING_CS:
					move_sprite(0,54,21);
				break;
				
				case BRIEFING_again_CS:
					move_sprite(0,54,21);
				break;
				
				case NOTES_CS:
					move_sprite(0,93,21);
				break;
				
				case HELP_CS:
					move_sprite(0,123,21);
				break;
				
				//strip one
				case LEVEL_CS:
					move_sprite(0,9,29);
				break;
				
				case ATTRIBUTES_CS:
					move_sprite(0,41,29);
				break;
				
				case ATTRIBUTES_again_CS:
					move_sprite(0,41,29);
				break;
				
				case FORT_CS:
					move_sprite(0,100,29);
				break;
				
				case ATTACK_BONUS_CS:
					move_sprite(0,128,29);
				break;
				
				//strip two
				case SP_CS:
					move_sprite(0,9,37);
				break;
				
				case STRENGTH_CS:
					move_sprite(0,41,37);
					set_sprite_tile(1, GetPlayerAttribute(STRENGTH)/10);
					set_sprite_tile(2, GetPlayerAttribute(STRENGTH)%10);
					move_sprite(1,49,40);
					move_sprite(2,57,40);
				break;
				
				case INTELLIGENCE_CS:
					move_sprite(0,66,37);
					set_sprite_tile(1, GetPlayerAttribute(INTELLIGENCE)/10);
					set_sprite_tile(2, GetPlayerAttribute(INTELLIGENCE)%10);
					move_sprite(1,74,40);
					move_sprite(2,82,40);
				break;
				
				case REFLEX_CS:
					move_sprite(0,100,37);
				break;
				
				case RANGED_DEFENSE_CS:
					move_sprite(0,128,37);
				break;
				
				//strip three
				case HP_CS:
					move_sprite(0,9,45);
				break;
				
				case DEXTERITY_CS:
					move_sprite(0,41,45);
					set_sprite_tile(1, GetPlayerAttribute(DEXTERITY)/10);
					set_sprite_tile(2, GetPlayerAttribute(DEXTERITY)%10);
					move_sprite(1,49,48);
					move_sprite(2,57,48);
				break;
				
				case WISDOM_CS:
					move_sprite(0,66,45);
					set_sprite_tile(1, GetPlayerAttribute(WISDOM)/10);
					set_sprite_tile(2, GetPlayerAttribute(WISDOM)%10);
					move_sprite(1,74,48);
					move_sprite(2,82,48);
				break;
				
				case WILLPOWER_CS:
					move_sprite(0,100,45);
				break;
				
				case MELEE_DEFENSE_CS:
					move_sprite(0,128,45);
				break;
				
				//strip four
				case SS_CS:
					move_sprite(0,9,53);
				break;
				
				case CONSTITUTION_CS:
					move_sprite(0,41,53);
					set_sprite_tile(1, GetPlayerAttribute(CONSTITUTION)/10);
					set_sprite_tile(2, GetPlayerAttribute(CONSTITUTION)%10);
					move_sprite(1,49,56);
					move_sprite(2,57,56);
				break;
				
				case CHARISMA_CS:
					move_sprite(0,66,53);
					set_sprite_tile(1, GetPlayerAttribute(CHARISMA)/10);
					set_sprite_tile(2, GetPlayerAttribute(CHARISMA)%10);
					move_sprite(1,74,56);
					move_sprite(2,82,56);
				break;
				
				case LUCK_CS:
					move_sprite(0,100,53);
				break;
				
				case TRAUMA_CS:
					move_sprite(0,128,53);
				break;
				
                case EURODOLLARS_CS:
                    move_sprite(0,10,61);
                break;
				
				case EURODOLLARS_again_CS:
                    move_sprite(0,10,61);
                break;

                //Skills
                case ADMIN_CS:
					move_sprite(0,12,68);
                break;

                case CONNECT_CS:
					move_sprite(0,12,76);
                break;

                case DRIVE_CS:
					move_sprite(0,12,84);
                break;

                case EXERT_CS:
					move_sprite(0,12,92);
                break;

                case FIX_CS:
					move_sprite(0,12,100);
                break;

                case HEAL_CS:
					move_sprite(0,12,108);
                break;

                case KNOW_CS:
					move_sprite(0,12,116);
                break;

                case LEAD_CS:
					move_sprite(0,12,124);
                break;

                case NOTICE_CS:
					move_sprite(0,12,132);
                break;

                case PERFORM_CS:
					move_sprite(0,36,68);
                break;

                case PROGRAM_CS:
					move_sprite(0,36,76);
                break;

                case PUNCH_CS:
					move_sprite(0,36,84);
                break;

                case SHOOT_CS:
					move_sprite(0,36,92);
                break;
                
                case SNEAK_CS:
					move_sprite(0,36,100);
                break;

                case STAB_CS:
					move_sprite(0,36,108);
                break;

                case SURVIVE_CS:
					move_sprite(0,36,116);
                break;

                case TALK_CS:
					move_sprite(0,36,124);
                break;

                case TRADE_CS:
					move_sprite(0,36,132);
                break;
				
				//bottom bitch
				case HEAT_CS:
                    move_sprite(0,26,149);
                break;
				
                //Inventory
                case INVENTORY_CS:
					move_sprite(0,66,61);
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

//MOVE THIS TO HELP with a speedy lookup thingy

void CharacterSheetGetInfo() {
	/*switch (charSheetPointerCS) {
		//Attributes
		case ATTRIBUTES_CS:
			dialog_print("test", sizeof("test"));
			break;
		
		case LEVEL_CS:
			dialog_print("level(lvl) is a   representation of your power level. you can advance a level by finishing missions.", sizeof("level(lvl) is a   representation of your power level. you can advance a level by finishing missions."));
		break;
		
		case STRENGTH_CS:
			dialog_print("strength(st) is   muscle and physical prowess.", sizeof("strength(st) is   muscle and physical prowess."));
		break;

		case DEXTERITY_CS:
			dialog_print("dexterity(dx) is  hand-eye coordination, reflexes,   and balance.", sizeof("dexterity(dx) is  hand-eye coordination, reflexes,   and balance."));
		break;

		case CONSTITUTION_CS:
			dialog_print("constitution(co)  is health and stamina.", sizeof("constitution(co)  is health and stamina."));
		break;
		
		case SP_CS:
			dialog_print("skill points(sp)  can be spent to   increase skills or attributes.", sizeof("skill points(sp)  can be spent to   increase skills or attributes."));
		break;
		
		case INTELLIGENCE_CS:
			dialog_print("intelligence(in)  is how well you   learn and reason.", sizeof("intelligence(in)  is how well you   learn and reason."));
		break;

		case WISDOM_CS:
			dialog_print("wisdom(wi) is your gut,perception,and common-sense.", sizeof("wisdom(wi) is your gut,perception,and common-sense."));
		break;

		case CHARISMA_CS:
			dialog_print("charisma(ch) is   influence,personal magnetism, and    ability to lead.", sizeof("charisma(ch) is   influence,personal magnetism, and    ability to lead."));
		break;

		//Combat
		case ATTACK_BONUS_CS:
			dialog_print("attack bonus(att+) is how easy it is for you to hit an opponent.", sizeof("attack bonus(att+) is how easy it is for you to hit an opponent."));
		break;

		case RANGED_DEFENSE_CS:
			dialog_print("ranged defense(rd) is how difficult  it is to hit you   with a ranged weapon.", sizeof("ranged defense(rd) is how difficult  it is to hit you   with a ranged weapon."));
		break;

		case MELEE_DEFENSE_CS:
			dialog_print("melee defense(md)  is how difficult  is to hit you in  melee combat.", sizeof("melee defense(md)  is how difficult  is to hit you in  melee combat."));
		break;

		case TRAUMA_CS:
			dialog_print("trauma target(tt) is how easy it is to score a critical hit on you.", sizeof("trauma target(tt) is how easy it is to score a critical hit on you."));
		break;

		//Saves
		case FORT_CS:
			dialog_print("fortitude(ft) resists exhaustion,  poison, disease,  or other bodily   afflictions.", sizeof("fortitude(ft) resists exhaustion,  poison, disease,  or other bodily   afflictions."));
		break;

		case REFLEX_CS:
			dialog_print("reflex(re) resists traps or occasions of sudden peril.", sizeof("reflex(re) resists traps or occasions of sudden peril."));
		break;

		case WILLPOWER_CS:
			dialog_print("will(wl) resists  mental influences, trauma, and other mental threats.", sizeof("will(wl) resists  mental influences, trauma, and other mental threats."));	 
		break;

		case LUCK_CS:
			dialog_print("luck(lk) is used  when blind chance is required.", sizeof("luck (lk) is used when blind chance is required."));
		break;

		//HP/SS/Euro/Heat
		case HP_CS:
			dialog_print("hit points(hp) are how close you are to a fatal blow.", sizeof("hit points(hp) are how close you are to a fatal blow."));
		break;

		case SS_CS:
			dialog_print("system strain(ss)  is how much your  body can take     before being rendered unconcious.", sizeof("system strain(ss)  is how much your  body can take     before being rendered unconcious."));
		break;

		case EURODOLLARS_CS:
			dialog_print("eurodollars($) are the strongest and  most prevelant    currency used     today.", sizeof("eurodollars($) are the strongest and  most prevelant    currency used     today."));
		break;

		case HEAT_CS:
			dialog_print("heat(!/) is how   reckless, destructive, or obvious  you are.", sizeof("heat(!/) is how   reckless, destructive, or obvious  you are."));
		break;
		
		//Skills
		case ADMIN_CS:
			dialog_print("admin(adm) is how to do paperwork or sort records.", sizeof("admin(adm) is how to do paperwork or sort records."));
		break;

		case CONNECT_CS:
			dialog_print("connect(con) is   used to find helpful people who can get things you    can't.", sizeof("connect(con) is   used to find helpful people who can get things you    can't."));
		break;

		case DRIVE_CS:
			dialog_print("drive(drv) is for driving vehicles.", sizeof("drive(drv) is for driving vehicles."));
		break;

		case EXERT_CS:
			dialog_print("exert(exr) is used for physical feats or exertions.", sizeof("exert(exr) is used for physical feats or exertions."));
		break;

		case FIX_CS:
			dialog_print("fix(fix) is used  to create or repair devices.", sizeof("fix(fix) is used  to create or repair devices."));
		break;

		case HEAL_CS:
			dialog_print("heal(hea) is used for medical treatment.", sizeof("heal(hea) is used for medical treatment."));
		break;

		case KNOW_CS:
			//dialog_print("know(kno) is used for knowing academic or scientific facts.", sizeof("know(kno) is used for knowing academic or scientific facts."));
		break;

		case LEAD_CS:
			//dialog_print("lead(lea) is used to convince others to do whatever    you're doing or go along with your   plan.", sizeof("lead(lea) is used to convince others to do whatever    you're doing or go along with your   plan."));
		break;

		case NOTICE_CS:
			//dialog_print("notice(ntc) is for spotting anomalies or interesting    features around   your environment.", sizeof("notice(ntc) is for spotting anomalies or interesting    features around   your environment."));
		break;

		case PERFORM_CS:
			//dialog_print("perform(prf) is   used to exhibit   some sort of performance.", sizeof("perform(prf) is   used to exhibit   some sort of performance."));
		break;

		case PROGRAM_CS:
			//dialog_print("program(prg) is   used for operating or hacking computers or hardware.", sizeof("program(prg) is   used for operating or hacking computers or hardware."));
		break;

		case PUNCH_CS:
			//dialog_print("punch(pnc) is used for fighting unarmed.", sizeof("punch(pnc) is used for fighting unarmed."));
		break;

		case SHOOT_CS:
			//dialog_print("shoot(sht) is used for attacks with  ranged weapons.", sizeof("shoot(sht) is used for attacks with  ranged weapons."));
		break;
		
		case SNEAK_CS:
			//dialog_print("sneak(snk) is used to move without   drawing notice.", sizeof("sneak(snk) is used to move without   drawing notice."));
		break;

		case STAB_CS:
			//dialog_print("stab(stb) is used for attacks with  melee weapons.", sizeof("stab(stb) is used for attacks with  melee weapons."));
		break;

		case SURVIVE_CS://
			//dialog_print("survive(srv) is   for living without modern amenities.", sizeof("survive(srv) is   for living without modern amenities."));
		break;

		case TALK_CS:
			//dialog_print("talk(tlk) is used to persuade others to your point of  view.", sizeof("talk(tlk) is used to persuade others to your point of  view."));
		break;

		case TRADE_CS:
			//dialog_print("trade(trd) is used to haggle prices  or get access to  rare or less-thanlegal items.", sizeof("trade(trd) is used to haggle prices  or get access to  rare or less-thanlegal items."));
		break;

		//Inventory
		case INVENTORY_CS:

		break;
	}*/
} 
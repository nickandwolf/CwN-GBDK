#include <gb/gb.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "inc/MainCharacter.h"
#include "../res/Character_Sprite.h"

uint8_t facing = 1;
uint8_t frame = 0;
int8_t playerX;
int8_t playerY; //the initialization will have to handle that
int8_t playerMapX; //gonna sound weird but maps start at 1
int8_t playerMapY;
uint8_t playerMoving = 0;
uint8_t playerTalking = 0;
uint8_t playerState = 0;

//should we allow multiple characters?
character PC[1]; //may need to work on optimization later

void InitalizeCharacter(uint8_t p) { //TODO: actually make this work
    //PC[p].level = 1;
    //PC[p].XP = 0;
	SetPlayerAttribute(p,STRENGTH,10);
	SetPlayerAttribute(p,DEXTERITY,10);
	SetPlayerAttribute(p,CONSTITUTION,10);
	SetPlayerAttribute(p,INTELLIGENCE,10);
	SetPlayerAttribute(p,WISDOM,10);
	SetPlayerAttribute(p,CHARISMA,10);
	
    PC[p].admin = -1;
    PC[p].connect = -1;
    PC[p].drive = -1;
    PC[p].exert = -1;
    PC[p].fix = -1;
    PC[p].heal = -1;
    PC[p].know = -1;
    PC[p].lead = -1;
    PC[p].notice = -1;
    PC[p].perform = -1;
    PC[p].program = -1;
    PC[p].punch = -1;
    PC[p].shoot = -1;
    PC[p].sneak = -1;
    PC[p].stab = -1;
    PC[p].survive = -1;
    PC[p].talk = -1;
    PC[p].trade = -1;
    PC[p].work = -1;
}

void SetPlayerName(uint8_t p, char *name) {
    PC[p].name = name;
}

/*
void SetPlayerBackground(uint8_t p, uint8_t background) {
    PC[p].background = background;
    switch(background) {
        case BUM: //Bum
            ImprovePlayerSkill(p,SURVIVE);
            //pointer
            
        break;

        case BUREAUCRAT: //Bureaucrat
            ImprovePlayerSkill(p,ADMINISTER);
        break;

        case CLERGY:
            ImprovePlayerSkill(p,LEAD);
        break;

        case CODER:
            ImprovePlayerSkill(p,PROGRAM);
        break;

        case CORP_SECURITY:
            //player selects any combat skill (STAB, PUNCH, SHOOT)
        break;

        case CORPER:
            ImprovePlayerSkill(p,WORK);
            //quick skills or roll?
            //roll on growth
            //roll on learning
            //only 3 rolls
        break;

        case CRIMINAL:
            ImprovePlayerSkill(p,SNEAK);
        break;

        case DOCTOR:
            ImprovePlayerSkill(p,HEAL);
        break;

        case DRONE_JOCKEY:
            ImprovePlayerSkill(p,DRIVE);
        break;

        case GANGER:
            //any combat
        break;

        case LABORER:
            ImprovePlayerSkill(p,EXERT);
        break;

        case LAW_ENFORCEMENT:
            ImprovePlayerSkill(p,ADMINISTER);
        break;

        case MANAGER:
            ImprovePlayerSkill(p,ADMINISTER);
        break;

        case OUTLANDER:
            ImprovePlayerSkill(p,SURVIVE);
        break;

        case PERFORMER:
            ImprovePlayerSkill(p,PERFORM);
        break;

        case SOLDIER:
            //ANY COMBAT
        break;

        case SPY:
            ImprovePlayerSkill(p,SNEAK);
        break;

        case TRADER:
            ImprovePlayerSkill(p,TRADE);
        break;

        case STREETWALKER:
            ImprovePlayerSkill(p,TALK);
        break;

        case TECHNICIAN:
            ImprovePlayerSkill(p,FIX);
        break;
    }
}

void InitPlayerBackground(uint8_t p) {
	PC[p].background;
}

char* GetPlayerBackground(uint8_t p) {
    switch(PC[p].background) {
		//
		return "nope";
    }
}
*/

/*
void UseDefaultAttributeArray(uint8_t p) {
    //need to make a UI
    //what would you like to assign?
	PC[p];
}

void UseDiceRollAttribute(uint8_t p) {
    //need to make a UI
    //show dice roll
    //apply to stat
    for (uint8_t i = 1; i < 7; i++) {
        //roll 3d6
        uint8_t roll = 0;
        SetPlayerAttribute(p, i, roll);
    }
}
*/

void SetPlayerAttribute(uint8_t p, uint8_t attribute, uint8_t value) {
    switch (attribute) {
        case STRENGTH:
            PC[p].strength = value;
        break;

        case DEXTERITY:
            PC[p].dexterity = value;
        break;

        case CONSTITUTION:
            PC[p].constitution = value;
        break;

        case INTELLIGENCE:
            PC[p].intelligence = value;
        break;

        case WISDOM:
            PC[p].wisdom = value;
        break;

        case CHARISMA:
            PC[p].charisma = value;
        break;
    }
	SetPlayerAttributeBonus(p);
}

void SetPlayerAttributeBonus(uint8_t p) {
    bool edge_prodigy = false;
    
    //for (uint8_t i = 0; i < 4; i++) {
    //    if (PC[p].edges[i] == PRODIGY_STR || PC[p].edges[i] == PRODIGY_DEX || PC[p].edges[i] == PRODIGY_CON || PC[p].edges[i] == PRODIGY_INT || PC[p].edges[i] == PRODIGY_WIS || PC[p].edges[i] == PRODIGY_CHA) edge_prodigy = true;
    //}
    
    for (uint8_t i = 0; i < 6; i++) {
        switch (i) {
            case 0:
                if (PC[p].strength < 4) PC[p].strength_bonus = -2;
                else if (PC[p].strength < 8) PC[p].strength_bonus = -1;
                else if (PC[p].strength < 14) PC[p].strength_bonus = 0;
                else if (PC[p].strength < 18) PC[p].strength_bonus = 1;
                else if (PC[p].strength == 18 && edge_prodigy) PC[p].strength_bonus = 3;
                else PC[p].strength_bonus = 2;
            break;

            case 1:
                if (PC[p].dexterity < 4) PC[p].dexterity_bonus = -2;
                else if (PC[p].dexterity< 8) PC[p].dexterity_bonus = -1;
                else if (PC[p].dexterity < 14) PC[p].dexterity_bonus = 0;
                else if (PC[p].dexterity < 18) PC[p].dexterity_bonus = 1;
                else if (PC[p].dexterity == 18 && edge_prodigy) PC[p].dexterity_bonus = 3;
                else PC[p].dexterity_bonus = 2;
            break;

            case 2:
                if (PC[p].constitution < 4) PC[p].constitution_bonus = -2;
                else if (PC[p].constitution < 8) PC[p].constitution_bonus = -1;
                else if (PC[p].constitution < 14) PC[p].constitution_bonus = 0;
                else if (PC[p].constitution < 18) PC[p].constitution_bonus = 1;
                else if (PC[p].constitution == 18 && edge_prodigy) PC[p].constitution_bonus = 3;
                else PC[p].constitution_bonus = 2;
            break;

            case 3:
                if (PC[p].intelligence < 4) PC[p].intelligence_bonus = -2;
                else if (PC[p].intelligence < 8) PC[p].intelligence_bonus = -1;
                else if (PC[p].intelligence < 14) PC[p].intelligence_bonus = 0;
                else if (PC[p].intelligence < 18) PC[p].intelligence_bonus = 1;
                else if (PC[p].intelligence == 18 && edge_prodigy) PC[p].intelligence_bonus = 3;
                else PC[p].intelligence_bonus = 2;
            break;

            case 4:
                if (PC[p].wisdom < 4) PC[p].wisdom_bonus = -2;
                else if (PC[p].wisdom < 8) PC[p].wisdom_bonus = -1;
                else if (PC[p].wisdom < 14) PC[p].wisdom_bonus = 0;
                else if (PC[p].wisdom < 18) PC[p].wisdom_bonus = 1;
                else if (PC[p].wisdom == 18 && edge_prodigy) PC[p].wisdom_bonus = 3;
                else PC[p].wisdom_bonus = 2;
            break;

            case 5:
                if (PC[p].charisma < 4) PC[p].charisma_bonus = -2;
                else if (PC[p].charisma < 8) PC[p].charisma_bonus = -1;
                else if (PC[p].charisma < 14) PC[p].charisma_bonus = 0;
                else if (PC[p].charisma < 18) PC[p].charisma_bonus = 1;
                else if (PC[p].charisma == 18 && edge_prodigy) PC[p].charisma_bonus = 3;
                else PC[p].charisma_bonus = 2;
            break;
        }
    }
}

uint8_t ImprovePlayerAttribute(uint8_t p, uint8_t attribute, uint8_t value, uint8_t type);//type is 0 = any, 1 = phys, 2 = mental

/*
void PickSkills(uint8_t p) {
    //need to make a UI
    //show skill text when picking
    //show points
}
*/

uint8_t ImprovePlayerSkill(uint8_t p, uint8_t skill) {
    switch (skill) {
        case ADMIN://TODO: Use the enum
            if (PC[p].admin < 3) PC[p].admin++;
            else return 0;
        break;

        case CONNECT:
            if (PC[p].connect < 3) PC[p].connect++;
            else return 0;
        break;

        case DRIVE:
            if (PC[p].drive < 3) PC[p].drive++;
            else return 0;
        break;

        case EXERT:
            if (PC[p].exert < 3) PC[p].exert++;
            else return 0;
        break;

        case FIX:
            if (PC[p].fix < 3) PC[p].fix++;
            else return 0;
        break;

        case HEAL:
            if (PC[p].heal < 3) PC[p].heal++;
            else return 0;
        break;

        case KNOW:
            if (PC[p].know < 3) PC[p].know++;
            else return 0;
        break;

        case LEAD:
            if (PC[p].lead < 3) PC[p].lead++;
            else return 0;
        break;

        case NOTICE:
            if (PC[p].notice < 3) PC[p].notice++;
            else return 0;
        break;

        case PERFORM:
            if (PC[p].perform < 3) PC[p].perform++;
            else return 0;
        break;

        case PROGRAM:
            if (PC[p].program < 3) PC[p].program++;
            else return 0;
        break;

        case PUNCH:
            if (PC[p].punch < 3) PC[p].punch++;
            else return 0;
        break;

        case SHOOT:
            if (PC[p].shoot < 3) PC[p].shoot++;
            else return 0;
        break;

        case SNEAK:
            if (PC[p].sneak < 3) PC[p].sneak++;
            else return 0;
        break;

        case STAB:
            if (PC[p].stab < 3) PC[p].stab++;
            else return 0;
        break;

        case SURVIVE:
            if (PC[p].survive < 3) PC[p].survive++;
            else return 0;
        break;

        case TALK:
            if (PC[p].talk < 3) PC[p].talk++;
            else return 0;
        break;

        case TRADE:
            if (PC[p].trade < 3) PC[p].trade++;
            else return 0;
        break;

        case WORK:
            if (PC[p].work < 3) PC[p].work++;
            else return 0;
        break;
    }
    return 1;
}

/*
void SetPlayerEdge(uint8_t p, uint8_t edge) {
    if (PC[p].edges[0] == 0) PC[p].edges[0] = edge;
    else if (PC[p].edges[1] == 0) PC[p].edges[1] = edge;
    else if (PC[p].edges[2] == 0) PC[p].edges[2] = edge;
    else if (PC[p].edges[3] == 0) PC[p].edges[3] = edge;
}
*/
/*****************************************************************/

char* GetPlayerName(uint8_t p) {
	return PC[p].name;
}

uint8_t GetPlayerAttribute(uint8_t p, uint8_t attribute) {
    switch (attribute) {
        case STRENGTH:
            return PC[p].strength;
        break;

        case DEXTERITY:
            return PC[p].dexterity;
        break;

        case CONSTITUTION:
            return PC[p].constitution;
        break;

        case INTELLIGENCE:
            return PC[p].intelligence;
        break;

        case WISDOM:
            return PC[p].wisdom;
        break;

        case CHARISMA:
            return PC[p].charisma;
        break;
    }
    return 0;
}

int8_t GetPlayerAttributeBonus(uint8_t p, uint8_t attribute) {
    switch (attribute) {
        case STRENGTH:
            return PC[p].strength_bonus;
        break;

        case DEXTERITY:
            return PC[p].dexterity_bonus;
        break;

        case CONSTITUTION:
            return PC[p].constitution_bonus;
        break;

        case INTELLIGENCE:
            return PC[p].intelligence_bonus;
        break;

        case WISDOM:
            return PC[p].wisdom_bonus;
        break;

        case CHARISMA:
            return PC[p].charisma_bonus;
        break;
    }

    return -5;
}

int8_t GetPlayerSkill(uint8_t p, uint8_t skill) {
    switch (skill) {
        case ADMIN:
            return PC[p].admin;
        break;
    
        case CONNECT:
            return PC[p].connect;
        break;
    
        case DRIVE:
            return PC[p].drive;
        break;
    
        case EXERT:
            return PC[p].exert;
        break;
    
        case FIX:
            return PC[p].fix;
        break;
    
        case HEAL:
            return PC[p].heal;
        break;
    
        case KNOW:
            return PC[p].know;
        break;
    
        case LEAD:
            return PC[p].lead;
        break;
    
        case NOTICE:
            return PC[p].notice;
        break;
    
        case PERFORM:
            return PC[p].perform;
        break;
    
        case PROGRAM:
            return PC[p].program;
        break;
    
        case PUNCH:
            return PC[p].punch;
        break;
    
        case SHOOT:
            return PC[p].shoot;
        break;
    
        case SNEAK:
            return PC[p].sneak;
        break;
    
        case STAB:
            return PC[p].stab;
        break;
    
        case SURVIVE:
            return PC[p].survive;
        break;
    
        case TALK:
            return PC[p].talk;
        break;
    
        case TRADE:
            return PC[p].trade;
        break;
    
        case WORK:
            return PC[p].work;
        break;
    }

    return -5;
}

uint8_t GetPlayerLevel(uint8_t p) {
    return PC[p].level;
}

uint8_t GetPlayerXP(uint8_t p) {
    return PC[p].XP;
}

uint8_t GetPlayerHP(uint8_t p) {
    return PC[p].HP;
}

uint8_t GetPlayerHP_Current(uint8_t p) {
    return PC[p].HP_current;
}

uint8_t GetPlayerSS(uint8_t p) {
    return PC[p].SS;
}

uint8_t GetPlayerSS_Current(uint8_t p) {
    return PC[p].SS_current;
}
/*****************************************************************/

void InitCharacterSprite() {
	set_sprite_data(33, 24, CharacterSprite);
	
	facing = 1;
	playerState = OVERWORLD; //decided by level
	
	set_sprite_tile(0, PC_F_IDLE);
	set_sprite_tile(1, PC_F_IDLE+1);
	set_sprite_tile(2, PC_F_IDLE+2);
	set_sprite_tile(3, PC_F_IDLE+3);
	
	move_sprite(0, playerX, playerY);
	move_sprite(1, playerX, playerY+8);
	move_sprite(2, playerX+8, playerY);
	move_sprite(3, playerX+8, playerY+8);
	
}

void AnimateCharacterSprite() {
	if (playerState == OVERWORLD) {
		set_sprite_prop(0, get_sprite_prop(0) & ~S_FLIPX);
		set_sprite_prop(1, get_sprite_prop(1) & ~S_FLIPX);
		set_sprite_prop(2, get_sprite_prop(2) & ~S_FLIPX);
		set_sprite_prop(3, get_sprite_prop(3) & ~S_FLIPX);
		
		switch(facing) {
			case 0://up
				set_sprite_tile(0, PC_B_IDLE);
				set_sprite_tile(1, PC_B_IDLE+1);
				set_sprite_tile(2, PC_B_IDLE+2);
				set_sprite_tile(3, PC_B_IDLE+3);
			break;

			case 1://down
				set_sprite_tile(0, PC_F_IDLE);
				set_sprite_tile(1, PC_F_IDLE+1);
				set_sprite_tile(2, PC_F_IDLE+2);
				set_sprite_tile(3, PC_F_IDLE+3);
			break;

			case 2://left
				set_sprite_tile(0, PC_S_IDLE);
				set_sprite_tile(1, PC_S_IDLE+1);
				set_sprite_tile(2, PC_S_IDLE+2);
				set_sprite_tile(3, PC_S_IDLE+3);
			break;

			case 3://right
				set_sprite_prop(0, S_FLIPX);
				set_sprite_prop(1, S_FLIPX);
				set_sprite_prop(2, S_FLIPX);
				set_sprite_prop(3, S_FLIPX);
			
				set_sprite_tile(2, PC_S_IDLE);
				set_sprite_tile(3, PC_S_IDLE+1);
				set_sprite_tile(0, PC_S_IDLE+2);
				set_sprite_tile(1, PC_S_IDLE+3);
			break;
		}
	}
	
	else if (playerState == PLAYER_MOVING) { //NEED TO DO META SPRITES
		if (frame == 1) {
			set_sprite_prop(0, S_FLIPX);
			set_sprite_prop(1, S_FLIPX);
			set_sprite_prop(2, S_FLIPX);
			set_sprite_prop(3, S_FLIPX);
		}
		else {
			set_sprite_prop(0, get_sprite_prop(0) & ~S_FLIPX);
			set_sprite_prop(1, get_sprite_prop(1) & ~S_FLIPX);
			set_sprite_prop(2, get_sprite_prop(2) & ~S_FLIPX);
			set_sprite_prop(3, get_sprite_prop(3) & ~S_FLIPX);
		}
		
		switch(facing) {
			case 0://up
				if (frame == 1) {//flip
					set_sprite_tile(0, PC_B_WALK);
					set_sprite_tile(1, PC_B_WALK+1);
					set_sprite_tile(2, PC_B_WALK+2);
					set_sprite_tile(3, PC_B_WALK+3);
				}
				else {//no flip
					set_sprite_tile(0, PC_B_WALK);
					set_sprite_tile(1, PC_B_WALK+1);
					set_sprite_tile(2, PC_B_WALK+2);
					set_sprite_tile(3, PC_B_WALK+3);
				}
			break;

			case 1://down
				if (frame == 1) {//flip
					set_sprite_tile(0, PC_F_WALK);
					set_sprite_tile(1, PC_F_WALK+1);
					set_sprite_tile(2, PC_F_WALK+2);
					set_sprite_tile(3, PC_F_WALK+3);
				}
				else {//no flip
					set_sprite_tile(0, PC_F_WALK);
					set_sprite_tile(1, PC_F_WALK+1);
					set_sprite_tile(2, PC_F_WALK+2);
					set_sprite_tile(3, PC_F_WALK+3);
				}
			break;

			case 2://left
				set_sprite_prop(0, get_sprite_prop(0) & ~S_FLIPX);
				set_sprite_prop(1, get_sprite_prop(1) & ~S_FLIPX);
				set_sprite_prop(2, get_sprite_prop(2) & ~S_FLIPX);
				set_sprite_prop(3, get_sprite_prop(3) & ~S_FLIPX);
				
				set_sprite_tile(0, PC_S_WALK);
				set_sprite_tile(1, PC_S_WALK+1);
				set_sprite_tile(2, PC_S_WALK+2);
				set_sprite_tile(3, PC_S_WALK+3);
				
				
			break;

			case 3://right
				set_sprite_prop(0, S_FLIPX);
				set_sprite_prop(1, S_FLIPX);
				set_sprite_prop(2, S_FLIPX);
				set_sprite_prop(3, S_FLIPX);
				
				set_sprite_tile(2, PC_S_WALK);
				set_sprite_tile(3, PC_S_WALK+1);
				set_sprite_tile(0, PC_S_WALK+2);
				set_sprite_tile(1, PC_S_WALK+3);
			break;
		}
		
		if (playerState == OVERWORLD) {
			if (frame ==  1) frame = 0;
			else frame = 1;
		}
	}
}
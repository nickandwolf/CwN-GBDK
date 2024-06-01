#include <gb/gb.h>
#include <stdint.h>
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
character PC; //may need to work on optimization later

void InitalizeCharacter() { //TODO: actually make this work
    PC.level = 1;
    PC.SP = 3;
	PC.Attribute_boosts = 1;
	
	SetPlayerAttribute(STRENGTH,10);
	SetPlayerAttribute(DEXTERITY,10);
	SetPlayerAttribute(CONSTITUTION,10);
	SetPlayerAttribute(INTELLIGENCE,10);
	SetPlayerAttribute(WISDOM,10);
	SetPlayerAttribute(CHARISMA,10);

    SetPlayerSkill(ADMIN, -1);
    SetPlayerSkill(CONNECT, -1);
    SetPlayerSkill(DRIVE, -1);
    SetPlayerSkill(EXERT, -1);
    SetPlayerSkill(FIX, -1);
    SetPlayerSkill(HEAL, -1);
    SetPlayerSkill(KNOW, -1);
    SetPlayerSkill(LEAD, -1);
    SetPlayerSkill(NOTICE, -1);
    SetPlayerSkill(PERFORM, -1);
    SetPlayerSkill(PROGRAM, -1);
    SetPlayerSkill(PUNCH, -1);
    SetPlayerSkill(SHOOT, -1);
    SetPlayerSkill(SNEAK, -1);
    SetPlayerSkill(STAB, -1);
    SetPlayerSkill(SURVIVE, -1);
    SetPlayerSkill(TALK, -1);
    SetPlayerSkill(TRADE, -1);
    SetPlayerSkill(WORK, -1);
	
	SetPlayerEuroDollars(0);
	SetPlayerHeat(0);
}

void SetPlayerName(char *name) {
    PC.name = name;
}

/*
void SetPlayerBackground(uint8_t p, uint8_t background) {
    PC.background = background;
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
	PC.background;
}

char* GetPlayerBackground(uint8_t p) {
    switch(PC.background) {
		//
		return "nope";
    }
}
*/

/*
void UseDefaultAttributeArray(uint8_t p) {
    //need to make a UI
    //what would you like to assign?
	PC;
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

void SetPlayerAttribute(uint8_t attribute, uint8_t value) {
    switch (attribute) {
        case STRENGTH:
            PC.strength = value;
        break;

        case DEXTERITY:
            PC.dexterity = value;
        break;

        case CONSTITUTION:
            PC.constitution = value;
        break;

        case INTELLIGENCE:
            PC.intelligence = value;
        break;

        case WISDOM:
            PC.wisdom = value;
        break;

        case CHARISMA:
            PC.charisma = value;
        break;
    }
	SetPlayerAttributeBonus();
}

void SetPlayerAttributeBonus() {
    uint8_t edge_prodigy = 0;
    
    //for (uint8_t i = 0; i < 4; i++) {
    //    if (PC.edges[i] == PRODIGY_STR || PC.edges[i] == PRODIGY_DEX || PC.edges[i] == PRODIGY_CON || PC.edges[i] == PRODIGY_INT || PC.edges[i] == PRODIGY_WIS || PC.edges[i] == PRODIGY_CHA) edge_prodigy = 1;
    //}
    

	if (PC.strength < 4) PC.strength_bonus = -2;
	else if (PC.strength < 8) PC.strength_bonus = -1;
	else if (PC.strength < 14) PC.strength_bonus = 0;
	else if (PC.strength < 18) PC.strength_bonus = 1;
	else if (PC.strength == 18 && edge_prodigy) PC.strength_bonus = 3;
	else PC.strength_bonus = 2;

	if (PC.dexterity < 4) PC.dexterity_bonus = -2;
	else if (PC.dexterity< 8) PC.dexterity_bonus = -1;
	else if (PC.dexterity < 14) PC.dexterity_bonus = 0;
	else if (PC.dexterity < 18) PC.dexterity_bonus = 1;
	else if (PC.dexterity == 18 && edge_prodigy) PC.dexterity_bonus = 3;
	else PC.dexterity_bonus = 2;

	if (PC.constitution < 4) PC.constitution_bonus = -2;
	else if (PC.constitution < 8) PC.constitution_bonus = -1;
	else if (PC.constitution < 14) PC.constitution_bonus = 0;
	else if (PC.constitution < 18) PC.constitution_bonus = 1;
	else if (PC.constitution == 18 && edge_prodigy) PC.constitution_bonus = 3;
	else PC.constitution_bonus = 2;

	if (PC.intelligence < 4) PC.intelligence_bonus = -2;
	else if (PC.intelligence < 8) PC.intelligence_bonus = -1;
	else if (PC.intelligence < 14) PC.intelligence_bonus = 0;
	else if (PC.intelligence < 18) PC.intelligence_bonus = 1;
	else if (PC.intelligence == 18 && edge_prodigy) PC.intelligence_bonus = 3;
	else PC.intelligence_bonus = 2;

	if (PC.wisdom < 4) PC.wisdom_bonus = -2;
	else if (PC.wisdom < 8) PC.wisdom_bonus = -1;
	else if (PC.wisdom < 14) PC.wisdom_bonus = 0;
	else if (PC.wisdom < 18) PC.wisdom_bonus = 1;
	else if (PC.wisdom == 18 && edge_prodigy) PC.wisdom_bonus = 3;
	else PC.wisdom_bonus = 2;

	if (PC.charisma < 4) PC.charisma_bonus = -2;
	else if (PC.charisma < 8) PC.charisma_bonus = -1;
	else if (PC.charisma < 14) PC.charisma_bonus = 0;
	else if (PC.charisma < 18) PC.charisma_bonus = 1;
	else if (PC.charisma == 18 && edge_prodigy) PC.charisma_bonus = 3;
	else PC.charisma_bonus = 2;
}

/*
void SetPlayerEdge(uint8_t p, uint8_t edge) {
    if (PC.edges[0] == 0) PC.edges[0] = edge;
    else if (PC.edges[1] == 0) PC.edges[1] = edge;
    else if (PC.edges[2] == 0) PC.edges[2] = edge;
    else if (PC.edges[3] == 0) PC.edges[3] = edge;
}
*/

void SetPlayerSkill(uint8_t skill, int8_t value) {
    if (value < -1 || value > 4) return;
    switch (skill) {
        case ADMIN://TODO: Use the enum
            PC.admin = value;
        break;

        case CONNECT:
            PC.connect = value;
        break;

        case DRIVE:
            PC.drive = value;
        break;

        case EXERT:
            PC.exert = value;
        break;

        case FIX:
            PC.fix = value;
        break;

        case HEAL:
            PC.heal = value;
        break;

        case KNOW:
            PC.know = value;
        break;

        case LEAD:
            PC.lead = value;
        break;

        case NOTICE:
            PC.notice = value;
        break;

        case PERFORM:
            PC.perform = value;
        break;

        case PROGRAM:
            PC.program = value;
        break;

        case PUNCH:
            PC.punch = value;
        break;

        case SHOOT:
            PC.shoot = value;
        break;

        case SNEAK:
            PC.sneak = value;
        break;

        case STAB:
            PC.stab = value;
        break;

        case SURVIVE:
            PC.survive = value;
        break;

        case TALK:
            PC.talk = value;
        break;

        case TRADE:
            PC.trade = value;
        break;

        case WORK:
            PC.work = value;
        break;
    }
}

void SetPlayerHP() {
    //add edge shit
    PC.HP = (PC.constitution_bonus + 4) * PC.level * 4;
}

uint8_t SetPlayerHP_Current(int8_t value) {
    //temp HP needs to happen too
    PC.HP_current += value;
    if (PC.HP_current < 1) return 0;
    return 1;
}

uint8_t SetPlayerEuroDollars(int32_t value) {
	if (PC.EuroDollars - value < 0) return 0;
	else if (PC.EuroDollars + value > 99999) PC.EuroDollars = 99999;
	else PC.EuroDollars += value;
	return 1;
}

void SetPlayerHeat(int8_t value) {
	if (PC.Heat - value < 0) PC.Heat = 0;
	else if (PC.Heat + value > 9) PC.Heat = 9;
	else PC.Heat += value;
}

/*****************************************************************/

uint8_t ImprovePlayerAttribute(uint8_t attribute, uint8_t type) {//type is 0 = any, 1 = phys, 2 = mental
	//this'll do something during a character creator or something...
}

uint8_t ImprovePlayerSkill(uint8_t skill) {
    switch (skill) {
        case ADMIN://TODO: Use the enum
            if (PC.admin < 4) PC.admin++;
            else return 0;
        break;

        case CONNECT:
            if (PC.connect < 4) PC.connect++;
            else return 0;
        break;

        case DRIVE:
            if (PC.drive < 4) PC.drive++;
            else return 0;
        break;

        case EXERT:
            if (PC.exert < 4) PC.exert++;
            else return 0;
        break;

        case FIX:
            if (PC.fix < 4) PC.fix++;
            else return 0;
        break;

        case HEAL:
            if (PC.heal < 4) PC.heal++;
            else return 0;
        break;

        case KNOW:
            if (PC.know < 4) PC.know++;
            else return 0;
        break;

        case LEAD:
            if (PC.lead < 4) PC.lead++;
            else return 0;
        break;

        case NOTICE:
            if (PC.notice < 4) PC.notice++;
            else return 0;
        break;

        case PERFORM:
            if (PC.perform < 4) PC.perform++;
            else return 0;
        break;

        case PROGRAM:
            if (PC.program < 4) PC.program++;
            else return 0;
        break;

        case PUNCH:
            if (PC.punch < 4) PC.punch++;
            else return 0;
        break;

        case SHOOT:
            if (PC.shoot < 4) PC.shoot++;
            else return 0;
        break;

        case SNEAK:
            if (PC.sneak < 4) PC.sneak++;
            else return 0;
        break;

        case STAB:
            if (PC.stab < 4) PC.stab++;
            else return 0;
        break;

        case SURVIVE:
            if (PC.survive < 4) PC.survive++;
            else return 0;
        break;

        case TALK:
            if (PC.talk < 4) PC.talk++;
            else return 0;
        break;

        case TRADE:
            if (PC.trade < 4) PC.trade++;
            else return 0;
        break;

        case WORK:
            if (PC.work < 4) PC.work++;
            else return 0;
        break;
    }
    return 1;
}

void LevelPlayerUp(void);

void SpendPlayerSP(uint8_t stat_type, uint8_t stat) {
	if (stat_type == 0 && GetPlayerAttributeBoosts() < 5) {//attribute
		switch (stat) {
			case STRENGTH:
				PC.strength++;
			break;
			
			case DEXTERITY:
				PC.dexterity++;
			break;
			
			case CONSTITUTION:
				PC.constitution++;
			break;
			
			case INTELLIGENCE:
				PC.intelligence++;
			break;
			
			case WISDOM:
				PC.wisdom++;
			break;
			
			case CHARISMA:
				PC.charisma++;
			break;
		}
		
		SetPlayerAttributeBonus();
		PC.SP-= GetPlayerAttributeBoosts();
		PC.Attribute_boosts++;
	}
	else {
		switch (stat) {
			case ADMIN:
				PC.admin++;
			break;
		
			case CONNECT:
				PC.connect++;
			break;
		
			case DRIVE:
				PC.drive++;
			break;
		
			case EXERT:
				PC.exert++;
			break;
		
			case FIX:
				PC.fix++;
			break;
		
			case HEAL:
				PC.heal++;
			break;
		
			case KNOW:
				PC.know++;
			break;
		
			case LEAD:
				PC.lead++;
			break;
		
			case NOTICE:
				PC.notice++;
			break;
		
			case PERFORM:
				PC.perform++;
			break;
		
			case PROGRAM:
				PC.program++;
			break;
		
			case PUNCH:
				PC.punch++;
			break;
		
			case SHOOT:
				PC.shoot++;
			break;
		
			case SNEAK:
				PC.sneak++;
			break;
		
			case STAB:
				PC.stab++;
			break;
		
			case SURVIVE:
				PC.survive++;
			break;
		
			case TALK:
				PC.talk++;
			break;
		
			case TRADE:
				PC.trade++;
			break;
		
			case WORK:
				PC.work++;
			break;
		}
		
		PC.SP -= GetPlayerSkill(stat)+1;
	}
}

/*****************************************************************/

char* GetPlayerName() {
	return PC.name;
}

uint8_t GetPlayerAttribute(uint8_t attribute) {
    switch (attribute) {
        case STRENGTH:
            return PC.strength;
        break;

        case DEXTERITY:
            return PC.dexterity;
        break;

        case CONSTITUTION:
            return PC.constitution;
        break;

        case INTELLIGENCE:
            return PC.intelligence;
        break;

        case WISDOM:
            return PC.wisdom;
        break;

        case CHARISMA:
            return PC.charisma;
        break;
    }
    return 0;
}

int8_t GetPlayerAttributeBonus(uint8_t attribute) {
    switch (attribute) {
        case STRENGTH:
            return PC.strength_bonus;
        break;

        case DEXTERITY:
            return PC.dexterity_bonus;
        break;

        case CONSTITUTION:
            return PC.constitution_bonus;
        break;

        case INTELLIGENCE:
            return PC.intelligence_bonus;
        break;

        case WISDOM:
            return PC.wisdom_bonus;
        break;

        case CHARISMA:
            return PC.charisma_bonus;
        break;
    }

    return -5;
}

int8_t GetPlayerSkill(uint8_t skill) {
    switch (skill) {
        case ADMIN:
            return PC.admin;
        break;
    
        case CONNECT:
            return PC.connect;
        break;
    
        case DRIVE:
            return PC.drive;
        break;
    
        case EXERT:
            return PC.exert;
        break;
    
        case FIX:
            return PC.fix;
        break;
    
        case HEAL:
            return PC.heal;
        break;
    
        case KNOW:
            return PC.know;
        break;
    
        case LEAD:
            return PC.lead;
        break;
    
        case NOTICE:
            return PC.notice;
        break;
    
        case PERFORM:
            return PC.perform;
        break;
    
        case PROGRAM:
            return PC.program;
        break;
    
        case PUNCH:
            return PC.punch;
        break;
    
        case SHOOT:
            return PC.shoot;
        break;
    
        case SNEAK:
            return PC.sneak;
        break;
    
        case STAB:
            return PC.stab;
        break;
    
        case SURVIVE:
            return PC.survive;
        break;
    
        case TALK:
            return PC.talk;
        break;
    
        case TRADE:
            return PC.trade;
        break;
    
        case WORK:
            return PC.work;
        break;
    }

    return -5;
}

uint8_t GetPlayerLevel() {
    return PC.level;
}

uint8_t GetPlayerSP() {
    return PC.SP;
}

uint8_t GetPlayerAttributeBoosts() {
	return PC.Attribute_boosts;
}

uint8_t GetPlayerSP_Cost(uint8_t stat_type, uint8_t stat) {
	if (stat_type) return GetPlayerAttributeBoosts();
	
	return GetPlayerSkill(stat) + 2;
}

uint8_t GetPlayerHP() {
    return PC.HP;
}

uint8_t GetPlayerHP_Current() {
    if (PC.HP_current < 1) return 0;
    return PC.HP_current;
}

uint8_t GetPlayerSS() {
    return PC.SS;
}

uint8_t GetPlayerSS_Current() {
    if (PC.SS_current > PC.SS) return 30;//TODO:what's the max SS can be?
    return PC.SS_current;
}

uint8_t GetPlayerAttack() {
	//check inv, edges, foci
	uint8_t attack = PC.level/2;
	return attack;
}

uint8_t GetPlayerRangedDefense() {
	//check whatever
	uint8_t ranged = 10 + PC.dexterity_bonus;
	return ranged;
}

uint8_t GetPlayerMeleeDefense() {
	uint8_t melee = 10 + PC.dexterity_bonus;
	return melee;
}

uint8_t GetPlayerTraumaTarget() {
	//check inventory and edges and whatever
	uint8_t trauma = 6;
	return trauma;
}

uint8_t GetPlayerFort() {//can make this simpler with just returning the right value
	uint8_t fort = 16 - PC.level;
	if (PC.strength_bonus > PC.constitution_bonus) fort -= PC.strength_bonus;
	else fort -= PC.constitution_bonus;
	
	return fort;
}

uint8_t GetPlayerReflex() {
	uint8_t reflex = 16 - PC.level;
	if (PC.dexterity_bonus > PC.intelligence_bonus) reflex -= PC.dexterity_bonus;
	else reflex -= PC.intelligence_bonus;
	
	return reflex;
}

uint8_t GetPlayerWill() {
	uint8_t will = 16 - PC.level;
	if (PC.wisdom_bonus > PC.charisma_bonus) will -= PC.wisdom_bonus;
	else will -= PC.charisma_bonus;
	
	return will;
}

uint8_t GetPlayerLuck() {
	//does anything modify luck?
	return 16 - PC.level;
}

uint32_t GetPlayerEuroDollars() {
	return PC.EuroDollars;
}

uint8_t GetPlayerHeat() {
	return PC.Heat;
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
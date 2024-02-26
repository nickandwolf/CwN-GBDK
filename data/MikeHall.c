//Mike Hall
#include "../src/inc/MainCharacter.h"

void MikeHall_Init() {
	InitalizeCharacter(0);
	SetPlayerName(0, "Mike Hall");
	
	PC[0].level = 1;
    

    PC[0].strength_bonus = 1;
    PC[0].dexterity_bonus = 1;
    PC[0].constitution_bonus = 2;
    PC[0].intelligence_bonus = 2;
    PC[0].wisdom_bonus = 1;
    PC[0].charisma_bonus = 1;

    PC[0].HP = 18;
    PC[0].HP_current = 18;
	
    PC[0].administer = 1;
    PC[0].connect = -1;
    PC[0].drive = -1;
    PC[0].exert = 0;
    PC[0].fix = -1;
    PC[0].heal = -1;
    PC[0].know = 0;
    PC[0].lead = -1;
    PC[0].notice = 0;
    PC[0].perform = -1;
    PC[0].program = -1;
    PC[0].punch = -1;
    PC[0].shoot = -1;
    PC[0].sneak = 1;
    PC[0].stab = -1;
    PC[0].survive = -1;
    PC[0].talk = -1;
    PC[0].trade = -1;
}
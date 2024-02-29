//Mike Hall
#include "../src/inc/MainCharacter.h"

void MikeHall_Init() {
	InitalizeCharacter(0);
	SetPlayerName(0, "Mike Hall");
	SetPlayerAttribute(0, STRENGTH, 10);
	SetPlayerAttribute(0, DEXTERITY, 14);
	SetPlayerAttribute(0, CONSTITUTION, 14);
	SetPlayerAttribute(0, INTELLIGENCE, 10);
	SetPlayerAttribute(0, WISDOM, 14);
	SetPlayerAttribute(0, CHARISMA, 7);
	
	SetPlayerAttributeBonus(0);
}
//Mike Hall
#include "../src/inc/MainCharacter.h"

void MikeHall_Init() {
	InitalizeCharacter();
	SetPlayerName("Mike Hall");
	SetPlayerAttribute(STRENGTH, 10);
	SetPlayerAttribute(DEXTERITY, 10);
	SetPlayerAttribute(CONSTITUTION, 18);
	SetPlayerAttribute(INTELLIGENCE, 10);
	SetPlayerAttribute(WISDOM, 10);
	SetPlayerAttribute(CHARISMA, 10);
	
	SetPlayerEuroDollars(400);
}
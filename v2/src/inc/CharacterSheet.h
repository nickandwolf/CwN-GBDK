#ifndef CHARACTER_SHEET_SCREEN_H
#define CHARACTER_SHEET_SCREEN_H

const enum CharacterSheetNumbers {
	SKILL_MINUS_ONE=352, SKILL_PLUS_MINUS_ZERO, SKILL_PLUS_ONE, SKILL_PLUS_TWO, SKILL_PLUS_THREE, SKILL_PLUS_FOUR,
	LEFT_BLANK, LEFT_PLUS, LEFT_MINUS, LEFT_PLUS_MINUS, LEFT_ONE, LEFT_TWO, LEFT_THREE, LEFT_FOUR, LEFT_FIVE, LEFT_SIX, LEFT_SEVEN, LEFT_EIGHT, LEFT_NINE,
	RIGHT_ZERO, RIGHT_ONE, RIGHT_TWO, RIGHT_THREE, RIGHT_FOUR, RIGHT_FIVE, RIGHT_SIX, RIGHT_SEVEN, RIGHT_EIGHT, RIGHT_NINE,
	ALT_LEFT_BLANK, ALT_LEFT_ONE, ALT_RIGHT_ZERO, ALT_RIGHT_ONE=128, ALT_RIGHT_TWO, ALT_RIGHT_THREE, ALT_RIGHT_FOUR, ALT_RIGHT_FIVE, ALT_RIGHT_SIX, ALT_RIGHT_SEVEN, ALT_RIGHT_EIGHT, ALT_RIGHT_NINE,
	ATTRIBUTE_ZERO, ATTRIBUTE_ONE, ATTRIBUTE_TWO, ATTRIBUTE_THREE, ATTRIBUTE_FOUR, ATTRIBUTE_FIVE,
	EURODOLLAR_BLANK, EURODOLLAR_ZERO, EURODOLLAR_ONE, EURODOLLAR_TWO, EURODOLLAR_THREE, EURODOLLAR_FOUR, EURODOLLAR_FIVE, EURODOLLAR_SIX, EURODOLLAR_SEVEN, EURODOLLAR_EIGHT, EURODOLLAR_NINE,
	SQUARE_SWORD, SQUARE_GUN, SQUARE_SHIELD, SQUARE_POTION, SQUARE_KEY, SQUARE_BACKPACK, SQUARE_X, SQUARE_QUESTION, SQUARE_HYPHEN
};

const enum CharacterSheetPointerStates {
	CHARACTER_CS, BRIEFING_CS,      BRIEFING_again_CS,  	NOTES_CS,       HELP_CS,          //4 (5)
    LEVEL_CS,	ATTRIBUTES_CS,		ATTRIBUTES_again_CS,	FORT_CS,		ATTACK_BONUS_CS,  //9
	SP_CS,		STRENGTH_CS,		INTELLIGENCE_CS,		REFLEX_CS,		RANGED_DEFENSE_CS,//14
	HP_CS,		DEXTERITY_CS,		WISDOM_CS,				WILLPOWER_CS,	MELEE_DEFENSE_CS, //19
	SS_CS,		CONSTITUTION_CS,	CHARISMA_CS,			LUCK_CS,		TRAUMA_CS,        //24 (5)
	EURODOLLARS_CS, EURODOLLARS_again_CS,//25,26   //46_INVENTORY
	ADMIN_CS,	PERFORM_CS,    //27,28             //46_INVENTORY
	CONNECT_CS,	PROGRAM_CS,    //29,30             //46_INVENTORY
	DRIVE_CS,	PUNCH_CS,      //31,32             //46_INVENTORY
	EXERT_CS,	SHOOT_CS,      //33,34             //46_INVENTORY
	FIX_CS,		SNEAK_CS,      //35,36             //46_INVENTORY
	HEAL_CS,	STAB_CS,       //37,38             //46_INVENTORY
	KNOW_CS,	SURVIVE_CS,    //39,40             //46_INVENTORY
	LEAD_CS,	TALK_CS,       //41,42             //46_INVENTORY
	NOTICE_CS,	TRADE_CS,      //43,44             //46_INVENTORY
	HEAT_CS, INVENTORY_CS      //45_HEAT           //46_INVENTORY
};

extern uint8_t charSheetIntro;

void InitCharacterSheet(void);
void UpdateCharacterSheetStats(void);
uint8_t CharacterSheetUpdate(void);
uint8_t CharacterSheetPointerUpdate(void);
uint8_t CharacterSheetInventoryPointerUpdate(void);
void CharacterSheetGetInfo(void);
void DefineSheetStat(void);


#endif
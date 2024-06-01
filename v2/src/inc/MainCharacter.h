/*
START STATIC
Get basic shit to work

then GET DYNAMIC
and start improving things and calculating HP/SS

SHIT GOTTA DO LEVEL UPS
*/

#ifndef MAIN_CHARACTER_H
#define MAIN_CHARACTER_H

#include <stdint.h>

//CHARACTER SHIT
/*
typedef struct Contact {
	char* name;
	char* background;
	char* social_circle;
	char* last_significant_interaction;
	char* what_do_they_get_outta_this;
	char* how_well_do_you_know_them;
	char* how_did_you_first_meet;
	char* what_can_they_do_for_you;
	//uint8_t friend;
} contact;
*/

typedef struct Character {
    char *name;
    //uint8_t background;

    uint8_t strength;
    uint8_t dexterity;
    uint8_t constitution;
    uint8_t intelligence;
    uint8_t wisdom;
    uint8_t charisma;

    int8_t strength_bonus;
    int8_t dexterity_bonus;
    int8_t constitution_bonus;
    int8_t intelligence_bonus;
    int8_t wisdom_bonus;
    int8_t charisma_bonus;

    int8_t admin;
    int8_t connect;
    int8_t drive;
    int8_t exert;
    int8_t fix;
    int8_t heal;
    int8_t know;
    int8_t lead;
    int8_t notice;
    int8_t perform;
    int8_t program;
    int8_t punch;
    int8_t shoot;
    int8_t sneak;
    int8_t stab;
    int8_t survive;
    int8_t talk;
    int8_t trade;
    int8_t work;

    int8_t HP;
    int8_t HP_current;

    uint8_t SS;
    uint8_t SS_current;

    uint8_t SP;
    uint8_t level;
	uint8_t Attribute_boosts;
    //uint8_t edges[4];
    //uint8_t foci[6];
	//char* contacts;
	
	uint32_t EuroDollars;
	uint8_t Heat;

} character;

const enum Attributes {ATTRIBUTE_NONE, STRENGTH, DEXTERITY, CONSTITUTION, INTELLIGENCE, WISDOM, CHARISMA};

const enum Skills {SKILL_NONE, ADMIN, CONNECT, DRIVE, EXERT, FIX, HEAL, KNOW, LEAD, NOTICE, PERFORM, PROGRAM, PUNCH, SHOOT, SNEAK, STAB, SURVIVE, TALK, TRADE, WORK};

//const enum Backgrounds {BACKGROUND_NONE, BUM, BUREAUCRAT, CLERGY, CODER, CORP_SECURITY, CORPER, CRIMINAL, DOCTOR, DRONE_JOCKEY, GANGER, LABORER, LAW_ENFORCEMENT, MANAGER, OUTLANDER, PERFORMER, SOLDIER, SPY, TRADER, STREETWALKER, TECHNICIAN};

//const enum Edges {EDGE_NONE, EDUCATED, FACE, FOCUSED, GHOST, HACKER, HARD_TO_KILL, MASTERFUL_EXPERTISE, ON_TARGET, PRODIGY_STR, PRODIGY_DEX, PRODIGY_CON, PRODIGY_INT, PRODIGY_WIS, PRODIGY_CHA, OPERATORS_FORTUNE, VETERANS_LUCK, VOICE_OF_THE_PEOPLE, WIRED};

//const enum Foci {FOCI_NONE, ACE_DRIVE1, ACE_DRIVER2, ALERT1, ALERT2, ALL_NATURAL, ARMSMASTER1, ARMSMASTER2, ASSASSIN1, ASSASSIN2, AUTHORITY1, AUTHORITY2, CLOSE_COMBATANT1, CLOSE_COMBATANT2, CYBERDOC1, CYBERDOC2, DEADEYE1, DEADEYE2, DIPLOMAT1, DIPLOMAT2, DRONE_PILOT1, DRONE_PILOT2, EXPERT_PROGRAMMER1, EXPERT_PROGRAMMER2, HEALER1, HEALER2, HENCHKEEPER1, HENCHKEEPER2, MANY_FACES, POP_IDOL1, POP_IDOL2, ROAMER1, ROAMER2, SAFE_HAVEN1, SAFE_HAVEN2, SHOCKING_ASSAULT1, SHOCKING_ASSAULT2, SNIPERS_EYE1, SNIPERS_EYE2, SPECIALIST1, SPECIALIST2, TINKER1, TINKER2};

//set functions
void InitalizeCharacter(void);
void SetPlayerName(char *name);
void SetPlayerAttribute(uint8_t attribute, uint8_t value);
void SetPlayerAttributeBonus(void);
void SetPlayerSkill(uint8_t skill, int8_t value);

void SetPlayerHP(void);
uint8_t SetPlayerHP_Current(int8_t value);

uint8_t SetPlayerEuroDollars(int32_t value);
void SetPlayerHeat(int8_t value);

//improve functions
uint8_t ImprovePlayerAttribute(uint8_t attribute, uint8_t type);//type is 0 = any, 1 = phys, 2 = mental
uint8_t ImprovePlayerSkill(uint8_t skill);
void LevelPlayerUp(void);
void SpendPlayerSP(uint8_t stat_type, uint8_t stat);

//void SetPlayerBackground(uint8_t p, enum Backgrounds background);
//void InitPlayerBackground(uint8_t p);

//void SetPlayerEdge(uint8_t p, uint8_t edge);

//get functions
char* GetPlayerName(void);

uint8_t GetPlayerAttribute(uint8_t attribute);
int8_t GetPlayerAttributeBonus(uint8_t attribute);
int8_t GetPlayerSkill(uint8_t skill);

uint8_t GetPlayerLevel(void);
uint8_t GetPlayerSP(void);
uint8_t GetPlayerAttributeBoosts(void);
uint8_t GetPlayerSP_Cost(uint8_t stat_type, uint8_t stat);

uint8_t GetPlayerHP(void);
uint8_t GetPlayerHP_Current(void);
uint8_t GetPlayerSS(void);
uint8_t GetPlayerSS_Current(void);

uint8_t GetPlayerAttack(void);
uint8_t GetPlayerRangedDefense(void);
uint8_t GetPlayerMeleeDefense(void);
uint8_t GetPlayerTraumaTarget(void);

uint8_t GetPlayerFort(void);
uint8_t GetPlayerReflex(void);
uint8_t GetPlayerWill(void);
uint8_t GetPlayerLuck(void);

uint32_t GetPlayerEuroDollars(void);
uint8_t GetPlayerHeat(void);

//PROGRAMMING SHIT
extern uint8_t facing;
extern uint8_t frame;
extern int8_t playerX;
extern int8_t playerY; //the initialization will have to handle that
extern int8_t playerMapX; //gonna sound weird but maps start at 1
extern int8_t playerMapY;
extern uint8_t playerState;

const enum PLAYER_STATES {OVERWORLD, PLAYER_MOVING};//add more as we go.

const enum Main_Char_Tiles {PC_F_IDLE = 33, PC_F_WALK = 37, PC_B_IDLE = 41, PC_B_WALK = 45, PC_S_IDLE = 49, PC_S_WALK = 53};

void InitCharacterSprite(void);
void AnimateCharacterSprite(void);

#endif
#ifndef KEYS_H
#define KEYS_H

#define TILES 16
#define MAP_WIDTH 20
#define MAP_HEIGHT 18
const enum GAME_STATE_SCENES {CHAR_SHEET_STATE, PAUSE_SCREEN_STATE, TITLE_SCREEN_STATE, HOSPITAL_1_STATE, APARTMENT_1_STATE};

void MainCharacterUpdate(void);
void PlacePlayer(void);
int8_t CheckCollision(void);

#endif
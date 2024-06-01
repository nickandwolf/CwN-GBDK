#ifndef MAIN_H
#define MAIN_H

#define TILES 16
#define MAP_WIDTH 20
#define MAP_HEIGHT 18

extern uint8_t mission;

void MainCharacterUpdate(void);
void PlacePlayer(void);
int8_t CheckCollision(void);

#endif
#ifndef DICE_ROLL_H
#define DICE_ROLL_H

//TODO: I think I can get rid of the END
const enum Dice {D4 = 16, D6 = 32, D8 = 56, D10 = 88, D12 = 128, D20 = 176};

uint8_t RollDie(uint8_t die);

void InitDiceData(void);

#endif
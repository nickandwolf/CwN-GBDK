#ifndef SPLASH_SCREEN_H
#define SPLASH_SCREEN_H

#define U_LESS_THAN(A, B) ((A) - (B) & 0x8000u)
#define PAL_DEF(C3, C2, C1, C0) ((C0 << 4 << 2) | (C1 << 4) | (C2 << 2) | C3)

void InitSplashScreen(void);


void FadeDMG(uint8_t fadeout, uint8_t taim);
void FadeOutDMG(uint8_t taim);
void FadeInDMG(uint8_t taim);
uint8_t FadeInOp(int16_t c, int16_t i);
int16_t DespRight(int16_t a, int16_t b);

#endif
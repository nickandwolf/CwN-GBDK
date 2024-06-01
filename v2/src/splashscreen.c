#include <stdint.h>
#include <gb/gb.h>
#include "../res/NickAndWolf_tiles.h"
#include "../res/NickAndWolf_map.h"
#include "inc/textFunctions.h"
#include "inc/splashscreen.h"

void InitSplashScreen() {
	HIDE_BKG;
	HIDE_WIN;
	HIDE_SPRITES;
	
	set_bkg_data(0,105,NickAndWolf_tiles);
	set_bkg_tiles(2,2,16,16,NickAndWolf_map);
	SHOW_BKG;
	
	//FadeInDMG(10);
	VBlankDelay(120)
	//FadeOutDMG(10);
	
	HIDE_BKG;
}

void FadeDMG(uint8_t fadeout, uint8_t taim) {
	uint8_t colors[12];
	uint8_t* pals[] = {(uint8_t*)0xFF47, (uint8_t*)0xFF48, (uint8_t*)0xFF49};
	uint8_t i, j; 
	uint8_t* c = colors;
	uint8_t p;

	//Pick current palette colors
	for(i = 0; i != 3; ++i) {
		p = (uint8_t)*(pals[i]);
		for(j = 0; j != 8; j += 2, ++c) {
			*c = (DespRight(p, j)) & 0x3;
		}
	}

	for(i = 0; i != 4; ++i) {
		p = fadeout ? 3 - i : i;
		for(j = 0; j != 3; ++j) {
			c = &colors[j << 2];
			*pals[j] = PAL_DEF(FadeInOp(c[0], p), FadeInOp(c[1], p), FadeInOp(c[2], p), FadeInOp(c[3], p));
		}
		VBlankDelay(taim);
	}
}

void FadeOutDMG(uint8_t taim) {
	FadeDMG(0,taim);
}

void FadeInDMG(uint8_t taim) {
	FadeDMG(1,taim);
}

uint8_t FadeInOp(int16_t c, int16_t i) {
	return U_LESS_THAN(c, i) ? 0: (c - i);
}

int16_t DespRight(int16_t a, int16_t b) {
	return a >> b;
}
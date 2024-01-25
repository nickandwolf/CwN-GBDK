#include "../res/NickAndWolf_tiles.h"
#include "../res/NickAndWolf_map.h"
#include "inc/splashscreen.h"
#include <gb/gb.h>

char skip = 0;

void InitSplashScreen() {
	set_bkg_data(0,105,NickAndWolf_tiles);
	set_bkg_tiles(2,2,16,16,NickAndWolf_map);
	
	SHOW_BKG;
}

void UpdateSplashScreen() {
	
}
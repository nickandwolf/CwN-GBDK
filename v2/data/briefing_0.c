#include <stdint.h>
#include <gb/gb.h>
#include "inc/title_1.h"

#include "../src/inc/textFunctions.h"
#include "../src/inc/gameStatesEnum.h"

#include "../res/briefing_tiles.h"
#include "../res/briefing_0_map.h"
#include "../res/CustomFont.h"

void InitBriefing_0(void) {
	HIDE_BKG;
	HIDE_WIN;
	HIDE_SPRITES;
	//BKG
	set_bkg_data(0, 113, briefing_tiles);
	set_bkg_tiles(0,0,20,18,briefing_0_map);
	
	set_sprite_data(0,65,CustomFont);
	SHOW_BKG;
	
	//SPRITES
	//arrow
	set_sprite_tile(0, 6);
	
	move_sprite(0, 8, 80);
	
	//new game
	set_sprite_tile(1, 39);
	set_sprite_tile(2, 30);
	set_sprite_tile(3, 48);
	set_sprite_tile(4, 0);
	set_sprite_tile(5, 32);
	set_sprite_tile(6, 26);
	set_sprite_tile(7, 38);
	set_sprite_tile(8, 30);
	
	move_sprite(1, 16, 80);
	move_sprite(2, 24, 80);
	move_sprite(3, 32, 80);
	move_sprite(4, 40, 80);
	move_sprite(5, 48, 80);
	move_sprite(6, 56, 80);
	move_sprite(7, 64, 80);
	move_sprite(8, 72, 80);
	
	//continue
	set_sprite_tile(9, 28);
	set_sprite_tile(10, 40);
	set_sprite_tile(11, 39);
	set_sprite_tile(12, 45);
	set_sprite_tile(13, 34);
	set_sprite_tile(14, 39);
	set_sprite_tile(15, 46);
	set_sprite_tile(16, 30);
	
	move_sprite(9, 16, 96);
	move_sprite(10, 24, 96);
	move_sprite(11, 32, 96);
	move_sprite(12, 40, 96);
	move_sprite(13, 48, 96);
	move_sprite(14, 56, 96);
	move_sprite(15, 64, 96);
	move_sprite(16, 72, 96);
	
	
	SHOW_SPRITES;
}
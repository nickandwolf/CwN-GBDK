#include <stdint.h>
#include <gb/gb.h>
#include "../src/inc/textFunctions.h"
#include "../src/inc/main.h"
#include "../src/inc/Font.h"

#include "../res/hospital_1_tiles.h"
#include "../res/hospital_1_map.h"
#include "../res/CustomFont_white.h"

#include "inc/hospital_1.h"

char pointerH1 = 0;

void InitHospital_1() {
	HIDE_BKG;
	HIDE_WIN;
	HIDE_SPRITES;
	
	//BKG
	set_bkg_data(0, 116, Hospital_1_tiles);
	set_bkg_tiles(0,0,20,18,Hospital_1_map);
	
	//set_sprite_data(0,59,CustomFont_white);
	SHOW_BKG;

}
	/*
	//SPRITES
	//arrow
	set_sprite_tile(0, 6);
	
	move_sprite(0, 8, 78);
	
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
}*/

uint8_t Hospital_1_Update() {
	switch(pointerH1) {
		case 0:
			InitHospital_1();
			pointerH1 = 1;
		break;
		
		case 1:
			dialog_print_p("mike", sizeof("mike"), "so how does it    look/", sizeof("so how does it    look/"));
			pointerH1 = 2;
			return 0;
		break;
		
		case 2:
			dialog_print_p("doctor", sizeof("doctor"), "i'm afraid it has spread through your bloodstream. we can operate but your insurance is only for basic care.", sizeof("i'm afraid it has spread through your bloodstream. we can operate but your insurance is only for basic care."));
			
			dialog_print_p("mike", sizeof("mike"), "how much would it cost/", sizeof("how much would it cost/"));
			
			dialog_print_p("doctor", sizeof("doctor"), "for the nanites, surgery, and therapy#$255,000.", sizeof("for the nanites, surgery, and therapy#$255,000."));
			
			dialog_print_p("mike", sizeof("mike"), "#how much time do i have/", sizeof("#how much time do i have/"));
			
			dialog_print_p("doctor", sizeof("doctor"), "between four days and two weeks.", sizeof("between four days and two weeks."));
			
			dialog_print_p("mike", sizeof("mike"), "# #", sizeof("# #"));
			
			dialog_print_p("doctor", sizeof("doctor"), "#", sizeof("#"));
			
			return APARTMENT_1_STATE;
			
		break;
	}
	
	return HOSPITAL_1_STATE;

}
#include <stdint.h>
#include <gb/gb.h>
#include "../src/inc/textFunctions.h"
#include "../src/inc/gameStatesEnum.h"
#include "../src/inc/Font.h"

#include "../res/hospital_1_tiles.h"
#include "../res/hospital_1_map.h"
#include "../res/CustomFont_white.h"

#include "inc/hospital_1.h"

uint8_t pointerH1 = 0;

void InitHospital_1() {
	HIDE_BKG;
	HIDE_WIN;
	HIDE_SPRITES;
	
	//BKG
	set_bkg_data(0, 152, Hospital_1_tiles);
	set_bkg_tiles(0,0,20,18,Hospital_1_map);
	
	SHOW_BKG;

}

uint8_t Hospital_1_Update() {
	switch(pointerH1) {
		case 0:
			InitHospital_1();
			pointerH1 = 1;
		break;
		
		case 1:
			dialog_print_p("mike", sizeof("mike"), "so how does it    look/", sizeof("so how does it    look/"));
			pointerH1 = 2;
			return CHAR_SHEET_STATE;
		break;
		
		case 2:
			InitHospital_1();
			pointerH1 = 3;
		break;
		
		case 3:
			//doctor
			set_bkg_tile_xy(13,4,144);
			set_bkg_tile_xy(13,5,145);
			set_bkg_tile_xy(14,5,146);
			set_bkg_tile_xy(13,6,147);
			set_bkg_tile_xy(14,6,148);
			set_bkg_tile_xy(13,7,149);
			set_bkg_tile_xy(14,7,150);
			
			dialog_print_p("doctor", sizeof("doctor"), "i'm afraid it has spread through    your bloodstream. we can operate but your insurance is only for basic    care.", sizeof("i'm afraid it has spread through    your bloodstream. we can operate but your insurance is only for basic    care."));
			
			//doctor
			set_bkg_tile_xy(13,4,291);
			
			//mike - open hand
			set_bkg_tile_xy(2,7,138);
			set_bkg_tile_xy(3,7,139);
			set_bkg_tile_xy(2,6,136);
			set_bkg_tile_xy(3,6,137);
			
			dialog_print_p("mike", sizeof("mike"), "how much would it cost/", sizeof("how much would it cost/"));
			
			//doctor
			set_bkg_tile_xy(13,4,144);
			
			dialog_print_p("doctor", sizeof("doctor"), "for the nanites,  surgery, and      therapy#$255,000.", sizeof("for the nanites,  surgery, and      therapy#$255,000."));
			
			//doctor
			set_bkg_tile_xy(13,4,291);
			
			//mike - fist
			set_bkg_tile_xy(2,6,140);
			set_bkg_tile_xy(3,6,141);
			set_bkg_tile_xy(2,7,142);
			set_bkg_tile_xy(3,7,143);
			
			dialog_print_p("mike", sizeof("mike"), "#how much time do i have/", sizeof("#how much time do i have/"));
			dialog_print_p("doctor", sizeof("doctor"), "between four days and two weeks.", sizeof("between four days and two weeks."));
			
			//mike - head down
			set_bkg_tile_xy(0,4,130);
			set_bkg_tile_xy(1,4,131);
			set_bkg_tile_xy(2,4,132);
			set_bkg_tile_xy(0,5,133);
			set_bkg_tile_xy(1,5,134);
			set_bkg_tile_xy(2,5,135);
			
			dialog_print_p("mike", sizeof("mike"), "# #", sizeof("# #"));
			
			//doctor
			set_bkg_tile_xy(13,4,144);
			set_bkg_tile_xy(13,5,303);
			set_bkg_tile_xy(14,5,304);
			set_bkg_tile_xy(13,6,323);
			set_bkg_tile_xy(14,6,324);
			set_bkg_tile_xy(13,7,340);
			set_bkg_tile_xy(14,7,341);
			
			dialog_print_p("doctor", sizeof("doctor"), "# # #", sizeof("# # #"));
			
			return APARTMENT_1_STATE;
			
		break;
	}
	
	return HOSPITAL_1_STATE;

}
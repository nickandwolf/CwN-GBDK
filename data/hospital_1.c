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
	set_bkg_data(0, 187, Hospital_1_tiles);
	set_bkg_tiles(0,0,20,18,Hospital_1_map);
	
	//set_sprite_data(0,59,CustomFont_white);
	SHOW_BKG;

}

uint8_t Hospital_1_Update() {
	switch(pointerH1) {
		case 0:
			InitHospital_1();
			pointerH1 = 1;
		break;
		
		case 1:
			//graphics start at 372 for cutscenes and shit
			dialog_print_p("mike", sizeof("mike"), "so how does it    look/", sizeof("so how does it    look/"));
			pointerH1 = 2;
			return 0;
		break;
		
		case 2:
			InitHospital_1();
			pointerH1 = 3;
		break;
		
		case 3:
			dialog_print_p("doctor", sizeof("doctor"), "i'm afraid it has spread through    your bloodstream. we can operate but your insurance is only for basic    care.", sizeof("i'm afraid it has spread through    your bloodstream. we can operate but your insurance is only for basic    care."));
			
			dialog_print_p("mike", sizeof("mike"), "how much would it cost/", sizeof("how much would it cost/"));
			
			dialog_print_p("doctor", sizeof("doctor"), "for the nanites,  surgery, and      therapy#$255,000.", sizeof("for the nanites,  surgery, and      therapy#$255,000."));
			
			dialog_print_p("mike", sizeof("mike"), "#how much time do i have/", sizeof("#how much time do i have/"));
			
			dialog_print_p("doctor", sizeof("doctor"), "between four days and two weeks.", sizeof("between four days and two weeks."));
			
			dialog_print_p("mike", sizeof("mike"), "# #", sizeof("# #"));
			
			dialog_print_p("doctor", sizeof("doctor"), "#", sizeof("#"));
			
			return APARTMENT_1_STATE;
			
		break;
	}
	
	return HOSPITAL_1_STATE;

}
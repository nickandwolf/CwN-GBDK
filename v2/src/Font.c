#include <stdint.h>
#include <gb/gb.h>
#include <gbdk/platform.h>

#include "inc/textFunctions.h"
#include "inc/Font.h"
#include "inc/MainCharacter.h"

#include "../res/dialog_frame.h"
#include "../res/CustomFont.h"

uint8_t DIALOG_DELAY = 1;

/*

question mark 	= /
elipses 		= #
coin			= $
more dialog		= &
end dialog		= *
*/

const unsigned char Font_symbols[25] = {
	'!', '"', '#', '$', '%', '&', 39, '(', ')', '*', '+', ',', '-', '.', '/',
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
};

void dialog_init() {
	set_win_data(0xBF,65,CustomFont);
	init_win(_BLANK_);//wipe the screen
	set_win_tiles(0,0,20,5,dialog_frame);//throw up a fresh border
	SHOW_WIN;//display to the world
}

void dialog_level_up_print_helper(void) {
	set_win_tile_xy(1,1,_U_);//5 character displacement (move it to the left)
	set_win_tile_xy(2,1,_P_);
	set_win_tile_xy(3,1,_G_);
	set_win_tile_xy(4,1,_R_);
	set_win_tile_xy(5,1,_A_);
	set_win_tile_xy(6,1,_D_);
	set_win_tile_xy(7,1,_E_);
	//newline
	set_win_tile_xy(6,2,_ARROW_);
	//new line
	set_win_tile_xy(12,3,_C_);
	set_win_tile_xy(13,3,_O_);
	set_win_tile_xy(14,3,_S_);
	set_win_tile_xy(15,3,_T_);
}

//TODO:clean this up with the ENUM
uint8_t dialog_level_up_print(uint8_t stat, int8_t value, uint8_t cost) {
	if (stat == 0) return 0;
	else if ((stat < 7 && value == 18) || (stat > 6 && value == 4)) {
		dialog_print("this attribute is maxed out!", sizeof("this attribute is maxed out!"));
		return 0;
	}
	
	dialog_init();
	
	//We wanna scroll up so we set the end point and move there
	uint8_t y = 160;
	while (y > DIALOG_WIN_HEIGHT) {
		move_win(7,y);
		y-=3;//the means the window could end up in the wrong spot, we correct that below
		//VBlankDelay(DIALOG_DELAY)
		vsync();
	}
	move_win(7,DIALOG_WIN_HEIGHT); //then we make sure it ends where it's supposed to be
	
	//we need to hide the player if he's in the wrong spot.
	int8_t tempPlayerY = 160; //TODO: All sprites will need to do this...
	if (playerY > DIALOG_WIN_HEIGHT-12) {
		move_sprite(0, playerX+8, tempPlayerY+16);
        move_sprite(2, playerX+16, tempPlayerY+16);
	}
	dialog_level_up_print_helper();
	
	//display current value and future value
	if (stat < 7) {
		//initial value tens then ones
		set_win_tile_xy(3,2,_ZERO_+(value/10));
		set_win_tile_xy(4,2,_ZERO_+(value%10));
		
		value++;
		
		//upgraded value tens then ones
		set_win_tile_xy(8,2,_ZERO_+(value/10));
		set_win_tile_xy(9,2,_ZERO_+(value%10));
	}
	else {//gotta detect negative numbers and put the correct value here
		if (value < 0) {
			set_win_tile_xy(3,2,_DASH_);//negative sign
			set_win_tile_xy(4,2,value*-1+_ZERO_);//inverse value
		}
		else {
			set_win_tile_xy(3,2,_PLUS_);
			set_win_tile_xy(4,2,value+_ZERO_);
		}
		value++;
		set_win_tile_xy(8,2,_PLUS_);
		set_win_tile_xy(9,2,value+_ZERO_);
	}
	
	//cost
	set_win_tile_xy(17,3,cost+_ZERO_);
	
	switch (stat) {
		case 0:
			//error
		break;
		
		case 1://ST
			set_win_tile_xy(9,1,_S_);
			set_win_tile_xy(10,1,_T_);
			set_win_tile_xy(11,1,_QUESTION_);
		break;
		
		case 2://DX
			set_win_tile_xy(9,1,_D_);
			set_win_tile_xy(10,1,_X_);
			set_win_tile_xy(11,1,_QUESTION_);
		break;
		
		case 3://CO
			set_win_tile_xy(9,1,_C_);
			set_win_tile_xy(10,1,_O_);
			set_win_tile_xy(11,1,_QUESTION_);
		break;
		
		case 4://IN
			set_win_tile_xy(9,1,_I_);
			set_win_tile_xy(10,1,_N_);
			set_win_tile_xy(11,1,_QUESTION_);
		break;
		
		case 5://WI
			set_win_tile_xy(9,1,_W_);
			set_win_tile_xy(10,1,_I_);
			set_win_tile_xy(11,1,_QUESTION_);
		break;
		
		case 6://CH
			set_win_tile_xy(9,1,_C_);
			set_win_tile_xy(10,1,_H_);
			set_win_tile_xy(11,1,_QUESTION_);
		break;
		
		case 7://ADM
			set_win_tile_xy(9,1,_A_);
			set_win_tile_xy(10,1,_D_);
			set_win_tile_xy(11,1,_M_);
			set_win_tile_xy(12,1,_QUESTION_);
		break;
		
		case 8://CON
			set_win_tile_xy(9,1,_C_);
			set_win_tile_xy(10,1,_O_);
			set_win_tile_xy(11,1,_N_);
			set_win_tile_xy(12,1,_QUESTION_);
		break;
		
		case 9://DRV
			set_win_tile_xy(9,1,_D_);
			set_win_tile_xy(10,1,_R_);
			set_win_tile_xy(11,1,_V_);
			set_win_tile_xy(12,1,_QUESTION_);
		break;
		
		case 10://EXR
			set_win_tile_xy(9,1,_E_);
			set_win_tile_xy(10,1,_X_);
			set_win_tile_xy(11,1,_R_);
			set_win_tile_xy(12,1,_QUESTION_);
		break;
		
		case 11://FIX
			set_win_tile_xy(9,1,_F_);
			set_win_tile_xy(10,1,_I_);
			set_win_tile_xy(11,1,_X_);
			set_win_tile_xy(12,1,_QUESTION_);
		break;
		
		case 12://HEA
			set_win_tile_xy(9,1,_H_);
			set_win_tile_xy(10,1,_E_);
			set_win_tile_xy(11,1,_A_);
			set_win_tile_xy(12,1,_QUESTION_);
		break;
		
		case 13://KNO
			set_win_tile_xy(9,1,_K_);
			set_win_tile_xy(10,1,_N_);
			set_win_tile_xy(11,1,_O_);
			set_win_tile_xy(12,1,_QUESTION_);
		break;
		
		case 14://LEA
			set_win_tile_xy(9,1,_L_);
			set_win_tile_xy(10,1,_E_);
			set_win_tile_xy(11,1,_A_);
			set_win_tile_xy(12,1,_QUESTION_);
		break;
		
		case 15://NTC
			set_win_tile_xy(9,1,_N_);
			set_win_tile_xy(10,1,_T_);
			set_win_tile_xy(11,1,_C_);
			set_win_tile_xy(12,1,_QUESTION_);
		break;
		
		case 16://PRF
			set_win_tile_xy(9,1,_P_);
			set_win_tile_xy(10,1,_R_);
			set_win_tile_xy(11,1,_F_);
			set_win_tile_xy(12,1,_QUESTION_);
		break;
		
		case 17://PRG
			set_win_tile_xy(9,1,_P_);
			set_win_tile_xy(10,1,_R_);
			set_win_tile_xy(11,1,_G_);
			set_win_tile_xy(12,1,_QUESTION_);
		break;
		
		case 18://PNC
			set_win_tile_xy(9,1,_P_);
			set_win_tile_xy(10,1,_N_);
			set_win_tile_xy(11,1,_C_);
			set_win_tile_xy(12,1,_QUESTION_);
		break;
		
		case 19://SHT
			set_win_tile_xy(9,1,_S_);
			set_win_tile_xy(10,1,_H_);
			set_win_tile_xy(11,1,_T_);
			set_win_tile_xy(12,1,_QUESTION_);
		break;
		
		case 20://SNK
			set_win_tile_xy(9,1,_S_);
			set_win_tile_xy(10,1,_N_);
			set_win_tile_xy(11,1,_K_);
			set_win_tile_xy(12,1,_QUESTION_);
		break;
		
		case 21://STb
			set_win_tile_xy(9,1,_S_);
			set_win_tile_xy(10,1,_T_);
			set_win_tile_xy(11,1,_B_);
			set_win_tile_xy(12,1,_QUESTION_);
		break;
		
		case 22://SRV
			set_win_tile_xy(9,1,_S_);
			set_win_tile_xy(10,1,_R_);
			set_win_tile_xy(11,1,_V_);
			set_win_tile_xy(12,1,_QUESTION_);
		break;
		
		case 23://TLK
			set_win_tile_xy(9,1,_T_);
			set_win_tile_xy(10,1,_L_);
			set_win_tile_xy(11,1,_K_);
			set_win_tile_xy(12,1,_QUESTION_);
		break;
		
		case 24://TRD
			set_win_tile_xy(9,1,_T_);
			set_win_tile_xy(10,1,_R_);
			set_win_tile_xy(11,1,_D_);
			set_win_tile_xy(12,1,_QUESTION_);
		break;
	}
	
	//we don't have buttons to accidentially close dialog
	//set_win_tile_xy(19,3,_END_);
	waitpadup();
	UPDATE_KEYS();
	
	//insert control here
	//YES
	set_win_tile_xy(13, 0, _Y_);
	set_win_tile_xy(14, 0, _E_);
	set_win_tile_xy(15, 0, _S_);
	
	//NO
	set_win_tile_xy(17, 0, _N_);
	set_win_tile_xy(18, 0, _O_);
	
	uint8_t choice_pointer = 1;//option 1 = 1; option 2 = 0;
	uint8_t actual_choice = 1;
	
	while (actual_choice) {	
		if (KEY_TICKED(J_RIGHT) || KEY_TICKED(J_LEFT)) {
			if (choice_pointer) choice_pointer = 0;
			else choice_pointer = 1;
		}
		if (KEY_TICKED(J_A)) actual_choice = 0;
		
		if (choice_pointer) {
			set_win_tile_xy(12,0,_ARROW_);
			set_win_tile_xy(16,0,_RIGHT_BAR_+1);
		}
		else {
			set_win_tile_xy(12,0,_TOP_BAR_);
			set_win_tile_xy(16,0,_ARROW_);
		}
		UPDATE_KEYS();
	}
	
	//put player back
	if (playerY > DIALOG_WIN_HEIGHT-12) {
		move_sprite(0, playerX+8, playerY+16);
        move_sprite(2, playerX+16, playerY+16);
	}
	
	//scroll it back down!
	y = DIALOG_WIN_HEIGHT;
	while (y < 160) {
		move_win(7,y);
		y+=3;
		//VBlankDelay(DIALOG_DELAY)
		vsync();
	}
	move_win(7,160);
	HIDE_WIN;
	
	return choice_pointer;
}

uint8_t dialog_yes_no_print(unsigned char *text, uint8_t size, unsigned char *choice1, uint8_t choice1_size, unsigned char *choice2, uint8_t choice2_size) {
	dialog_init();
	
	//We wanna scroll up so we set the end point and move there
	uint8_t y = 160;
	while (y > DIALOG_WIN_HEIGHT) {
		move_win(7,y);
		y-=3;//the means the window could end up in the wrong spot, we correct that below
		//VBlankDelay(DIALOG_DELAY)
		vsync();
	}
	move_win(7,DIALOG_WIN_HEIGHT); //then we make sure it ends where it's supposed to be
	
	//we need to hide the player if he's in the wrong spot.
	int8_t tempPlayerY = 160; //TODO: All sprites will need to do this...
	if (playerY > DIALOG_WIN_HEIGHT-12) {
		move_sprite(0, playerX+8, tempPlayerY+16);
        move_sprite(2, playerX+16, tempPlayerY+16);
	}
	
	
    // This is an imaginary cursor.
	uint8_t xpos=0, ypos=0;
    // This is the string index.
	uint8_t index=0;

	while (index-0<(size-1))
	{
		//fix glitched text by putting correct right border.
		set_win_tile_xy(19,3,_RIGHT_BAR_);
		
        // This do a line jump if there's no more space on tile width (can be personalized).
		if (xpos % DIALOG_WIDTH == 0) {xpos=1; ypos++;}
		else xpos++;

        // This is the string index.
		(xpos == 1 && text[index] == ' ')?index++:index;

        // This put a - sign if there's no width space and a word isn't finished.
		if (xpos == DIALOG_WIDTH && text[index] != ' ' && text[index+1] != ' ') {
			set_win_tile_xy(xpos, ypos, ('-'-0x20+Font_sprite_start)); xpos=1; ypos++;
		}
		
		(xpos == 1 && text[index] == ' ')?index++:index;
        
		// This variable sets the current character of the string based on its index.
		const unsigned char *current = &text[index];
		
        // This fills the canvas with an empty tile if there's no more space.
        // Note that it uses the 0x00 tile.
		if (ypos > DIALOG_HEIGHT) {
				set_win_tile_xy(19,3,_ARROW_);
				waitpadup();
				waitpad(J_A);
				//init_win(0xCC);
				fill_win_rect(DIALOG_INIT_X, DIALOG_INIT_Y, DIALOG_WIDTH, DIALOG_HEIGHT, _BLANK_);
				xpos=ypos=1;
				set_win_tile_xy(19,3,_RIGHT_BAR_);
			}

        // This print the letters.
		if (*current != ' ') set_win_tile_xy(xpos, ypos, (*current-0x47+Font_sprite_start));
		
		
        // This print the symbols.
		for (uint8_t i=0; i<(sizeof(Font_symbols)); i++)
			if (*current == Font_symbols[i]) set_win_tile_xy(xpos, ypos, (*current-0x20+Font_sprite_start));
		
        VBlankDelay(DIALOG_DELAY);

		index++;
	}
	
	//we don't have buttons to accidentially close dialog
	set_win_tile_xy(19,3,_END_);
	waitpadup();
	UPDATE_KEYS();
	
	//insert control here
	uint8_t choice1_place = choice1_size-1;
	uint8_t choice2_place = choice2_size-1;
	
	uint8_t choice_index = 0;
	
	while (choice_index < choice1_size-1) {
		const unsigned char *choice1_current = &choice1[choice_index];
		set_win_tile_xy(19-choice1_place-choice2_place-1, 0, (*choice1_current-0x47+Font_sprite_start));
		choice_index++;
		choice1_place--;
	}
	
	choice_index = 0;
	
	while (choice_index < choice2_size-1) {
		const unsigned char *choice2_current = &choice2[choice_index];
		set_win_tile_xy(19-choice2_place, 0, (*choice2_current-0x47+Font_sprite_start));
		choice_index++;
		choice2_place--;
	}
	
	uint8_t choice_pointer = 1;//option 1 = 1; option 2 = 0;
	uint8_t actual_choice = 1;
	
	while (actual_choice) {	
		if (KEY_TICKED(J_RIGHT) || KEY_TICKED(J_LEFT)) {
			if (choice_pointer) choice_pointer = 0;
			else choice_pointer = 1;
		}
		if (KEY_TICKED(J_A)) actual_choice = 0;
		
		if (choice_pointer) {
			set_win_tile_xy(19-choice1_size-choice2_size,0,_ARROW_);
			set_win_tile_xy(19-choice2_size,0,_RIGHT_BAR_+1);
		}
		else {
			set_win_tile_xy(19-choice1_size-choice2_size,0,_TOP_BAR_);
			set_win_tile_xy(19-choice2_size,0,_ARROW_);
		}
		UPDATE_KEYS();
	}
	
	//put player back
	if (playerY > DIALOG_WIN_HEIGHT-12) {
		move_sprite(0, playerX+8, playerY+16);
        move_sprite(2, playerX+16, playerY+16);
	}
	
	//scroll it back down!
	y = DIALOG_WIN_HEIGHT;
	while (y < 160) {
		move_win(7,y);
		y+=3;
		//VBlankDelay(DIALOG_DELAY)
		vsync();
	}
	move_win(7,160);
	HIDE_WIN;
	
	return choice_pointer;
}

void dialog_print_p(unsigned char *name, uint8_t name_size, unsigned char *text, uint8_t size) {
	dialog_init();
	
	//We wanna scroll up so we set the end point and move there
	uint8_t y = 160;
	while (y > DIALOG_WIN_HEIGHT) {
		move_win(7,y);
		y-=3;//the means the window could end up in the wrong spot, we correct that below
		//VBlankDelay(DIALOG_DELAY)
		vsync();
	}
	move_win(7,DIALOG_WIN_HEIGHT); //then we make sure it ends where it's supposed to be
	
	//we need to hide the player if he's in the wrong spot.
	int8_t tempPlayerY = 160; //TODO: All sprites will need to do this...
	if (playerY > DIALOG_WIN_HEIGHT-12) {
		move_sprite(0, playerX+8, tempPlayerY+16);
        move_sprite(2, playerX+16, tempPlayerY+16);
	}
	
	//PUT A DUDE'S NAME
	uint8_t name_xpos=0, name_ypos=0;
	uint8_t name_index = 0;
	
	while (name_index < name_size-1) {
		const unsigned char *name_current = &name[name_index];
		set_win_tile_xy(name_xpos, name_ypos, (*name_current-0x47+Font_sprite_start));
		name_xpos++;
		name_index++;
	}
	
	
    // This is an imaginary cursor.
	uint8_t xpos=0, ypos=0;
    // This is the string index.
	uint8_t index=0;

	while (index-0<(size-1))
	{
		//fix glitched text by putting correct right border.
		set_win_tile_xy(19,3,_RIGHT_BAR_);
		
        // This do a line jump if there's no more space on tile width (can be personalized).
		if (xpos % DIALOG_WIDTH == 0) {xpos=1; ypos++;}
		else xpos++;

        // This is the string index.
		(xpos == 1 && text[index] == ' ')?index++:index;

        // This put a - sign if there's no width space and a word isn't finished.
		//fuck this includes periods. TODO:Decide whether to keep this or not (I'll have to redo all dialog)
		if (xpos == DIALOG_WIDTH && text[index] != ' ' && text[index+1] != ' ') {
			set_win_tile_xy(xpos, ypos, ('-'-0x20+Font_sprite_start)); xpos=1; ypos++;
		}
		
		//no idea why this was duplicated
		//(xpos == 1 && text[index] == ' ')?index++:index;
        
		// This variable sets the current character of the string based on its index.
		const unsigned char *current = &text[index];
		
        // This fills the canvas with an empty tile if there's no more space.
        // Note that it uses the 0x00 tile.
		if (ypos > DIALOG_HEIGHT) {
				set_win_tile_xy(19,3,_ARROW_);
				waitpadup();
				waitpad(J_A);
				//init_win(0xCC);
				fill_win_rect(DIALOG_INIT_X, DIALOG_INIT_Y, DIALOG_WIDTH, DIALOG_HEIGHT, _BLANK_);
				xpos=ypos=1;
				set_win_tile_xy(19,3,_RIGHT_BAR_);
			}

        // This print the letters.
		if (*current != ' ') set_win_tile_xy(xpos, ypos, (*current-0x47+Font_sprite_start));
		
		
        // This print the symbols.
		for (uint8_t i=0; i<(sizeof(Font_symbols)); i++)
			if (*current == Font_symbols[i]) set_win_tile_xy(xpos, ypos, (*current-0x20+Font_sprite_start));
		
        VBlankDelay(DIALOG_DELAY);

		index++;
	}
	
	//we don't have buttons to accidentially close dialog
	set_win_tile_xy(19,3,_END_);
	waitpadup();
	waitpad(J_A);
	
	//put player back
	if (playerY > DIALOG_WIN_HEIGHT-12) {
		move_sprite(0, playerX+8, playerY+16);
        move_sprite(2, playerX+16, playerY+16);
	}
	
	//scroll it back down!
	y = DIALOG_WIN_HEIGHT;
	while (y < 160) {
		move_win(7,y);
		y+=3;
		//VBlankDelay(DIALOG_DELAY)
		vsync();
	}
	move_win(7,160);
	HIDE_WIN;
}

void dialog_print(unsigned char *text, uint8_t size) {
	dialog_init();
	
	//We wanna scroll up so we set the end point and move there
	uint8_t y = 160;
	while (y > DIALOG_WIN_HEIGHT) {
		move_win(7,y);
		y-=3;//the means the window could end up in the wrong spot, we correct that below
		//VBlankDelay(DIALOG_DELAY)
		vsync();
	}
	move_win(7,DIALOG_WIN_HEIGHT); //then we make sure it ends where it's supposed to be
	
	//we need to hide the player if he's in the wrong spot.
	int8_t tempPlayerY = 160; //TODO: All sprites will need to do this...
	if (playerY > DIALOG_WIN_HEIGHT-12) {
		move_sprite(0, playerX+8, tempPlayerY+16);
        move_sprite(2, playerX+16, tempPlayerY+16);
	}
	
	
    // This is an imaginary cursor.
	uint8_t xpos=0, ypos=0;
    // This is the string index.
	uint8_t index=0;

	while (index-0<(size-1))
	{
		//fix glitched text by putting correct right border.
		set_win_tile_xy(19,3,_RIGHT_BAR_);
		
        // This do a line jump if there's no more space on tile width (can be personalized).
		if (xpos % DIALOG_WIDTH == 0) {xpos=1; ypos++;}
		else xpos++;

        // This is the string index.
		(xpos == 1 && text[index] == ' ')?index++:index;

        // This put a - sign if there's no width space and a word isn't finished.
		if (xpos == DIALOG_WIDTH && text[index] != ' ' && text[index+1] != ' ') {
			set_win_tile_xy(xpos, ypos, ('-'-0x20+Font_sprite_start)); xpos=1; ypos++;
		}
		
		(xpos == 1 && text[index] == ' ')?index++:index;
        
		// This variable sets the current character of the string based on its index.
		const unsigned char *current = &text[index];
		
        // This fills the canvas with an empty tile if there's no more space.
        // Note that it uses the 0x00 tile.
		if (ypos > DIALOG_HEIGHT) {
				set_win_tile_xy(19,3,_ARROW_);
				waitpadup();
				waitpad(J_A);
				//init_win(0xCC);
				fill_win_rect(DIALOG_INIT_X, DIALOG_INIT_Y, DIALOG_WIDTH, DIALOG_HEIGHT, _BLANK_);
				xpos=ypos=1;
				set_win_tile_xy(19,3,_RIGHT_BAR_);
			}

        // This print the letters.
		if (*current != ' ') set_win_tile_xy(xpos, ypos, (*current-0x47+Font_sprite_start));
		
		
        // This print the symbols.
		for (uint8_t i=0; i<(sizeof(Font_symbols)); i++)
			if (*current == Font_symbols[i]) set_win_tile_xy(xpos, ypos, (*current-0x20+Font_sprite_start));
		
        VBlankDelay(DIALOG_DELAY);

		index++;
	}
	
	//we don't have buttons to accidentially close dialog
	set_win_tile_xy(19,3,_END_);
	waitpadup();
	waitpad(J_A);
	
	//put player back
	if (playerY > DIALOG_WIN_HEIGHT-12) {
		move_sprite(0, playerX+8, playerY+16);
        move_sprite(2, playerX+16, playerY+16);
	}
	
	//scroll it back down!
	y = DIALOG_WIN_HEIGHT;
	while (y < 160) {
		move_win(7,y);
		y+=3;
		//VBlankDelay(DIALOG_DELAY)
		vsync();
	}
	move_win(7,160);
	HIDE_WIN;
}
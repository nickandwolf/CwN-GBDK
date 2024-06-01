#ifndef TEXT_FUNCTIONS_H
#define TEXT_FUNCTIONS_H

extern uint8_t previous_keys;
extern uint8_t keys;

#define UPDATE_KEYS() previous_keys = keys; keys = joypad()
 
#define KEY_PRESSED(K) (keys & (K))
#define KEY_TICKED(K)   ((keys & (K)) && !(previous_keys & (K)))
#define KEY_RELEASED(K) ((previous_keys & (K)) && !(keys & (K)))

#define ANY_KEY_PRESSED (keys)

#define VBlankDelay(d) for (uint8_t i=0; i<d; i++) vsync();

#endif
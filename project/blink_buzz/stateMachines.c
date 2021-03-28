#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

void switch_state_advance()
{
  if (switch1_state_down){
    state1_advance();
  }
  else if (switch2_state_down){
    state2_advance();
  }
  else if (switch3_state_down){
    state3_advance();
  }
  else if (switch4_state_down){
    state4_advance();
  } else {
    default_state_advance();
  }
  led_changed = 1;
  led_update();
}

void default_state_advance() //everything is off when no buttons are pressed
{
  char changed = 0;
  static char state = 0; //can be char since we only need one byte

  red_on = 0; green_on = 0;
  buzzer_set_period(0);
  
  led_changed = 1;
  led_update();
}

void state1_advance() //Plays the B-flat major scale and toggles the LEDs
{
  static char state = 0;
  switch(state) {
  case 0: red_on = 1; green_on = 0; buzzer_set_period(7644); state++; break;
  case 1: red_on = 0; green_on = 1; buzzer_set_period(6810); state++; break;
  case 2: red_on = 1; green_on = 0; buzzer_set_period(6067); state++; break;
  case 3: red_on = 0; green_on = 1; buzzer_set_period(5726); state++; break;
  case 4: red_on = 1; green_on = 0; buzzer_set_period(5102); state++; break;
  case 5: red_on = 0; green_on = 1; buzzer_set_period(4545); state++; break;
  case 6: red_on = 1; green_on = 0; buzzer_set_period(4049); state++; break;
  case 7: red_on = 0; green_on = 1; buzzer_set_period(3822); state = 0; break;
  default: state = 0;
  }
  led_changed = 1;
  led_update();
  
}

void state2_advance() //Plays an arpeggio and flashes LEDs in binary from 0-3 then in reverse from 3-0
{
  static char state = 0;
  switch(state) {
  case 0: red_on = 0; green_on = 0; buzzer_set_period(7644); state++; break;
  case 1: red_on = 0; green_on = 1; buzzer_set_period(6067); state++; break;
  case 2: red_on = 1; green_on = 0; buzzer_set_period(5102); state++; break;
  case 3: red_on = 1; green_on = 1; buzzer_set_period(3822); state++; break;
  case 4: red_on = 1; green_on = 0; buzzer_set_period(5102); state++; break;
  case 5: red_on = 0; green_on = 1; buzzer_set_period(6067); state++; break;
  case 6: red_on = 0; green_on = 0; buzzer_set_period(7644); state++; break;
  case 7: red_on = 0; green_on = 0; buzzer_set_period(0); state = 0; break;
  default: state = 0;
  }
  led_changed = 1;
  led_update();
  
}

void state3_advance() //Does a race countdown
{
  static char state = 0;
  switch(state) {
  case 0: red_on = 1; green_on = 0; buzzer_set_period(4545); state++; break;
  case 1: red_on = 0; green_on = 0; buzzer_set_period(0); state++; break;
  case 2: red_on = 1; green_on = 0; buzzer_set_period(4545); state++; break;
  case 3: red_on = 0; green_on = 0; buzzer_set_period(0); state++; break;
  case 4: red_on = 1; green_on = 0; buzzer_set_period(4545); state++; break;
  case 5: red_on = 0; green_on = 0; buzzer_set_period(0); state++; break;
  case 6: red_on = 0; green_on = 1; buzzer_set_period(2272); state++; break;
  case 7: red_on = 0; green_on = 1; buzzer_set_period(2272); state++; break;
  case 8: red_on = 0; green_on = 0; buzzer_set_period(0); state = 0; break;
  default: state = 0;
  }
  led_changed = 1;
  led_update();
  
}

void state4_advance() //LEDs flash together repeatedly and a siren plays
{
  static char state = 0;
  switch(state) {
  case 0: red_on = 0; green_on = 0; buzzer_set_period(2000); state++; break;
  case 1: red_on = 1; green_on = 1; buzzer_set_period(1950); state++; break;
  case 2: red_on = 0; green_on = 0; buzzer_set_period(1900); state++; break;
  case 3: red_on = 1; green_on = 1; buzzer_set_period(1850); state++; break;
  case 4: red_on = 0; green_on = 0; buzzer_set_period(1800); state++; break;
  case 5: red_on = 1; green_on = 1; buzzer_set_period(1750); state++; break;
  case 6: red_on = 0; green_on = 0; buzzer_set_period(1700); state++; break;
  case 7: red_on = 1; green_on = 1; buzzer_set_period(1650); state++; break;
  case 8: red_on = 0; green_on = 0; buzzer_set_period(1600); state++; break;
  case 9: red_on = 1; green_on = 1; buzzer_set_period(1650); state++; break;
  case 10: red_on = 0; green_on = 0; buzzer_set_period(1700); state++; break;
  case 11: red_on = 1; green_on = 1; buzzer_set_period(1750); state++; break;
  case 12: red_on = 0; green_on = 0; buzzer_set_period(1800); state++; break;
  case 13: red_on = 1; green_on = 1; buzzer_set_period(1850); state++; break;
  case 14: red_on = 0; green_on = 0; buzzer_set_period(1900); state++; break;
  case 15: red_on = 1; green_on = 1; buzzer_set_period(1950); state = 0; break;
  default: state = 0;
  }
  led_changed = 1;
  led_update();
  
}

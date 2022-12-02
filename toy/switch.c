#include <msp430.h>
#include "switch.h"
#include "led.h"
#include "buzzer.h"



char state = 0;

static char
switch_update_interrupt_sense(){
  char p2val = P2IN; //detects changes from buttons 
  P2IES |= (p2val & SWITCHES);
  return p2val;
}



void switch_init(){

  P2REN |= SWITCHES;
  P2IE |= SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();

}



void switch_interrupt_handler(){

  char p2val = switch_update_interrupt_sense();

  if (~p2val & SW1) {
    state = 1;
    sixteenth_note = 0;
  }
  else if (~p2val & SW2) {
    state = 2;
    sixteenth_note = 0;
  }
  else if (~p2val & SW3) {
    state = 3;
    sixteenth_note = 0;
  }
  else if (~p2val & SW4) {
    state = 4;
    sixteenth_note = 0;
  }
  else {
    state =0;
    sixteenth_note=0;
  }
}
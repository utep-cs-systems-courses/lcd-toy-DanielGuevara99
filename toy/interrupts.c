#include <msp430.h>
#include "switch.h"
#include "led.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include <unistd.h>

int sixteenth_note = 0;

void __interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */

  static char count = 0;
  count++;
  static char colorC = 0;
  switch (state) {
  case 1:
    song4(sixteenth_note);
    if (count == 75){
	sixteenth_note++;
	count = 0;
      }
    break;

  case 2:
    buzzer_set_period(10000);
    break;

  case 3:
    newShape(COLOR_ORANGE,COLOR_BLUE);
    count = 0;
    break;

  case 4:
    siren(sixteenth_note);
    if(count == 45){
      sixteenth_note++;
      count =0;
    if(colorC==1){
      clearScreen(COLOR_RED);
      colorC--;
    }else{
      clearScreen(COLOR_BLUE);
      colorC++;
    }
    }
   break;

  default:
    buzzer_set_period(0);
    count = 0;
    sixteenth_note = 0;
  }
}

/* Switch on P2 */

void

__interrupt_vec(PORT2_VECTOR) Port_2(){

  if (P2IFG & SWITCHES) {      /* did a button cause this interrupt? */

    P2IFG &= ~SWITCHES;      /* clear pending sw interrupts */

    switch_interrupt_handler();/* single handler for all switches */

  }

}
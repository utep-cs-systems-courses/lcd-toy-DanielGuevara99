#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"

void buzzer_init(){

  timerAUpmode();// used to drive speaker 

  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;// enable output to speaker

}



void buzzer_set_period(short cycles){ // buzzer clock = 2MHz.

  CCR0 = cycles;
  CCR1 = cycles >> 1;/* one half cycle */

}


void song1(int sixteenth_note){
  switch (sixteenth_note){
    case 0:
      // baseline to song
      buzzer_set_period(C0_SHARP);
      break;
    case 2:
      buzzer_set_period(D1_FLAT);
      break;
    case 4:
      buzzer_set_period(F2_SHARP);
      break;
    case 6:
      buzzer_set_period(G3_SHARP);
      break;
    case 8:
      buzzer_set_period(A4);
      break;
    case 10:
      buzzer_set_period(0);
      break;
    case 12:
      buzzer_set_period(B3);
      break;
    case 14:
      buzzer_set_period(D4);
      break;
    case 16:
      buzzer_set_period(F4_SHARP);
      break;
    case 18:
      buzzer_set_period(E4);
      break;
    case 19:
      buzzer_set_period(0);
      break;
    case 20:
      buzzer_set_period(E4);
      break;
    case 24:
      buzzer_set_period(0);
      break;
    case 28:
      //baseline to song
      buzzer_set_period(C0_SHARP);
      break;
    case 30:
      buzzer_set_period(D1_FLAT);
      break;
    case 32:
      buzzer_set_period(F2_SHARP);
      break;
    case 34:
      buzzer_set_period(G3_SHARP);
      break;
    case 36:
      buzzer_set_period(A4);
      break;
    case 40:
      buzzer_set_period(0);
      break;
    case 42:
      buzzer_set_period(B4);
      break;
    case 43:
      buzzer_set_period(C5_SHARP);
      break;
    case 44:
      buzzer_set_period(D5);
      break;
    case 46:
      buzzer_set_period(B4);
      break;
    case 47:
      buzzer_set_period(0);
      break;
    case 48:
      buzzer_set_period(B4);
      break;
    case 52:
      buzzer_set_period(0);
      break;
    case 56:
      buzzer_set_period(B4);
      break;
    case 58:
      buzzer_set_period(C5);
      break;
    case 60:
      buzzer_set_period(B4);
      break;
    case 62:
      buzzer_set_period(A4);
      break;
    case 64:
      buzzer_set_period(G4);
      break;
    case 68:
      buzzer_set_period(0);
      break;
    case 70:
      buzzer_set_period(A4);
      break;
    case 72:
      buzzer_set_period(B4);
      break;
    case 74:
      buzzer_set_period(B3);
      break;
    case 76:
      buzzer_set_period(C4);
      break;
    case 78:
      buzzer_set_period(D4);
      break;
    case 80:
      buzzer_set_period(F4_SHARP);
      break;
    case 82:
      buzzer_set_period(E4);
      break;
    case 86:
      buzzer_set_period(0);
      break;
    case 312:
    state =0;
    }
}

void song2(int sixteenth_note){}
void song3(int sixteenth_note){}
void song4(int sixteenth_note){

  switch (sixteenth_note){
    case 0:
      buzzer_set_period(A4);
      break;
    case 4:
      buzzer_set_period(B4);
      break;
    case 6:
      buzzer_set_period(C4_SHARP);
      break;
    case 8:
      buzzer_set_period(G4_SHARP);
      break;
    case 12:
      buzzer_set_period(F4_SHARP);
      break;
    }
}
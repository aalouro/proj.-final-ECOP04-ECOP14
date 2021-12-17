#include <pic18f4520.h>
#include "config.h"
#include "bits.h"
#include "lcd.h"
#include "keypad.h"

void main(void) {
 unsigned int tecla = 16;
 char i;
 unsigned char coluna=0, x=0;
 lcdInit();
 kpInit();
 

TRISD = 0x00;
PORTD = 0x00;
 
 for(;;){
kpDebounce();
if (kpRead() != tecla){
 tecla = kpRead();
 if (bitTst(tecla, 0)) { x++;}
 if (bitTst(tecla, 1)) { x--;}
 if(x==0){PORTD = 0b00000001;
 lcdInit();
 char msg[13] = "Loja Fechada";
 for(i=0;i<12;i++) {
 lcdChar(msg[i]);
 }
 }
 
if(x==1){PORTD = 0b00000010;
 lcdInit();
 char msg[16] = "Estamos abertos";
 for(i=0;i<15;i++) {
 lcdChar(msg[i]);
 }}
 
 if(x==2){PORTD = 0b00000011;
 lcdInit();
  char msg[16] = "Pausa de almoco";
 for(i=0;i<15;i++) {
 lcdChar(msg[i]);
 }
 }
 
 if(x==3){PORTD = 0b00000100;
 lcdInit();
  char msg[16] = "Sabado";
 for(i=0;i<15;i++) {
 lcdChar(msg[i]);
 }}
 
 if(x==4){PORTD = 0b00000101;
 lcdInit();
  char msg[16] = "Feriado";
 for(i=0;i<15;i++) {
 lcdChar(msg[i]);
 }}
 if(x==5) x=0;
 
}
}
}
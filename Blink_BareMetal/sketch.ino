#include <avr/io.h>
#include <util/delay.h>


int main(void){
  DDRB=32;

  while(1){
    PORTB=32;
    _delay_ms(1000);
    PORTB=0;
    _delay_ms(1000);
  }
}
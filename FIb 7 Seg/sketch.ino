#define HundredsPort 0x31
#define TensPort 0x108
#define UnitsPort 0x22

#include <avr/io.h>
#include <util/delay.h>


void displaySevenSeg(int a, volatile byte* segmentPort){
  switch(a){
    case 0: *segmentPort=252;
            break;
    case 1: *segmentPort=96;
            break;
    case 2: *segmentPort=218;
            break;
    case 3: *segmentPort=242;
            break;
    case 4: *segmentPort=102;
            break;
    case 5: *segmentPort=182;
            break;
    case 6: *segmentPort=190;
            break;
    case 7: *segmentPort=224;
            break;
    case 8: *segmentPort=254;
            break;
    case 9: *segmentPort=246;
            break;                                    
  }
}


int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    
    int a = 0;
    int b = 1;
    int next;

    for (int i = 2; i <= n; i++) {
        next = a + b;
        a = b;
        b = next;
    }

    return b;
}

void displayThreeDigitNumber(int a){
  int units=a%10;
  int tens=(a%100)/10;
  int hundreds=(a%1000)/100;

  displaySevenSeg(units, UnitsPort);
  displaySevenSeg(tens, TensPort);
  displaySevenSeg(hundreds, HundredsPort);

}

int main(void){
  DDRF=255;
  DDRK=255;
  DDRA=255;

  while(1){
    for(int i=0;i<14;i++){
    displayThreeDigitNumber(fibonacci(i));
    _delay_ms(1000);
    }
  }
}

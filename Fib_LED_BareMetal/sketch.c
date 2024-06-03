#include <avr/io.h>
#include <util/delay.h>

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

int main(void){
  DDRD=255;

  while(1){
    for(int i=0;i<14;i++){
    PORTD=fibonacci(i);
    _delay_ms(1000);
    }
  }
}

#include <SPI.h>

#define SPI_CS 10 
int x, y; 
int response; 

void setup() {
  Serial.begin(9600);
  SPI.begin();
  pinMode(SPI_CS, INPUT);
}

void loop() {
  
  digitalWrite(SPI_CS, LOW);
  x = (SPI.transfer(0x00) << 8) | SPI.transfer(0x00);
  y = SPI.transfer(0x00);
  digitalWrite(SPI_CS, HIGH);

  
  switch (y) {
    case 0:
      response = x + 1;
      break;
    case 1:
      response = x - 1;
      break;
    case 2:
      response = x * 2;
      break;
    case 3:
      response = x / 3;
      break;
    default:
      response = 0xFF;
  }

  
  digitalWrite(SPI_CS, LOW);
  SPI.transfer(response);
  digitalWrite(SPI_CS, HIGH);
}
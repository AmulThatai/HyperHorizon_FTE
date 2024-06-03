#include <SPI.h>

#define SPI_CS 10 
void setup() {
  Serial.begin(9600);
  SPI.begin();
  pinMode(SPI_CS, OUTPUT);
}

void loop() {
  int x = random(0, 100); // generate a random integer x
  int y = random(0, 4); // generate a random operation y

  // send x and y to Arduino Board B over SPI
  digitalWrite(SPI_CS, LOW);
  SPI.transfer(x >> 8); // send high byte of x
  SPI.transfer(x & 0xFF); // send low byte of x
  SPI.transfer(y);
  digitalWrite(SPI_CS, HIGH);

  // receive response from Arduino Board B over SPI
  digitalWrite(SPI_CS, LOW);
  int response = SPI.transfer(0x00); 
  digitalWrite(SPI_CS, HIGH);

  
  if (response == 0xFF) {
    Serial.println("NACK received. Invalid command or edge case.");
  } else {
    Serial.print("f(x) = ");
    Serial.println(response);
  }

  delay(1000);
}
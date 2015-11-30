#include <Wire.h>

byte inputPin2 = 2;
byte inputPin3 = 3;

byte lastReading1 = 1;
byte lastReading2 = 1;


void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  pinMode(inputPin2, INPUT);
  pinMode(inputPin3, INPUT);
}

void loop() {
  Wire.beginTransmission(7); // transmit to device #8
  byte buttonRotate = digitalRead(inputPin2);
  Wire.write(buttonRotate);   // sends one byte
  lastReading1 = buttonRotate;
  Wire.endTransmission(7);    // stop transmitting
  delay(500);
  
  Wire.beginTransmission(8); //
  byte buttonRight = digitalRead(inputPin3);
  Wire.write(buttonRight);   // sends one byte
  lastReading2 = buttonRight;
  Wire.endTransmission(8);    // stop transmitting

  delay(500);
}
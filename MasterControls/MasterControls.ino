#include <Wire.h>

// Inputs
byte inputPin2 = 2;
byte inputPin3 = 3;
byte inputPin4 = 4;
byte inputPin5 = 5;

byte lastReading1 = 1;
byte lastReading2 = 1;
byte lastReading3 = 1;
byte lastReading4 = 1;



void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  pinMode(inputPin2, INPUT);
  pinMode(inputPin3, INPUT);
  pinMode(inputPin4, INPUT);
  pinMode(inputPin5, INPUT);
}

void loop() {
  Wire.beginTransmission(8); // transmit to device #8
  byte buttonRotate = digitalRead(inputPin2);
  byte buttonRight  = digitalRead(inputPin3);
  byte buttonDown   = digitalRead(inputPin4);
  byte buttonLeft   = digitalRead(inputPin5);
  Wire.write(buttonRotate);   // sends one byte
  Wire.write(buttonRight);
  Wire.write(buttonDown);
  Wire.write(buttonLeft);
  Wire.endTransmission();    // stop transmitting

  lastReading1 = buttonRotate;
  lastReading2 = buttonRight; 
  lastReading3 = buttonDown;
  lastReading4 = buttonLeft; 
  delay(500);
}

#include <Wire.h>

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
  Wire.beginTransmission(5); // transmit to device #8
  byte buttonRotate = digitalRead(inputPin2);
  Wire.write(buttonRotate);   // sends one byte
  lastReading1 = buttonRotate;
   Wire.endTransmission(5);
   // stop transmitting
  
  Wire.beginTransmission(6); //
  byte buttonRight = digitalRead(inputPin3);
  Wire.write(buttonRight);   // sends one byte
  lastReading2 = buttonRight;
  Wire.endTransmission(6); 
  
  Wire.beginTransmission(7); // transmit to device #8
  byte buttonDown = digitalRead(inputPin4);
  Wire.write(buttonDown);   // sends one byte
  lastReading3 = buttonDown;
   Wire.endTransmission(7);
 
  
  Wire.beginTransmission(8); //
  byte buttonLeft = digitalRead(inputPin5);
  Wire.write(buttonLeft);   // sends one byte
  lastReading4 = buttonLeft;
  Wire.endTransmission(8);    // stop transmitting


  delay(500);
}

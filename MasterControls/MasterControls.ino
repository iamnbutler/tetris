#include <Wire.h>
 
int inputPin2 = 2;
int inputPin3 = 3;
int inputPin4 = 4;
int inputPin5 = 5;

int lastReading1 = 1;
int lastReading2 = 1;
int lastReading3 = 1;
int lastReading4 = 1;

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  pinMode(inputPin2, INPUT);
  pinMode(inputPin3, INPUT);
  pinMode(inputPin4, INPUT);
  pinMode(inputPin5, INPUT);
}

void loop() {
  Wire.beginTransmission(8); // transmit to device #8
  int buttonRotate = digitalRead(inputPin2);
  int buttonRight = digitalRead(inputPin3);
  int buttonDown = digitalRead(inputPin4);
  int buttonLeft = digitalRead(inputPin5);
  Wire.write(buttonRotate);
  Wire.write(buttonRight);   // sends one byte
  Wire.write(buttonDown);
  Wire.write(buttonLeft); 
  Wire.write(lastReading1);
  Wire.write(lastReading2);
  Wire.write(lastReading3);
  Wire.write(lastReading4);
  Wire.endTransmission(8);    // stop transmitting

  lastReading1 = buttonRotate;
  lastReading2 = buttonRight;
  lastReading3 = buttonDown;
  lastReading4 = buttonLeft;

  delay(200);
}

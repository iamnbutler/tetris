#include <Wire.h>

byte ledPin1 = 13;
byte ledPin2 = 12;
byte ledState1 = 0;
byte ledState2 = 0;
byte lastReading1 = 1;
byte lastReading2 = 1;

void setup() {
  Wire.begin(7);               // join i2c bus with address #8
  pinMode(ledPin1, OUTPUT);
  Wire.onReceive(receiveEvent1);
  
  Wire.begin(8);
  pinMode(ledPin2, OUTPUT);
  Wire.onReceive(receiveEvent2);
  Serial.begin(9600);           // start serial for output
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent1(int howMany1) {
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int buttonRotate= Wire.read();    // receive byte as an integer
  
  if (buttonRotate == 0 && lastReading1 == 1) {
    if (ledState1 == 1) {
      ledState1 = 0;
    } else {
      ledState1 = 1;
    }
    delay(30);
  }
  lastReading1 = buttonRotate;
  
  digitalWrite(ledPin1, ledState1);

  Serial.println(buttonRotate); 
} 

  void receiveEvent2(int howMany2) {
  while (1 < Wire.available()) { // loop through all but the last
    char b = Wire.read(); // receive byte as a character
    Serial.print(b);         // print the character
  }
  int buttonRight= Wire.read();    // receive byte as an integer
  
  if (buttonRight == 0 && lastReading2 == 1) {
    if (ledState2 == 1) {
      ledState2 = 0;
    } else {
      ledState2 = 1;
    }
    delay(30);
  }
  lastReading2 = buttonRight;
  
  digitalWrite(ledPin2, ledState2);

  Serial.println(buttonRight);         // print the integer
}
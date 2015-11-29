#include <Wire.h>

byte ledPin = 9;
byte ledState = 0;

byte lastReading1 = 1;
byte lastReading2 = 1;
byte lastReading3 = 1;
byte lastReading4 = 1;


void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  pinMode(ledPin, OUTPUT);
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int buttonRotate = Wire.read();    // receive byte as an integer
  int buttonRight  = Wire.read();
  int buttonDown   = Wire.read();
  int buttonLeft   = Wire.read();
  
  if (buttonRotate == 0 && lastReading1 == 1) {
    if (ledState == 1) {
      ledState = 0;
    } else {
      ledState = 1;
    }
    delay(30);
  }
  lastReading1 = buttonRotate;
  lastReading2 = buttonRight;
  lastReading3 = buttonDown;
  lastReading4 = buttonLeft;
  
  digitalWrite(ledPin, ledState);

  
  Serial.println(buttonRotate);         // print the integer
  Serial.println(buttonRight);
  Serial.println(buttonDown);
  Serial.println(buttonLeft);
}

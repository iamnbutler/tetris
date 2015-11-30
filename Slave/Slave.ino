#include <Wire.h>

int ledPin1 = 13;
int ledPin2 = 12;
int ledPin3 = 11;
int ledPin4 = 10;

int ledState1 = 0;
int ledState2 = 0;
int ledState3 = 0;
int ledState4 = 0;

void setup() {
  Wire.begin(8);               // join i2c bus with address #8
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);           // start serial for output
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int buttons) {
 
  int buttonRotate= Wire.read();    // receive byte as an integer
  int buttonRight = Wire.read();
  int buttonDown= Wire.read();
  int buttonLeft = Wire.read();
  int lastReading1= Wire.read();    // receive byte as an integer
  int lastReading2 = Wire.read();
  int lastReading3= Wire.read(); 
  int lastReading4 = Wire.read();
  
  if (buttonRotate == 0 && lastReading1 == 1) {
    if (ledState1 == 1) {
      ledState1 = 0;
    } else {
      ledState1 = 1;
    }
    delay(10);
  }

  if (buttonRight == 0 && lastReading2 == 1) {
    if (ledState2 == 1) {
      ledState2 = 0;
    } else {
      ledState2 = 1;
    }
    delay(10);
  }

  if (buttonDown == 0 && lastReading3 == 1) {
    if (ledState3 == 1) {
      ledState3 = 0;
  } else {
      ledState3 = 1;
  }
  delay(10);
}

if (buttonLeft == 0 && lastReading4 == 1) {
    if (ledState4 == 1) {
      ledState4 = 0;
  } else {
     ledState4 = 1;
  }
  delay(10);
}
  
  digitalWrite(ledPin1, ledState1);
  digitalWrite(ledPin2, ledState2);
  digitalWrite(ledPin3, ledState3);
  digitalWrite(ledPin4, ledState4);

  Serial.println(buttonRotate); 
  Serial.println(buttonRight); 
  Serial.println(buttonDown); 
  Serial.println(buttonLeft); 

} 

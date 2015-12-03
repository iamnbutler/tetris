// Display stuff
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

#define CLK 8  // MUST be on PORTB! (Use pin 11 on Mega)
#define LAT A3
#define OE  9
#define A   A0
#define B   A1
#define C   A2
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

// Code
int led = 13;
int button = 12;
char string[32]; // Set max string length

void setup() {
pinMode(led, OUTPUT);
pinMode(button, INPUT);
Serial.begin(9600);
matrix.begin();
}

void loop(){
  String inString = Serial.readStringUntil('\n'); // Read string until newline

  if(inString == "1"){
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }

  readArray();
}

void readArray() {
  // String inString = Serial.readStringUntil('\n'); // Read string until newline

  // if (inString != null) {
  //   // trim off any whitespace:
  //   inString = trim(inString);
  //   // convert to an int and map to the screen height:
  //   inByte = float(inString);
  //   println(inByte);
  // }
}
// Tetris
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

#define CLK 8  // MUST be on PORTB! (Use pin 11 on Mega)
#define LAT A3
#define OE  9
#define A   A0
#define B   A1
#define C   A2
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

// Colors

const int xbColor = matrix.Color333(200,30,30);
const int ibColor = matrix.Color333(140,0,130);
const int tbColor = matrix.Color333(240,160,30);
const int zbColor = matrix.Color333(120,30,30);
const int sbColor = matrix.Color333(60,60,0);
const int lbColor = matrix.Color333(30,90,120);
const int jbColor = matrix.Color333(170,120,90);

void setup() {
  Serial.begin(9600);
  matrix.begin();
}

void loop() {
  // Loop
}

void writePixel() {
  matrix.drawPixel(row, col, color);
}
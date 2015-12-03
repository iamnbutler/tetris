// ===
// FLAPPY
// ===

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

#define CLK 8  // MUST be on PORTB! (Use pin 11 on Mega)
#define LAT A3
#define OE  9
#define A   A0
#define B   A1
#define C   A2
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

// ===
// VARS
// ===

unsigned long previousMillis = 0;  // The current time of the game
const long interval = 1200; // Speed the block drops
int step = 0; // Frame of game
int pillarTrigger = 0; // Trigger pillar creation
const int cols = 16; // Display columns
const int rows = 32; // Display rows
// Colors

const int blank =           matrix.Color333(7,7,7);
const int sky =             matrix.Color333(0,4,7);
const int pillar =             matrix.Color333(7,0,4);
const int grassColor1 =     matrix.Color333(4,7,0);
const int grassColor2 =     matrix.Color333(0,7,0);
const int groundColor =     matrix.Color333(7,2,0);

// ===
// START
// ===

void setup() {
  Serial.begin(9600);
  matrix.begin();
  matrix.fillRect(0, 0, 28, 16, sky);
}

void loop() {
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  
    step++;
    pillarTrigger++;

    if (step > 15) {
      step = 0;
    }

    if (pillarTrigger > 7) {
      pillarTrigger = 0;
    }
  }

  generateTerrain(); // Generate Terrain
  makePillars();
  Serial.println(pillarTrigger);
}

void generateTerrain(){
  // Moving grass animation
  for (int i=0; i < rows; i++){
    if (i==27) {
      for (int j=0; j < cols; j++){
        if (step % 2) {
          if (j % 2) {
            matrix.drawPixel(i, j, grassColor2);
          } else {
            matrix.drawPixel(i, j, grassColor1);
          }
        } else {
          if (j % 2) {
            matrix.drawPixel(i, j, grassColor1);
          } else {
            matrix.drawPixel(i, j, grassColor2);
          }
        }
      }
    }
    if (i==28) {
      for (int j=0; j < cols; j++){
        if (step % 2) {
          if (j % 2) {
            matrix.drawPixel(i, j, grassColor1);
          } else {
            matrix.drawPixel(i, j, grassColor2);
          }
        } else {
          if (j % 2) {
            matrix.drawPixel(i, j, grassColor2);
          } else {
            matrix.drawPixel(i, j, grassColor1);
          }
        }
      }
    }
    if (i==29 || i==30 || i==31) {
      for (int j=0; j < cols; j++){
        matrix.drawPixel(i, j, groundColor);
      }
    }
  }
  delay(1200);
}

void makePillars() {
  int pillarGap = random(6,15);
  matrix.drawLine(0, 0 + step, 26, 0 + step, sky);
  for (int i=0; i < 10; i++){
    matrix.drawPixel(pillarGap + i, 0 + step, blank);
  }
}
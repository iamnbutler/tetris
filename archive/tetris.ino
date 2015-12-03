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

// Variables
const int cols = 16;
const int rows = 32;

int turn = 0;               // Turn and "Level" are interchangeable
unsigned long previousMillis = 0;  // The current time of the game
const long interval = 400; // Speed the block drops
int timeStep = 0;

// Colors
  const int grassColor1 = matrix.Color333(60,180,0);
  const int grassColor2 = matrix.Color333(20,240,0);
  const int groundColor = matrix.Color333(200,120,60);

// Build counter to define refresh rate (15fps?)

// TODO: Start Game

void setup() {
  matrix.begin();
  randomSeed(analogRead(5));
  Serial.begin(9600);
  Serial.println("Setup");
}

void loop() {
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  
    timeStep++;
  } 

  Serial.println("Test");
  Serial.println(timeStep);

  createGround();
  // MoveLeft();


  for (int i=0; i < rows; i++){
    for (int j=0; j < cols; j++){
      matrix.drawPixel(i, j, grassColor1);
    }
    if (i = 28) {
      // Moving grass animation

      for (int j=0; j < cols; j++){
        
        if (timeStep % 2) {
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
  }
}

void run() { // Run the game

}

void keyPressed() { // Keybinds

}
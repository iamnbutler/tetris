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
int turn = 0;               // Turn and "Level" are interchangeable
unsigned long previousMillis = 0;  // The current time of the game
const long interval = 400; // Speed the block drops
int timeStep = 0;
boolean turnStart = true;
boolean gameOver = false;   // If the game has ended or not
int tetrisBoard[16][8] = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};


// Build counter to define refresh rate (15fps?)

// TODO: Start Game

void setup() {
  Serial.begin(9600);
  matrix.begin();
  randomSeed(analogRead(5));
  Display(0,0,1,1,32,16); // X, Y, blockWidth, blockHeight, Rows, Cols
}

void loop() {
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  
    timeStep++;
  } 

  if (turnStart) {
    CreateBlock();
  }

  MoveDown();

  if(timeStep == 15){
    // WARNING: This is wrong. Don't calculate based on 32 steps, but on faux collision
    EndTurn();
  }
}

void run() { // Run the game

}

void keyPressed() { // Keybinds

}
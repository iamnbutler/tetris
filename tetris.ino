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

// Build counter to define refresh rate (15fps?)

// TODO: Start Game

void setup() {
  Serial.begin(9600);
  matrix.begin();
}

void loop() {
  
  // // T
  // for (int i = 0; i < 31; i++) {
  //   // Clear background
  //   matrix.fillScreen(0);
    
  //   matrix.drawPixel(1 + i,0, matrix.Color333(200, 110, 70));
  //   matrix.drawPixel(1 + i,1, matrix.Color333(200, 110, 70));
  //   matrix.drawPixel(1 + i,2, matrix.Color333(200, 110, 70));
  //   matrix.drawPixel(0 + i,1, matrix.Color333(200, 110, 70));
  //   delay(100);
  // }
  Grid();
}

void run() { // Run the game

}

void keyPressed() { // Keybinds

}

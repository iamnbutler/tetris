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

// TODO: Start Game

void setup() { 
	matrix.begin();
}

void loop() {
	


	// T
	matrix.drawPixel(31,0, matrix.Color333(200, 110, 70));
	matrix.drawPixel(31,1, matrix.Color333(200, 110, 70));
	matrix.drawPixel(31,2, matrix.Color333(200, 110, 70));
	matrix.drawPixel(30,1, matrix.Color333(200, 110, 70));

	// L
	matrix.drawPixel(31,3, matrix.Color333(120, 110, 200));
	matrix.drawPixel(31,4, matrix.Color333(120, 110, 200));
	matrix.drawPixel(30,4, matrix.Color333(120, 110, 200));
	matrix.drawPixel(29,4, matrix.Color333(120, 110, 200));

	// S
	matrix.drawPixel(31,5, matrix.Color333(170, 220, 200));
	matrix.drawPixel(31,6, matrix.Color333(170, 220, 200));
	matrix.drawPixel(30,6, matrix.Color333(170, 220, 200));
	matrix.drawPixel(30,7, matrix.Color333(170, 220, 200));

	matrix.drawPixel(0,0, matrix.Color333(255, 0, 0));
	matrix.drawPixel(0,1, matrix.Color333(0, 255, 0));
	matrix.drawPixel(0,2, matrix.Color333(0, 0, 255));
}

void run() { // Run the game

}

void keyPressed() { // Keybinds

}

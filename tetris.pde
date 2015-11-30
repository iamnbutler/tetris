import processing.serial.*;

import cc.arduino.*;

Arduino arduino;
 
import controlP5.*;
 
final int CYAN = color(0,255,255);
final int ORANGE = color(255,165,0);
final int YELLOW = color(255,255,0);
final int PURPLE = color(160,32,240);
final int BLUE = color(0,0,255);
final int RED = color(255,0,0);
final int GREEN = color(0,255,0);
 
ControlP5 controlP5;
Grid board, preview;
Tetromino curr;
Shape next;
Shape[] shapes = new Shape[7];
int timer = 20;
int currTime = 0;

int lines = 0;

final int SPEED_DECREASE = 2;
boolean game_over = true;
 
void setup() {
  size(16, 32, P2D);
  
  controlP5 = new ControlP5(this);
  
  shapes[0] = new Shape(4, new int[] {8,9,10,11}, CYAN);  // I
  shapes[1] = new Shape(3, new int[] {0,3,4,5}, BLUE);  // J
  shapes[2] = new Shape(3, new int[] {2,3,4,5}, ORANGE);  // L
  shapes[3] = new Shape(2, new int[] {0,1,2,3}, YELLOW);  // O
  shapes[4] = new Shape(4, new int[] {5,6,8,9}, GREEN);  // S
  shapes[5] = new Shape(3, new int[] {1,3,4,5,}, PURPLE);  // T
  shapes[6] = new Shape(4, new int[] {4,5,9,10}, RED);  // Z
  board = new Grid(0, 0, 160, 320, 32, 16);
  
  next = shapes[(int)random(7)];
  loadNext();
}
 
void draw() {
  background(0);
  if (game_over) {
    controlP5.draw(); // show the play again button
    return;
  }
  currTime++;
  if (currTime >= timer && board.animateCount == -1)
    curr.stepDown();
  
  board.draw();
  if (curr != null)
    curr.draw();

  fill(255);
}
 
void loadNext() {
  curr = new Tetromino(next);
  next = shapes[(int)random(7)];
  currTime = 0;
}
 
void keyPressed() {
  if (curr == null || game_over)
    return;
  switch(keyCode) {
    case LEFT : curr.left(); break;
    case RIGHT : curr.right(); break;
    case UP : curr.rotate(); break;
    case DOWN : curr.hardDown(); break;

  }
}
 
void play(int value) {
  board.clear();
  loadNext();
}
// TODO: Delete full rows

// TODO: Calculate Score

// TODO: Display Grid

// TODO: Display Blocks

// TODO: Make Sound

// TODO: Game Over

  // ============= //
 //  START GRID   //
// ============= //

int displayFloor = 31;

// Define constants

const int cols = 8;
const int rows = 16;

  // Empty pixel color
  const int c = matrix.Color333(0, 0, 0);

// Define Variables
int pixel[cols][rows];

void Display(int x, int y, int w, int h, int rows, int cols){
  blockWidth = w;
  blockHeight = h; 
  for (int i=0; i < rows; i++){
    for (int j=0; j < cols; j++){
      // pixelMap[i][j] = false; // At the start there are no filled pixels
    }
  }
}

void FillPixel(int row, int col, int color){
  if (col < 0 || col >= cols || row < 0 || row >= rows) {
   return; // Don't do anything if the pixel is off of the grid
  }
  matrix.drawPixel(row, col, color);
}

void MoveDown(){ // Shift current block down by 1 pixel per "turn"
  // WARNING: This is wrong. Don't calculate based on 32 steps, but on faux collision
  if(timeStep < 15){
    // First clear the trail from the last frame (prevent the block "smearing")
    for (int i = 0; i < 4; ++i){
      for (int j = 0; j < 3; ++j){
        FillPixel(yPos + (i - 1) + timeStep, xPos + j, matrix.Color333(0,0,0));
      }
    }
    // Next print the next frame of the block
    for (int i = 0; i < 4; ++i){
      for (int j = 0; j < 3; ++j){
        if (blockLayout[i][j] == 1) {
          FillPixel(yPos + i + timeStep, xPos + j, blockColor);
        }
      }
    }
  }
}

void EndTurn() { // Set things up for the nxt block and check for complete rows

  timeStep = 0; // Reset the step
  Serial.println("Array Row 0:");
  Serial.print(tetrisBoard[15][0]);
  Serial.print(", ");
  Serial.print(tetrisBoard[15][1]);
  Serial.print(", ");
  Serial.print(tetrisBoard[15][2]);
  Serial.print(", ");
  Serial.print(tetrisBoard[15][3]);
  Serial.print(", ");
  Serial.print(tetrisBoard[15][4]);
  Serial.print(", ");
  Serial.print(tetrisBoard[15][5]);
  Serial.print(", ");
  Serial.print(tetrisBoard[15][6]);
  Serial.print(", ");
  Serial.print(tetrisBoard[15][7]);
  Serial.println();
}

void ClearDisplay(){
  // Clear background completely
  matrix.fillScreen(0);
}


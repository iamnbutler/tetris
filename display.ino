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

const int cols = 16;
const int rows = 32;

  const int c = matrix.Color333(0, 0, 0);

// Define Variables
int pixel[cols][rows];

void Display(int x, int y, int w, int h, int rows, int cols){
  blockWidth = w;
  blockHeight = h; 
  int i = 0; 
  int j = 0;
  for (i=0; i < rows; i++){
    for (j=0; j < cols; j++){
      // pixel[i][j] = 0;
      FillPixel(i,j,c);
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
  if(timeStep <= 31){
    matrix.fillScreen(0);
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
}

void ClearDisplay(){
  // Clear background completely
  matrix.fillScreen(0);
}


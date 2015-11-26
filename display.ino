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
bool pixelMap[31][15];

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
      pixelMap[i][j] = false;
      FillPixel(i,j,c);
    }
  }
}

void UpdateDisplay() {
  // for (int i = 0; i < 4; ++i){
  //   for (int j = 0; j < 3; ++j){
  //     if (blockLayout[i][j] == 1) {
  //       FillPixel(yPos + i + timeStep, xPos + j, blockColor);
  //     }
  //   }
  // }
}

void FillPixel(int row, int col, int color){
  if (col < 0 || col >= cols || row < 0 || row >= rows) {
   return; // Don't do anything if the pixel is off of the grid
  }
  matrix.drawPixel(row, col, color);
}

void MoveDown(){ // Shift current block down by 1 pixel per "turn"
  // WARNING: This is wrong. Don't calculate based on 32 steps, but on faux collision
  if(timeStep < 31){
    // First clear the trail from the last frame (prevent the block "smearing")
    for (int i = 0; i < 4; ++i){
      for (int j = 0; j < 3; ++j){
        FillPixel(yPos + (i - 1) + timeStep, xPos + (j - 1), matrix.Color333(0,0,0));
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
  if(timeStep < 31){
    // First clear the trail from the last frame (prevent the block "smearing")
    for (int i = 0; i < 4; ++i){
      for (int j = 0; j < 3; ++j){
        FillPixel(yPos + (i - 1) + timeStep, xPos + j, matrix.Color333(0,0,0));
      }
    }
  }
}

void EndTurn() { // Set things up for the nxt block and check for complete rows
  timeStep = 0; // Reset the step
  turnStart = true;
  // UpdateDisplay();
}

void ClearDisplay(){
  // Clear background completely
  matrix.fillScreen(0);
}


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

  // Empty pixel color
  const int c = matrix.Color333(0, 0, 0);

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

void MoveLeft(){ // Shift current block down by 1 pixel per "turn"
  // // First clear the trail from the last frame (prevent the block "smearing")
  // for (int i = 0; i < 4; ++i){
  //   for (int j = 0; j < 3; ++j){
  //     FillPixel(yPos + (i - 1) + timeStep, xPos + j, matrix.Color333(0,0,0));
  //   }
  // }
  // // Next print the next frame of the block
  // for (int i = 0; i < 4; ++i){
  //   for (int j = 0; j < 3; ++j){
  //     if (blockLayout[i][j] == 1) {
  //       FillPixel(yPos + i + timeStep, xPos + j, blockColor);
  //     }
  //   }
  // }
  for (int i=0; i < rows; i++){
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

void EndTurn() { // Set things up for the nxt block and check for complete rows

  timeStep = 0; // Reset the step
  // UpdateDisplay();
}

void ClearDisplay(){
  // Clear background completely
  matrix.fillScreen(0);
}

void createGround() {
  for (int i=29; i < rows; i++){
    for (int j=0; j < cols; j++){
      matrix.drawPixel(i, j, groundColor);
    }
  }
}

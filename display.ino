// TODO: Delete full rows

// TODO: Calculate Score

// TODO: Display Grid

// TODO: Display Blocks

// TODO: Make Sound

// TODO: Game Over

  // ============= //
 //  START GRID   //
// ============= //

// Define constants

const int cols = 16;
const int rows = 32;

  // Colors

  const int xColor[] = {200,30,30};
  const int iColor[] = {200,30,30};
  const int tColor[] = {240,160,30};
  const int zColor[] = {200,30,30};

// Define Variables
int i,j;
int pixel[cols][rows];

void Grid(){
  // Clear background each frame (this prevents smearing as things move)
  // matrix.fillScreen(0);
  
  for (i=0;i < rows;i++){
    for (j=0;j < cols;j++){
      matrix.drawPixel(i,j, matrix.Color333(0, 0, 0));
      // pixel[i][j] = 0;
    }
  }

  Serial.println("done");
}

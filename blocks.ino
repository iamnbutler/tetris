// TODO: Make Blocks
//   int currentBlock = block[0,0,2,2,blockType,0];

int blockLayout[4][3] = {{0,0,0},{0,0,0},{0,0,0},{0,0,0}},
    prevBlockLayout[4][3] = {{0,0,0},{0,0,0},{0,0,0},{0,0,0}},
  xPos            = 0,
  yPos            = 0,
  blockWidth      = 0,
  blockHeight     = 0,
  blockColor      = 0,
  rotation        = 0; // Rotation in degrees, can be 0, 90, 180, 270

int lastLine = 0;       // This starts faux collision detection

  // Colors

  const int xbColor = matrix.Color333(200,30,30);
  const int ibColor = matrix.Color333(140,0,130);
  const int tbColor = matrix.Color333(240,160,30);
  const int zbColor = matrix.Color333(120,30,30);
  const int sbColor = matrix.Color333(60,60,0);
  const int lbColor = matrix.Color333(30,90,120);
  const int jbColor = matrix.Color333(170,120,90);

void NewBlock(){

  turnStart = false;

  // Store the previous block layout before defining new block
  prevBlockLayout[4][3] = blockLayout[4][3];

  // TODO: protection against the same block coming up more than twice in a row
  int blockType = random(1,6);

  // Block blockTypes: X = 0, T = 1, L = 2, J = 3, I = 4, S = 5, Z = 6
  switch (blockType) { // Define block layouts
    case 0: // x shape
      blockLayout[2][0] = 1;
      blockLayout[2][1] = 1;
      blockLayout[3][0] = 1;
      blockLayout[3][1] = 1;
      blockColor = xbColor;
      break;
    case 1: // T shape
      blockLayout[2][1] = 1;
      blockLayout[3][0] = 1;
      blockLayout[3][1] = 1;
      blockLayout[3][2] = 1;
      blockColor = tbColor;
      break;
    case 2: // L shape
      blockLayout[1][0] = 1;
      blockLayout[2][0] = 1;
      blockLayout[3][0] = 1;
      blockLayout[3][1] = 1;
      blockColor = lbColor;
      break;
    case 3: // J shape
      blockLayout[3][0] = 1;
      blockLayout[1][1] = 1;
      blockLayout[2][1] = 1;
      blockLayout[3][1] = 1;
      blockColor = jbColor;
      break;
    case 4: // I shape
      blockLayout[0][0] = 1;
      blockLayout[1][0] = 1;
      blockLayout[2][0] = 1;
      blockLayout[3][0] = 1;
      blockColor = ibColor;
      break;
    case 5: // S shape
      blockLayout[2][0] = 1;
      blockLayout[2][1] = 1;
      blockLayout[3][1] = 1;
      blockLayout[3][2] = 1;
      blockColor = sbColor;
      break;
    case 6: // J shape
      blockLayout[2][0] = 1;
      blockLayout[2][1] = 1;
      blockLayout[3][1] = 1;
      blockLayout[3][2] = 1;
      blockColor = jbColor;
      break;
  }

  rotation = 0; // Block default rotation state

  // TODO: end turn when block reaches last row
  if (yPos >= lastLine) {
    turn++;
  }
}



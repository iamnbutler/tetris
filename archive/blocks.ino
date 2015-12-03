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

void CreateBlock(){

  // Store the previous block layout before defining new block
  prevBlockLayout[4][3] = blockLayout[4][3];

  // Store the previous block layout before defining new block
  prevBlockLayout[4][3] = blockLayout[4][3];

  // TODO: protection against the same block coming up more than twice in a row
  int blockType = random(1,6);

}
// TODO: Make Blocks
	
	// TODO: protection against the same block coming up more than twice in a row

int block[]           = {0,0,0,0}, // Block data: {xPos, yPos, blockType, rotation}
	xPos              = 0,
	yPos              = 0,
	blockType         = 0, // Block types: square = 0, T = 1, L = 2, J = 3, I = 4, S = 5, Z = 6
	rotation          = 0, // Rotation in degrees, can be 0, 90, 180, 270
	blockSize         = 20;

// Block Colors
final int tetColor0 = color(0,0,0), 
			tetColor1 = color(0,0,0),
			tetColor2 = color(0,0,0),
			tetColor3 = color(0,0,0),
			tetColor4 = color(0,0,0),
			tetColor5 = color(0,0,0),
			tetColor6 = color(0,0,0);
// Tetris

// TODO: Start Game

void setup() { // Run once
	// Framerate defaults to 60

	size(180, 320);
}

void run() { // Run the game

}

void keyPressed() { // Keybinds
  if (curr == null || game_over)
    return;
  switch(keyCode) {
    case LEFT : curr.left(); break;
    case RIGHT : curr.right(); break;
    case UP : curr.rotate(); break;
    case DOWN : curr.down(); break;
    case ' ' : curr.hardDown(); break;
  }
}
/// Display game board
enum GRID { PLAYER1, PLAYER2, EMPTY };
void displayBoard(GRID array[C4_ROW][C4_COLUMN]) {
	int r, // row
		c; // column


		   // Display top bar here
	cout << "X";
	for (c = 0; c < C4_COLUMN; c++) {
		cout << "  " << c;
	}
	cout << "  X\n";

	// Display board here
	for (r = 0; r < C4_ROW; r++) {

		// Left-side table index here
		cout << "\x1b[0m" << r;

		// Main table values
		for (c = 0; c < C4_COLUMN; c++) {

			if (array[r][c] == EMPTY) {
				cout << "\x1b[0m  -";
			}
			else if (array[r][c] == PLAYER1) {
				cout << "\u001b[38;5;160m  X";
			}
			else if (array[r][c] == PLAYER2) {
				cout << "\u001b[38;5;226m  O";
			}
		}

		// Right-side table index here
		cout << "\x1b[0m" << "  " << r << "\n";
	}

	// Display bottom index here
	cout << "X";
	for (c = 0; c < C4_COLUMN; c++) {
		cout << "  " << c;
	}
	cout << "  X\n";
}


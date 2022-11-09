#include <iostream>
#include "./connect4.hpp"
using namespace std;
class C4Interface {

private:
  int countClick = 0;

private:
  /* data */

public:
  void displayMenu();
  int menuChoose();
  void displayBoard(int board[C4_ROW][C4_COLUMN]);
};

void C4Interface::displayMenu() {
  printf("==========================\n");
  printf("Each player chooses a different color piece, for example: with the "
         "black side playing first and the white side playing second. The "
         "player who connects the four pieces in a line wins.\n\n");
  printf("0. play with other player\n");
  printf("1. play with computer\n");
  printf("2. check the score\n");
  printf("3. check the record list\n");
  printf("4.quit\n\n");
  printf("==========================\n");
}
int C4Interface::menuChoose() {
  int choose = 0;
  while (1) {
    scanf("%d", &choose);
    if (choose == 0 || choose == 1 || choose == 2 || choose == 3 ||
        choose == 4) {
      break;
    }
    printf("Input must between 0 to 4. Please input again\n");
  }
  return choose;
}
void C4Interface::displayBoard(int array[C4_ROW][C4_COLUMN]) {
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

			if (array[r][c] == NONE) {
				cout << "\x1b[0m  -";
			}
			else if (array[r][c] == RED) {
				cout << "\u001b[38;5;160m  X";
			}
			else if (array[r][c] == YELLOW) {
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

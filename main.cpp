
#pragma one
#include <iomanip>
#include <iostream>
#include <string>

#include "./core/c4_interface.hpp"
#include "./core/common.hpp"
#include "./core/connect4.hpp"

using namespace std;
int main() {
  C4Interface *c4Interface = new C4Interface();
  int board[C4_ROW][C4_COLUMN];

  for (size_t i = 0; i < C4_ROW; i++) {
    for (size_t k = 0; k < C4_COLUMN; k++) {
      board[i][k] = NONE;
    }
  }
  int index = -1;
  index = dropPiece(0, RED, board);
  cout << index << endl;
  index = dropPiece(0, YELLOW, board);
  cout << index << endl;
  index = dropPiece(3, RED, board);
  cout << index << endl;
  dropPieceToIndex(31, YELLOW, board);

  c4Interface->displayBoard(board);
  return 0;
}
/// lineNumber: the number player choose
/// @return the step, what index number is changed.
// int dropPiece(int lineNumber, PieceColor color, int **array){

// 	int x, turn = 1;
//   bool win;
//   string p1Name, p2Name;
//   //GRID a[C4_ROW][C4_COLUMN];

//   //Get names
//   cout << "Please enter a name for Player 1: ";
//   cin >> p1Name;

//   cout << "Please enter a name for Player 2: ";
//   cin >> p2Name;

//   for (int r = 0; r < C4_ROW; r++)
//       for (int c = 0; c < C4_COLUMN; c++)
//         array[r][c] = 0;

//    // displayBoard(a);

//   // sets initializer place
//   x = 1;

//   while (win == false) {

//     if (turn % 2 == 1) {
//       cout << "\n" << p1Name << ", Your Turn" << endl;
//       cout << "Enter Column #: ";
//       cin >> lineNumber;

//       x = 1;
// 			// dropPiece(lineNumber, 1, array)
//       // place checker
//       while (!(array[C4_ROW - x][lineNumber - 1] == 0)) {
//         x++;

//         // Overflow checker
//         if (x > C4_ROW) {

//           cout << "\nColumn " << lineNumber << " is Full" << endl;
//           cout << "Choose another Column #: ";
//           cin >> lineNumber;
//           x = 0;

//         } // end if x > c4_row
//       }   // end while !(array[C4_ROW - x][lineNumber - 1] == EMPTY)

//       array[C4_ROW - x][lineNumber - 1] = 0;

//     } // end if turn % 2 == 1
//     else if (turn % 2 == 0) {

//       cout << "\n" << p2Name << ", Your Turn " << endl;
//       cout << "Enter Column #: ";
//       cin >> lineNumber;

//       // place checker
//       while (!(array[C4_ROW - x][lineNumber - 1] == 0)) {
//         x++;

//         // Overflow checker
//         if (x > C4_ROW) {

//           cout << "\nColumn " << lineNumber << " is Full" << endl;
//           cout << "Choose another Column #: ";
//           cin >> lineNumber;
//           x = 0;

//         } // end if x > c4_row
//       }   // end while !(array[C4_ROW - x][lineNumber - 1] == EMPTY)

//       array[C4_ROW - x][lineNumber - 1] = 0;

//     } // end else if turn %2 ==0

//     // turn counter
//     turn++;

//     // initializer
//     x = 1;
//     //displayBoard(a);
//     return lineNumber;
//   } // end while win == false

// /// Display game board
// enum GRID { PLAYER1 = 1, PLAYER2 = 2, EMPTY = 0 };
// void displayBoard(GRID array[C4_ROW][C4_COLUMN])
// {
//   int r, // row
//       c; // column

//   cout << endl;

//   for (r = 0; r < C4_ROW; r++) {
//     cout << C4_ROW - r;

//     for (c = 0; c < C4_COLUMN; c++) {

//       if (array[r][c] == 0) {
//         cout << " _ ";
//       } else if (array[r][c] == PLAYER1) {
//         cout << " X ";
//       } else if (array[r][c] == PLAYER2) {
//         cout << " O ";
//       }
//     }
//     cout << endl;
//   }
//   for (c = 1; c <= C4_COLUMN; c++) {
//     cout << "  " << c;
//   }
//   cout << endl;
// }
//   }
// //         cout << "\n";

//  //  int option;
//  //  cout << "Please choose your option: (0- " <<size<<")";
//  // cin >> option;

//  //  for (int i = 0; i < size; i++) {
//  //    cout << i + 2;
//  //    cout << recording_list[i][3];
//  //   cout << recording_list[i][4];

//    // return 0;
// //}
// //}

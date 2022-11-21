/* ********************************************************
**                       Game Board                      **  
** Drops game piece into selected column and displays    **
** the game board                                        **
**********************************************************/

#include "../connect4.hpp"
#include "../common.hpp"

namespace std {
int dropPiece(int lineNumber, PieceColor color, int array[C4_ROW][C4_COLUMN]) {
  if (lineNumber > 6 || lineNumber < 0) {
    throw "Error";
  }
  int *loop = array[0];
  int i = C4_ROW - 1;
  for (; i >= 0; i--) {
    if (array[i][lineNumber] == NONE) {
      array[i][lineNumber] = color;
      break;
    }
  }
  int index = i * C4_COLUMN + lineNumber;
  return index;
}
void dropPieceToIndex(int index, PieceColor color,
                      int array[C4_ROW][C4_COLUMN]) {
  int row = index / C4_COLUMN;
  int column = index - row * C4_COLUMN;
  array[row][column] = color;
}
} // namespace std

int Connect4::dropPiece(int line, PieceColor color) {
  int index = -1;
  index = std::dropPiece(line, color, this->_table);
  // log("c4 drop");
  return index;
}
void Connect4::getBoard(int newBoard[C4_ROW][C4_COLUMN]) {
  for (int i = 0; i < C4_ROW; i++) {
    for (int k = 0; k < C4_COLUMN; k++) {
      newBoard[i][k] = this->_table[i][k];
    }
  }
}

void Connect4::init() {
  for (int i = 0; i < C4_ROW; i++) {
    for (int k = 0; k < C4_COLUMN; k++) {
      this->_table[i][k] = NONE;
    }
  }
}
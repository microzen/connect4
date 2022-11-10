
// Please check the C++ Style Guide
// https://google.github.io/styleguide/cppguide.html

#pragma one
#include <iomanip>
#include <iostream>
#include <string>

#include "./core/c4_interface.hpp"
#include "./core/connect4.hpp"
#include "./core/common.hpp"

using namespace std;
int main() {
  C4Interface *c4Interface = new C4Interface();
  int board[C4_ROW][C4_COLUMN];

  for (size_t i = 0; i < C4_ROW; i++)
  {
    for (size_t k = 0; k < C4_COLUMN; k++)
    {
      board[i][k] = NONE;
    }
  }
  int index = -1;
  index = dropPiece(0, RED, board);
  cout<<index<<endl;
  index = dropPiece(0, YELLOW, board);
  cout<<index<<endl;
  index = dropPiece(3, RED, board);
  cout<<index<<endl;
  dropPieceToIndex(31, YELLOW, board);

  c4Interface->displayBoard(board);
  return 0;
}
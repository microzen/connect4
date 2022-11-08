
// Please check the C++ Style Guide
// https://google.github.io/styleguide/cppguide.html

#pragma one
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "./demo/demo_hpp.hpp"
#include "./common/file_operator.hpp"
#include "./core/c4_interface.hpp"
#include "./connect4/winning.hpp"

using namespace std;
int main()
{

  C4Interface *c4Interface = new C4Interface();
  c4Interface->displayMenu();

  int chose = c4Interface->menuChoose();

  int board[C4_ROW][C4_COLUMN];

  for (size_t i = 0; i < C4_ROW; i++)
  {
    for (size_t k = 0; k < C4_COLUMN; k++)
    {
      board[i][k] = NONE;
    }
  }

  board[5][1] = RED;
  board[5][0] = YELLOW;

  c4Interface->displayBoard(board);

  return 0;
}

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
  int size = 10;
  int array[] = {41, 40, 35, 36, 29, 30, 37, 21, 22, 38};
  isWin(array, size);

  return 0;
  C4Interface *c4Interface = new C4Interface();
  c4Interface->displayMenu();

  int chose = c4Interface->menuChoose();
  return 0;
}
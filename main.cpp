
// Please check the C++ Style Guide
// https://google.github.io/styleguide/cppguide.html

#pragma one
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "./demo/demo_hpp.hpp"
#include "./common/file_operator.hpp"

using namespace std;
int main()
{
  HelloWorld("Yezhi");

  string *file = FileReader("");
  for (size_t i = 0; i < FILE_LINE_SIZE; i++)
  {
    cout << file[i] << endl;
  }

  for (size_t i = 0; i < 7 * 6; i++)
  {
    if (i % 7 == 0)
    {
      cout << endl;
    }
    cout << setw(4) << i;
  }

  return 0;
}
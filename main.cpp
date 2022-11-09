
// Please check the C++ Style Guide
// https://google.github.io/styleguide/cppguide.html

#pragma one
#include <iostream>
#include <string>
#include <iomanip>

#include "./demo/demo_hpp.hpp"
#include "./core/convert.hpp"
#include "./core/c4_interface.hpp"

using namespace std;
int main()
{
  int size = 7;
  std::string str = "a1ee;a2;a3;a4;a5;a6;a7";
  std::string *arr = convertToArray(str, ";", size);
  for (size_t i = 0; i < size; i++)
  {
    cout << arr[i] << endl;
  }

  return 0;
}

// Please check the C++ Style Guide
// https://google.github.io/styleguide/cppguide.html

#pragma one
#include <iomanip>
#include <iostream>
#include <string>

#include "./core/c4_interface.hpp"
#include "./core/convert.hpp"
#include "./core/file_operator.hpp"
#include "./demo/demo_hpp.hpp"

using namespace std;
int main() {
  int fsize = 10;
  string *files = readFileToStringArray("./test.txt", fsize);

  int size = 3;
  for (int i = 0; i < fsize; i++) {
    std::string *arr = convertToArray(files[i], ";", size);
    cout << "name  " << arr[0] << endl;
  }
  return 0;
}
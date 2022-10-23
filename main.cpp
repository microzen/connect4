
// Please check the C++ Style Guide
// https://google.github.io/styleguide/cppguide.html

// #include <iostream>
// #include "demo.h"

// int main(int argc, char const *argv[])
// {
//     LOG;
//     return 0;
// }

#include <iostream>
#include <string>
#include <vector>

#include "./common/demo.hpp"
#include "./common/fileReader.hpp"

using namespace std;
int main() {
  HelloWorld("Yezhi");

  string *file = FileReader("");
  for (size_t i = 0; i < FILE_LINE_SIZE; i++) {
    cout << file[i] << endl;
    }
  return 0;
}
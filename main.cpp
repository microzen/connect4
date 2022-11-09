
// Please check the C++ Style Guide
// https://google.github.io/styleguide/cppguide.html

#pragma one
#include <iomanip>
#include <iostream>
#include <string>

#include "./core/c4_interface.hpp"
#include "./core/common.hpp"
#include "./demo/demo_hpp.hpp"

using namespace std;
int main() {
  int fsize = 4;
  string *files = readFileToStringArray("./recording_list.txt", fsize);
  cout << "File:" << endl;
  for (int i = 0; i < fsize; i++) {
    cout << files[i] << endl;
  }

  int size = 5;
  string str = files[0];
  string *array = convertToArray(str, ";", size);
  cout << "\nFirst line:" << endl;
  for (int i = 0; i < size; i++) {
    cout << array[i] << endl;
  }
  int reSize = stoi(array[3]); // (int array[3]);
  string *reStr = convertToArray(array[4], ",", reSize);

  cout << "\nRecording list:" << endl;
  for (int i = 0; i < reSize; i++) {
    cout << reStr[i] << endl;
  }
  return 0;
}
#include <iostream>
#include <string>

#include "fileReader.hpp"

using namespace std;

string *FileReader(string path) {

  string *fileStr = new string[FILE_LINE_SIZE];

  for (size_t i = 0; i < FILE_LINE_SIZE; i++) {
    fileStr[i] = to_string(i);
  }

  return fileStr;
}
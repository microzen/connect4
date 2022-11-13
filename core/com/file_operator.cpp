// Example, you can change anything but follow the rule
// string[] readFileToStringArray(string,int = FILE_LINE_MAX_SIZE)

#include <fstream>
#include <string>
#include "../common.hpp"

std::string *readFileToStringArray(std::string path, int lineSize = FILE_LINE_MAX_SIZE)
{
  std::ifstream connect4;
  connect4.open(path);
  // connect4.open(path, std::ios::out);
  std::string *fileStr = new std::string[lineSize];
  for (size_t i = 0; i < lineSize; i++)
  {
    getline(connect4, fileStr[i]);
  }
  connect4.close();
  return fileStr;
}
void writeFileToStringArray(std::string path, std::string *array, int size = FILE_LINE_MAX_SIZE)
{
  std::ofstream connect4;
  connect4.open(path);
  // connect4.open(path, std::ios::in);
  std::string strStream;
  for (size_t i = 0; i < size - 1; i++)
  {
    strStream = array[i];
    connect4 << strStream << std::endl;
  }
  connect4 << array[size - 1];
  connect4.close();
}
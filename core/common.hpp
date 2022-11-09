

#ifndef COMMON_HPP
#define COMMON_HPP

#define FILE_LINE_MAX_SIZE 10

#include <iostream>
#include <string>
std::string *readFileToStringArray(std::string, int);
std::string convertToString(std::string arrays[], std::string replacer, int size);
std::string *convertToArray(std::string str, std::string replacer, int size);
#endif

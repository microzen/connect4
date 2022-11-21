/* ********************************************************
**                    Common Header file                 **  
**********************************************************/

#ifndef COMMON_HPP
#define COMMON_HPP

#define FILE_LINE_MAX_SIZE 10

#include <iostream>
#include <string>



std::string *readFileToStringArray(std::string, int);
void writeFileToStringArray(std::string, std::string *, int);
std::string convertToString(std::string arrays[], std::string replacer, int size);
std::string *convertToArray(std::string str, std::string replacer, int size);
void log(std::string);
void log(int);
void log(double);
void log(long long);
#endif

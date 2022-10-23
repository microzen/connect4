#include <iostream>
#include <vector>
#include <string>

#include "fileReader.hpp"
using namespace std;
vector<string> FileReader(string path)
{
    vector<string> ve;
    for (size_t i = 0; i < ROW_SIZE; i++)
    {
        ve.push_back(to_string(i));
    }
    return ve;
}
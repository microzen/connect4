#include <iostream>
#include <string>
#include "../common.hpp"
using namespace std;
void log(string str)
{
    cout<<"LOG: " << str << endl;
}
void log(int log)
{
    cout<<"LOG: " << log << endl;
}

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
#include <vector>
#include <string>

#include "./common/demo.hpp"
#include "./common/fileReader.hpp"

using namespace std;
int main()
{
    HelloWorld("Yezhi");
    
    vector<string> ve = FileReader("");
    for (size_t i = 0; i < ve.size(); i++)
    {
        cout << ve[i]<<endl;
    }
    
    return 0;
}
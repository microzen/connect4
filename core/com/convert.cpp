#include <string>
using namespace std;
string convertToString(string arrays[], string replacer, int size)
{
    string str = "";
    for (int i = 0; i < size; i++)
    {
        if (i > 0)
        {
            str = str + replacer;
        }
        str = str + arrays[i];
    }
    return str;
}

std::string *convertToArray(std::string str, std::string replacer, int size)
{
    std::string* result = new string[size];
    std::string::size_type begin, end;

    end = str.find(replacer);
    begin = 0;
    for (size_t i = 0; i < size - 1; i++)
    {
        result[i] = str.substr(begin, end - begin);
        begin = end + replacer.size();
        end = str.find(replacer, begin);
    }
    result[size - 1] = str.substr(begin, end - begin);
    return result;
}
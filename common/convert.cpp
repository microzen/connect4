#include <string>
#include <vector>
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

std::vector<std::string> convertToArray(std::string str, std::string replacer)
{
    std::vector<std::string> result;
    std::string::size_type begin, end;

    end = str.find(replacer);
    begin = 0;

    while (end != std::string::npos)
    {
        if (end - begin != 0)
        {
            result.push_back(str.substr(begin, end - begin));
        }
        begin = end + replacer.size();
        end = str.find(replacer, begin);
    }

    if (begin != str.length())
    {
        result.push_back(str.substr(begin));
    }
    return result;
}
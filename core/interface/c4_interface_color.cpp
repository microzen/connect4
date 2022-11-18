#include "../c4_interface.hpp"

std::string C4Interface::redStr(std::string str)
{
    std::string _redstr ="\u001b[38;5;160m";
    _redstr +=str + "\x1b[0m";
    return _redstr;
}

std::string C4Interface::yellowStr(std::string str)
{
    std::string _redstr ="\u001b[38;5;226m";
    _redstr +=str +"\x1b[0m";
    return _redstr;
}
#include <string>
#include <ctime>
#include "../connect4.hpp"
#include "../common.hpp"
using namespace std;
string IPlayer::serializeInfo()
{
    string score = to_string(this->_score);
    string name = this->_name;

    time_t rawtime;
    struct tm *tinfo;
    char buffer[10];
    time(&rawtime);
    tinfo = localtime(&rawtime);

    string strtime = to_string(1900 + tinfo->tm_year) + "-" + to_string(tinfo->tm_mon) + "-" + to_string(tinfo->tm_mday);
    string info = name + ";" + score + ";" + strtime;
    return info;
}
string IC4Game::serializeInfo(){
    // #TODO:
    return "";
}
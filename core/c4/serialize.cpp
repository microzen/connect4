#include "../common.hpp"
#include "../connect4.hpp"
#include <ctime>
#include <string>
using namespace std;
string IPlayer::serializeInfo() {
  string score = to_string(this->_score);
  string name = this->_name;

  time_t rawtime;
  struct tm *tinfo;
  char buffer[10];
  time(&rawtime);
  tinfo = localtime(&rawtime);

  string strtime = to_string(1900 + tinfo->tm_year) + "-" +
                   to_string(tinfo->tm_mon) + "-" + to_string(tinfo->tm_mday);
  string info = name + ";" + score + ";" + strtime;
  return info;
}

string IC4Game::serializeInfo()
{
    //[player1_name];[player2_name];[date];[size];[recording]
    string player1 = this->_player[0]->getName();
    string player2 = this->_player[1]->getName();
    string data = "test";
    C4Recording *re = this->recording;
    int size = re->getSize();
    int *r_array = this->recording->toArray();
    // TODO:
    return "";

}
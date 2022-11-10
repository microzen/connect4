#include <iostream>
#include "../connect4.hpp"

using namespace std;
class ConnectSub
{
public:
    void dropPiece(int);
};
class User
{
private:
    string _name;
    int _score;

public:
    User(std::string, int);
    ~User();
    // void Winning(Recording);
protected:
    void Save();
};

User::User(std::string name, int score)
{
    this->_name = name;
    this->_score = score;
}

User::~User()
{
}

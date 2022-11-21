/* ********************************************************
**                       About Game                      **  
**********************************************************/

#include "../connect4.hpp"
#include "../common.hpp"

IC4Game::IC4Game()
{
    this->_turn = -1;
}

void IC4Game::getReady(IC4 *connect4, IPlayer *player1, IPlayer *player2)
{
    if (this->_status != UNSTART)
    {
        throw "Status is not UNSTART!";
    }
    this->_connect4 = connect4;
    this->_connect4->init();

    this->_player[0] = player1;
    this->_player[1] = player2;
    this->_player[0]->setColor(RED);
    this->_player[1]->setColor(YELLOW);

    this->recording = new C4Recording();

    this->_status = PLAYING;
    this->start_time = std::chrono::system_clock::now();
    this->_turn = -1;
    this->player_time[0] = 0;
    this->player_time[1] = 0;
    
    // #TODO:
}

void IC4Game::nextTurn()
{
    if (this->getStatus() != PLAYING)
    {
        throw "Game haven't started!";
    }
    if (getTurnNumber() >= 0)
    {
        this->end_time = std::chrono::system_clock::now();
        std::chrono::duration<double> diff = this->end_time - this->start_time;
        long long turn_time_used = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
        this->player_time[this->getTurnNumber() % 2] += (turn_time_used / 1000.0);
        this->start_time = std::chrono::system_clock::now();
    }

    this->_turn++;
}
C4Status IC4Game::getStatus()
{
    return this->_status;
}
void IC4Game::setStatus(C4Status status)
{
    this->_status = status;
}
IPlayer *IC4Game::currentPlayer()
{
    return this->_player[this->getTurnNumber() % 2];
    ;
}
IC4 *IC4Game::IC4Game::getConnect4()
{
    return this->_connect4;
}
int IC4Game::getTurnNumber()
{
    return this->_turn;
}
double IC4Game::currentPlayerUsedTimeAsSeconds()
{
    return this->player_time[this->getTurnNumber() % 2];
}
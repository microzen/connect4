#include "../connect4.hpp"
// void IC4Game::setPlayer(IPlayer *player)
// {
//     this->_player[0] = player;
// }
IC4Game::IC4Game(){
    this->_turn = 0;
}
void IC4Game::start(IC4 *connect4, IPlayer *player1, IPlayer *player2)
{
    if(this->_status != UNSTART){
        throw "Status is not UNSTART!";
    }
    this->_player[0] = player1;
    this->_player[1] = player2;
    this->_connect4 = connect4;
    this->current= this->_player[0];
    this->_player[0]->setColor(RED);
    this->_player[1]->setColor(YELLOW);
    this->_connect4->init();
    this->recording = new C4Recording();

    // #TODO:
}
void IC4Game::nextTurn()
{
    if(this->_status != PLAYING){
        throw "Game haven't started!";
    }
    this->_turn++;
    current = this->_player[this->_turn / 2];
}
C4Status IC4Game::getStatus()
{
    return this->_status;
}
void IC4Game::setStatus(C4Status status)
{
    // #TODO:
}
IPlayer *IC4Game::currentPlayer()
{
    return this->current;
    // #TODO:
}
IC4 *IC4Game::IC4Game::getConnect4()
{
    return this->_connect4;
}
int IC4Game::getTurnNumber()
{
    return this->_turn;
}
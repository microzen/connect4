#include <string>
#include "../connect4.hpp"
IPlayer::IPlayer(std::string name,IC4 *ic4){
    this->_name =name;
    this->_connect4 = ic4;
}
int IPlayer::dropPiece(int line)
{
    this->_connect4->dropPiece(line, this->_color);
}
void IPlayer::setColor(PieceColor color)
{
    this->_color = color;
}
std::string IPlayer::getName()
{
    return this->_name;
}
void IPlayer::setScore(int score)
{
    this->_score = score;
}
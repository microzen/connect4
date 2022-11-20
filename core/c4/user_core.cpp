#include "../connect4.hpp"
#include <string>
IPlayer::IPlayer(std::string name, IC4 *ic4) {
  this->_name = name;
  this->_connect4 = ic4;
}
int IPlayer::dropPiece(int line) {
  int index = -1;
  index = this->_connect4->dropPiece(line, this->_color);
  return index;
}
void IPlayer::setColor(PieceColor color) { this->_color = color; }
std::string IPlayer::getName() { return this->_name; }
void IPlayer::setScore(int score) { this->_score = score; }
PieceColor IPlayer::getColor() { return this->_color; }
int IPlayer::getScore() { return this->_score; }
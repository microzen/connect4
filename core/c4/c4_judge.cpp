#include "../connect4.hpp"
// bool IC4BaseRule::isWin()
// {
//     return false;
// }
// IJudgeProxy::IJudgeProxy(IPlayer *player1, IPlayer *player2, IC4 *connect4, IC4Game *game){
//     this->_connect4 = connect4;
//     this->_game=game;
//     this->_game->setPlayer(player1);
//     this->_game->setPlayer(player2);
//     this->_player[0] = player1;
//     this->_player[1] = player2;
//     this->_player[0]->setColor(RED);
//     this->_player[1]->setColor(YELLOW);
// }
int IJudgeProxy::dropPiece(int step,PieceColor color){
    
    this->_recording->addStep(step);
    // this.
}
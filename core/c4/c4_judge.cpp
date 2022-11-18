#include "../connect4.hpp"
#include "../common.hpp"
// bool IC4BaseRule::isWin(int *steps, int size)
// {
//     return false;
// }
IJudgeProxy::IJudgeProxy(IC4BaseRule *rule, IC4 *connect4, IC4Game *game)
{
    this->_game = game;
    this->_connect4 = connect4;
    this->_rule = rule;

    this->_r_recording = new C4Recording();
    this->_y_recording = new C4Recording();
}
int IJudgeProxy::dropPiece(int step, PieceColor color)
{
    int index = 0;
    bool iswin = false;

    index = this->_connect4->dropPiece(index,color);
    this->_game->recording->addStep(index);

    C4Recording *color_recording = nullptr;
    if (color == RED)
    {  
        color_recording = this->_r_recording;
    }
    else if (color == YELLOW)
    {
        color_recording = _y_recording;
    }else{
        throw "Wrong Color";
    }
    color_recording->addStep(step);
    iswin = this->_rule->isWin(color_recording->toArray(), color_recording->getSize());
    if (iswin){
        this->_game->setStatus(WON);
    }
    return index;
}
void IJudgeProxy::getBoard(int board[C4_ROW][C4_COLUMN]){
   return this->_connect4->getBoard(board);
}
void IJudgeProxy::init(){
    this->_connect4->init();
}
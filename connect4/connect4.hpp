#ifndef connect4_hpp
#define connect4_hpp

#define C4_ROW 6
#define C4_COLUMN 7

enum PieceColor{
    NONE = 0,
    RED,
    YELLOW
};

#include <iostream>
#include <time.h>
#include <string>

class Connect4
{
public:
    int getInTurn();
    void dropPiece(int);
    bool isWin();
    std::string **getTable();

private:
    int _turn;
    time_t _start_time;
    void _reset();
    std::string **_table;
};

#endif
#ifndef CONNECT4_HPP
#define CONNECT4_HPP

#include <string>

#define C4_ROW 6
#define C4_COLUMN 7
#define C4_MAXVALUE 42

enum PieceColor
{
    NONE = 0,
    RED,
    YELLOW
};
enum C4Status
{
    UNSTART = -1,
    PLAYING = 1,
    WON = 2,
    END = 0
};

int dropPiece(int, PieceColor, int [C4_ROW][C4_COLUMN]);
void dropPieceToIndex(int, PieceColor, int [C4_ROW][C4_COLUMN]);

class C4Recording
{
private:
    int _index = -1;
    int _steps[C4_MAXVALUE];

public:
    int *toArray();
    int getSize();
    void removeStep();
    void addStep(int);
};
class IC4
{
protected:
    int _table[C4_ROW][C4_COLUMN];

public:
    int **getBoard();
    void init();
    int dropPiece(int, PieceColor);
};

class IPlayer
{
protected:
    std::string _name;
    PieceColor _color;
    IC4 *_connect4 = nullptr;

public:
    IPlayer(std::string, IC4);
    int dropPiece(int);
};
class IC4BaseRule
{
protected:
    C4Status _status = UNSTART;

public:
    bool isWin();
};
class IC4Game
{
protected:
    IPlayer _player[2];
    IC4 *_connect4 = nullptr;
    IPlayer *current = nullptr;
    C4Recording *_recording = nullptr;
    int _turn = 0;
    int _player_counter = 0;

public:
    IPlayer *currentPlayer();
    void setPlayer(IPlayer);
    void nextTurn();
    int getTurnNumber();
};
class IJudgeProxy : public IPlayer
{
protected:
    C4Recording *_recording = nullptr;
    IC4Game *_game = nullptr;

public:
    IJudgeProxy(IPlayer, IC4Game);
    int dropPiece(int);
};
#endif
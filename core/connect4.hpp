#ifndef CONNECT4_HPP
#define CONNECT4_HPP

#include <string>
#include "./storage.hpp"

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
namespace std
{
    int dropPiece(int, PieceColor, int[C4_ROW][C4_COLUMN]);
    void dropPieceToIndex(int, PieceColor, int[C4_ROW][C4_COLUMN]);
} // namespace std

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
    IC4();
    void getBoard(int[C4_ROW][C4_COLUMN]);
    void init();
    int dropPiece(int, PieceColor);
};

class IPlayer : ISerialize
{
protected:
    std::string _name;
    int _score;
    PieceColor _color;
    IC4 *_connect4 = nullptr;

public:
    IPlayer(std::string, IC4*);
    int dropPiece(int);
    void setColor(PieceColor);
    std::string getName();
    void setScore(int);
    std::string serializeInfo();
};
class IC4BaseRule
{
public:
    bool isWin(int*,int);
};
class IC4Game : public ISerialize
{
protected:
    C4Status _status = UNSTART;
    IPlayer *(_player[2]);
    IC4 *_connect4 = nullptr;
    IPlayer *current = nullptr;
    int _turn = 0;
    int _player_counter = 0;

public:
    IC4Game();
    IPlayer *currentPlayer();
    void setPlayer(IPlayer *);
    void nextTurn();
    int getTurnNumber();
    C4Status getStatus();
    std::string serializeInfo();
};
class IJudgeProxy : public IC4Game, public IC4
{
protected:
    C4Recording *_recording = nullptr;
    IC4Game *_game = nullptr;

public:
    IJudgeProxy(IPlayer *, IPlayer *, IC4BaseRule*, IC4 *, IC4Game *);
    int dropPiece(int,PieceColor);
};
#endif
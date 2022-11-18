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
    virtual void getBoard(int[C4_ROW][C4_COLUMN]) = 0;
    virtual void init() = 0;
    virtual int dropPiece(int, PieceColor) = 0;
};

class Connect4 : public IC4
{
public:
    // Connect4();
    void getBoard(int[C4_ROW][C4_COLUMN]);
    void init();
    int dropPiece(int, PieceColor);
};

class IPlayer : public ISerialize
{
protected:
    std::string _name;
    int _score;
    PieceColor _color;
    IC4 *_connect4 = nullptr;

public:
    IPlayer(std::string, IC4 *);
    int dropPiece(int);
    void setColor(PieceColor);
    PieceColor getColor();
    std::string getName();
    void setScore(int);
    int getScore();
    std::string serializeInfo();
};

class IC4BaseRule
{
public:
    bool isWin(int *, int);
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
    void start(IC4 *, IPlayer *, IPlayer *);
    IC4 *getConnect4();
    IPlayer *currentPlayer();
    void setPlayer(IPlayer *);
    void nextTurn();
    int getTurnNumber();
    C4Status getStatus();
    void setStatus(C4Status);
    std::string serializeInfo();
    C4Recording *recording = nullptr;
};
class IJudgeProxy : public IC4 //, public IC4Game
{
protected:
    C4Recording *_r_recording = nullptr;
    C4Recording *_y_recording = nullptr;
    IC4Game *_game = nullptr;
    IC4BaseRule *_rule = nullptr;
    IC4 *_connect4 = nullptr;

public:
    IJudgeProxy(IC4BaseRule *, IC4 *, IC4Game *);
    int dropPiece(int, PieceColor);
    void init();
    void getBoard(int[C4_ROW][C4_COLUMN]);
};
#endif
#ifndef C4INTERFACE_HPP
#define C4INTERFACE_HPP
#include <string>
#include "./connect4.hpp"
class C4Interface
{
private:
    std::string redStr(std::string);
    std::string yellowStr(std::string);

public:
    void displayMenu();
    int menuChoose();
    void displayBoard(int[C4_ROW][C4_COLUMN]);
    std::string askName();
    int askLine(std::string);
    /// @brief
    /// @param  string name
    /// @param  int turn
    /// @param  double time second
    /// @param  PieceColor
    void displayGameInfoWithColor(std::string, int, double, PieceColor);
    /// @brief
    /// @param  string name
    /// @param  int scores
    /// @param  string time
    /// @param  PieceColor
    void displayWinningInfo(std::string, int, std::string, PieceColor);

    /// @brief 
    /// @param  string player one's name
    /// @param  int player two's name
    /// @param  string player one's scores
    /// @param  int player two's scores
    void displayStartInfo(std::string,int,std::string,int);
    void displayRuleOfPlaying();
};
class C4Application
{
private:
    IC4 *_connect4 = nullptr;
    IC4Game *_game = nullptr;
    C4Interface *_interface = nullptr;

public:
    int meunModule(C4Interface *);
    std::string askNameModule(C4Interface *);
    void startGameModule();
    void gameModule(IPlayer *, IPlayer *, IC4Game *, IC4 *, C4Interface *);
    void recordingModule(CacheStorage*,C4Interface*);
    void scoreModule(CacheStorage*);
};
#endif
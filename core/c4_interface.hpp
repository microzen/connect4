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
    /// @param  string time
    /// @param  PieceColor
    void displayPlayerInfoWithColor(std::string, int, std::string, PieceColor);
    /// @brief
    /// @param  string name
    /// @param  int scores
    /// @param  string time
    /// @param  PieceColor
    void displayWinningInfo(std::string, int, std::string, PieceColor);
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
    void recordingModule();
    void scoreModule();
};
#endif
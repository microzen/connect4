#include "../connect4/connect4.hpp"
class C4Interface
{
public:
    void displayMenu();
    int menuChoose();
    void displayBoard(int[C4_ROW][C4_COLUMN]);
};
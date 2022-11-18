#include <iostream>
#include <iomanip>
#include <string>
#include "../c4_interface.hpp"
#include "../connect4.hpp"
#include "../common.hpp"
using namespace std;
void C4Application::gameModule(IPlayer *player1, IPlayer *player2, IC4Game *game, IC4 *connect4, C4Interface *inter)
{
    int line = -1;
    int board[C4_ROW][C4_COLUMN];
    IPlayer *current_player;
    game->start(connect4, player1, player2);

    log("start");
    do
    {
        current_player = game->currentPlayer();
        inter->displayPlayerInfoWithColor(current_player->getName(), game->getTurnNumber(), "test", current_player->getColor());
        line = inter->askLine(current_player->getName());
        current_player->dropPiece(line);
        if (game->getStatus() == WON)
        {
            inter->displayWinningInfo(current_player->getName(), current_player->getScore(), "test", current_player->getColor());
            break;
        }
        game->getConnect4()->getBoard(board);
        inter->displayBoard(board);
        return;
        game->nextTurn();
    } while (1);

    // save
}
int C4Application::meunModule(C4Interface *inter)
{
    inter->displayMenu();

    int choice = inter->menuChoose();

    return choice;
}
std::string C4Application::askNameModule(C4Interface *inter)
{
    return inter->askName();
}

void C4Application::scoreModule()
{
    std::string t_name, t_scores, t_datetime;
    const int score_size = 3; // constant
    CacheStorage *storage = new CacheStorage("score_list.txt");
    int size = storage->getSize();
    // file reader
    std::string *array = storage->getContentAsArray();
    cout << setw(16) << "Name"
         << setw(16) << "Scores"
         << setw(20) << "Data" << endl;

    string score_list[size][score_size];
    string *temp = nullptr;
    for (int i = 0; i < size; i++)
    {
        // conver a string to array by ;
        temp = convertToArray(array[i], ";", score_size);
        score_list[i][0] = temp[0];
        score_list[i][1] = temp[1];
        score_list[i][2] = temp[2];
    }
    for (int i = 0; i < size; i++)
    {
        for (int k = 0; k < size - i - 1; k++)
            if (score_list[k][1] < score_list[k + 1][1])
            {
                t_name = score_list[k][0];
                t_scores = score_list[k][1];
                t_datetime = score_list[k][2];

                score_list[k][0] = score_list[k + 1][0];
                score_list[k][1] = score_list[k + 1][1];
                score_list[k][2] = score_list[k + 1][2];

                score_list[k + 1][0] = t_name;
                score_list[k + 1][1] = t_scores;
                score_list[k + 1][2] = t_datetime;
            } // sort by score
    }
    for (int i = 0; i < size; i++)
    {
        cout << setw(16) << score_list[i][0]
             << setw(16) << score_list[i][1]
             << setw(20) << score_list[i][2] << endl;
    } // display output
}
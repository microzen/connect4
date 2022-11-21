/* ********************************************************
**                     Business Logic                    **
** Displays score list and record list                   **
**********************************************************/

#include <iomanip>
#include <iostream>
#include <string>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#include "../c4_interface.hpp"
#include "../common.hpp"
#include "../connect4.hpp"

using namespace std;

void exit();

void C4Application::gameModule(IPlayer *player1, IPlayer *player2,
                               IC4Game *game, IC4 *connect4,
                               C4Interface *inter) {
  int line = -1;
  int board[C4_ROW][C4_COLUMN];
  IPlayer *current_player = nullptr;
  string name;
  int turn_number;
  double seconds;
  PieceColor color;
  int scores;
  log(1);
  game->getReady(connect4, player1, player2);
  log(2);
  inter->displayStartInfo(player1->getName(), player1->getScore(),
                          player2->getName(), player2->getScore());
  do {

    // log("new turn");
    game->nextTurn(); // turn start form -1
    game->getConnect4()->getBoard(board);
    inter->displayBoard(board);

    current_player = game->currentPlayer();

    name = current_player->getName();
    turn_number = game->getTurnNumber();
    color = current_player->getColor();
    seconds = game->currentPlayerUsedTimeAsSeconds();

    inter->displayGameInfoWithColor(name, turn_number, seconds, color);

    line = inter->askLine(name);
    // log(line);

    cout << "\n";

    current_player->dropPiece(line);

    // log("droped");

    if (game->getStatus() == WON) {

      game->getConnect4()->getBoard(board);
      inter->displayBoard(board);
      
      scores = current_player->getScore();
      inter->displayWinningInfo(name, scores, "Today", color);
      break;
    }

  } while (1);
exit();
  // save
}
int C4Application::meunModule(C4Interface *inter) {
  inter->displayMenu();

  int choice = inter->menuChoose();

  return choice;
}
std::string C4Application::askNameModule(C4Interface *inter) {
  return inter->askName();
}

void C4Application::scoreModule(CacheStorage *storage) {

  std::string t_name, t_scores, t_datetime;
  const int score_size = 3; // constant

  int size = storage->getSize();
  // file reader
  std::string *array = storage->getContentAsArray();

  string score_list[size][score_size];
  string *temp = nullptr;
  for (int i = 0; i < size; i++) {
    // conver a string to array by ;
    temp = convertToArray(array[i], ";", score_size);
    score_list[i][0] = temp[0];
    score_list[i][1] = temp[1];
    score_list[i][2] = temp[2];
  }
  for (int i = 0; i < size; i++) {
    for (int k = 0; k < size - i - 1; k++)
      if (score_list[k][1] < score_list[k + 1][1]) {
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
  cout << "\n=======================[ Score List ]=======================\n"
       << endl;
  cout << left << setw(20) << "Name" << setw(20) << "Scores" << setw(20) << "Date" << endl;
  for (int i = 0; i < size; i++) {
    cout << setw(20) << score_list[i][0] << setw(20) << score_list[i][1] << setw(20)
         << score_list[i][2] << endl;
  } // display output
  
exit();
}
void C4Application::recordingModule(CacheStorage *storage,
                                    C4Interface *c4Interface) {

  cout << "\n=====================[ Recording List ]=====================\n"
       << endl;
  string t_player1, t_player2, t_size, t_data, t_recording;
  const int score_size = 3;     // constant
  const int recording_size = 5; // constant

  int size = storage->getSize();

  std::string *array = storage->getContentAsArray();

  string recording_list[size][5];
  string *temp = nullptr;
  for (int i = 0; i < size; i++) {
    // conver a string to array by ;
    temp = convertToArray(array[i], ";", recording_size);
    recording_list[i][0] = temp[0];
    recording_list[i][1] = temp[1];
    recording_list[i][2] = temp[2];
    recording_list[i][3] = temp[3];
    recording_list[i][4] = temp[4];
  }
  for (int i = 0; i < size; i++) {
    for (int k = 0; k < size - i - 1; k++)
      if (recording_list[k][2] < recording_list[k + 1][2]) {
        t_player1 = recording_list[k][0];
        t_player2 = recording_list[k][1];
        t_data = recording_list[k][2];
        t_size = recording_list[k][3];
        t_recording = recording_list[k][4];

        recording_list[k][0] = recording_list[k + 1][0];
        recording_list[k][1] = recording_list[k + 1][1];
        recording_list[k][2] = recording_list[k + 1][2];
        recording_list[k][3] = recording_list[k + 1][3];
        recording_list[k][4] = recording_list[k + 1][4];

        recording_list[k + 1][0] = t_player1;
        recording_list[k + 1][1] = t_player2;
        recording_list[k + 1][2] = t_data;
        recording_list[k + 1][3] = t_size;
        recording_list[k + 1][4] = t_recording;
      }
  }

  cout << left << setw(8) << "Num";
  cout << setw(30) << "Name";
  cout << setw(10) << "Date" << endl;
  // cout << setw(6) << "Size" << endl;

  for (int i = 0; i < size; i++) {
    cout << left << i + 1 << setw(7) << ") ";
    cout << setw(12) << recording_list[i][0] << setw(6) << " VS ";
    cout << setw(12) << recording_list[i][1];
    cout << setw(10) << recording_list[i][2];
    cout << "\n";
  } // display file

  int option;

  cout << "\nPlease choose your option (0 - " << size
       << ") to display more details: ";
  cin >> option;

  int board[C4_ROW][C4_COLUMN];

  for (size_t i = 0; i < C4_ROW; i++) {
    for (size_t k = 0; k < C4_COLUMN; k++) {
      board[i][k] = NONE;
    }
  }
  int step_size = stoi(recording_list[option - 1][3]);
  string *steps = convertToArray(recording_list[option - 1][4], ",", step_size);
  cout << "\nHistory " << option << "): " << recording_list[option - 1][0]
       << " VS " << recording_list[option - 1][1] << endl;
  for (size_t i = 0; i < step_size; i++) {
    PieceColor color;
    if (i % 2 == 0) {
      color = RED;
    } else {
      color = YELLOW;
    }
    dropPieceToIndex(stoi(steps[i]), color, board);
  }
  c4Interface->displayBoard(board);
  
exit();
}

int get_ch()
{
    struct termios stored_termios, new_termios;
    int ch; //ASCII
    tcgetattr(STDIN_FILENO, &stored_termios); // GET: STDIN_FILENO = Standard input
    new_termios = stored_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO); // Local modes = ICANON
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios); //SET: Immediate
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &stored_termios); // Original termios
    return ch;
}

void exit()
{
    printf("\nPress 'q' or 'esc' key to back [Menu Page]\n");
    int ch; //ASCII
    do
    {
        // loop your assignment code here 
        ch = get_ch();
        // printf("key=%c, ASCII=%d\n", ch,ch); // Or cout<<c<<endl in C++
    } while (ch != 'q' && ch != 27); // Esc = 27, q = 113 in ASCII

    // printf("End! with key '%c'\n",ch);
    // return 0;
}

// Please check the C++ Style Guide
// https://google.github.io/styleguide/cppguide.html

#pragma one
#include <iomanip>
#include <iostream>
#include <string>

#include "./core/c4_interface.hpp"
#include "./core/common.hpp"
#include "./core/connect4.hpp"
#include "./core/storage.hpp"

using namespace std;

int main() {
  string t_player1, t_player2, t_size, t_data, t_recording;
  const int score_size = 3;     // constant
  const int recording_size = 5; // constant

  CacheStorage *storage = new CacheStorage("recording_list.txt");
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

  cout << "Num";
  cout << setw(6) << "Name";
  cout << setw(12) << "Data";
  cout << setw(6) << "Size"<<endl;


  for (int i = 0; i < size; i++) {
    cout << i + 1 << ")" << setw(5) << recording_list[i][0] << "/";
    cout << recording_list[i][1];
    cout << setw(16) << recording_list[i][2];
    cout << "\n";
  } // display file
  
  int option;

  cout << "Please choose your option (0- " <<size<<"):";
  cin >> option;

    cout<<recording_list[option-1][0];
    cout<<setw(16)<<recording_list[option-1][1];
    cout<<setw(16)<<recording_list[option-1][2];
    cout<<setw(20)<<recording_list[option-1][3]<<"\n";
    cout<<recording_list[option-1][4];


  C4Interface *c4Interface = new C4Interface();
  int board[C4_ROW][C4_COLUMN];

  for (size_t i = 0; i < C4_ROW; i++)
  {
    for (size_t k = 0; k < C4_COLUMN; k++)
    {
      board[i][k] = NONE;
    }
  }

  recording_list[i][4]=
  // todo
  // convert the recording list [4] to a array.
  // drop ecch step to borad
  // display
  int index = -1;
  index = dropPiece(0, RED, board);
  cout<<index<<endl;
  index = dropPiece(0, YELLOW, board);
  cout<<index<<endl;
  index = dropPiece(3, RED, board);
  cout<<index<<endl;
  index = dropPiece(3, YELLOW, board);
  cout<<index<<endl;
  index = dropPiece(2, RED, board);
  cout<<index<<endl;
  index = dropPiece(1, RED, board);
  cout<<index<<endl;
  index = dropPiece(4, YELLOW, board);
  cout<<index<<endl;
  index = dropPiece(6, YELLOW, board);
  cout<<index<<endl;
  dropPieceToIndex(38, YELLOW, board);

  c4Interface->displayBoard(board);
  
//  string recording_list[option][4];
 //string *piece = nullptr;
  //for (int i = 0; i < size; i++) {
    //piece = convertArray(array[i],";",recording_option)
  //cout<<recording_list[option-1][0];
   // recording_list[option-1][1]=piece[0];
  //  
    return 0;
  }
    
  



//  }

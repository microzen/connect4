
// Please check the C++ Style Guide
// https://google.github.io/styleguide/cppguide.html

#pragma one
#include <iomanip>
#include <iostream>
#include <string>

#include "./core/c4_interface.hpp"
#include "./core/common.hpp"
#include "./core/storage.hpp"
#include "./core/connect4.hpp"

using namespace std;
int main()
{
  C4Application *app = new C4Application();
  C4Interface *inter = new C4Interface();

  IC4 *connect4 = new Connect4();

  IPlayer *player1 = nullptr;
  IPlayer *player2 = nullptr;
  IC4Game *game = new IC4Game();
  IC4BaseRule *rule = new IC4BaseRule();
  IJudgeProxy *proxy = new IJudgeProxy(rule, connect4, game);
  CacheStorage *recording_storage = new CacheStorage("recording_list.txt");
  CacheStorage *socre_storage = new CacheStorage("score_list.txt");

  int choice = 0;
  do
  {
    choice = app->meunModule(inter);
    switch (choice)
    {
    case 1:
      player1 = new IPlayer(app->askNameModule(inter), proxy);
      player2 = new IPlayer(app->askNameModule(inter), proxy);
      app->gameModule(player1, player2, game, proxy, inter);
      break;

    case 2:
      app->scoreModule(socre_storage);
      break;
    case 3:
      app->recordingModule(recording_storage, inter);
      break;
    default:
      break;
    }

  } while (choice == 0);
  return 0;
}

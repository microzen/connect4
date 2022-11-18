
// Please check the C++ Style Guide
// https://google.github.io/styleguide/cppguide.html

#pragma one
#include <iomanip>
#include <iostream>
#include <string>

#include "./core/c4_interface.hpp"
#include "./core/common.hpp"
#include "./core/storage.hpp"

using namespace std;
int main()
{
  C4Application *app = new C4Application();
  C4Interface *inter = new C4Interface();

  int choice = app->meunModule(inter);

  IC4 *connect4 = new Connect4();

  IPlayer *player1 = nullptr;
  IPlayer *player2 = nullptr;
  IC4Game *game = new IC4Game();
  IC4BaseRule *rule = new IC4BaseRule();
  IJudgeProxy *proxy = new IJudgeProxy(rule, connect4, game);

  switch (choice)
  {
  case 1:
    player1 = new IPlayer(app->askNameModule(inter), proxy);
    player2 = new IPlayer(app->askNameModule(inter), proxy);
    app->gameModule(player1, player2, game, proxy, inter);
    break;

  case 2:
  case 3:
    app->scoreModule();
    break;
  default:
    break;
  }
  return 0;
}


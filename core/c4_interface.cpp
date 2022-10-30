#include <iostream>
using namespace std;
class C4Interface {

private:
  int countClick = 0;

private:
  /* data */

public:
  void displayMenu();
  int menuChoose();
};

void C4Interface::displayMenu() {
  printf("==========================\n");
  printf("Each player chooses a different color piece, for example: with the "
         "black side playing first and the white side playing second. The "
         "player who connects the four pieces in a line wins.\n\n");
  printf("0. play with other player\n");
  printf("1. play with computer\n");
  printf("2. check the score\n");
  printf("3. check the record list\n");
  printf("4.quit\n\n");
  printf("==========================\n");
}
int C4Interface::menuChoose() {
  int choose = 0;
  while (1) {
    scanf("%d", &choose);
    if (choose == 0 || choose == 1 || choose == 2 || choose == 3 ||
        choose == 4) {
      break;
    }
    printf("Input must between 0 to 4. Please input again\n");
  }
  return choose;
}

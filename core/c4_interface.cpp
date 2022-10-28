#include <iostream>
using namespace std;
class C4Interface
{
private:
    /* data */
public:
    void displayMenu();
    int menuChoose();
};

void C4Interface::displayMenu()
{
    printf("1.play with other player\n");
    printf("2.play with computer\n");
    printf("3.check the score\n");
    printf("4.check the record list\n");
}
int C4Interface::menuChoose()
{
    int choose;
    cout << "Each player chooses a different color piece, for example: with the black side playing first and the white side playing second. The player who connects the four pieces in a line wins." << endl
         << endl;

    do
    {
        cout << "1.play with other player\n2.play with computer\n3.check the score list\n4.check the record list\5.quit";
        cout << "menu" << endl;
        cout << "select your choose: ";
        cin >> choose;

        switch (choose)
        {
        case 0:
            cout << "you choose to play with other players\n"; // play with other player
            break;
        case 1:
            cout << " you choose to play with computer\n"; // play with computer
            break;
        case 2:
            cout << " check the score list\n"; // Check the score list
            break;
        case 3:
            cout << " check the record list\n"; // Check the recording list
            break;
        case 4:
            cout << " see you next time\n"; // Quit
            break;
        }

    } while (choose != 4);
    return choose;
}
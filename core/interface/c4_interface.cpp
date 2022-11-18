#include <iostream>
#include "../connect4.hpp"
#include "../c4_interface.hpp"

using namespace std;

void C4Interface::displayMenu()
{
	cout << "\n";
	cout << "===============================RULE===============================" << endl;
	cout << "Each player chooses a different color piece." << endl;
	cout << "For example, with the black side playing first and the white side playing second." << endl;
	cout << "The player who connects the four pieces in a line wins." << endl;
	cout << "==================================================================\n"
		 << endl;
	cout << "1. Play with Other Player" << endl;
	cout << "2. Check the Score List" << endl;
	cout << "3. Check the Recording List" << endl;
	cout << "4. Quit\n" << endl;
}
int C4Interface::menuChoose()
{
	int choose = 0;
	while (1)
	{
		cout << "Please type the number and press [ENTER]:";
		cin >> choose;
		if (choose >= 1 && choose <= 4)
		{
			break;
		}
		cout << "Input must between 1 to 4. Please try again!\n"
			 << endl;
	}
	return choose;
}
void C4Interface::displayBoard(int array[C4_ROW][C4_COLUMN])
{
	int r, // row
		c; // column

	// Display top bar here
	cout << "X";
	for (c = 0; c < C4_COLUMN; c++)
	{
		cout << "  " << c;
	}
	cout << "  X\n";

	// Display board here
	for (r = 0; r < C4_ROW; r++)
	{

		// Left-side table index here
		cout << "\x1b[0m" << r;

		// Main table values
		for (c = 0; c < C4_COLUMN; c++)
		{

			if (array[r][c] == NONE)
			{
				cout << "\x1b[0m  -";
			}
			else if (array[r][c] == RED)
			{
				cout << this->redStr("  X");
			}
			else if (array[r][c] == YELLOW)
			{
				cout << this->yellowStr("  O");
			}
		}

		// Right-side table index here
		cout << "\x1b[0m"
			 << "  " << r << "\n";
	}

	// Display bottom index here
	cout << "X";
	for (c = 0; c < C4_COLUMN; c++)
	{
		cout << "  " << c;
	}
	cout << "  X\n";
}

std::string C4Interface::askName()
{
	std::string name;
	cout << "Please enter a name: ";
	cin >> name;

	return name;
}
int C4Interface::askLine(string name)
{
	int line;
	cout << name << ", Your Turn!";
	cout << "\nEnter Column #: ";
	cin >> line;
	return line;
}

void C4Interface::displayPlayerInfoWithColor(string name, int turn, string time, PieceColor color)
{

	cout << "\nPlayer: " << name << endl;
	cout << "" << turn << endl;
	cout << "\nGame Piece Color: " << color << endl;
	cout << "\n\nTime: " << time << endl;
}
void C4Interface::displayWinningInfo(string name, int score, string time, PieceColor color)
{
	cout << "\nThe Winner is " << name << endl;
	cout << "Congratulations!!" << endl;

	cout << "\nTotal score is: " << score << endl;

	cout << "\nGame Piece Color: " << color << endl;

	cout << "Time: " << time << endl;
}
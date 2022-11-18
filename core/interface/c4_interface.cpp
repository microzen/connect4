#include <iostream>
#include "../connect4.hpp"
#include "../c4_interface.hpp"

using namespace std;

void C4Interface::displayMenu()
{
	cout << "\n";
	cout << "==============================[RULE]==============================" << endl;
	cout << "Each player chooses a different color piece." << endl;
	cout << "\nFor example, with the [RED](" << redStr("X")
		 << ") side playing first \nand the [YELLOW](" << yellowStr("O")
		 << ") side playing second." << endl;
	cout << "\nThe player who connects the four pieces in a line wins." << endl;
	cout << "==================================================================\n"
		 << endl;
	cout << "1. Play with Other Player" << endl;
	cout << "2. Check the Score List" << endl;
	cout << "3. Check the Recording List" << endl;
	cout << "0. Quit\n"
		 << endl;
}
int C4Interface::menuChoose()
{
	int choose = 0;
	int min, max;
	min = 0;
	max = 3;
	while (1)
	{
		cout << "Please type the number and press [ENTER]:";
		cin >> choose;
		if (choose >= min && choose <= max)
		{
			break;
		}
		cout << "Input must between " << min << " to " << max << ". Please try again!\n"
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
	// cout << name << ", Your Turn!";
	cout << "Enter Column #: ";
	cin >> line;
	return line;
}

void C4Interface::displayGameInfoWithColor(string name, int turn, double seconds, PieceColor color)
{
	string str = "Player Name: " + name;
	str += " | Turn: " + to_string(turn);
	str += " | Time: " + to_string(seconds);
	str += " | Your Piece: ";
	if (color == RED)
	{
		str += this->redStr("X");
	}
	else if (color == YELLOW)
	{
		str += this->yellowStr("O");
	}
	cout << str << endl;
}
void C4Interface::displayWinningInfo(string name, int score, string time, PieceColor color)
{
	cout << "\nThe Winner is " << name << endl;
	cout << "Congratulations!!" << endl;

	cout << "\nTotal score is: " << score << endl;

	cout << "\nGame Piece Color: " << color << endl;

	cout << "Time: " << time << endl;
}
void C4Interface::displayStartInfo(std::string p1, int p1s, std::string p2, int p2s)
{
	cout << "======= " << p1 << " (" << redStr("X") << ") .VS " << p2 << " (" << yellowStr("O") << ") =======" << endl;
}
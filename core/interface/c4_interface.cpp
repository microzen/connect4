/* ********************************************************
**                       Game Output                     **  
** Includes main menu, game board, asking for player     **
** names, display player info, and winning info          **
**********************************************************/

#include <iostream>
#include "../connect4.hpp"
#include "../c4_interface.hpp"

#define PIECE_SYMBOL_Y "O"
#define PIECE_SYMBOL_R "O"

using namespace std;

void C4Interface::displayMenu()
{
	cout << "\n";
	cout << "==============================[RULES]==============================" << endl;
	cout << "Each player chooses a different color game piece." << endl;
	cout << "\nThe [RED](" << redStr(PIECE_SYMBOL_R)
		 << ") game piece plays first \nand the [YELLOW](" << yellowStr(PIECE_SYMBOL_Y)
		 << ") game piece plays second." << endl;
	cout << "\nThe first player to connect four game pieces in a line wins." << endl;
	cout << "===================================================================\n"
		 << endl;
	cout << "1. Play with Another Player" << endl;
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
		cout << "Please type the number and press [ENTER]: ";
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
	for (c = 1; c < C4_COLUMN + 1; c++)
	{
		cout << "  " << c;
	}
	cout << "  X\n";

	// Display board here
	for (r = 0; r < C4_ROW ; r++)
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
				cout << "  " << this->redStr(PIECE_SYMBOL_R);
			}
			else if (array[r][c] == YELLOW)
			{
				cout << "  " << this->yellowStr(PIECE_SYMBOL_Y);
			}
		}

		// Right-side table index here
		cout << "\x1b[0m"
			 << "  " << r << "\n";
	}

	// Display bottom index here
	cout << "X";
	for (c = 1; c < C4_COLUMN + 1; c++)
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
  line = line - 1;
	return line;
}

void C4Interface::displayGameInfoWithColor(string name, int turn, double seconds, PieceColor color)
{
	string str = "Current Player: " + name;
	str += " | Turn: " + to_string(turn);
	str += " | Total Time: " + to_string((int)seconds) + " sec";
	str += "\nYour Piece: ";
	if (color == RED)
	{
		str += this->redStr(PIECE_SYMBOL_R);
	}
	else if (color == YELLOW)
	{
		str += this->yellowStr(PIECE_SYMBOL_Y);
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
	cout << "\n======= " << p1 << " (" << redStr(PIECE_SYMBOL_R) << ") .VS " << p2 << " (" << yellowStr(PIECE_SYMBOL_Y) << ") =======" << endl;
  cout << "Player 1: "<<p1 << " | Scores: "<<p1s<<endl;
  cout << "Player 2: "<<p2 << " | Scores: "<<p2s<<endl;
  cout << "\n";
}

void C4Interface::displayRuleOfPlaying(){
  cout << "\n=====[ Play with Another Player ]======"<<endl;
  cout << "You selected option 1: Play with Another Player."<<endl;
  cout << "Please enter names for Player 1 and Player 2.\n"<<endl;
}
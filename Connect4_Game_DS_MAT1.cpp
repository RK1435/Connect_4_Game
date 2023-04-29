// Connect4_Game_DS_MAT1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <istream>
#include <stdlib.h>
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLDCYAN "\033[1m\033[36m" 
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
using namespace std;

class playerInfo
{
public:
	char playerName[81];
	char playerID;
};

class connectFour {
public:
	int PlayerChoice(char board[][10], playerInfo activePlayer)
	{
		int dropChoice;
		do
		{
			cout << activePlayer.playerName << "'s Turn ";
			cout << "Please enter a number between 1 and 7: ";
			cin >> dropChoice;

			while (board[1][dropChoice] == 'R' || board[1][dropChoice] == 'B')
			{
				cout << "That row is full, please enter a new row: ";
				cin >> dropChoice;

			}

		} while (dropChoice < 1 || dropChoice > 7);

		return dropChoice;
	}

	void CheckBelow(char board[][10], playerInfo activePlayer, int dropChoice)
	{
		int length, turn;
		length = 6;
		turn = 0;

		do
		{
			if (board[length][dropChoice] != 'R' && board[length][dropChoice] != 'B')
			{
				board[length][dropChoice] = activePlayer.playerID;
				turn = 1;
			}
			else
				--length;
		} while (turn != 1);

	}

	void DisplayBoard(char board[][10])
	{

		int rows = 6, columns = 7, i, ix;

		for (i = 1; i <= rows; i++)
		{
			cout << "|";
			for (ix = 1; ix <= columns; ix++)
			{
				if (board[i][ix] != 'R' && board[i][ix] != 'B')
					board[i][ix] = '*';

				cout << board[i][ix];

			}
			cout << "|" << endl;
		}
	}

	int CheckConnectFour(char board[][10], playerInfo activePlayer)
	{
		char RB;
		int win;

		RB = activePlayer.playerID;
		win = 0;

		for (int i = 8; i >= 1; --i)
		{
			for (int ix = 9; ix >= 1; --ix)
			{

				if (board[i][ix] == RB &&
					board[i - 1][ix - 1] == RB &&
					board[i - 2][ix - 2] == RB &&
					board[i - 3][ix - 3] == RB)
				{
					win = 1;
				}

				if (board[i][ix] == RB &&
					board[i][ix - 1] == RB &&
					board[i][ix - 2] == RB &&
					board[i][ix - 3] == RB)
				{
					win = 1;
				}

				if (board[i][ix] == RB &&
					board[i - 1][ix] == RB &&
					board[i - 2][ix] == RB &&
					board[i - 3][ix] == RB)
				{
					win = 1;
				}

				if (board[i][ix] == RB &&
					board[i - 1][ix + 1] == RB &&
					board[i - 2][ix + 2] == RB &&
					board[i - 3][ix + 3] == RB)
				{
					win = 1;
				}

				if (board[i][ix] == RB &&
					board[i][ix + 1] == RB &&
					board[i][ix + 2] == RB &&
					board[i][ix + 3] == RB)
				{
					win = 1;
				}
			}

		}

		return win;
	}

	int FullBoard(char board[][10])
	{
		int full;
		full = 0;
		for (int i = 1; i <= 7; ++i)
		{
			if (board[1][i] != '*')
				++full;
		}

		return full;
	}

	void PlayerWin(playerInfo activePlayer)
	{
		cout << endl << activePlayer.playerName << " Connected Four, You Win!" << endl;
	}

	int restart(char board[][10])
	{
		int restart;

		cout << "Would you like to restart? Yes(1) No(2): ";
		cin >> restart;
		if (restart == 1)
		{
			for (int i = 1; i <= 6; i++)
			{
				for (int ix = 1; ix <= 7; ix++)
				{
					board[i][ix] = '*';
				}
			}
		}
		else
			cout << "Thanks for Playing the Game. Goodbye!" << endl;
		return restart;
	}
};
int main()
{
	connectFour cf;
	playerInfo playerOne, playerTwo;
	char board[9][10];
	int trueWidth = 7;
	int trueLength = 6;
	int dropChoice, win, full, again;
	// cout << "    **********" << endl;
	cout << RED << "   ********                                                                                             ** " << endl;
	cout << RED << " **             ****     **         **          ** ** **        * * * *      **                       **  **   " << endl;
	cout << RED << "**            **    **   ** * **    ** * **    **        *    **             **                     **      **   " << endl;
	cout << RED << "**           **      **  **    **   **    **   **    ** *    **            ******      ******      **       **   " << endl;
	cout << RED << " **           **    **   **     **  **     **  **            **              **                    ** ** ** ***     " << endl;
	cout << RED << "   ********     ****     **     **  **     **    ** * ** *     * * * * *      * ***                         **  " << endl;
	// cout << "    **********" << endl;
	cout << BOLDCYAN << "\t \t \t \tPlay Connect 4 Game" << endl << endl;
	cout << RED << "\t \t \t============ RULES ============" << endl << endl;
	cout << GREEN << "\n1. One Player will get one chance \n2. Turn based game and if you connect 4 Red's or 4 Blue's Player win's \n3. If the Board is full the match is Draw \n4. Please enter the column numbers between 1-7 to play.\n" << RESET << endl;
	cout << YELLOW << "Player One please enter your name: " << RESET;
	cin >> playerOne.playerName;
	playerOne.playerID = 'R';
	cout << BLUE << "Player Two please enter your name: " << RESET;
	cin >> playerTwo.playerName;
	playerTwo.playerID = 'B';

	full = 0;
	win = 0;
	again = 0;
	cf.DisplayBoard(board);
	do
	{
		dropChoice = cf.PlayerChoice(board, playerOne);
		cf.CheckBelow(board, playerOne, dropChoice);
		cf.DisplayBoard(board);
		win = cf.CheckConnectFour(board, playerOne);
		if (win == 1)
		{
			cf.PlayerWin(playerOne);
			again = cf.restart(board);
			if (again == 2)
			{
				break;
			}
		}

		dropChoice = cf.PlayerChoice(board, playerTwo);
		cf.CheckBelow(board, playerTwo, dropChoice);
		cf.DisplayBoard(board);
		win = cf.CheckConnectFour(board, playerTwo);
		if (win == 1)
		{
			cf.PlayerWin(playerTwo);
			again = cf.restart(board);
			if (again == 2)
			{
				break;
			}
		}

		full = cf.FullBoard(board);
		if (full == 7)
		{
			cout << "The board is full, it is a draw!" << endl;
			again = cf.restart(board);
		}

	} while (again != 2);

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

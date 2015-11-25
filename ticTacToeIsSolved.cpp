/*
* Checks if a tic-tac-toe board is solved or not.
*/

#include <string>
#include <iostream>

using namespace std;

enum Player
{
	NONE = ' ',
	X = 'x',
	O = 'o'
};

enum Direction
{
	HORIZONTAL = 1,
	DIAGONAL_FORWARD = 2,
	VERTICAL = 3,
	DIAGONAL_BACKWARD = 4
};

bool tripletIsWinner(char board[], int pos, Direction direction);
bool ticTacToeIsSolved(char board[]);

int main()
{
	char ticTacToe[9] = 
	{
		'x', ' ', 'x',
		' ', 'x', 'o',
		'o', 'o', 'o'
	};

	if (ticTacToeIsSolved(ticTacToe))
	{
		cout << "the board is solved!";
	}
	else
	{
		cout << "the board is not solved...";
	}

	cout << endl;
	system("Pause");
	return 0;
}

bool tripletIsWinner(char board[], int pos, Direction direction)
{
	char player = board[pos];

	if (player != Player::NONE)
	{
		return (player == board[pos - direction]
			&& player == board[pos + direction]);
	}
	
	return false;
}

bool ticTacToeIsSolved(char board[])
{
	int middlePos = 4;
	if (board[middlePos] != Player::NONE)
	{
		Direction directions[4] = { HORIZONTAL, DIAGONAL_FORWARD, VERTICAL, DIAGONAL_BACKWARD };
		for (int i = 0; i < 4; i++)
			if (tripletIsWinner(board, middlePos, directions[i])) 
				return true;
	}

	int topPos = 1;
	if (board[topPos] != Player::NONE)
		if (tripletIsWinner(board, topPos, Direction::HORIZONTAL))
			return true;

	int rightPos = 5;
	if (board[rightPos] != Player::NONE)
		if (tripletIsWinner(board, rightPos, Direction::VERTICAL))
			return true;

	int bottomPos = 7;
	if (board[bottomPos] != Player::NONE)
		if (tripletIsWinner(board, bottomPos, Direction::HORIZONTAL))
			return true;

	int leftPos = 3;
	if (board[leftPos] != Player::NONE)
		if (tripletIsWinner(board, leftPos, Direction::VERTICAL))
			return true;

	return false;
}

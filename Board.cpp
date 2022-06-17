#include "Board.h"

Board::Board(int a)
{
	if (a < 3)
	{
		a = 3;
	}
	this->size = a * a;
	board = new char[size];
	for (int i = 0; i < size; i++)
	{
		board[i] = ' ';
	}
}

Board::~Board()
{
	delete[] board;
}

int Board::getSize()
{
	return size;
}

void Board::printBoard()
{
	for (int i = 0; i < size; i++)
	{
		cout << board[i] << ' ';
		if ((i + 1) % (int)sqrt(size) == 0)
		{
			cout << endl;
		}
	}
}

void Board::placeXO(int koor, char XO)
{
	int tempKoor = koor;
	if (!(isOccupied(koor)))
	{
		board[koor] = XO;
	}
	else
	{
		while (tempKoor == koor)
		{
			cout << "Sudah ditempati" << endl;
			cout << "Input : "; cin >> tempKoor;
		}
		board[tempKoor] = XO;
	}
}

bool Board::cekWin()
{
	int streak = 0;
	int vstreak = 0;
	for (int i = 0; i < size; i++)
	{
		if (board[i] == board[i + 1] && board[i] != ' ')
		{
			streak += 1;
		}
		else if ((i + 1) % (int)sqrt(size) == 0)
		{
			streak = 0;
		}
		if (streak == ((int)sqrt(size) - 1))
		{
			return 1;
			break;
		}
	}
	for (int i = 0; i < (int)sqrt(size); i++)
	{
		for (int j = 0; j < (int)sqrt(size); j++)
		{
			if (board2D(i, j) == board2D(i, j + 1) && board2D(i, j) != ' ')
			{
				vstreak += 1;
			}

			if (vstreak == 2)
			{
				return 1;
				break;
			}
		}
		vstreak = 0;
	}
	return 0;
}

bool Board::isOccupied(int koor)
{
	return board[koor] != ' ';
}

char Board::board2D(int x, int y)
{
	return board[x + (int)sqrt(size) * y];
}

void Board::clearBoard()
{
	for (int i = 0; i < size; i++)
	{
		board[i] = ' ';
	}
}
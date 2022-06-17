#include "GameManager.h"


GameManager::GameManager(Board* board, Player* player1, Player* player2)
{
	board = board;
	player[0] = player1;
	player[1] = player2;
}

void GameManager::play()
{
	for (int i = 0; i < board->getSize(); i++)
	{
		int koor;
		Giliran(i);
		cout << "Giliran " << giliran->getNama() << endl;
		cout << "Input : "; cin >> koor;
		input(koor);
		board->printBoard();
		if (board->cekWin())
		{
			gameOver(1);
			break;
		}
		if (i == board->getSize())
		{
			gameOver(0);
		}
	}
}

void GameManager::gameOver(int status)
{
	if (status == 0)
	{
		cout << "DRAW!!";
		giliran = NULL;
	}
	else
	{
		notifyWinner();
	}
}

void GameManager::input(int koor)
{
	board->placeXO(koor, giliran->getSimbol());
}

Player GameManager::Giliran(int a)
{
	if ((a + 1) % 2 == 0)
	{
		giliran = player[1];
	}
	else
	{
		giliran = player[0];
	}

	return *giliran;
}

void GameManager::notifyWinner()
{
	player[0]->Observer(giliran->getNama());
	player[1]->Observer(giliran->getNama());
}
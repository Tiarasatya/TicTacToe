#pragma once
#include<iostream>
#include<math.h>
using namespace std;

class Board
{
private : 
	char* board;
	int size;
public:
	Board();
	Board(int size);
	~Board();
	int getSize();
	void placeXO(int koor, char XO);
	bool cekWin();
	bool isOccupied(int koor);
	void clearBoard();
	void printBoard();
	char board2D(int x, int y);
};



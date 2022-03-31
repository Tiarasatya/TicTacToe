#pragma once
#include<iostream>
using namespace std;

class board
{
private :
	char sizeBoard[][];
public:
	board();
	bool isFull();
	bool isEmpty();  
	void resetBoard();
};

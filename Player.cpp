#include "Player.h"

Player::Player(string a, char b)
{
	setNama(a);
	setSimbol(b);
}

void Player::setNama(string a)
{
	name = a;
}

void Player::setSimbol(char a)
{
	simbol = a;
}

string Player::getNama()
{
	return name;
}

char Player::getSimbol()
{
	return simbol;
}

int Player::getWin()
{
	return jumlahWin;
}

int Player::getLose()
{
	return jumlahKalah;
}

void Player::Observer(string name)
{
	if (name == this->name)
	{
		jumlahWin += 1;
		cout << this->name << " Menang!" << endl;
	}
	else
	{
		jumlahKalah += 1;
		cout << this->name << " Kalah!" << endl;
	}
}
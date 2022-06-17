#include <iostream>
using namespace std;

class Player
{
private:
	string name;
	char simbol;
	int jumlahWin = 0;
	int jumlahKalah = 0;
public:
	Player();
	Player(string a, char b);
	void setNama(string a);
	void setSimbol(char a);
	string getNama();
	char getSimbol();
	int getWin();
	int getLose();
	void Observer(string name);
};
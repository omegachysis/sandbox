#include "stdafx.h"

item playerItems[1000];
int playerHP = 100;
int playerHunger = 100;
int playerHPMax = 100;
int playerCapacity = 100;
int playerGold = 0;

void addItem(item item)
{
	for (int i = 0; i < 1000; i++)
	{
		if (playerItems[i].name == "")
		{
			playerItems[i] = item;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	string _end;
	getline(cin, _end);
	return 0;
}
#include "stdafx.h"

#include "game.h"

// Pause and wait for the user to press 'enter' to continue
void beat()
{
	string _end;
	getline(cin, _end);
}

int _tmain(int argc, _TCHAR* argv[])
{
	player::itemsAdd(items::apple);
	beat();

	player::heal(20000);
	beat();

	player::damage(100);
	beat();

	return 0;
}
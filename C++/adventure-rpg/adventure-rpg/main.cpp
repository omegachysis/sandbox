#include "stdafx.h"
#include "main.h"

// Pause and wait for the user to press 'enter' to continue
void beat()
{
	string _end;
	getline(cin, _end);
}

// Entry point for the program.  Start the game here.
int _tmain(int argc, _TCHAR* argv[])
{
	player::itemAdd(items::apple, 5);
	beat();

	player::itemAdd(items::ironSword);
	beat();

	player::itemUse("apple");
	beat();

	player::heal(20000);
	beat();

	player::damage(100);
	beat();

	return 0;
}
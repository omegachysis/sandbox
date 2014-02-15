#include "stdafx.h"
#include "main.h"

// Entry point for the program.  Start the game here.
int _tmain(int argc, _TCHAR* argv[])
{
	nline();
	hline();
	center(" * Welcome to Adventure RPG! * ");
	center("     -- Programmed in C++ --   ");
	hline();
	nline();
	beat();

	/*player::itemAdd(items::apple, 5);
	beat();

	player::itemAdd(items::ironSword);
	beat();

	player::itemUse("apple");
	beat();

	player::heal(20000);
	beat();

	player::damage(100);
	beat();*/

	return 0;
}
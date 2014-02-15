#include "stdafx.h"
#include "main.h"

// Entry point for the program.  Start the game here.
int _tmain(int argc, _TCHAR* argv[])
{
	nl();
	hline();
	center(" * Welcome to Adventure RPG! * ");
	center("     -- Programmed in C++ --   ");
	hline();
	center("Created by Matthew Robinson");
	hline();
	nl();
	hline();
	center("MAIN MENU");
	hline();
	cout << " 0 - Quit Game\n";
	cout << " 1 - New Game\n";
	cout << " 2 - Continue\n";
	cout << " 3 - Load Game\n";
	hline();

	string choice;
	while (true)
	{
		cout << " :: ";
		getline(cin, choice);
		if (choice == "0")
			break;
		else if (choice == "1")
			game::gameNew();
		else if (choice == "2")
			game::gameContinue();
		else if (choice == "3")
			game::gameLoad();
		else
			cout << "Please enter one of the number choice listed above.\n";

	}
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
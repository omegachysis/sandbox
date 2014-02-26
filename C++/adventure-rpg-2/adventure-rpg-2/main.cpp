#include "main.h"
#include "player.h"
#include "flow.h"
#include "itemdb.h"

using namespace flow;

int main()
{
	Player player;
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

	beat();

	player.itemAdd(itemdb::apple, 50);
	player.itemAdd(itemdb::banana);
	player.itemAdd(itemdb::woodenSword);
	beat();
	displayInventory(player);
	beat();

	/*string choice;
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
			cout << "Please enter one of the number choices listed above.\n";

	}*/
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
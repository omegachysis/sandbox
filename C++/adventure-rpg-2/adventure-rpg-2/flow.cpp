#include "flow.h"

struct Player;

// Pause and wait for the user to press 'enter' to continue
void flow::beat()
{
	string _end;
	getline(std::cin, _end);
}

// Print out a nice separator line
void flow::hline()
{
	// 50 units wide
	std::cout << string(50, '-') << "\n";
}

// Print a string to std::cout centered to fit 50 units.
void flow::center(string s)
{
	int buffer = (50 - s.length()) / 2;
	std::cout << string(buffer, ' ') << s << string(buffer, ' ') << "\n";
}

// Print a new line
void flow::nl()
{
	std::cout << "\n";
}

void flow::displayInventory(Player& player)
{
	flow::hline();
	std::cout << "INVENTORY:\n";
	flow::hline();
	for (int i = 0; i < player.inventory.size(); i++)
	{
		cout << "  " << i << " - " << player.inventory[i].name << "\n";
	}
}
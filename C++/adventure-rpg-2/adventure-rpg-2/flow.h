#pragma once

#include "main.h"
#include "player.h"

struct Player;

namespace flow
{
	void beat();
	void hline();
	void center(string s);
	void nl();

	void displayInventory(Player& player);
}
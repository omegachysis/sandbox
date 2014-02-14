#pragma once

#include "stdafx.h"

namespace player
{
	item::Item inventory[10000];
	unsigned short health = 100;
	unsigned short healthMax = 100;
	unsigned short capacity = 100;
	unsigned short gold = 0;

	void kill()
	{
		cout << " --- GAME OVER --- \n";
		string _end;
		getline(cin, _end);
		std::exit(0);
	}

	void damage(unsigned short damageHP)
	{
		cout << "You recieved " << damageHP << " HP of damage!\n";

		if (damageHP >= health)
			kill();
		else
			health -= damageHP;

		cout << "     HP: " << health << "\n";
	}
	void heal(unsigned short healHP)
	{
		cout << "You were healed " << healHP << " HP!\n";

		if (healHP + health > healthMax)
			health = healthMax;
		else
			health += healHP;

		cout << "     HP: " << health << "\n";
	}

	void itemsAdd(item::Item item, unsigned short quantity)
	{
		cout << "You obtained " << quantity << "x " << item.name << "!\n";
		for (int i = 0; i < 10000; i++)
		{
			if (inventory[i].name == "")
			{
				inventory[i] = item;
				quantity--;
				if (quantity == 0)
					break;
			}
		}
	}
	void itemsAdd(item::Item item)
	{
		itemsAdd(item, 1);
	}
}
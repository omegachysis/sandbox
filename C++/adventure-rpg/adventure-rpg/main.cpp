#include "stdafx.h"

#include "items.h"

namespace player
{
	item inventory[10000];
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

	void itemsAdd(item item, unsigned short quantity)
	{
		cout << "You obtained " << quantity << "x " << item.name << "!\n";
		for (int i = 0; i < 10000; i++)
		{
			if (inventory[i].name == "")
			{
				inventory[i] = item;
				break;
			}
		}
	}
	void itemsAdd(item item)
	{
		itemsAdd(item, 1);
	}
}

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
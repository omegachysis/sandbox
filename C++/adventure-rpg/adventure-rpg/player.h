#pragma once

#include "stdafx.h"

namespace player
{
	Item inventory[10000];
	float health = 100;
	float healthMax = 100;
	short capacity = 100;
	short gold = 0;
	Item weapon;

	void heal(float);
	void damage(float);
	void itemRemove(unsigned short);

    short itemIndexByName(string name)
	{
		for (short i = 0; i < 10000; i++)
		{
			if (inventory[i].name == name)
				return i;
		}

		return -1;
	}

	void itemUse(unsigned short index)
	{
		Item item;
		item = inventory[index];

		if (item.type == typeWeapon)
			weapon = item;
		else if (item.type == typeAid)
		{
			item.condition--;
			for (short i = 0; i < 5; i++)
			{
				itemParam param = item.params[i];
				if (param.type == paramHeal)
					heal(param.value);
				else if (param.type == paramDamage)
					damage(param.value);
			}
			if (item.condition == 0)
			{
				itemRemove(index);
				cout << "You consumed 1x " << item.name << ".\n";
			}
			
		}
		else
			cout << "You cannot use or equip that item.\n";
	}
	void itemUse(string name)
	{
		itemUse(itemIndexByName(name));
	}

	void kill()
	{
		cout << " --- GAME OVER --- \n";
		string _end;
		getline(cin, _end);
		std::exit(0);
	}

	void damage(float damageHP)
	{
		cout << "You recieved " << damageHP << " HP of damage!\n";

		if (damageHP >= health)
			kill();
		else
			health -= damageHP;

		cout << "     HP: " << health << "\n";
	}
	void heal(float healHP)
	{
		cout << "You were healed " << healHP << " HP!\n";

		if (healHP + health > healthMax)
			health = healthMax;
		else
			health += healHP;

		cout << "     HP: " << health << "\n";
	}

	void itemAdd(item::Item item, unsigned short quantity)
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
	void itemAdd(item::Item item)
	{
		itemAdd(item, 1);
	}

	void itemRemove(unsigned short index)
	{
		inventory[index] = Item();
	}
}
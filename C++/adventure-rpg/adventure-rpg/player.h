#pragma once

#include "stdafx.h"

namespace player
{
	Item inventory[10000];	// maximum 10,000 items; doubtful we will even need close to this much.
	float health = 100;
	float healthMax = 100;
	short capacity = 100;	// maximum carrying sum weight of items; the player will have trouble fighting
							// if he goes over this.
	short gold = 0;
	Item weapon;			// the current weapon equipped for battle

	// function prototypes
	void heal(float);
	void damage(float);
	void itemRemove(unsigned short);

	// Returns the index of the first item found with this name.
	// Returns -1 if an item by that name does not exist in the inventory.
    short itemIndexByName(string name)
	{
		for (short i = 0; i < 10000; i++)
		{
			if (inventory[i].name == name)
				return i;
		}

		return -1;
	}

	// Player uses items like potions and such.
	// This will equip items like apparel and weapons.
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

	// Ask the player to use/equip an item by name. The first item by index will be chosen.
	//  This will not favor condition!  Try to avoid using this in general.
	void itemUse(string name)
	{
		itemUse(itemIndexByName(name));
	}

	// Immediately trigger the GAME OVER sequence and exit the program.
	void kill()
	{
		cout << " --- GAME OVER --- \n";
		string _end;
		getline(cin, _end);
		std::exit(0);
	}
	
	// Reduce the player's HP by damageHP amount.
	//  A notification will be received.
	void damage(float damageHP)
	{
		cout << "You recieved " << damageHP << " HP of damage!\n";

		if (damageHP >= health)
			kill();
		else
			health -= damageHP;

		cout << "     HP: " << health << "\n";
	}

	// Increase the player's HP by healHP amount.
	//  A notification will be received.
	void heal(float healHP)
	{
		cout << "You were healed " << healHP << " HP!\n";

		if (healHP + health > healthMax)
			health = healthMax;
		else
			health += healHP;

		cout << "     HP: " << health << "\n";
	}

	// Add items to the player's inventory.
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

	// Remove item at index
	void itemRemove(unsigned short index)
	{
		inventory[index] = Item();
	}
	void itemRemove(string name)
	{
		short i = itemIndexByName(name);
		if (i == -1) {}
		// Don't do anything because the item doesn't exist in the inventory!
		else
			itemRemove(i);
	}
}
#pragma once

#include "main.h"
#include "item.h"
#include <vector>

struct Player
{
	float health;
	unsigned int healthMax;
	int gold;
	unsigned int capacity;
	std::vector<item::Item> inventory;
	item::Item weapon;

	Player();
	void damage(float damageHP);
	void heal(float healHP);
	void itemRemove(unsigned int index);
	void itemRemove(string name);
	short itemIndexByName(string name);
	void itemUse(unsigned int index);
	void itemUse(string name);
	bool hasItem(string name);
	bool hasItem(unsigned int index);
	void itemAdd(item::Item item, unsigned int quantity);
	void itemAdd(item::Item item);
	void kill();
};
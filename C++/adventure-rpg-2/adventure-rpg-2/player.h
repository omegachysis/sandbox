#pragma once

#include "main.h"
#include "item.h"

struct Player
{
	float health;
	unsigned int maxHealth;
	int gold;
	unsigned int capacity;
	item::Item inventory[10000];
	item::Item weapon;

	void damage(float damageHP);
	void heal(float healHP);
	void itemRemove(unsigned int index);
	void itemRemove(string name);
	short itemIndexByName(string name);
	void itemUse(unsigned int index);
	void itemUse(string name);
	void itemAdd(item::Item item, unsigned int quantity);
	void itemAdd(item::Item item);
	void kill();
};
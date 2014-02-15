#include "player.h"

void Player::damage(float damageHP)
{

}

void Player::heal(float healHP)
{

}

void Player::itemRemove(unsigned int index)
{

}

void Player::itemRemove(string name)
{

}

bool Player::hasItem(string name)
{
	return (this->itemIndexByName(name) != -1);
}

short Player::itemIndexByName(string name)
{
	for (int i = 0; i < 10,000; i++)
	{
		if (inventory[i].name == name)
			return i;
	}
	
	return -1;
}

void Player::itemUse(unsigned int index)
{

}

void Player::itemUse(string name)
{

}

void Player::itemAdd(item::Item item, unsigned int quantity)
{
	cout << "You obtained " << quantity << "x " << item.name << "!\n";
	for (int i = 0; i < 10,000; i++)
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

void Player::itemAdd(item::Item item)
{
	this->itemAdd(item, 1);
}

void Player::kill()
{

}
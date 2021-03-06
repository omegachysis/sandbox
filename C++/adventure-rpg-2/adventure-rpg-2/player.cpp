#include "player.h"
#include "item.h"

Player::Player()
{
	health = 0.0;
	healthMax = 100.0;
	gold = 0.0;
	capacity = 100.0;
	std::vector<item::Item> inventory(1000);
	weapon = item::Item();
}

// Decrease the player's HP
void Player::damage(float damageHP)
{
	cout << "You recieved " << damageHP << " HP of damage!\n";

	if (damageHP >= health)
		kill();
	else
		health -= damageHP;

	cout << " ~  HP: " << int(health + 0.5) << "\n";
}

// Restore some of the player's HP
void Player::heal(float healHP)
{
	cout << "You were healed " << healHP << " HP!\n";

	if (healHP + health < healthMax)
		health = healthMax;
	else
		health += healHP;

	cout << " ~  HP: " << int(health + 0.5) << "\n";
}

// Remove an item from the player's inventory.
void Player::itemRemove(unsigned int index)
{
	inventory[index] = item::Item();
}
void Player::itemRemove(string name)
{
	int i = itemIndexByName(name);
	if (i == -1) {}
	// Don't do anything because the item doesn't exist in the inventory!
	else
		itemRemove(i);
}

// Return 'true' if the player's inventory contains an item by this name.
// Return 'false' if the player's inventory does not contain it.
bool Player::hasItem(string name)
{
	return (this->itemIndexByName(name) != -1);
}
// TODO: check if there is an item at a given inventory slot.
bool Player::hasItem(unsigned int index)
{
	return (inventory[index].name != "");
}

// Get the index of an item by it's name.  The first one found
// in order of index will be chosen.
short Player::itemIndexByName(string name)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory[i].name == name)
			return i;
	}
	
	return -1;
}

// Use/Equip an item by index.
void Player::itemUse(unsigned int index)
{
	inventory[index].use(*this, index);
}

// Use/Equip an item by name.  The first item found
// in order of index will be chosen.
void Player::itemUse(string name)
{
	itemUse(itemIndexByName(name));
}

// Add an item to the player's inventory.
void Player::itemAdd(item::Item item, unsigned int quantity)
{
	cout << "You obtained " << quantity << "x " << item.name << "!\n";
	for (int i = 0; i < quantity; i++)
	{
		inventory.push_back(item);
	}
}
// Add a single item.
void Player::itemAdd(item::Item item)
{
	this->itemAdd(item, 1);
}

// Immediately trigger the GAME OVER sequence and exit the program.
void Player::kill()
{
	cout << " --- GAME OVER --- \n";
	string _end;
	getline(cin, _end);
	std::exit(0);
}
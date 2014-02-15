#pragma once

#include "item.h"

using namespace item;

namespace itemdb
{
	Item apple("apple",	typeAid, 5,	1, ItemParam(paramHeal, 10));
	Item banana("banana", typeAid, 7, 1, ItemParam(paramHeal, 12));
	Item watermelon("watermelon", typeAid, 20, 4, ItemParam(paramHeal, 40));

	Item ironSword("iron sword", typeWeapon, 80, 7, ItemParam(paramDamage, 12));
	Item steelSword("steel sword", typeWeapon, 140, 7, ItemParam(paramDamage, 18));
	Item woodenSword("wooden sword", typeWeapon, 30, 4, ItemParam(paramDamage, 6));
}
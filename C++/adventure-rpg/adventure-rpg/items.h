#pragma once
#include "stdafx.h"

using namespace item;

namespace items
{
	Item apple("apple", typeAid, 5, 1, itemParam(paramHeal, 10));
	Item banana("banana", typeAid, 8, 1, itemParam(paramHeal, 12));
	Item watermelon("watermelon", typeAid, 10, 5, itemParam(paramHeal, 25));

	Item ironSword("iron sword", typeWeapon, 180, 12, 60, itemParam(paramDamage, 10));
	Item ironDagger("iron dagger", typeWeapon, 80, 3, 40, itemParam(paramDamage, 5));
	Item tinDagger("tin dagger", typeWeapon, 40, 1, 30, itemParam(paramDamage, 4));
}
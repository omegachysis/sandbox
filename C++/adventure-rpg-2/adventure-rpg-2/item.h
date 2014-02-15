#pragma once

#include "main.h"

typedef signed int gold;

namespace item
{

	enum itemType
	{
		typeNone,
		typeWeapon,
		typeApparel,
		typeAmmo,
		typeAid,
		typeMisc,
	};

	enum paramType {
		paramNone,
		paramDamage,
		paramDamageResist,
		paramHeal,
	};

	struct ItemParam
	{
		paramType type;
		float value;

		ItemParam(paramType pType, float val);
		ItemParam();
	};

	struct Item
	{
		string name;
		itemType type;
		gold value;
		float weight;
		short condition;
		short conditionMax;
		ItemParam params[5];

		Item();
		Item(string name, itemType type, gold value, float weight,
			short condition, short conditionMax, ItemParam params[5]);
		Item(string name, itemType type, gold value, float weight, ItemParam param);
	};

}
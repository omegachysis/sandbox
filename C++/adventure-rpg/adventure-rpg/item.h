#pragma once

namespace item
{
	enum itemType {
		typeNone,
		typeWeapon,
		typeApparel,
		typeAmmo,
		typeAid,
		typeMisc,
	};

	// Item Params define the effects of using or equipping certain items.  
	//  Each item will have an array of Params to define its uses.
	enum paramType {
		paramNone,
		paramDamage,
		paramDamageResist,
		paramHeal,
	};
	struct itemParam {
		paramType type;
		float value;

		itemParam(paramType pType, float val)
		{
			type = pType;
			value = val;
		}
		itemParam()
		{
			type = paramNone;
			value = 0.0;
		}
	};
	struct Item {
		std::string name;
		itemType type;
		unsigned short value;
		float weight;
		short condition;		// The current number of uses left
		short conditionMax;	// The maximum number of uses this item can have
		itemParam params[5];

		Item()
		{
			name = "";
			type = typeNone;
			value = 0;
			weight = 0;
			condition = 0;
			conditionMax = 0;
			std::fill_n(params, 5, itemParam());
		}

		Item(std::string iName, itemType iType, int iValue, float iWeight, int iCondition, int iConditionMax,
			itemParam iParams[5])
		{
			name = iName;
			type = iType;
			value = iValue;
			weight = iWeight;
			condition = iCondition;
			conditionMax = iConditionMax;
			memcpy(params, iParams, sizeof(params));
		}

		Item(std::string iName, itemType iType, int iValue, float iWeight)
		{
			name = iName;
			type = iType;
			value = iValue;
			weight = iWeight;
			condition = 1;
			conditionMax = 1;
			std::fill_n(params, 5, itemParam());
		}

		Item(std::string iName, itemType iType, int iValue, float iWeight, itemParam iParam)
		{
			name = iName;
			type = iType;
			value = iValue;
			weight = iWeight;
			condition = 1;
			conditionMax = 1;
			std::fill_n(params, 5, itemParam());
			params[0] = iParam;
		}

		Item(std::string iName, itemType iType, int iValue, float iWeight, int iCondition, itemParam iParam)
		{
			name = iName;
			type = iType;
			value = iValue;
			weight = iWeight;
			condition = iCondition;
			conditionMax = iCondition;
			std::fill_n(params, 5, itemParam());
			params[0] = iParam;
		}
	};
}

enum itemType {
	typeWeapon,
	typeApparel,
	typeAmmo,
	typeAid,
	typeItem,
};

// Item Params define the effects of using or equipping certain items.  
//  Each item will have an array of Params to define its uses.
enum paramType {
	paramDamage,
	paramDamageResist,
	paramHeal,
	paramFeed,
	paramNone,
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
struct item {
	std::string name;
	itemType type;
	int value;
	float weight;
	int condition;		// The current number of uses left
	int conditionMax;	// The maximum number of uses this item can have
	itemParam params[5];

	item(string iName, itemType iType, int iValue, float iWeight, int iCondition, int iConditionMax,
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
	item(string iName, itemType iType, int iValue, float iWeight)
	{
		name = iName;
		type = iType;
		value = iValue;
		weight = iWeight;
		condition = 1;
		conditionMax = 1;
	}
};
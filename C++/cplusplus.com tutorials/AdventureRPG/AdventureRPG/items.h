
#include <string>

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
	paramHPIncrease,
	paramHPDecrease,
};
struct itemParam {
	paramType type;
	float value;
};
struct item {
	std::string name;
	itemType type;
	int value;
	float weight;
	int condition;		// The current number of uses left
	int conditionMax;	// The maximum number of uses this item can have
	itemParam params[5];
};
#include "item.h"

item::Item::Item()
{
	name = "";
	type = item::typeNone;
	value = 0;
	weight = 0;
	condition = 0;
	conditionMax = 0;
}
item::Item::Item(string name, itemType type, gold value, float weight,
	short condition, short conditionMax, ItemParam params[5])
{
	this->name = name;
	this->type = type;
	this->value = value;
	this->weight = weight;
	this->condition = condition;
	this->conditionMax = conditionMax;
	memcpy(params, this->params, sizeof(params));
}
item::Item::Item(string name, itemType type, gold value, float weight, ItemParam param)
{
	this->name = name;
	this->type = type;
	this->value = value;
	this->weight = weight;
	condition = 1;
	conditionMax = 1;
	params[0] = param;
}

item::ItemParam::ItemParam()
{
	type = item::paramNone;
	value = 0;
}

item::ItemParam::ItemParam(paramType pType, float val)
{
	type = pType;
	value = val;
}
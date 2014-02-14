#pragma once
#include "stdafx.h"

namespace items
{
	item apple("apple", typeAid, 5, 1, itemParam(paramHeal, 10));
	item banana("banana", typeAid, 8, 1, itemParam(paramHeal, 12));
	item watermelon("watermelon", typeAid, 10, 5, itemParam(paramHeal, 25));
}
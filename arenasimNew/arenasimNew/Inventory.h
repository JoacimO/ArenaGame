#pragma once
#include "Item.h"
#include "Consumable.h"
#include "Wearable.h"
#include <vector>


class Inventory
{
			
public:
	Inventory();
	enum typeofItem { ConsumableItem, WearableItem };
	Item* getItem(int type, int itemIndex);
	void storeItem(Item* Item, int type);
	void removeitem(int itemIndex, int type);
	void displayUsables();
	int getAmountOfUsables();
	int getAmountOfWearables();
private:
	std::vector<Item*> mWearables;
	std::vector<Item*> mUsables;

};					
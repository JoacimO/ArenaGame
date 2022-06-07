#pragma once
#include "Location.h"
#include "Item.h"
#include "Consumable.h"
#include "Wearable.h"
class Shop : public Location
{
public:
	Shop(Player* player);
	void selectLocationOption();

private:
	const std::vector<std::string> SHOP_OPTIONS = { "Shop","Leave"};
	const int ITEMS_IN_SHOP = 6;
	Item* mItems[6];
	void _buyItem(int input);
	void _randomizeItems();
};
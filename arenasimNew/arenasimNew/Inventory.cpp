#include "Inventory.h"

//inventory holds 2 vectorlists that hold conusumables and wearables respectively
//methods store and remove items from these lists.
Inventory::Inventory()
{
	mUsables.clear();
	mWearables.clear();
}

//gets item of specific index
Item* Inventory::getItem(int type,int itemIndex)
{
	if (type == typeofItem::WearableItem)
	{
		return mWearables[itemIndex];
	}
	else
	{
		return mUsables[itemIndex];
	}

}

//stores item based on type
void Inventory::storeItem(Item* item,int type)
{
	if (type == typeofItem::WearableItem)
	{
		mWearables.push_back(item);
		item->setStorageIndex(mWearables.size()-1);
	}
	else
	{
		mUsables.push_back(item);
		item->setStorageIndex(mWearables.size() - 1);
	}

}

//removes item from inventory 
void Inventory::removeitem(int itemIndex,int type) 
{
	if (type == typeofItem::WearableItem)
	{
		mWearables.erase(mWearables.begin() + itemIndex);
	}
	else
	{
		mUsables.erase(mUsables.begin() + itemIndex);
	}
}


void Inventory::displayUsables()
{
	for (size_t i = 0; i < mUsables.size(); i++)
	{
		std::cout << i + 1 << ": " << mUsables[i]->getName() << std::endl;
	}
}

int Inventory::getAmountOfUsables()
{
	int amountOfItems = 0;
	for (size_t i = 0; i < mUsables.size(); i++)
	{
		amountOfItems++;
	}
	return amountOfItems;
}
int Inventory::getAmountOfWearables()
{
	int amountOfItems = 0;
	for (size_t i = 0; i < mWearables.size(); i++)
	{
		amountOfItems++;
	}
	return amountOfItems;
}

#include "Item.h"
//base Item class
//items have a base type, consumable or wearable aswell as under types such as helmets or different types of potions
Item::Item() :
	mCost(0),
	mRatingValue(0),
	mItemType(-1),
	mType(3),
	mStorageIndex(99999)
{

};

std::string Item::getName()
{
	return mName;
}

void Item::setName(std::string name)
{
	mName = name;
}
//value that decides items power
int Item::getRatingValue()
{
	return mRatingValue;
}
void Item::setRatingValue(int ratingValue)
{
	mRatingValue = ratingValue;
}

//virual function overidden in member classes
void Item::getInfo()
{}

int Item::getCost()
{
	return mCost;
}

//sets base type to either wearable or consumable through enum
void Item::setType(int type)
{
	mType = type;
}
int Item::getType()
{
	return mType;
}

//sets type through enum in member classes
void Item::setItemType(int type)
{
	mItemType = type;
	applyName();

}

int Item::getItemType()
{
	return mItemType;
}

//virtual function sets name based on item in class type such as damage potion or helmet
void Item::applyName()
{}

void Item::setCost(int cost)
{
	mCost = cost;
}

int Item::getStorageIndex()
{
	return mStorageIndex;
}
void Item::setStorageIndex(int i)
{
	mStorageIndex = i;
}
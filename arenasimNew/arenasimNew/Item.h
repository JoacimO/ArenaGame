#pragma once
#include <string>
#include <vector>
#include <iostream>
class Item
{
public: 
	Item();
	std::string getName();
	virtual void getInfo();
	int getCost();
	int getType();
	void setItemType(int type);
	int getItemType();
	void setRatingValue(int ratingValue);
	int getStorageIndex();
	void setStorageIndex(int index);
protected:
	void setCost(int cost);
	void setName(std::string name);
	void setType(int type);
	int getRatingValue();
	virtual void applyName();

	enum typeOfItems { ConsumableItem, WearableItem };
private:
	int mType;
	int mItemType;
	std::string mName;
	int mCost;
	int mRatingValue;
	int mStorageIndex;
};
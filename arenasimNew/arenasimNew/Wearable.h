#pragma once
#include "Item.h"
#include "Entity.h"
class Wearable : public Item
{
public:
	Wearable(int cost, int ratingValue);

	void getInfo();
	int getHealth();
	float getCritChance();
	float getCritMod();
	int getDotDamage();
	bool getIsEquiped();
	void setIsEqupied(bool equiped);
protected:
	void applyName();
private:
	void _setStats();
	bool mIsEquiped;
	int mHealth;
	int mCritChance;
	float mCritMod;
	int mDotDamage;
	bool mActiveStats[4];
	const int NUM_OF_STATS = 4;
	enum typeOfWearable
	{
		Helmet, Back, ChestPiece, ShoulderPads, Waist, Legs, Gloves, Boots
	};

};
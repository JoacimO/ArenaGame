#include "Wearable.h"

//wearable, derived from item 
Wearable::Wearable(int cost, int ratingValue) :
	mHealth(0),
	mCritChance(0),
	mCritMod(0),
	mDotDamage(0),
	mIsEquiped(false)

{
	setType(typeOfItems::WearableItem);
	setCost(cost);
	setRatingValue(ratingValue);
	for (size_t i = 0; i < NUM_OF_STATS; i++)
	{
		mActiveStats[i] = false;
	}
	if (getCost() > 0)
	{
		_setStats();
	}

}
//Applies name based on itemType
void Wearable::applyName()
{
	switch (getItemType())
	{
	case Helmet:
		setName("Helmet");
		break;
	case Back:
		setName("Back");
		break;
	case ChestPiece:
		setName("Chest Piece");
		break;
	case ShoulderPads:
		setName("Shoulder Pads");
		break;
	case Waist:
		setName("Waist");
		break;
	case Legs:
		setName("Legs");
		break;
	case Gloves:
		setName("Gloves");
		break;
	case Boots:
		setName("Boots");
		break;
	default:
		break;
	}
}

//sets stats on wearable, wearable has 4 different possible stats and 2 of them can be active at once
void Wearable::_setStats()
{
	int chooseStat[2];
	int ratingVal = getRatingValue();
	for (size_t i = 0; i < 2; i++)
	{
		chooseStat[i] = rand() % NUM_OF_STATS;
	}
	mActiveStats[chooseStat[0]] = true;
	mActiveStats[chooseStat[1]] = true;

	if (mActiveStats[0])
	{
		mHealth = ratingVal / 1.5f + 1;
	}
	if (mActiveStats[1])
	{
		mCritChance = ratingVal / 10;
	}
	if (mActiveStats[2])
	{
		mCritMod = ratingVal / 50 + (2.01f + ratingVal / 100);
	}
	if (mActiveStats[3])
	{
		mDotDamage = ratingVal / 2 + 1;
	}
	if (ratingVal > 0)
	{
		setCost(ratingVal + rand() % ratingVal + 1);
	}

}

//virtual function to get info from items for wearable this prints the active stats
void Wearable::getInfo()
{
	std::cout << "Rating Value: " << getRatingValue() << std::endl;
	if (mActiveStats[0])
	{
		std::cout << "Health: " << mHealth << std::endl;
	}
	if (mActiveStats[1])
	{
		std::cout << "Crit Chance: " << mCritChance  << "%" << std::endl;
	}
	if (mActiveStats[2])
	{
		std::cout << "Crit Modifier: " << mCritMod << std::endl;
	}
	if (mActiveStats[3])
	{
		std::cout << "Over Time Effect Potency: " << mDotDamage << std::endl;
	}
}


int Wearable::getHealth()
{
	return mHealth;
}
float Wearable::getCritChance()
{
	return mCritChance;
}
float Wearable::getCritMod()
{
	return mCritMod;
}
int Wearable::getDotDamage()
{
	return mDotDamage;
}

bool  Wearable::getIsEquiped()
{
	return mIsEquiped;
}

//sets if player has this piece equiped used for applying stats in player.
void  Wearable::setIsEqupied(bool equiped)
{
	mIsEquiped = equiped;
}
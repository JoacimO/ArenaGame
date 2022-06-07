#pragma once
#include "Ability.h"
#include <string>
#include <vector>
#include <iostream>
class Entity
{
public:
	Entity();
	void useAbility(int ability);
	void useAbility(Ability* ability);

	int getHealth();
	std::string getName();

	virtual void takeTurn();

	void changeHealth(int amount);
	Ability* getUsedAbility();
	int getMaxHealth();
	int getLevel();
	bool getIsPlayer();
	void setIsPlayer(bool isPlayer);

	void setDotEffect(int damage, int duration, std::string name, bool dot);
	int getDotDamage(int index, bool dot);
	std::string getDotName(int index, bool dot);
	int getAmountOfDots(bool dot);
	void clearDotEffects();

	void setHealth(int health);
	int getGoldPieces();
	void setDamage(int damage);
	void randomizeScaleFactor(int index);
	int getScaleFactor(int index);
	void setTempDamage(int damage);
	void resetTempDamage();
	int getTempDamage();
	bool getUsedItem();

	void setExtraHealth(int val);
	void setCritChance(float val);
	void setCritMod(float val);
	void setDotDamage(int val);

	int getExtraHealth();
	float getCritChance();
	float getCritMod();
	int getDotDamage();

	void printStats();

protected:
	void setLevel(int level);
	void setMaxHealth(int health);
	void setName(std::string name);
	void setGoldPieces(int val);
	Ability* mAbilities[4];
	const int NUM_OF_ABILITIES = 4;
	
private:

	std::string mName;
	bool mIsPlayer;
	int mLevel;
	int mHealth;
	int mDamage;
	int mMaxHealth;
	int mNumberOfDots;
	int mNumberOfHots;
	int mGoldPieces;
	int mTempDamage;
	bool mUsedItem;
	struct mDotEffect
	{
		int damage,duration;
		std::string name;
	};
	std::vector<mDotEffect> mDotEffects;
	std::vector<mDotEffect> mHotEffects;
	Ability* mUsedAbility;
	float mScaleFactors[4];
	float MAX_SCALE_FACTOR = 4.0f;
	int mExtraHealth;
	float mCritChance;
	float mCritMod;
	int mDotDamage;
};

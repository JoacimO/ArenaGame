#include "PlayerClass.h"
#include "Enemy.h"

//base player specification class 
using namespace std;
PlayerClass::PlayerClass():
	mMaxHealth(0),
	mCritChance(0),
	mDotDamage(0),
	mCritMod(0)
{
	for (size_t i = 0; i < 4; i++)
	{
		mClassAbilities[i] = new Ability();
	}
}

//returns specific ability of index
Ability* PlayerClass::getAbility(int ability)
{
	return mClassAbilities[ability];
}

//returns class name
std::string PlayerClass::getName()
{
	return mName;
}

int PlayerClass::getMaxHealth()
{
	return mMaxHealth;
}

void PlayerClass::setMaxHealth(int health)
{
	mMaxHealth = health;
}

void PlayerClass::setName(std::string name)
{
	mName = name;
}


//returns all abilities that this class is able to learn.
vector<Ability*> PlayerClass::getAvailableAbilities()
{
	return mAvailableAbilities;
}
float PlayerClass::getCritChance()
{
	return mCritChance;
}
float PlayerClass::getCritMod()
{
	return mCritMod;
}

int PlayerClass::getDotDamage()
{
	return mDotDamage;
}

void PlayerClass::setCritChance(float critChance)
{
	mCritChance = critChance;
}
void PlayerClass::setCritMod(float critMod)
{
	mCritMod = critMod;
}
void PlayerClass::setDotDamage(int dotDamage)
{
	mDotDamage = dotDamage;
}
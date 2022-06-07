#include "Ability.h"

//abilities with damage, type of ability, ability to target self etc
Ability::Ability(std::string name, int damage, bool dot, int dotDamage, int dotDuration, bool targetSelf,int cooldown) :
	mName(name),
	mDamage(damage),
	mIsDot(dot),
	mDotDamage(dotDamage),
	mDotDuration(dotDuration),
	mIsHeal(targetSelf),
	mCooldown(cooldown),
	mCostInShop(0),
	mBaseDamage(damage),
	mBaseDotDamage(dotDamage),
	mCurrentCoolDownTime(0)
{};
//constructor for basic enemy abilities
Ability::Ability(std::string name, int damage):
mName(name),
mDamage(damage),
mIsDot(0),
mDotDamage(0),
mDotDuration(0),
mIsHeal(0),
mCooldown(0),
mCostInShop(0),
mBaseDamage(0),
mBaseDotDamage(0),
mCurrentCoolDownTime(0)
{};

//full constructor
Ability::Ability(std::string name, int damage, bool dot, int dotDamage, int dotDuration, bool targetSelf, int cooldown, int costInShop) :
	mName(name),
	mDamage(damage),
	mIsDot(dot),
	mDotDamage(dotDamage),
	mDotDuration(dotDuration),
	mIsHeal(targetSelf),
	mCooldown(cooldown),
	mCostInShop(costInShop),
	mBaseDamage(damage),
	mBaseDotDamage(dotDamage),
	mCurrentCoolDownTime(0)
{};

//temp ability constructor
Ability::Ability() :
	mName(" "),
	mDamage(0),
	mIsDot(0),
	mDotDamage(0),
	mDotDuration(0),
	mIsHeal(0),
	mCooldown(0),
	mCostInShop(0),
	mBaseDamage(0),
	mBaseDotDamage(0),
	mCurrentCoolDownTime(0)
{};

std::string Ability::getName()
{
	return mName;
}

int Ability::getDamage()
{
	return mDamage;
}
bool Ability::getIsDot()
{
	return mIsDot;
}
int Ability::getDotDamage()
{
	return mDotDamage;
}

int Ability::getDotDuration()
{
	return mDotDuration;
}

//return if ability is a heal or not
bool Ability::getIsHeal()
{
	return mIsHeal;
}

int Ability::getCost()
{
	return mCostInShop;
}

void Ability::setDamage(float damage)
{
	mDamage = damage;
}

void Ability::setDotDamage(float damage)
{
	mDotDamage = damage;
}
int Ability::getBaseDamage()
{
	return mBaseDamage;
}
int Ability::getBaseDotDamage()
{
	return mBaseDotDamage;

}
//if cooldown is higher than 0 return true
bool Ability::getOnCooldown()
{
	return (mCurrentCoolDownTime > 0);
}

void Ability::startCoolDown()
{
	mCurrentCoolDownTime = mCooldown;
}

void Ability::resetCooldown()
{
	mCurrentCoolDownTime = 0;
}

void Ability::updateCoolDown()
{
	mCurrentCoolDownTime--;
}
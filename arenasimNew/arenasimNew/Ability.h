#pragma once
#include <string>
class Ability
{
public:
	Ability(std::string name, int damage);
	Ability(std::string name,int damage, bool dot, int dotDamage,int dotDuration, bool targetSelf,int cooldown);
	Ability(std::string name, int damage, bool dot, int dotDamage, int dotDuration, bool targetSelf, int cooldown, int costInShop);
	Ability();
	std::string getName();
	int getDamage();
	bool getIsDot();
	int getDotDamage();
	int getDotDuration();
	bool getIsHeal();
	int getCost();
	void setDamage(float damage);
	void setDotDamage(float damage);
	int getBaseDamage();
	int getBaseDotDamage();
	bool getOnCooldown();
	void startCoolDown();
	void updateCoolDown();
	void resetCooldown();
private:
	std::string mName;
	int mDamage;
	bool mIsDot;
	int mDotDamage;
	int mDotDuration;
	const bool mIsHeal;
	const int mCostInShop;
	const int mCooldown;
	int mCurrentCoolDownTime;
	const int mBaseDamage;
	const int mBaseDotDamage;
};


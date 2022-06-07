#pragma once
#include "Entity.h"
#include <string>
#include <vector>
class PlayerClass
{
public:
	PlayerClass();
	std::string getName();
	Ability* getAbility(int ability);
	int getMaxHealth();
	void setMaxHealth(int health);
	void setName(std::string name);
	std::vector<Ability*> getAvailableAbilities();
	float getCritChance();
	float getCritMod();
	int getDotDamage();

protected:
	Ability* mClassAbilities[4];
	std::vector<Ability*> mAvailableAbilities;
	void setCritChance(float critChance);
	void setCritMod(float critMod);
	void setDotDamage(int dotDamage);

private:
	std::string mName;
	int mMaxHealth;
	float mCritChance;
	float mCritMod;
	int mDotDamage;


};


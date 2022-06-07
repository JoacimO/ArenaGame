#include "Entity.h"

//base class for all combat capable classes
Entity::Entity() :
	mNumberOfDots(0),
	mGoldPieces(0),
	mMaxHealth(0),
	mLevel(0),
	mHealth(0),
	mDamage(0),
	mName("BaseEntity"),
	mIsPlayer(false),
	mUsedItem(false)
{
	//temp empty abilities
	//all combatants have 4 abilities
	for (size_t i = 0; i < 4; i++)
	{
		mAbilities[i] = new Ability();
	}
	mUsedAbility = new Ability();
	for (size_t i = 0; i < 4; i++)
	{
		mScaleFactors[i] = 0;
	}
	for (size_t i = 0; i < 4; i++)
	{
		randomizeScaleFactor(i);
	}

}

//all combatanats except player randomly chooses it's ability
void Entity::takeTurn()
{
	int ability;
	ability = rand() % 4;
	useAbility(ability);
}

//uses ability based on turn, for player this is based on input
//also damage calculation
void Entity::useAbility(int ability)
{
	if (ability < NUM_OF_ABILITIES)
	{
		bool crit = false;
		if (rand() % 100 < mCritChance)
		{
			crit = true;
			std::cout << getName() << " Critically hits!" << std::endl;
		}
		mUsedAbility = mAbilities[ability];
		if (crit)
		{
			mUsedAbility->setDamage((((mUsedAbility->getBaseDamage() * mScaleFactors[ability] * getLevel()) / 10) + 1 + mTempDamage) * mCritMod );
		}
		else
		{
			mUsedAbility->setDamage(((mUsedAbility->getBaseDamage() * mScaleFactors[ability] * getLevel()) / 10) + 1 + mTempDamage);
		}
		mUsedAbility->setDotDamage(((mUsedAbility->getBaseDotDamage() * mScaleFactors[ability] * getLevel()) / 10) + 1 + mDotDamage + (mTempDamage / 2));
		mUsedItem = false;
	}
	else
	{
		mUsedItem = true;
	}

}

bool Entity::getUsedItem()
{
	return mUsedItem;
}

void Entity::useAbility(Ability* ability)
{
	mUsedAbility = ability;
	mUsedAbility->setDamage(((mUsedAbility->getBaseDamage() * getLevel()) / 10) + 1);
	mUsedAbility->setDotDamage(((mUsedAbility->getBaseDotDamage() * getLevel()) / 10) + mDotDamage + 1);
}

Ability* Entity::getUsedAbility()
{
	return mUsedAbility;
}

void Entity::setLevel(int level)
{
	mLevel = level;
}

int Entity::getHealth()
{
	return mHealth;
}

void  Entity::setHealth(int health)
{
	mHealth = health;
}

void  Entity::setDamage(int damage)
{
	mDamage = damage;
}

//increase health by amount, - to decrease health, + to increase health
void Entity::changeHealth(int amount)
{
	mHealth += amount;
	if (mHealth > mMaxHealth)
	{
		mHealth = mMaxHealth;
	}
}

std::string Entity::getName()
{
	return mName;
}

void Entity::setName(std::string name)
{
	mName = name;
}

int Entity::getMaxHealth()
{
	return mMaxHealth + mExtraHealth;
}

void Entity::setMaxHealth(int health)
{
	mMaxHealth = health;
}

int Entity::getLevel()
{
	return mLevel;
}

//returns if this entity is the player, used for fights
bool Entity::getIsPlayer()
{
	return mIsPlayer;
}

void Entity::setIsPlayer(bool isPlayer)
{
	mIsPlayer = isPlayer;
}

//adds a Damage over time effect or a heal over time effect to the relevant list 
void Entity::setDotEffect(int damage, int duration, std::string name, bool dot)
{
	if (dot)
	{
		mDotEffect temp = { damage, duration, name };
		mNumberOfDots++;
		mDotEffects.push_back(temp);
	}
	else
	{
		mDotEffect temp = { damage, duration, name };
		mNumberOfHots++;
		mHotEffects.push_back(temp);
	}

}

//gets the dot damage/heal amount of a specific item in the Dot or Hot list
int Entity::getDotDamage(int index, bool dot)
{
	if (dot)
	{
		mDotEffects[index].duration--;
		if (mDotEffects[index].duration < 0)
		{
			mDotEffects.push_back(mDotEffects[index]);
			mDotEffects.pop_back();
			mNumberOfDots--;
		}
		return mDotEffects[index].damage;
	}
	else
	{
		mHotEffects[index].duration--;
		if (mHotEffects[index].duration < 0)
		{
			mHotEffects.push_back(mDotEffects[index]);
			mHotEffects.pop_back();
			mNumberOfHots--;
		}
		return mHotEffects[index].damage;
	}

}

//get dot or hot name of a specific item
std::string Entity::getDotName(int index, bool dot)
{
	if (dot)
		return mDotEffects[index].name;
	else
		return mHotEffects[index].name;

}

//returns the current total number of dot or hot effects on this entity
int Entity::getAmountOfDots(bool dot)
{
	if (dot)
	{
		return mNumberOfDots;
	}
	else if (!dot)
	{
		return mNumberOfHots;
	}
		
}

void Entity::clearDotEffects()
{
	mDotEffects.clear();
}


void Entity::setGoldPieces(int amount)
{
	mGoldPieces = amount;
}

int Entity::getGoldPieces()
{
	return mGoldPieces;
}

//sets scale factors for abilities, an entity will be better at using some abilites even if the specific stats of a certain ability might be higher
//another ability could be better due to scale factors
void Entity::randomizeScaleFactor(int index)
{

	mScaleFactors[index] = float(rand()) / float((RAND_MAX)) * MAX_SCALE_FACTOR;
	float i = mScaleFactors[index];

}

int Entity::getScaleFactor(int index)
{
	return mScaleFactors[index];
}

void Entity::setTempDamage(int damage)
{
	mTempDamage = damage;
}
void Entity::resetTempDamage()
{
	mTempDamage = 0;
}
int Entity::getTempDamage()
{
	return mTempDamage;
}

void Entity::setExtraHealth(int val)
{
	mExtraHealth = val;
}
void Entity::setCritChance(float val)
{
	mCritChance = val;
}
void Entity::setCritMod(float val)
{
	mCritMod = val;
}
void Entity::setDotDamage(int val)
{
	mDotDamage = val;
}

int Entity::getExtraHealth()
{
	return mExtraHealth;
}
float Entity::getCritChance()
{
	return mCritChance;
}
float Entity::getCritMod()
{
	return mCritMod;
}
int Entity::getDotDamage()
{
	return mDotDamage;
}

//Prints stats, mainly used for player but could have uses in a "scry" spell or printing the information of a special enemy.
void Entity::printStats()
{
	std::cout << "Crit Chance: " << mCritChance << std::endl;
	std::cout << "Crit Modifier: " << mCritMod << std::endl;
	std::cout << "Over Time Effect Potency: " << mDotDamage << std::endl;
}
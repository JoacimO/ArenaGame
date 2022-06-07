#include "Player.h"

using namespace std;
//player class, derived from Entity and allows for creation of character and sets player to level 1.
Player::Player() :
	mExperiencePoints(0),
	mGearCritChance(0),
	mGearCritMod(0),
	mGearDotDamage(0),
	mGearHealth(0),
	mTempHealth(0)
{
	setGoldPieces(10);
	setLevel(1);
	mClass = new PlayerClass();
	mInventory = new Inventory();
	setIsPlayer(true);
	for (size_t i = 0; i < sizeof(mGear) / sizeof(mGear[0]); i++)
	{
		mGear[i] = new Wearable(0, 0);
	}
}

//sets player name and specialization from user input.
void Player::createCharacter()
{
	cout << "Please enter your name " << endl;
	string name;
	cin >> name;
	cout << "Hello " << name << " please choose your class" << endl;
	setName(name);
	_displayAvailableClasses();
	int choice;
	cin >> choice;
	setClass(choice);
	cout << "You are now a " << getClass();
	setAbilities();
	setMaxHealth(mClass->getMaxHealth());
	_setStats();
}

void Player::_displayAvailableClasses()
{
	cout << "1. Warrior" << endl;
	cout << "2. Mage" << endl;
	cout << "3. Rogue" << endl;
}

std::string Player::getClass()
{
	return mClass->getName();
}

//gets abilities from the set specialization (mage,rogue etc)
//and returns that specializations abilities
void Player::setAbilities()
{
	for (size_t i = 0; i < 4; i++)
	{
		mAbilities[i] = mClass->getAbility(i);
	}
}

//take player input for ability to use
void Player::takeTurn()
{
	bool abilityUsed = false;
	cout << "Choose ability to use" << endl;
	_displayAbilities();
	while (!abilityUsed)
	{
		int choice;
		cin >> choice;
		choice--;
		if (choice < NUM_OF_ABILITIES)
		{
			//use ability based on input
			//input fed into array, checks if that ability is on cooldown then uses it through an Entity.cpp specific method
			if (!mAbilities[choice]->getOnCooldown())
			{

				useAbility(choice);
				mAbilities[choice]->startCoolDown();
				abilityUsed = true;


			}

			else if (mAbilities[choice]->getOnCooldown())
			{
				std::cout << "Ability is on cooldown" << std::endl;
			}
		}
		else
		{
			//use inventory item
			if (choice == NUM_OF_ABILITIES)
			{
				mInventory->displayUsables();
				int usableChoice;
				cin >> usableChoice;
				usableChoice--;
				mInventory->getItem(Inventory::ConsumableItem, usableChoice)->getInfo();
				cout << "Use?: " << endl << "1. Yes" << "\n" << "2. No" << endl;
				int useConsumable;
				cin >> useConsumable;
				useConsumable--;
				if (useConsumable == 0)
				{
					Consumable* temp;
					temp = (Consumable*)mInventory->getItem(Inventory::ConsumableItem, usableChoice);
					temp->use(this);

					abilityUsed = true;
				}
				else
				{
					abilityUsed = false;
					_displayAbilities();
				}
				if (usableChoice == mInventory->getAmountOfUsables())
				{
					abilityUsed = false;
					_displayAbilities();
				}

			}
		}



	}


	for (size_t i = 0; i < 4; i++)
	{
		if (mAbilities[i]->getOnCooldown())
		{
			mAbilities[i]->updateCoolDown();
		}
	}
}

//Get current player abilities and display on console
void Player::_displayAbilities()
{
	string onCooldown;
	for (size_t i = 0; i < NUM_OF_ABILITIES; i++)
	{
		if (mAbilities[i]->getOnCooldown())
		{
			onCooldown = " (On Cooldown)";
		}
		else
		{
			onCooldown = "";
		}
		cout << i + 1 << " " << mAbilities[i]->getName() << onCooldown << endl;
	}
	cout << NUM_OF_ABILITIES + 1 << " Items" << endl;
}

//set class to one of the derived classes
void Player::setClass(int playerClass)
{
	switch (playerClass)
	{
	case 1:
		mClass = new Warrior();
		break;
	case 2:
		mClass = new Mage();
		break;
	case 3:
		mClass = new Rogue();
		break;
	default:
		break;
	}
}
// return current player class;
PlayerClass* Player::getPlayerClass()
{
	return mClass;
}

int Player::getExperiencePoints()
{
	return mExperiencePoints;
}
void Player::increaseExperiencePoints(int amount)
{
	mExperiencePoints += amount;
}


//if xp is higher than arbitrary value based on level, level up
void Player::checkIncreaseLevel()
{
	if (mExperiencePoints >= 100 * pow(2, getLevel() - 2))
	{
		mExperiencePoints = 0;
		setLevel(getLevel() + 1);
		std::cout << "You level Up!" << std::endl;
		std::cout << "You are now level " << getLevel() << std::endl;
		setMaxHealth(getMaxHealth() + getLevel() * 1.35f);
	}
}

void Player::ChangeGPValue(int amount)
{
	setGoldPieces(getGoldPieces() + amount);
}

Ability* Player::getAbility(int ability)
{
	return mAbilities[ability];
}

void Player::setAbility(int index, Ability* ability)
{
	mAbilities[index] = ability;
}

void Player::incrementLevel()
{
	setLevel(getLevel() + 1);
}

void Player::setTempHealth(int extraHealth)
{
	mTempHealth = extraHealth;
}

int Player::getTempHealth()
{
	return mTempHealth;
}

Inventory* Player::getInventory()
{
	return mInventory;
}

void Player::equipItem(Wearable* item)
{
	mGear[item->getItemType()] = item;
	mGear[item->getItemType()]->setIsEqupied(true);
}

void Player::applyGearModifiers()
{
	int tempGearHealth = 0;
	float tempGearCritMod = 0;
	float tempGearCritChance = 0;
	int tempGearDotDamage = 0;

	for (size_t i = 0; i < sizeof(mGear) / sizeof(mGear[0]); i++)
	{
		if (mGear[i]->getIsEquiped())
		{
			tempGearHealth += mGear[i]->getHealth();
			tempGearCritMod += mGear[i]->getCritMod();
			tempGearCritChance += mGear[i]->getCritChance();
			tempGearDotDamage += mGear[i]->getDotDamage();
		}

	}

	mGearHealth = tempGearHealth;
	mGearCritMod = tempGearCritMod;
	mGearCritChance = tempGearCritChance;
	mGearDotDamage = tempGearDotDamage;

	setExtraHealth(mGearHealth);
	setCritMod(mGearCritMod);
	setCritChance(mGearCritChance);
	setDotDamage(mGearDotDamage);
}

int Player::getGearHealth()
{
	return mGearHealth;
}
float Player::getGearCritChance()
{
	return mGearCritChance;
}
float Player::getGearCritMod()
{
	return mGearCritMod;
}
int Player::getGearDotDamage()
{
	return mGearDotDamage;
}

void Player::_setStats()
{
	setCritChance(mClass->getCritChance());
	setCritMod(mClass->getCritMod());
	setDotDamage(mClass->getDotDamage());
}

bool Player::getGearSlotUsed(int gearType)
{
	return mGear[gearType]->getIsEquiped();
}

Wearable* Player::getGearPiece(int gearPiece)
{
	return mGear[gearPiece];
}

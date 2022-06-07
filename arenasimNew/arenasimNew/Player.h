#pragma once
#include <string.h>
#include <iostream>
#include "Entity.h"
#include "PlayerClass.h"
#include "Mage.h"
#include "Rogue.h"
#include "Warrior.h"
#include "Inventory.h"
#include "Consumable.h"
class Player : public Entity
{
public:
	Player();
	std::string getClass();
	PlayerClass* getPlayerClass();
	void setClass(int playerClass);
	void setAbilities();
	void createCharacter();
	void takeTurn();
	void increaseExperiencePoints(int amount);
	int getExperiencePoints();
	void checkIncreaseLevel();
	void ChangeGPValue(int amount);
	Ability* getAbility(int ability);
	void setAbility(int index, Ability* ability);
	void incrementLevel();
	void setTempHealth(int extraHealth);
	int getTempHealth();
	Inventory* getInventory();
	void equipItem(Wearable* item);
	int getGearHealth();
	float getGearCritChance( );
	float getGearCritMod();
	int getGearDotDamage();
	void applyGearModifiers();
	bool getGearSlotUsed(int gearType);
	Wearable* getGearPiece(int gearPiece);
private:
	PlayerClass* mClass;
	void _displayAvailableClasses();
	void _displayAbilities();
	std::string mName;
	int mExperiencePoints;
	int mTempHealth;
	Inventory* mInventory;
	Wearable* mGear[8];
	int mGearHealth;
	float mGearCritChance;
	float mGearCritMod;
	int mGearDotDamage;

	void _setStats();


};


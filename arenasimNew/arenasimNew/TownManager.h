#pragma once
#include "Location.h"
#include "Trainer.h"
#include "PlayerRoom.h"
#include "Arena.h"
#include "Shop.h"
#include <iostream>
#include <string>
class TownManager
{
public:
	TownManager(Player* playerClass);
	void printTownOptions();
	void makeChoice(int input);
	bool getChoiceMade();
	bool getInMenu();
	void setChoiceMade(bool choiceMade);
	bool getStartFight();
	bool getLeaveCity();
private:
	const int NUMBER_OF_LOCATIONS = 4;
	int mChoice;
	bool mFightStarting;
	bool mChoiceMade;
	bool mInMenu;
	Player* mPlayer;
	bool mLeaveCity;
	void _executeChoice();
	Location* mLocations[4];
	Location* mChosenLocation;
};

#include "TownManager.h"

//prints town options and keeps track of locations
TownManager::TownManager(Player* player) :
	mPlayer(player),
	mInMenu(false),
	mChoice(0),
	mChoiceMade(false),
	mLeaveCity(false),
	mFightStarting(false)
{
	mChosenLocation = new Location();
	for (size_t i = 0; i < NUMBER_OF_LOCATIONS; i++)
	{
		mLocations[i] = new Location();
	}
};

//prints all town locations to console
void TownManager::printTownOptions()
{
	mLocations[0] = new Arena(mPlayer);
	mLocations[1] = new Trainer(mPlayer);
	mLocations[2] = new Shop(mPlayer);
	mLocations[3] = new PlayerRoom(mPlayer);
	for (size_t i = 0; i < NUMBER_OF_LOCATIONS; i++)
	{
		std::cout << i + 1 << ". " << mLocations[i]->getName() << std::endl;
	}
	std::cout << NUMBER_OF_LOCATIONS + 1 << ". Leave city " << std::endl;
}

//gets the players choice in town and sets the choice if it is valid
void TownManager::makeChoice(int choice)
{
	mChoice = choice - 1;
	if (mChoice < NUMBER_OF_LOCATIONS && mChoice >= 0)
	{
		_executeChoice();
	}
	else if (mChoice == NUMBER_OF_LOCATIONS)
	{
		mChoiceMade = true;
		mLeaveCity = true;
	}
	else
	{
		std::cout << "Invalid Location! Try again" << std::endl;
	}

}
//sets choice, prints choice options and gets input for location
//handles interaction with town locations
void TownManager::_executeChoice()
{

	mChosenLocation = mLocations[mChoice];

	mChosenLocation->printDescription();
	mChosenLocation->printOptions();
	mChosenLocation->setInput();
	mChosenLocation->printLocationOptions();
	mChosenLocation->selectLocationOption();
	mChoiceMade = true;
	mFightStarting = mChosenLocation->getStartFight();
	if (mChosenLocation->getLeaveLocation())
	{
		mChoiceMade = false;
	}
	
}


bool TownManager::getChoiceMade()
{
	return mChoiceMade;
}

bool TownManager::getInMenu()
{
	return mInMenu;
}

//sets if player has chosen a menu option
void TownManager::setChoiceMade(bool choiceMade)
{
	mChoiceMade = choiceMade;
}

bool TownManager::getLeaveCity()
{
	return mLeaveCity;
}

bool  TownManager::getStartFight()
{
	return mFightStarting;
}
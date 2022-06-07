#include "Location.h"

Location::Location() :
	mInput(),
	mLocationNPCText("..."),
	mShopName("basic location"),
	mLeaveLocation(false),
	mStartFight(false),
	mPlayer(new Player())
{};

//print description of location
void Location::printDescription()
{
	std::cout << mDescription << std::endl;
}

//print things you can do at locaiton
void Location::printOptions()
{
	for (int i = 0; i < mOptions.size(); i++)
	{
		std::cout << i + 1 << ". " << mOptions[i] << std::endl;
	}
}

//return location name
std::string Location::getName()
{
	return mShopName;
}

//set location name
void Location::setName(std::string name)
{
	mShopName = name;
}

//sets description that prints whenever you enter a location
void Location::setDescription(std::string description)
{
	mDescription = description;
}

void Location::setOptions(std::vector<std::string> options)
{
	mOptions = options;
}

//sets value to return to main town menu
void Location::leave()
{
	mLeaveLocation = true;
	return;
}

//returns bool to leave location and go back to main town menu
bool Location::getLeaveLocation()
{
	return mLeaveLocation;
}

void Location::setInput()
{
	std::cin >> mInput;
}

void  Location::setPlayer(Player* player)
{
	mPlayer = player;
}

Player* Location::getPlayer()
{
	return mPlayer;
}

//prints current location alternatives such as "recieve training" etc
void Location::printLocationOptions()
{
	for (size_t i = 0; i < mLocationAlternatives.size(); i++)
	{
		std::cout << i + 1 << ". " << mLocationAlternatives[i] << std::endl;
	}

}

//sets location option text 
void Location::setLocationOptions(std::vector<std::string> options)
{
	mLocationAlternatives = options;
}

//virtual class only used in derived classes
void Location::selectLocationOption()
{}

int Location::getInput()
{
	return mInput;
}

//asks for an input based on a list of strings and returns value of index 
int Location::queryInput(std::vector<std::string> alternatives)
{
	int input;
	for (size_t i = 0; i < alternatives.size(); i++)
	{
		std::cout << i + 1 << ". " << alternatives[i] << std::endl;
	}
	std::cin >> input;

	return input;
}

void Location::setStartFight(bool start)
{
	mStartFight = start;
}
bool Location::getStartFight()
{
	return mStartFight;
}

//prints  information of a specific ability used in 2 out of 3 locations.
void Location::printAbilityInformation(Ability* ability, bool printCost)
{
	std::string type;

	std::cout <<"Ability Name: " << ability->getName() << std::endl;

	//accounts for if spell is a healing spell or a damage spell
	if (ability->getIsHeal())
	{
		type = "Heal";
	}
	else
	{
		type = "Damage";
	}
	if (printCost)
	{
		std::cout << "Cost: " << ability->getCost() << " GP" << " Your Money: " << getPlayer()->getGoldPieces() << " GP" << std::endl;
	}

	std::cout << type << " " << ability->getDamage() << std::endl;
	std::string isDot;
	//accounts for if spell is a over time effect and prints as much information as is needed.
	if (ability->getIsDot())
	{
		isDot = "Yes";

	}
	else
	{
		isDot = "No";
	}
	std::cout << "Is Dot/Hot: " << isDot << std::endl;
	if (ability->getIsDot())
	{
		std::cout << "Dot/Hot Potency: " << ability->getDotDamage() << std::endl;
		std::cout << "Dot/Hot Duration: " << ability->getDotDuration() << std::endl;
	}
	std::cout << std::endl;


}
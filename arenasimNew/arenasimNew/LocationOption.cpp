#include "LocationOption.h"
//class to hold information for locations 
LocationOption::LocationOption(int length, std::string optionName) :
	mNumOfAlternatives(length),
	mOptionName(optionName)
{};

//adds a new options under a locations first set of uptions so say a trainer holds both training 
//and specific abilities that trainer can teach you, holds the abilities or the items in a shop
void LocationOption::addLocationAlternativeName(std::string name)
{
	mOptionAlternatives.push_back(name);
}

std::string LocationOption::getOptionName(int index)
{
	return mOptionAlternatives[index];
}

//print all options for this option. 
void LocationOption::printOptionAlternatives()
{
	for (size_t i = 0; i < mOptionAlternatives.size(); i++)
	{
		std::cout << i + 1 << ". " << mOptionAlternatives[i] << std::endl;
	}
}

int LocationOption::getNumOfAlternatives()
{
	return mNumOfAlternatives;
}
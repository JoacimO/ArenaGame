#pragma once
#include "Location.h"
#include "Ability.h"

class Trainer : public Location
{
public:
	Trainer(Player* player);
	void selectLocationOption();
private:
	const std::vector<std::string> TRAINER_OPTIONS = { "Trainer","Abilities","Leave"};
	
	void _ChooseTrainingOption(int input);
	void _ChooseAbility(int input);
	int mChosenAbility;
	int mTrainingCost;
	
};
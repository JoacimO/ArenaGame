#include "Trainer.h"

//derived from location
//allows player to train and increase their level as well as buy new abilities 
Trainer::Trainer(Player* player):
	mChosenAbility(0),
	mTrainingCost(100)
{
	setPlayer(player);
	setName(getPlayer()->getClass() + " Trainer");

	setOptions(TRAINER_OPTIONS);

	//adds a location option and then adds under-categories
	mLocationOptions.push_back(new LocationOption(2, TRAINER_OPTIONS[0]));

		mLocationOptions.back()->addLocationAlternativeName("Train");
		mLocationOptions.back()->addLocationAlternativeName("Quit");

	int numberOfAbilities = getPlayer()->getPlayerClass()->getAvailableAbilities().size();
	mLocationOptions.push_back(new LocationOption(numberOfAbilities, TRAINER_OPTIONS[1]));

		for (size_t i = 0; i < numberOfAbilities; i++)
		{
			mLocationOptions.back()->addLocationAlternativeName(getPlayer()->getPlayerClass()->getAvailableAbilities()[i]->getName());
		}
		mLocationOptions.back()->addLocationAlternativeName("Leave");
}


//if player has enough money increase level. 
void Trainer::_ChooseTrainingOption(int input)
{
	switch (input)
	{
	case 1:
		if (getPlayer()->getGoldPieces() >= mTrainingCost * getPlayer()->getLevel() * 1.5f)
		{
			getPlayer()->incrementLevel();
			leave();
		}
		else
		{
			std::cout << "You don't have enough money"<< std::endl;
			leave();
		}
		break;
	case 2:
		leave();
		break;
	}
}

//walks player through buying ability
// asks them if they want to buy ability with stats and displays ability information
//checks if they have enough money
//asks which ability to exchange for new ability
//sets ability
void Trainer::_ChooseAbility(int input)
{
	input -= 1;
	if (input == mLocationOptions[1]->getNumOfAlternatives())
	{
		leave();
		return;
	}
	int learnAbility;
	Ability* chosenAbility;
	
	Player* player = getPlayer();
	 
	chosenAbility = player->getPlayerClass()->getAvailableAbilities()[input]; 
	printAbilityInformation(chosenAbility,true);
	std::cout << "Learn this ability? : " << player->getPlayerClass()->getAvailableAbilities()[input]->getName() << std::endl;
	learnAbility = queryInput({ "Yes","No", });
	if (learnAbility == 1 && player->getGoldPieces() < chosenAbility->getCost())
	{
		std::cout << "You don't have enough money." << std::endl;
		learnAbility = 2;
	}
	if (learnAbility == 1)
	{
		std::cout << "Choose ability to unlearn" << std::endl;
		for (int i = 0; i < 4; i++)
		{
			std::cout << i + 1 << ". "<< player->getAbility(i)->getName() << std::endl;
		}
		setInput();
		std::cout << "You unlearned: " << player->getAbility(getInput()-1)->getName() <<
			    " and learned: " << player->getPlayerClass()->getAvailableAbilities()[input]->getName() << std::endl;
		player->setAbility(getInput()-1, chosenAbility);
		player->randomizeScaleFactor(getInput() - 1);
		player->ChangeGPValue(-chosenAbility->getCost());
		leave();
	}
	else
	{
		mLocationOptions[1]->printOptionAlternatives();
		setInput();
		_ChooseAbility(getInput());
	}


}

//virtual function to interact with location
void Trainer::selectLocationOption()
{
	switch (getInput())
	{
	case 1:
		std::cout << "Train?: " << std::endl;
		mLocationOptions[0]->printOptionAlternatives();
		setInput();
		_ChooseTrainingOption(getInput());
		break;
	case 2:
		std::cout << "Choose which ability to learn: " << std::endl;
		mLocationOptions[1]->printOptionAlternatives();
		 setInput();
		_ChooseAbility(getInput());
		break;
	case 3:
		leave();
		break;

	}
}


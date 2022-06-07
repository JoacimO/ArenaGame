#include "FightManager.h"

//takes 2 combat entities and makes them do combat
//fighter 1 and fighter 2 is randomly determined
FightManager::FightManager(Entity* fighter1, Entity* fighter2) :
	mFightFinished(false),
	mPlayerWon(false),
	mFighter1(fighter1),
	mFighter2(fighter2)
{
	mFighter1->setHealth(mFighter1->getMaxHealth());
	mFighter2->setHealth(mFighter2->getMaxHealth());
}



void FightManager::takeTurns()
{
	//fighters take their turns
	std::cout << mFighter1->getName() << " Starts!" << std::endl << std::endl;
	mFighter1->takeTurn();
	_applyAbility(mFighter1->getUsedAbility(), mFighter1, mFighter2);
	if (mFighter2->getHealth() > 0)
	{
		mFighter2->takeTurn();
		_applyAbility(mFighter2->getUsedAbility(), mFighter2, mFighter1);
	}


	// if any combatants health hits 0 the fight is done and 
	// win or loss is handled
	if (mFighter1->getHealth() <= 0 || mFighter2->getHealth() <= 0)
	{
		mFightFinished = true;
		_handleWinLoss();
	}
}
//the main part of combat
//starts by outputting name of ability to console
//then sets a new dot /hot effect 
//output amount of damage or healing
//loop over all dots and hots and apply for this round
//apply actual damage or healing
void FightManager::_applyAbility(Ability* ability, Entity* user, Entity* target)
{
	int dotDamage = 0;
	int hotPotency = 0;
	bool isHeal = ability->getIsHeal();
	if (!user->getUsedItem())
	{
		std::cout << user->getName() << " used " << ability->getName() << std::endl;




		//print damage or heal amount
		if (!isHeal)
		{
			std::cout << target->getName() << " takes " << ability->getDamage() << " damage!" << std::endl;
		}
		else
		{
			std::cout << user->getName() << " heals for " << ability->getDamage() << " hit points!" << std::endl;
		}

		//print dot proccs and add value to dotDamage
		if (target->getAmountOfDots(true) > 0)
		{
			for (int i = 0; i < target->getAmountOfDots(true); i++)
			{

				std::cout << target->getName() << " takes " << target->getDotDamage(i, true) << " from " << target->getDotName(i, true) << std::endl;
				dotDamage += target->getDotDamage(i, true);
			}
		}

		//print hot proccs and add value to hotpotency
		if (user->getAmountOfDots(false) > 0)
		{
			for (int i = 0; i < user->getAmountOfDots(false); i++)
			{
				std::cout << user->getName() << " heals " << user->getDotDamage(i, false) << " from " << user->getDotName(i, false) << std::endl;
				hotPotency += user->getDotDamage(i, false);
			}
		}

		//set dot after processing dot damage for turn
		if (ability->getIsDot())
		{
			if (!isHeal)
			{
				target->setDotEffect(ability->getDotDamage(), ability->getDotDuration(), ability->getName(), true);
			}
			else
			{
				user->setDotEffect(ability->getDotDamage(), ability->getDotDuration(), ability->getName(), false);
			}
		}
	}
	///apply damage
	if (!isHeal)
	{
		target->changeHealth(-ability->getDamage() - dotDamage + hotPotency + user->getTempDamage());
	}
	else
	{
		user->changeHealth(ability->getDamage() + hotPotency - dotDamage);
	}
}

//player wins if they have hp when combat ends
//but the player can be any of fighter 1 and 2
void FightManager::_handleWinLoss()
{
	mFighter1->clearDotEffects();
	mFighter2->clearDotEffects();
	if (mFighter1->getIsPlayer() && mFighter1->getHealth() > 0)
	{
		mPlayerWon = true;
		std::cout << "Player Won!" << std::endl;
	}
	else if (mFighter2->getIsPlayer() && mFighter2->getHealth() > 0)
	{
		mPlayerWon = true;
		std::cout << "Player Won!" << std::endl;
	}
	else
	{
		mPlayerWon = false;
		std::cout << "Player was Defeated!" << std::endl;
	}
}

bool FightManager::getPlayerWon()
{
	return mPlayerWon;
}

bool FightManager::getFightFinished()
{
	return mFightFinished;
}
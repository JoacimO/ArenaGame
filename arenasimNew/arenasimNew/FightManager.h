#pragma once
#include "Entity.h"
#include <iostream>

class FightManager
{
public:
	FightManager(Entity* fighter1, Entity* fighter2);
	void takeTurns();
	bool getPlayerWon();
	bool getFightFinished();
private:
	void _handleWinLoss();
	void _applyAbility(Ability* ability, Entity* user, Entity* target);
	Entity* mFighter1;
	Entity* mFighter2;
	bool mPlayerWon;
	bool mFightFinished;
};
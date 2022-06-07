#pragma once
#include "Entity.h"
class Enemy : public Entity
{
public:
	Enemy(int playerLevel);
	int getExperienceReward();

private:

	int mExperienceReward;
	const std::vector<std::string> ENEMIES = { "Rat", "Bandit", "Drake","Knight","Lion", "Gladiator" };
	void _setAbilities(int index);
	enum typeOfEnemy
	{
		Rat, Bandit, Drake,Knight, Lion, Gladiator
	};

};

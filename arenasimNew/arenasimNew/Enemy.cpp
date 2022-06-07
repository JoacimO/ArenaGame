#include "Enemy.h"

//derived from entity, an enemy can give play XP while an entity can not
//Enemies also have drops such as gold and items.
Enemy::Enemy(int playerLevel) :
	mExperienceReward(playerLevel * 50)
{
	setLevel(playerLevel);
	setMaxHealth(10 * playerLevel * 0.5f);
	int random = rand() % ENEMIES.size();
	setName(ENEMIES[random]);
	setGoldPieces(playerLevel * rand() % 10 + 1);
	_setAbilities(random);
}

int Enemy::getExperienceReward()
{
	return mExperienceReward;
}


//sets abilities of enemy based on randomized value
void Enemy::_setAbilities(int index)
{
	switch (index)
	{
	case typeOfEnemy::Rat:
		 mAbilities[0] = new Ability("Bite",5);
		 mAbilities[1] = new Ability("Poison",1,1,4,4,0,0);
		 mAbilities[2] = new Ability("Bite", 5);
		 mAbilities[3] = new Ability("Poison", 1, 1, 4, 4, 0, 0);
		break;

	case typeOfEnemy::Bandit:
		mAbilities[0] = new Ability("Slash", 10);
		mAbilities[1] = new Ability("Health Potion", 5, 1, 4, 4, 1, 0);
		mAbilities[2] = new Ability("Slash", 10);
		mAbilities[3] = new Ability("Poison", 1, true, 4, 4, 0, 0);
		break;

	case typeOfEnemy::Drake:
		mAbilities[0] = new Ability("Bite", 20);
		mAbilities[1] = new Ability("Fire Breath", 30, 1, 10, 10, 0, 0);
		mAbilities[2] = new Ability("Bite", 5);
		mAbilities[3] = new Ability("Fire Breath", 30, 1, 10, 10, 0, 0);
		break;

	case typeOfEnemy::Knight:
		mAbilities[0] = new Ability("Slash", 5);
		mAbilities[1] = new Ability("Second Wind", 0, 2, 5, 10, 1, 0);
		mAbilities[2] = new Ability("Bash", 25, 1, 25, 1, 0, 0);
		mAbilities[3] = new Ability("Slash", 5);
		break;

	case typeOfEnemy::Lion:
		mAbilities[0] = new Ability("Bite", 10);
		mAbilities[1] = new Ability("Bleed", 10, 0, 20, 1, 0, 0);
		mAbilities[2] = new Ability("Bite", 5);
		mAbilities[3] = new Ability("Poison", 1, 0, 4, 4, 0, 0);
		break;

	case typeOfEnemy::Gladiator:
		mAbilities[0] = new Ability("Punch", 5);
		mAbilities[1] = new Ability("Stab", 15);
		mAbilities[2] = new Ability("Punch", 5);
		mAbilities[3] = new Ability("Stab", 15);
		break;

	}
}
#include "Warrior.h"

//derived from PlayerClass
Warrior::Warrior()
{
	setMaxHealth(20);
	setName("Warrior");
	//set name, damage, if it is a dot, the dot damage, the dot duration, 
	//if you can target yourself with it, the cooldown, and the in shop cost for the ability
	mClassAbilities[0] = new Ability("Slash", 10, 0, 0, 0, 0,0,10);
	mClassAbilities[1] = new Ability("Crush", 30, true, 1, 20, 0, 2, 50);
	mClassAbilities[2] = new Ability("Second Wind", 40, false, 0, 0, false, 2, 20);
	mClassAbilities[3] = new Ability("Bleed", 10, true, 4, 6, false, 1, 10);

	setCritChance(0.5f);
	setCritMod(4.0f);
	setDotDamage(0);

	for (size_t i = 0; i < 4; i++)
	{
		mAvailableAbilities.push_back(mClassAbilities[i]);
	}
	mAvailableAbilities.push_back(new Ability("Execute", 40, false, 0, 0, false, 3, 100));
	mAvailableAbilities.push_back(new Ability("Carve", 25, true, 25, 2, false, 3, 90));

}

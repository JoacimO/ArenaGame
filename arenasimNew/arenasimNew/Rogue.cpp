#include "Rogue.h"

//derived from PlayerClass same as mage and warrior
Rogue::Rogue()
{
	setMaxHealth(15);
	setName("Rogue");
	mClassAbilities[0] = new Ability("Stab", 3, 0, 0, 0, 0,0,10);
	mClassAbilities[1] = new Ability("Poison", 1, true, 1, 20, 0,0,15);
	mClassAbilities[2] = new Ability("Recovery Potion", 20, true, 10, 5, true,3,30);
	mClassAbilities[3] = new Ability("Bleed", 10, true, 4, 6, false,4,40);

	setCritChance(10.0f);
	setCritMod(2.0f);
	setDotDamage(3);
	for (size_t i = 0; i < 4; i++)
	{
		mAvailableAbilities.push_back(mClassAbilities[i]);
	}
	mAvailableAbilities.push_back(new Ability("Backstab", 40, false, 0, 0, false, 1, 30));
}
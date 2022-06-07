#include "Mage.h"

//derived from playerClass
//mage class, set specific abilities and allows for class specific funtions if wanted
Mage::Mage() 
{
	setMaxHealth(10);
	setName("Mage");
	mClassAbilities[0] = new Ability("Whack", 3, 0, 0, 0, 0,0,3);
	mClassAbilities[1] = new Ability("Fireball", 20,0,0,0,0,1,20);
	mClassAbilities[2] = new Ability("Incinerate",5,true,7,4,false,3,10);
	mClassAbilities[3] = new Ability("Heal",10,0,0,0,true,2,20);
	setCritChance(1.0f);
	setCritMod(10.0f);
	setDotDamage(1);

	for (size_t i = 0; i < 4; i++)
	{
		mAvailableAbilities.push_back(mClassAbilities[i]);
	}
	mAvailableAbilities.push_back(new Ability("Rejuvenate", 10, 1, 10, 5, 1, 3, 35));
	mAvailableAbilities.push_back(new Ability("Meteor Swarm", 100, 1, 100, 3, 1, 10, 200));
}
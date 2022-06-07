#include "Consumable.h"

//consumables, derived from item
Consumable::Consumable(int cost, int ratingValue)
{
	setRatingValue(ratingValue);
	setCost(ratingValue + rand() % ratingValue);
	setType(typeOfItems::ConsumableItem);
};

//uses consumable, effect based on type.
void Consumable::use(Entity* entity)
{
	int ratingValue = getRatingValue();
	int healthincrease = ratingValue / 10 + 1;
	int damageUpVal = ratingValue / 8 + 1;
	switch (getConsumableType())
	{
	case healthPotion:
		
		entity->setHealth(entity->getHealth() + healthincrease);
		std::cout << entity->getName() << " drank a health potion and regained " << healthincrease << std::endl;
		break;

	case damageIncrease:
		entity->setTempDamage(damageUpVal);
		std::cout << entity->getName() << " drank a damage potion and their damage is increased by " << damageUpVal << " until the end of the match" << std::endl;
		break;

	case abilityHolder: //generates a random ability and uses it.
		entity->useAbility(new Ability("Wild Scroll", ratingValue, rand() % 2, ratingValue / 2 + 1, ratingValue / 4 + 1, rand() % 2, ratingValue / 5 + 1));
		std::cout << entity->getName() << " opens a mysterious magical scroll and activates it ..." << std::endl;
		break;

	}
}


int Consumable::getConsumableType()
{
	return getItemType();
}

//sets name based on type
void Consumable::applyName()
{
	switch (getItemType())
	{
	case healthPotion:
		setName("Health Potion");
		break;
	case damageIncrease:
		setName("Damage Up");
		break;
	case abilityHolder:
		setName("Wild Scroll");
		break;
	}
}

//returns info of items such as healing value or how much extra damage you gain from the potion.
void Consumable::getInfo()
{
	int ratingValue = getRatingValue();
	std::cout << "Rating Value: " << ratingValue << std::endl;
	switch (getItemType())
	{
	case healthPotion:
		std::cout << "Name: Health Potion    ||" << " Healing Recieved: " << ratingValue / 10 + 1 << 
			"    || Cost:" << getCost() << std::endl;
		break;
	case damageIncrease:
		std::cout << "Name: Damage Up    ||" << "Damage: " << ratingValue / 8 + 1 <<
			"    || Cost:" << getCost() << std::endl; ;
		break;
	case abilityHolder:
		std::cout << "Name: Wild Scroll" <<
			"    || Cost:" << getCost() << std::endl;;
		break;
	}
}
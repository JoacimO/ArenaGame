#pragma once
#include "Item.h"
#include "Entity.h"
#include "Ability.h"
class Consumable : public Item
{
public:
	Consumable(int cost, int ratingValue);
	void use(Entity* Entity);
	void setConsumableType(int type);
	int getConsumableType();
	void getInfo();
private:
	void applyName();
	enum typeOfConsumable
	{
		healthPotion, damageIncrease, abilityHolder
	};

	
};
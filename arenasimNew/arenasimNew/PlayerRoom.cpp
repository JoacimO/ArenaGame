#include "PlayerRoom.h"

//derived of location, player room displays information to player about current stats, items and abilities,
//also allows player to sleep for a small bonus to health.
PlayerRoom::PlayerRoom(Player* player)
{
	setName("Inn");
	setDescription("You arrive at the inn and you get shown to your room");
	setOptions(PLAYER_ROOM_OPTIONS);
	setPlayer(player);
	for (size_t i = 0; i < PLAYER_ROOM_OPTIONS.size(); i++)
	{
		mLocationOptions.push_back(new LocationOption(0, PLAYER_ROOM_OPTIONS[i]));
	}

}

//virtual function to interact with location 
void PlayerRoom::selectLocationOption()
{
	switch (getInput())
	{
	case 1:
		std::cout << PLAYER_ROOM_OPTIONS[0] << ": " << std::endl;
		for (size_t i = 0; i < 4; i++)
		{
			printAbilityInformation(getPlayer()->getAbility(i), false);
		}
		leave();
		break;
	case 2:
		std::cout << PLAYER_ROOM_OPTIONS[1] << ": " << std::endl;
		_trySleep();
		leave();
		break;
	case 3:
		std::cout << PLAYER_ROOM_OPTIONS[2] << ": " << std::endl;
		_printStats();
		leave();
		break;
	case 4:
		std::cout << PLAYER_ROOM_OPTIONS[3] << ": " << std::endl;
		_displayInventory();
		break;
	case 5:
		leave();
		break;

	}
}

//check if player has enough money, if they do give them 1.1 * level in temporary hit points for the next battle.
void PlayerRoom::_trySleep()
{
	int sleep;
	sleep = queryInput({ "Yes", "No" });
	if (sleep == 1)
	{
		if (getPlayer()->getGoldPieces() > SLEEP_COST)
		{
			getPlayer()->setTempHealth(getPlayer()->getLevel() * 1.1f);
			getPlayer()->ChangeGPValue(-SLEEP_COST);
			std::cout << "You go to sleep and wake up feeling well rested!" << std::endl;
			std::cout << "Your max HP for the next battle is " << getPlayer()->getMaxHealth() + getPlayer()->getTempHealth() << std::endl;

		}
		else
		{
			std::cout << "You don't have enough money" << std::endl;
			
		}
	}

}

//print player stats such as health, gold and what abilities has a high scale factor. 
//also prints currently equiped items.
void PlayerRoom::_printStats()
{
	Player* player = getPlayer();
	std::cout << "Current Max Health: " << player->getMaxHealth() + player->getTempHealth() << std::endl;
	std::cout << "Current Gold Pieces: " << player->getGoldPieces() << std::endl;
	getPlayer()->printStats();
	std::cout << "Equpied Items: " << std::endl;
	for (size_t i = 0; i < 8; i++)
	{
		Wearable* currentItem = player->getGearPiece(i);
		//print equiped items
		if (currentItem->getIsEquiped())
		{
			std::cout<<std::endl;
			std::cout << currentItem->getName() << std::endl;
			currentItem->getInfo();
			std::cout << std::endl;
		}
	}
	
	for (size_t i = 0; i < 4; i++)
	{
	
		if (getPlayer()->getScaleFactor(i) > 1.5f)
		{
			std::cout << "You are talented at using " << player->getAbility(i)->getName() << std::endl;
		}
		
	}
	
}

//displays entire inventory and allows player to look at stats of a specific item by index.
void PlayerRoom::_displayInventory()
{
	Inventory* playerInventory = getPlayer()->getInventory();
	int numUsables = 0, numWearables = 0;
	std::vector<Item*> tempInventory;

	//if player has no items in inventory, exit this funtion
	if (playerInventory->getAmountOfUsables() + playerInventory->getAmountOfWearables() == 0)
	{
		std::cout << "You don't have any items in your inventory" << std::endl;
		leave();
		return;
	}

	//if total amount of items is > 1 : print inventory and place all items into a temp inventory
	//so player can interact with consumable and wearable inventory as if it was one big inventory
	for (size_t i = 0; i < playerInventory->getAmountOfUsables(); i++)
	{
		Item* temp = playerInventory->getItem(playerInventory->ConsumableItem, i);
		tempInventory.push_back(temp);
		std::cout << i+1 << " " << temp->getName() << std::endl;
	}
	for (size_t i = 0; i < playerInventory->getAmountOfWearables(); i++)
	{
		Item* temp = playerInventory->getItem(playerInventory->WearableItem, i);
		tempInventory.push_back(temp);
		std::cout << i + numUsables + 1 << " " << temp->getName() << std::endl;
	}
	std::cout << tempInventory.size() + 1 << " " << "Leave" << std::endl;

	setInput();
	tempInventory[getInput() - 1]->getInfo();
	queryInput({ "Leave" });

	if (getInput() >= tempInventory.size())
	{
		leave();
		tempInventory.~vector();
		return;
	}
	tempInventory.~vector();
	leave();
}
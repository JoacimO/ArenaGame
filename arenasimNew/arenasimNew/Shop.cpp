#include "Shop.h"

Shop::Shop(Player* player)
{

	setPlayer(player);
	setName("Shop");
	setOptions(SHOP_OPTIONS);
	for (size_t i = 0; i < ITEMS_IN_SHOP; i++)
	{
		mItems[i] = new Item();
	}
	_randomizeItems();
	mLocationOptions.push_back(new LocationOption(ITEMS_IN_SHOP, SHOP_OPTIONS[0]));
	for (size_t i = 0; i < ITEMS_IN_SHOP; i++)
	{
		mLocationOptions.back()->addLocationAlternativeName(mItems[i]->getName());
	}
	mLocationOptions.back()->addLocationAlternativeName("Leave");
}

void Shop::selectLocationOption()
{
	switch (getInput())
	{
	case 1:
		std::cout << "Welcome to the shop: " << std::endl;
		mLocationOptions[0]->printOptionAlternatives();
		setInput();
		_buyItem(getInput());
		break;
	case 2:
		leave();
		break;

	}
}

//randomizes item and sets "item score" value
void Shop::_randomizeItems()
{
	int randomValues[3];
	int playerLevel = getPlayer()->getLevel();

	for (size_t i = 0; i < ITEMS_IN_SHOP; i++)
	{
		for (size_t i = 0; i < 3; i++)
		{
			randomValues[i] = (rand() % 6 + 1);
		}
		if (randomValues[0] % 2 == 0)
		{
			Wearable* temp = new Wearable(randomValues[1] * playerLevel, randomValues[2] * playerLevel);
			int wearableType = rand() % 8;
			temp->setItemType(wearableType);
			mItems[i] = temp;
		}
		else
		{
			Consumable* temp = new Consumable(randomValues[1] * playerLevel, randomValues[2] * playerLevel);
			int consumableType = rand() % 3;
			temp->setItemType(consumableType);
			mItems[i] = temp;
		}
	}
}


//gives player option to buy item and asks them if the want to equip this sitem if it is a wearable item
void Shop::_buyItem(int input)
{
	input -= 1;

	// allows player to leave 
	if (input == ITEMS_IN_SHOP)
	{
		leave();
		return;
	}

	int buyItem;
	Item* chosenItem = mItems[input];
	Player* player = getPlayer();

	std::cout << "Buy: " << chosenItem->getName() << "?" << std::endl;
	std::cout << "Current Gold Pieces: " << player->getGoldPieces() << std::endl;
	std::cout << "Cost: " << chosenItem->getCost() << std::endl;

	chosenItem->getInfo();
	buyItem = queryInput({ "Yes", "No" }); //ask if player wants to buy item 

	//check if player has enough money 
	if (buyItem == 1 && player->getGoldPieces() < chosenItem->getCost())
	{
		std::cout << "You don't have enough money" << std::endl;
		buyItem = 2;
	}

	//if player buys item remove gold, place item into inventory, ask if they want to equip if item is wearable.
	if (buyItem == 1)
	{

		Inventory* playerInventory = player->getInventory();
		playerInventory->storeItem(chosenItem, chosenItem->getType());
		player->ChangeGPValue(-chosenItem->getCost());
		if (chosenItem->getType() == Inventory::WearableItem)
		{
			Wearable* tempWearable = (Wearable*)chosenItem;
			std::cout << "Equip this item?" << std::endl;
			int equip;
			equip = queryInput({ "Yes", "No" });
			if (equip == 1)
			{
				if (player->getGearSlotUsed(tempWearable->getItemType()))
				{
					std::cout << "Sell: " << player->getGearPiece(tempWearable->getItemType())->getName() << std::endl;;
					
					player->getGearPiece(tempWearable->getItemType())->getInfo();
					int sellItem = queryInput({ "Yes","No" });
					switch (sellItem)
					{
					case 1:
						player->ChangeGPValue(player->getGearPiece(tempWearable->getItemType())->getCost() / 2);
						player->getInventory()->removeitem(player->getGearPiece(tempWearable->getItemType())->getStorageIndex(),Inventory::WearableItem);
						break;
					case 2:
						player->getGearPiece(tempWearable->getItemType())->getInfo();
						std::cout << "Was Placed in to your inventory " << std::endl;
						break;
					default:
						break;
					}
				}

				player->equipItem(tempWearable);
				player->applyGearModifiers();
			}
			else
			{
				leave();
			}

		}
		leave();
	}
	else
	{
		mLocationOptions[0]->printOptionAlternatives();
		setInput();
		_buyItem(getInput());
	}
}
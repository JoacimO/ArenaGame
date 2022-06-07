#include "Arena.h"

Arena::Arena(Player* player)
{ 
	setName("Arena");
	setPlayer(player);
	setDescription("You arrive at the Arena");
	setOptions(ARENA_OPTIONS);

};

//virtual function
//fight or go back to menu
void Arena::selectLocationOption()
{
	switch (getInput())
	{
	case 1:
		_fight();
		break;
	case 2:
		leave();
		break;

	}
}

//leaves to main menu where check exists to see if a fight is starting
void Arena::_fight()
{
	setStartFight(true);
	leave();
}
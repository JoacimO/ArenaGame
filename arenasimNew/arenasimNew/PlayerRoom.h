
#include "Location.h"
class PlayerRoom : public Location
{
public:
	PlayerRoom(Player* player);
	void selectLocationOption();
private:
	const std::vector<std::string> PLAYER_ROOM_OPTIONS = { "Check Abilities","Sleep","Check stats","Check Inventory","Leave"};
	void _trySleep();
	void _printStats();
	void _displayInventory();
	const int SLEEP_COST = 10;
};
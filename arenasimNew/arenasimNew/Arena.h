#pragma once
#include "Location.h"
class Arena : public Location
{
public:
	Arena(Player* player);
	void selectLocationOption();
private:
	const std::vector<std::string> ARENA_OPTIONS = {"Fight", "Leave"};
	void _fight();
};

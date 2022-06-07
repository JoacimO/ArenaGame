#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Player.h"
#include "LocationOption.h"
class Location
{
public:
	Location();
	void printDescription();
	virtual void printOptions();
	std::string getName();
	bool getLeaveLocation();
	void setPlayer(Player* player);
	void printLocationOptions();
	virtual void selectLocationOption();
	void setInput();
	bool getStartFight();
protected:
	std::vector<LocationOption*> mLocationOptions;
	void setName(std::string text);
	void setDescription(std::string text);
	void setOptions(std::vector<std::string> options);
	void setLocationOptions(std::vector<std::string> options);
	void leave();
	Player* getPlayer();
	int getInput();
	int queryInput(std::vector<std::string> alternatives);
	void setStartFight(bool start);
	void printAbilityInformation(Ability* ability, bool printCost);
private:
	bool mLeaveLocation;
	std::string mLocationNPCText;
	std::string mShopName;
	std::string mDescription;
	std::vector<std::string> mOptions;
	std::vector<std::string> mLocationAlternatives;
	Player* mPlayer;
	int mInput;
	bool mStartFight;
};

#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include <time.h>
#include "Player.h"
#include "Enemy.h"
#include "FightManager.h"
#include "TownManager.h"

class Game
{
public:
	Game();
	void startGame();
	void runTime();

private:
	void _initializeRandomizer();
	void _clearScreen();
	void _printIntroduction();
	bool mGameRunning;
	bool mEncounter;
	Player* mPlayer;
	int mPlayerMaxHealth;
	Enemy* mEnemy;
	FightManager* mFightManager;
	TownManager* mTownManager;
	bool mFightManagerInitialized;

};


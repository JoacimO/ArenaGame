#include "Game.h"

using namespace std;
Game::Game() :
	mEncounter(false),
	mGameRunning(false),
	mFightManagerInitialized(false),
	mPlayerMaxHealth(0)
{
	_initializeRandomizer();
	mEnemy = new Enemy(0);
	mPlayer = new Player();
	mFightManager = new FightManager(mPlayer, mEnemy);
	mTownManager = new TownManager(mPlayer);

}
//starts the game, else statement for bug checking.
void Game::startGame()
{

	if (!mGameRunning)
	{
		runTime();
		mGameRunning = true;
	}
	else
	{
		std::cout << "Game is already running" << std::endl;
	}
}

//Makes player create character
//shows town menu (not implemented)
//starts combat
//handles rewards from combat

//maybe list--
//items
//ability shop
//new abilities on level up
//
void Game::runTime()
{

	//print introduction
	_printIntroduction();
	//create character
	mPlayer->createCharacter();
	mGameRunning = true;
	while (mGameRunning)
	{
		_clearScreen();
		
		//town interface
		mTownManager->printTownOptions();
		if (!mTownManager->getChoiceMade())
		{
			int input = 0;
			cin >> input;
			mTownManager->makeChoice(input);

			if (mTownManager->getStartFight())
			{
				mEncounter = true;
			}
			if (mTownManager->getLeaveCity())
			{
				mGameRunning = false;
				mEncounter = false;
			}
			cout << "Press enter to continue.. " << endl;
			cin.ignore();
			cin.get();
		}
		
		//fight start
		while (mEncounter)
		{
			_clearScreen();
			//initialize fightmanager with appropriate participants
			//based on level
			if (!mFightManagerInitialized)
			{
				mPlayerMaxHealth = mPlayer->getMaxHealth() + mPlayer->getTempHealth();
				mPlayer->setHealth(mPlayerMaxHealth);

				//resets cooldowns of all abilities
				for (size_t i = 0; i < 4; i++)
				{
					mPlayer->getAbility(i)->resetCooldown();
				}

				int level = mPlayer->getLevel();
				mEnemy = new Enemy(level);
				Entity* first = new Entity();
				Entity* second = new Entity();
				int turnOrder = rand() % 2;
				if (turnOrder == 0)
				{
					first = mPlayer;
					second = mEnemy;
				}
				else
				{
					first = mEnemy;
					second = mPlayer;
				}

				mFightManager = new FightManager(first, second);
				mFightManagerInitialized = true;
			}

			//print health values
			std::cout << "HP: " << mPlayer->getHealth() << " / " << mPlayerMaxHealth <<
				" LVL: " << mPlayer->getLevel() << std::endl;
			std::cout << "Enemy HP: " << mEnemy->getHealth() << " / " << mEnemy->getMaxHealth() << " Enemy LVL: " << mEnemy->getLevel() << std::endl;

			//fighters take turns
			mFightManager->takeTurns();
			//clear screen after turn is done and player continues.
			

			//if fight is done handle rewards and reset player temp stats 
			if (mFightManager->getFightFinished())
			{
				if (mFightManager->getPlayerWon())
				{
					string piece = "";
					string experience = "";
					cout << "You gain: " << mEnemy->getExperienceReward() << " Experience points" << std::endl;
					mPlayer->increaseExperiencePoints(mEnemy->getExperienceReward());
					mPlayer->checkIncreaseLevel();

					if (mEnemy->getGoldPieces() == 1)
						piece = "Piece";
					else
						piece = "Pieces";

					cout << "You gain: " << mEnemy->getGoldPieces() << " Gold " << piece << std::endl;
					mPlayer->ChangeGPValue(mEnemy->getGoldPieces());

				}
				mPlayer->setTempHealth(0);
				mPlayer->resetTempDamage();
				mEncounter = false;
				mFightManagerInitialized = false;
			}
			std::cin.ignore();
			std::cin.get();
			_clearScreen();

		}
	}
}

//clears screen
void Game::_clearScreen()
{
	
	//https://stackoverflow.com/questions/6486289/how-can-i-clear-console
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);

}

void Game::_initializeRandomizer()
{
	srand(time(NULL));
}

void Game::_printIntroduction()
{
	cout << "You arrive at the coloseum" << endl;
	cout << "you have ventured far to participate in the games! You seek to advance your skills and earn glory and fortune." << endl;
	cout << "But before that. Who are you?" << endl;
}
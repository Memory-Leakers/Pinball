#include "CoinsManager.h"

CoinsManager::CoinsManager(Application* _app)
{
	app = _app;

	for (int i = 0; i < MAX_COINS ;i++)
	{
		coins[i] = new Coins("Coin", "Coin", app, coinSpawnPos[i]);
		isPosAvailable[i] = false;
	}
}

void CoinsManager::PreUpdate()
{
	for (int i = 0; i < MAX_COINS; i++)
	{
		if (coins[i]->pendingToDelete)
		{
			coins[i]->pBody->body->SetTransform(b2Vec2(-100, -100), 0);
		}
		else 
		{
			coins[i]->PreUpdate();
		}
	}
}

void CoinsManager::Update()
{
	int currentActiveCoins = 0;

	for (int i = 0; i < MAX_COINS; i++)
	{
		if (!coins[i]->pendingToDelete)
		{
			currentActiveCoins++;
		}

		coins[i]->Update();
	}

	if (currentActiveCoins < 5)
	{
		if (--count <= 0)
		{
			int randNum = rand() % 9;

			while (!coins[randNum]->pendingToDelete)
			{
				randNum = rand() % 9;
			}

			b2Vec2 pos;
			pos.x = PIXELS_TO_METER(coinSpawnPos[randNum].x);
			pos.y = PIXELS_TO_METER(coinSpawnPos[randNum].y);
			coins[randNum]->pBody->body->SetTransform(pos, 0);

			count = 5 * FPS;

			coins[randNum]->pendingToDelete = false;

		}


	}
}

void CoinsManager::PostUpdate()
{
	for (int i = 0; i < MAX_COINS; i++)
	{
		coins[i]->PostUpdate();
	}
}

void CoinsManager::CleanUp()
{
}

CoinsManager::~CoinsManager()
{
	for (int i = 0; i < MAX_COINS; i++)
	{
		if (coins[i] != nullptr)
		{
			delete coins[i];
			coins[i] = nullptr;
		}
	}
}




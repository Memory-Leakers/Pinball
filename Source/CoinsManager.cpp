#include "CoinsManager.h"

CoinsManager::CoinsManager(Application* _app)
{
	app = _app;

	for (int i = 0; i < MAX_COINS ;i++)
	{
		coins[i] = new Coins("Coin", "Coin", app, coinSpawnPos[i]);
		isPosAvailable[i] = false;
	}

	for (int i = 0; i < 6; i++)
	{
		coinsLayer2L[i] = new Coins("Coin", "Coin", app, iPoint(-100, -100));
		coinsLayer2L[i]->pendingToDelete = true;
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
	// Coins 2 layer Left
	for (int i = 0; i < 6; i++)
	{
		if (coinsLayer2L[i]->pendingToDelete)
		{
			coinsLayer2L[i]->pBody->body->SetTransform(b2Vec2(PIXELS_TO_METER(-100), PIXELS_TO_METER(-100)), 0);
		}
		else
		{
			b2Vec2 pos;
			pos.x = PIXELS_TO_METER(coinSpawnPos2L[i].x);
			pos.y = PIXELS_TO_METER(coinSpawnPos2L[i].y);
			coinsLayer2L[i]->pBody->body->SetTransform(pos, 0);
			coinsLayer2L[i]->PreUpdate();
		}
	}
	for (int i = 0; i < COINNUM; i++)
	{
		if (coinPool[i]->pendingToDelete)
		{
			coinPool[i]->pBody->body->SetTransform(b2Vec2(-100, -100), 0);
		}
		else
		{
			coinPool[i]->PreUpdate();

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

	// Coins 2 layer Left
	for (int i = 0; i < 6; i++)
	{
		coinsLayer2L[i]->Update();
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

	int currentActiveCoins2 = 0;

	for (int i = 0; i < COINNUM; i++)
	{
		if (!coinPool[i]->pendingToDelete)
		{
			currentActiveCoins2++;
		}

		coinPool[i]->Update();
	}

	if (currentActiveCoins2 < 5)
	{
		if (--count <= 0)
		{
			int randNum = rand() % 15;

			while (!coinPool[randNum]->pendingToDelete)
			{
				randNum = rand() % 15;
			}
			int x = 457;
			int y = 550;

			x += (randNum % COIN_ROW)*25;
			y += (randNum / COIN_COLUMN) * 25;
		
			b2Vec2 pos;
			pos.x = PIXELS_TO_METER(x);
			pos.y = PIXELS_TO_METER(y);
			coinPool[randNum]->pBody->body->SetTransform(pos, 0);

			count = 5 * FPS;

			coinPool[randNum]->pendingToDelete = false;
		}
	}
}

void CoinsManager::PostUpdate()
{
	for (int i = 0; i < MAX_COINS; i++)
	{
		coins[i]->PostUpdate();
	}
	// Coins 2 layer Left
	for (int i = 0; i < 6; i++)
	{
		coinsLayer2L[i]->PostUpdate();
	}
	for (int i = 0; i < COINNUM; i++)
	{
		coinPool[i]->PostUpdate();
	}
}

void CoinsManager::CleanUp()
{
}

void CoinsManager::SpawnLayer2L()
{
	for (int i = 0; i < 6; i++)
	{
		coinsLayer2L[i]->pendingToDelete = false;
	}
}

void CoinsManager::DeleteLayer2L()
{
	for (int i = 0; i < 6; i++)
	{
		coinsLayer2L[i]->pendingToDelete = true;
	}
}
void CoinsManager::AddCoins(Coins* coin[], int size)
{
	for (int i = 0; i < size; i++)
	{
		coinPool[i] = coin[i];
	}
}

CoinsManager::~CoinsManager()
{
	for (int i = 0; i < MAX_COINS; i++)
	{
		RELEASE(coins[i]);
	}

	for (int i = 0; i < 6; i++)
	{
		RELEASE(coinsLayer2L[i]);
	}

	for (int i = 0; i < COINNUM; i++)
	{
			RELEASE(coinPool[i]);
	}
}

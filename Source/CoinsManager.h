#pragma once

#include "Coins.h"
#include "Timer.h"
#include <map>

#define COINNUM 15
#define MAX_COINS 9
#define COIN_ROW 5
#define COIN_COLUMN 3

class CoinsManager
{
private:
	iPoint coinSpawnPos[MAX_COINS] = { {316, 394}, {305, 349}, {324, 293},	//	Curva al lado de Boss
										{111, 236}, {168, 238}, {227, 240}, //	Encima de trigger para ca�on
											{144, 511}, {110, 443},			//	Camino al Toc�n
												{277, 454} };				// Debajo de Pared Azul

	iPoint coinSpawnPos2L[6] = { {92,640}, {80,600}, {90,500},{100,530}, {120,550}, {50,530} };

	bool isPosAvailable[MAX_COINS] = { false };
	Coins* coins[MAX_COINS];
	Coins* coinsLayer2L[6];
	Application* app;
	Coins* coinPool[COINNUM];

	int count = 5 * FPS; // = 15 segundos

public:
	CoinsManager(Application* _app);

	~CoinsManager();

	void PreUpdate();

	void Update();

	void PostUpdate();

	void CleanUp();

	void SpawnLayer2L();

	void DeleteLayer2L();

	void AddCoins(Coins* coin[], int size);
};

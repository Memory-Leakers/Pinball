#pragma once

#include "Coins.h"
#include "Timer.h"
#include <map>

#define MAX_COINS 9

class CoinsManager
{
private:
	iPoint coinSpawnPos[MAX_COINS] = { {316, 394}, {305, 349}, {324, 293},	//	Curva al lado de Boss
										{111, 236}, {168, 238}, {227, 240}, //	Encima de trigger para cañon
											{144, 511}, {110, 443},			//	Camino al Tocón
												{277, 454} };				// Debajo de Pared Azul

	iPoint coinSpawnPos2L[6] = { {92,640}, {80,600}, {90,500},{100,530}, {120,550}, {50,530} };

	bool isPosAvailable[MAX_COINS] = { false };
	Coins* coins[MAX_COINS];
	Coins* coinsLayer2L[6];
	Application* app;

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

};


#pragma once
#include "GameObject.h"

#include "SDL/include/SDL_rect.h"

class HealthBar
{
	//barra de vida SDL_Rect que disminuye de tama�o x cuando baja la vida
	// la canitdad de rojo aumenta mediante disminuye la cantidad de x
	// Ejemplo: x = 100 (full vida) red = 0; x = 50 red = 125; etc...

	int health;

	SDL_Rect healthRect;

	void Update()
	{
		
	}

	void UpdateHealthBar(int newHealth)	//	disminuye x y aumenta red en funci�n de el par�metro health.
	{
		health = newHealth;
	}
	 

};

class Boss : public GameObject
{
public:

	int health;
	int currentPhase;	// 0 = phase 0; 1 = phase 1;

	//	barra de vida (mini clase)



	Boss();

};


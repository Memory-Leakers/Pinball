#pragma once
#include "GameObject.h"

#include "SDL/include/SDL_rect.h"

class HealthBar
{
	//barra de vida SDL_Rect que disminuye de tamaño x cuando baja la vida
	// la canitdad de rojo aumenta mediante disminuye la cantidad de x
	// Ejemplo: x = 100 (full vida) red = 0; x = 50 red = 125; etc...
public:

	HealthBar(Application* app)
	{
		_app = app;
	};

	Application* _app;

	int totalHealth;	//Health in points (ex: 100000)
	int currentHealth;	//Current boss health

	int healthPercentage; // currentHealth  / (totalHealth / 100) Example -> 90.000 / (100.000 / 100) = 90%

	int totalHealthX;	//The total X of teh health rect

	int RGBrank; // -1 + (healthPercentage * 0,02)	// This makes the rank go from 1 to -1 // Example -> -1 + (80 * 0.02) = 0.6

	SDL_Rect healthRect;

	void PostUpdate()
	{
		healthPercentage = currentHealth / (totalHealth / 100);

		RGBrank = -1 + (healthPercentage * 0.02);

		healthRect.x = (healthPercentage / 100) * totalHealthX;

		if (RGBrank >= 0)
		{
			_app->renderer->DrawQuad(healthRect, (int)(255 - (RGBrank * 255)), 255, 0);
		}
		else 
		{
			_app->renderer->DrawQuad(healthRect, 255,(int)(255 - abs(RGBrank * 255)), 0);
		}

	} 

};

class Boss : public GameObject
{
public:

	int health;
	int currentPhase;	// 0 = phase 0; 1 = phase 1;

	//	barra de vida (mini clase)



	Boss(SDL_Texture* texture, std::string name, std::string tag, Application* _app);
};


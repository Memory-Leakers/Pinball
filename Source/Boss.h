#pragma once
#include "GameObject.h"

#include "SDL/include/SDL_rect.h"

class HealthBar
{
private:
	int healthPercentage; // currentHealth  / (totalHealth / 100) Example -> 90.000 / (100.000 / 100) = 90%

	float RGBrank; // -1 + (healthPercentage * 0,02)	// This makes the rank go from 1 to -1 // Example -> -1 + (80 * 0.02) = 0.6
public:

	HealthBar(Application* app, int x, int y, int width, int height, int health)
	{
		// Get variables
		_app = app;
		healthRect.x = x;
		healthRect.y = y;

		totalHealthW = width;

		healthRect.w = totalHealthW;
		healthRect.h = height;

		totalHealth = health;

		//Set variables
		currentHealth = totalHealth;
	};

	Application* _app;

	int totalHealth;	//Health in points (ex: 100000)
	int currentHealth;	//Current boss health

	int totalHealthW;	//The total X of teh health rect

	SDL_Rect healthRect;

	void PostUpdate()
	{
		healthPercentage = currentHealth / (totalHealth / 100);	//Current health Percentage

		RGBrank = (float)(-1 + (healthPercentage * 0.02));	// Current RGB rank, from 1 to -1

		float currentPercentage = (float)(healthPercentage / 100.0f);	//Percentage passed to float Example -> 90 = 0.9

		healthRect.w = currentPercentage * totalHealthW;	//	The rect width is equal to it's own total width times the current percentage

		//Change color logic
		if (RGBrank >= 0)
		{
			int red = (int)(255 - (RGBrank * 255));
			_app->renderer->AddRectRenderQueue(healthRect,red, 255, 0);
		}
		else 
		{
			int green = (int)(255 - abs(RGBrank * 255));
			_app->renderer->AddRectRenderQueue(healthRect, 255,green, 0);
		}

	} 
};

class Boss : public GameObject
{
private:
public:

	int health;
	int currentPhase;	// 0 = phase 0; 1 = phase 1;

	HealthBar* healthBar = nullptr;

	Boss(int health, std::string name, std::string tag, Application* _app);
	
	~Boss();

	void Update() override;

	void PostUpdate() override;

	void CleanUp() override;
};


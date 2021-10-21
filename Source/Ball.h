#pragma once
#include "GameObject.h"

class Ball :  public GameObject
{
public:
	Ball() {};

	Ball(SDL_Texture* texture, SDL_Texture* shadowTexture, std::string name, std::string tag,Application* _app);

	void OnCollision(PhysBody* col) override;

	void PreUpdate() override;

	void PostUpdate() override;

	SDL_Texture* shadow;

	b2Vec2 velocity;

	b2Vec2 velocityInvertido;

	b2Vec2 normal;
};


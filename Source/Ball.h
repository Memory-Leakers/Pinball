#pragma once
#include "GameObject.h"

class Ball :  public GameObject
{
public:

	Ball(Ball &ball, b2Vec2 pos);

	Ball(std::string name, std::string tag,Application* _app);

	void OnCollision(PhysBody* col) override;

	void Start() override;

	void PreUpdate() override;

	void PostUpdate() override;

	/*b2Vec2 velocity;

	b2Vec2 velocityInvertido;

	b2Vec2 normal;*/
};


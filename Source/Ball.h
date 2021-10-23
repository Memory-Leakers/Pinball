#pragma once
#include "GameObject.h"
#include "ScoreSystem.h"

class Ball :  public GameObject
{
private:
	int impulseForce = 200;

	bool initialSpring = false;

	ScoreSystem* scoreInstance;

public:

	Ball(Ball &ball, b2Vec2 pos, bool getVelocity);

	Ball(std::string name, std::string tag,Application* _app);

	void OnCollision(PhysBody* col) override;

	void Start() override;

	void Update() override;

	void PreUpdate() override;

	void PostUpdate() override;

	bool isTeleporting = false; // Activated when collisioning with a teleport Sensor


	/*b2Vec2 velocity;

	b2Vec2 velocityInvertido;

	b2Vec2 normal;*/
};


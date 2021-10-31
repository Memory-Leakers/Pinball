#pragma once
#include "GameObject.h"
#include "ScoreSystem.h"

class CoinsManager;

class Ball :  public GameObject
{
private:
	int impulseForce = 200;

	bool initialSpring = false;

	ScoreSystem* scoreInstance;

	CoinsManager* coinsManager;

public:

	Ball(Ball &ball, b2Vec2 pos, bool getVelocity, CoinsManager* coinsManager);

	Ball(std::string name, std::string tag, Application* _app, iPoint initPos = { 535, 780 }, CoinsManager* coinsManager = nullptr);

	void OnCollision(PhysBody* col) override;

	void Start() override;

	void Update() override;

	void PreUpdate() override;

	void PostUpdate() override;

	bool isTeleporting = false; // Activated when collisioning with a teleport Sensor

	bool isDeath = false; //Activated when collisioning with a death sensor

	bool topLayer = false; //False =  Player is on lower map | True = Player is on the second layer platforms

	bool saveSpring = true;
	/*b2Vec2 velocity;

	b2Vec2 velocityInvertido;

	b2Vec2 normal;*/
};


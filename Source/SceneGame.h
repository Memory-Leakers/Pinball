#pragma once
#include "Scene.h"
class Ball;
class Flipper;
class Boing;
class Sensor;
class Boss;
class Spring;

class SceneGame : public Scene
{
public:
    SceneGame(Application* app) :Scene(app)
    {

    }

    bool Start() override;

    bool PreUpdate() override;

    bool Update() override;

    bool PostUpdate() override;

    bool CleanUp() override;

    void CreateMap();

    void DeleteMap();

public:

    uint uis[3];

    Ball* player;

    Boing* boing;

    Flipper* flipper;

    Sensor* sensor;

    Boss* boss;

    Spring* spring;

    Sensor* sBallSpring;
    Sensor* sTeleportIn;

    iPoint teleportPosition;    //Determines where the player teleports when it hits the teleportIn Sensor

    //Map
    PhysBody* bg1;
    PhysBody* bg2;
    PhysBody* bg3;
    PhysBody* ball;
    PhysBody* flipper1;
    PhysBody* flipper2;

    PhysBody* smDivider1M;
    PhysBody* smDivider2M;

    PhysBody* pm;
};

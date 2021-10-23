#pragma once
#include "Scene.h"
class Ball;
class Flipper;
class Boing;
class PolygonBoing;
class Sensor;
class Boss;
class Spring;

#define BOINGCOUNT 5
#define TRIBOINGCOUNT 2
#define BOSSBOINGCOUNT 5

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

    Boing* boing[BOINGCOUNT];

    PolygonBoing* triBoing[TRIBOINGCOUNT];

    PolygonBoing* bossBoing[BOSSBOINGCOUNT];

    Flipper* flipper;

    Sensor* sensor;

    Sensor* deathSensor;

    Boss* boss;

    Spring* spring;

    Sensor* sBallSpring;

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

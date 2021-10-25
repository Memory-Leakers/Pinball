#pragma once
#include "Scene.h"
class Ball;
class Flipper;
class Boing;
class PolygonBoing;
class Sensor;
class KeySensor;
class Boss;
class Spring;
class PhysLayerL;
class PhysLayerR;
class ScoreSystem;
class CoinsManager;

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

    void SecondLayer();

    void DeleteMap();

public:

    uint uis[3];

    Ball* player;

    int playerLifes = 3;

    Boing* boing[BOINGCOUNT];

    PolygonBoing* triBoing[TRIBOINGCOUNT];

    PolygonBoing* bossBoing[BOSSBOINGCOUNT];

    Flipper* flipper_right;
    Flipper* flipper_left;

    Sensor* deathSensor;

    Boss* boss;

    Spring* spring;

    PhysLayerL* physLayer;
    PhysLayerR* physLayer2;

    CoinsManager* coinsManager;

    Sensor* sBallSpring;
    Sensor* sTeleportIn;
    Sensor* Cannon1;
    Sensor* Cannon2;
    Sensor* Cannon3;
    Sensor* enterPhysLayerL;
    Sensor* exitPhysLayerL;
    Sensor* enterPhysLayerR;
    Sensor* exitPhysLayerR;
    KeySensor* rightKey1;
    KeySensor* rightKey2;
    
    // background
    SDL_Texture* bg; 

    iPoint teleportPosition;    //Determines where the player teleports when it hits the teleportIn Sensor

    ScoreSystem* scoreSystem;

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

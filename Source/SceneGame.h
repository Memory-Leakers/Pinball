#pragma once
#include "Scene.h"
class Ball;
class Flipper;
class Boing;
class Sensor;
class Boss;
class Spring;
class PhysLayerL;
class ScoreSystem;

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

    Flipper* flipper_right;
    Flipper* flipper_left;
    Sensor* sensor;

    Boss* boss;

    Spring* spring;

    PhysLayerL* physLayer;

    Sensor* sBallSpring;
    Sensor* sTeleportIn;
    
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

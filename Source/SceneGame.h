#pragma once
#include "Scene.h"
class Ball;
class Flipper;
class Boing;

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
public:

    uint uis[3];

    Ball* player;

    Boing* boing;

    Flipper* flipper;
    
};

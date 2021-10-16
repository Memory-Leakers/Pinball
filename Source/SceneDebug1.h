#pragma once
#include "Scene.h"
class Ball;
class Flipper;

class SceneDebug1 : public Scene
{
public:
    SceneDebug1(Application* app) :Scene(app)
    {
    
    }

    bool Start() override;

    bool PostUpdate() override;

    bool CleanUp() override;

    Ball* player;

    Flipper* flipper;
    //GameObject ball;
};


#pragma once
#include "Scene.h"

class SceneDebug1 :
    public Scene
{
public:
    SceneDebug1(Application* app) :Scene(app)
    {
    
    }

    bool Start() override;

    //GameObject ball;
};


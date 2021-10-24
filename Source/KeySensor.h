#pragma once
#include "GameObject.h"
class KeySensor :
    public GameObject
{
public:
    KeySensor(SDL_Rect rect, int layer, std::string name, std::string tag, Application* _app);

    void OnCollision(PhysBody* col) override;

    bool unlocked = false;

};


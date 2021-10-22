#pragma once
#include "GameObject.h"
class Sensor : public GameObject
{
public:
    Sensor(SDL_Rect rect, int layer, std::string name, std::string tag, Application* _app);

    void OnCollision(PhysBody* col) override;



};


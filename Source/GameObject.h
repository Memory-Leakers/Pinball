#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include "Point.h"
struct SDL_Texture;
class PhysBody;

class GameObject 
{
public:

	GameObject();

	GameObject(SDL_Texture* texture,std::string name = "Default", std::string tag = "None");

	GameObject(GameObject& obj);

	~GameObject();

	virtual void OnCollision(PhysBody* col);

	bool CompareTag(std::string tag);

	iPoint GetDrawPos();

	float GetDegreeAngle();

public:

	std::string name;

	std::string tag;

	SDL_Texture* texture;

	PhysBody* pBody = nullptr;
};

#endif // !GAMEOBJECT_H
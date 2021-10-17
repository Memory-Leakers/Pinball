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

	GameObject(std::string name, SDL_Texture* texture);

	GameObject(GameObject& obj);

	GameObject(std::string name);

	~GameObject();

	virtual void OnCollision(PhysBody* col);

	bool CompareTag(std::string tag);

	iPoint GetDrawPos();

public:

	std::string name;

	std::string tag;

	SDL_Texture* texture;

	PhysBody* pBody = nullptr;
};

#endif // !GAMEOBJECT_H
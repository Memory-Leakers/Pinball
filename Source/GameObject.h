#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>

#include "ModulePhysics.h"

class GameObject 
{
public:

	GameObject(std::string name);

	~GameObject();

	std::string name;

	std::string tag;

	PhysBody* pBody = nullptr;

	virtual void OnCollision(PhysBody* col);

	bool CampareTag(std::string tag);
};

#endif // !GAMEOBJECT_H
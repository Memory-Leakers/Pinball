#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>

#include "ModulePhysics.h"

class GameObject 
{
public:

	GameObject();

	~GameObject();

	std::string tag;

	PhysBody* pBody;

	virtual void OnCollision(PhysBody* col);

	bool CampareTag(std::string tag);
};

#endif // !GAMEOBJECT_H
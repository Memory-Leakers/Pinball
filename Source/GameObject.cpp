#include "GameObject.h"

GameObject::GameObject(std::string name)
{
	this->name = name;
}

GameObject::~GameObject()
{
	if(pBody!=nullptr)
	{
		delete pBody;
		pBody = nullptr;
	}
}

void GameObject::OnCollision(PhysBody* col)
{
}

bool GameObject::CampareTag(std::string tag)
{
	if(this->tag == tag)
	{
		return true;
	}

	return false;
}

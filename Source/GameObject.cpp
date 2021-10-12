#include "GameObject.h"

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

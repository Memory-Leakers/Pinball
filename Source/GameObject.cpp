#include "GameObject.h"
#include "ModulePhysics.h"

GameObject::GameObject()
{
}

GameObject::GameObject(SDL_Texture* texture, std::string name, std::string tag)
{
	this->name = name;

	this->texture = texture;
}

GameObject::GameObject(GameObject& obj)
{
	this->name = obj.name;
	this->tag = obj.tag;
	this->pBody = obj.pBody;
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

bool GameObject::CompareTag(std::string tag)
{
	if(this->tag == tag)
	{
		return true;
	}

	return false;
}

iPoint GameObject::GetDrawPos()
{
	b2Vec2 pos;
	pos = pBody->body->GetPosition();

	pos.x = METERS_TO_PIXELS(pos.x - pBody->width);
	pos.y = METERS_TO_PIXELS(pos.y - pBody->height);

	return iPoint(pos.x,pos.y);
}

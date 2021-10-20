#include "GameObject.h"
#include "ModulePhysics.h"

GameObject::GameObject()
{
}

//TODO: Poner Applicationi* en constructor
GameObject::GameObject(SDL_Texture* texture, std::string name, std::string tag, Application* _app)
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

void GameObject::PreUpdate()
{
}

void GameObject::Update()
{
}

void GameObject::PostUpdate()
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

float GameObject::GetDegreeAngle()
{
	float agle = 0;

	agle = (pBody->body->GetAngle() * 180) / b2_pi;

	return agle;
}

#pragma once
#include "Module.h"
#include "Globals.h"
#include "Box2D/Box2D/Box2D.h"
#include <math.h>

class GameObject;

#define GRAVITY_X 0.0f
#define GRAVITY_Y -7.0f

#define PIXELS_PER_METER 50.0f
#define METERS_PER_PIXELS 0.02f

#define METERS_TO_PIXELS(m) ((int)floor(PIXELS_PER_METER * m) )
#define PIXELS_TO_METER(p) ((float)METERS_PER_PIXELS * p)


class PhysBody
{
public:
	PhysBody() : body(NULL)
	{}

	PhysBody(GameObject* g) : body(NULL)
	{
		gameObject = g;
	}

	void GetPosition(int& x, int& y) const;
	float GetRotation() const;
	bool Contains(int x, int y) const;
	int RayCast(int x1, int y1, int x2, int y2, float& normal_x, float& normal_y) const;

public:
	int width, height;
	b2Body* body;
	GameObject* gameObject;
	// TODO 6: Add a pointer to a module that might want to listen to a collision from this body
	Module* listenerModule = nullptr;
};

class ModulePhysics : public Module, public b2ContactListener
{
public:
	ModulePhysics(Application* app, bool start_enabled = true);
	~ModulePhysics();

	bool Start();
	UpdateStatus PreUpdate();
	UpdateStatus PostUpdate();
	bool CleanUp();

	PhysBody* CreateCircle(int x, int y, int radius);
	PhysBody* CreateRectangle(int x, int y, int width, int height);
	PhysBody* CreateRectangleSensor(int x, int y, int width, int height);
	PhysBody* CreateChain(int x, int y, int* points, int size);

	void BeginContact(b2Contact* contact) override;

private:

	b2World* world;
	bool debug;
};
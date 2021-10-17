#include "Globals.h"
#include "Application.h"
#include "ModulePhysics.h"
#include "math.h"
#include "GameObject.h"

ModulePhysics::ModulePhysics(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	world = NULL;	
	debug = true;
}

// Destructor
ModulePhysics::~ModulePhysics()
{
}

bool ModulePhysics::Start()
{
	LOG("Creating Physics 2D environment");

	world = new b2World(b2Vec2(GRAVITY_X, -GRAVITY_Y));
	b2BodyDef bd;
	mouseBody = world->CreateBody(&bd);

	world->SetContactListener(this);

	return true;
}

// 
UpdateStatus ModulePhysics::PreUpdate()
{
	world->Step(1.0f / 60.0f, 6, 2);

	// TODO: HomeWork
	/*
	for(b2Contact* c = world->GetContactList(); c; c = c->GetNext())
	{
	}
	*/

	return UPDATE_CONTINUE;
}

PhysBody* ModulePhysics::CreateCircle(int x, int y, int radius,GameObject* gameObject)
{
	b2BodyDef body;
	body.type = b2_dynamicBody;
	body.position.Set(PIXELS_TO_METER(x), PIXELS_TO_METER(y));

	b2Body* b = world->CreateBody(&body);

	b2CircleShape shape;
	shape.m_radius = PIXELS_TO_METER(radius);
	b2FixtureDef fixture;
	fixture.shape = &shape;
	fixture.density = 1.0f;

	b->CreateFixture(&fixture);

	PhysBody* pbody = new PhysBody();
	pbody->body = b;
	pbody->width = pbody->height = radius;

	pbody->body->SetUserData(pbody);

	pbody->gameObject = gameObject;

	return pbody;
}

PhysBody* ModulePhysics::CreateRectangle(int x, int y, int width, int height)
{
	b2BodyDef body;
	body.type = b2_dynamicBody;
	body.position.Set(PIXELS_TO_METER(x), PIXELS_TO_METER(y));

	b2Body* b = world->CreateBody(&body);
	b2PolygonShape box;
	box.SetAsBox(PIXELS_TO_METER(width) * 0.5f, PIXELS_TO_METER(height) * 0.5f);

	b2FixtureDef fixture;
	fixture.shape = &box;
	fixture.density = 1.0f;

	b->CreateFixture(&fixture);

	PhysBody* pbody = new PhysBody();
	pbody->body = b;
	pbody->width = width * 0.5f;
	pbody->height = height * 0.5f;

	pbody->body->SetUserData(pbody);

	return pbody;
}

PhysBody* ModulePhysics::CreateChainObj(int x, int y, int* points, int size, bool loop)
{
	b2BodyDef body;
	body.type = b2_dynamicBody;
	body.position.Set(PIXELS_TO_METER(x), PIXELS_TO_METER(y));

	b2Body* b = world->CreateBody(&body);

	b2ChainShape shape;
	b2Vec2* p = new b2Vec2[size / 2];

	for (uint i = 0; i < size / 2; ++i)
	{
		p[i].x = PIXELS_TO_METER(points[i * 2 + 0]);
		p[i].y = PIXELS_TO_METER(points[i * 2 + 1]);
	}

	if (loop)
	{
		shape.CreateLoop(p, size / 2);
	}
	else
	{
		shape.CreateChain(p, size / 2);
	}
		
	b2FixtureDef fixture;
	fixture.shape = &shape;

	b->CreateFixture(&fixture);

	delete p;

	PhysBody* pbody = new PhysBody();
	pbody->body = b;
	pbody->width = pbody->height = 0;

	pbody->body->SetUserData(pbody);

	return pbody;
}

void ModulePhysics::BeginContact(b2Contact* contact)
{
	/*
	PhysBody* a = (PhysBody*)contact->GetFixtureA()->GetBody()->GetUserData();

	PhysBody* b = (PhysBody*)contact->GetFixtureB()->GetBody()->GetUserData();

	if (a && a->gameObject)
	a->gameObject->OnCollision(b);

	if (b && b->gameObject)
	b->gameObject->OnCollision(a);
	
	//LOG("collision!!");
	*/
}

UpdateStatus ModulePhysics::PostUpdate()
{
	if(App->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN)
		debug = !debug;

	if (!debug)
		return UPDATE_CONTINUE;

	// Bonus code: this will iterate all objects in the world and draw the circles
	// You need to provide your own macro to translate meters to pixels
	for (b2Body* b = world->GetBodyList(); b; b = b->GetNext())
	{
		for (b2Fixture* f = b->GetFixtureList(); f; f = f->GetNext())
		{
			switch (f->GetType())
			{
				// Draw circles ------------------------------------------------
			case b2Shape::e_circle:
			{
				b2CircleShape* shape = (b2CircleShape*)f->GetShape();
				b2Vec2 pos = f->GetBody()->GetPosition();
				App->renderer->DrawCircle(METERS_TO_PIXELS(pos.x), METERS_TO_PIXELS(pos.y), METERS_TO_PIXELS(shape->m_radius), 0, 0, 0);
			}
			break;

			// Draw polygons ------------------------------------------------
			case b2Shape::e_polygon:
			{
				b2PolygonShape* polygonShape = (b2PolygonShape*)f->GetShape();
				int32 count = polygonShape->GetVertexCount();
				b2Vec2 prev, v;

				for (int32 i = 0; i < count; ++i)
				{
					v = b->GetWorldPoint(polygonShape->GetVertex(i));
					if (i > 0)
						App->renderer->DrawLine(METERS_TO_PIXELS(prev.x), METERS_TO_PIXELS(prev.y), METERS_TO_PIXELS(v.x), METERS_TO_PIXELS(v.y), 255, 100, 100);

					prev = v;
				}

				v = b->GetWorldPoint(polygonShape->GetVertex(0));
				App->renderer->DrawLine(METERS_TO_PIXELS(prev.x), METERS_TO_PIXELS(prev.y), METERS_TO_PIXELS(v.x), METERS_TO_PIXELS(v.y), 255, 100, 100);
			}
			break;

			// Draw chains contour -------------------------------------------
			case b2Shape::e_chain:
			{
				b2ChainShape* shape = (b2ChainShape*)f->GetShape();
				b2Vec2 prev, v;

				for (int32 i = 0; i < shape->m_count; ++i)
				{
					v = b->GetWorldPoint(shape->m_vertices[i]);
					if (i > 0)
						App->renderer->DrawLine(METERS_TO_PIXELS(prev.x), METERS_TO_PIXELS(prev.y), METERS_TO_PIXELS(v.x), METERS_TO_PIXELS(v.y), 100, 255, 100);
					prev = v;
				}

				v = b->GetWorldPoint(shape->m_vertices[0]);
				App->renderer->DrawLine(METERS_TO_PIXELS(prev.x), METERS_TO_PIXELS(prev.y), METERS_TO_PIXELS(v.x), METERS_TO_PIXELS(v.y), 100, 255, 100);
			}
			break;

			// Draw a single segment(edge) ----------------------------------
			case b2Shape::e_edge:
			{
				b2EdgeShape* shape = (b2EdgeShape*)f->GetShape();
				b2Vec2 v1, v2;

				v1 = b->GetWorldPoint(shape->m_vertex0);
				v1 = b->GetWorldPoint(shape->m_vertex1);
				App->renderer->DrawLine(METERS_TO_PIXELS(v1.x), METERS_TO_PIXELS(v1.y), METERS_TO_PIXELS(v2.x), METERS_TO_PIXELS(v2.y), 100, 100, 255);
			}
			break;
			}
		}

		// If mouse button 1 is pressed ...
		if (App->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_DOWN)
		{
			PhysBody pBody;
			pBody.body = b;

			// test if the current body contains mouse position
			if (pBody.Contains(App->input->GetMouseX(), App->input->GetMouseY()))
			{
				b2MouseJointDef def;
				def.bodyA = mouseBody;
				def.bodyB = pBody.body;
				def.target = b2Vec2(PIXELS_TO_METER(App->input->GetMouseX()), PIXELS_TO_METER(App->input->GetMouseY()));
				def.dampingRatio = 0.5f;
				def.frequencyHz = 2.0f;
				def.maxForce = 100.0f * pBody.body->GetMass();
				mouseJoint = (b2MouseJoint*)world->CreateJoint(&def);
			}
		}

		if (App->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_REPEAT && mouseJoint != nullptr)
		{
			b2Vec2 nextPos = { (float)App->input->GetMouseX(),(float)App->input->GetMouseY() };

			nextPos.x = PIXELS_TO_METER(nextPos.x);
			nextPos.y = PIXELS_TO_METER(nextPos.y);

			mouseJoint->SetTarget(nextPos);
			// -------------------------------------------
			App->renderer->DrawLine(METERS_TO_PIXELS(mouseJoint->GetAnchorA().x), METERS_TO_PIXELS(mouseJoint->GetAnchorA().y),
				METERS_TO_PIXELS(mouseJoint->GetAnchorB().x), METERS_TO_PIXELS(mouseJoint->GetAnchorB().y),
				255, 0, 0);
		}

		if (App->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_UP && mouseJoint != nullptr)
		{
			world->DestroyJoint(mouseJoint);
			mouseJoint = nullptr;
		}
	}

	return UPDATE_CONTINUE;
}
// Called before quitting
bool ModulePhysics::CleanUp()
{
	LOG("Destroying physics world");

	// Delete the whole physics world!
	delete world;

	return true;
}

void PhysBody::GetPosition(int& x, int& y) const
{
	b2Vec2 pos = body->GetPosition();
	x = METERS_TO_PIXELS(pos.x) - (width);
	y = METERS_TO_PIXELS(pos.y) - (height);
}

float PhysBody::GetRotation() const
{
	return RADTODEG * body->GetAngle();
}

bool PhysBody::Contains(int x, int y) const
{
	b2Fixture* f = body->GetFixtureList();

	b2Vec2 b = { PIXELS_TO_METER(x),PIXELS_TO_METER(y) };

	for (int i = 0; f != nullptr; f = f->GetNext())
	{
		if (f->GetShape()->TestPoint(body->GetTransform(),b))
		{
			return true;
		}
	}

	return false;
}

int PhysBody::RayCast(int x1, int y1, int x2, int y2, float& normal_x, float& normal_y) const
{
	b2Fixture* f = body->GetFixtureList();

	b2RayCastInput input;
	input.p1 = b2Vec2(PIXELS_TO_METER(x1), PIXELS_TO_METER(y1));
	input.p2 = b2Vec2(PIXELS_TO_METER(x2), PIXELS_TO_METER(y2));

	// multiplo de distancia entre p1 y p2
	// ej distancia = 2,  maxFraction = 2,  distancia de deteccion = 2*2 = 4
	input.maxFraction = 1.0f;

	b2RayCastOutput* output = nullptr;

	for (int i = 0; f != nullptr; f = f->GetNext())
	{
		f->RayCast(output, input, 0);

		if (output != nullptr)
		{
			normal_x = output->normal.x;
			normal_y = output->normal.y;

			float distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

			distance *= output->fraction;

			delete output;

			return distance;
		}
	}

	return -1;
}

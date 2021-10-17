#include "Boing.h"
#include "GameObject.h"

Boing::Boing(Point<int> pos)
{
}

Boing::~Boing()
{
}

void Boing::OnCollision(PhysBody* col)
{
	if (col->gameObject->CompareTag("Player")) 
	{
		/*b2Vec2 velocity;

		velocity = col->body->GetLinearVelocity();

		b2Vec2 normal;
		*/

		//Vectorvelocidad.reflected
	}
}
#pragma once
#include "Collision.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

class GameObject;

class RadiusCollision : public Collision 
{
public:

	RadiusCollision(GameObject* gameObject);
	~RadiusCollision();

	void initialise();

	void update();

	float getRadius() const;

	bool isColliding(RadiusCollision * collider);



private:
	float radius;

};


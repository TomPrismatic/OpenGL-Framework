#pragma once
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

class GameObject;

class Collision
{
public:

	Collision();
	virtual ~Collision();

	virtual void initialise() = 0;

	virtual glm::vec3 getCentrePosition();

protected:
	GameObject * gameObject = NULL;
	glm::vec3 centrePosition;
};


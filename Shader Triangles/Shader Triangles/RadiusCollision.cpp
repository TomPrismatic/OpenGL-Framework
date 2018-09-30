#include "RadiusCollision.h"
#include "GameObject.h"



RadiusCollision::RadiusCollision(GameObject* gameObject)
{
	this->gameObject = gameObject;
}


void RadiusCollision::initialise()
{
	centrePosition = gameObject->transform.objPosition;
	radius = (gameObject->getObjectDiameter()) / 2;
}

void RadiusCollision::update()
{
	centrePosition = gameObject->transform.objPosition;
}

void RadiusCollision::setRadius(float length)
{
	radius = length;
}

float RadiusCollision::getRadius() const
{
	return radius;
}

bool RadiusCollision::isColliding(RadiusCollision * collider)
{

	if (Transform::getDistanceBetweenObjects(centrePosition, collider->getCentrePosition()) < radius + collider->getRadius())
	{
		return true;
	}

	else
	{
		return false;
	}
}

RadiusCollision::~RadiusCollision()
{
}

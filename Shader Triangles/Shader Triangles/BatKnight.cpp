#include "BatKnight.h"



BatKnight::BatKnight()
{
}


BatKnight::~BatKnight()
{
}

void BatKnight::Movement(float deltaTime)
{
	currentTime = glutGet(GLUT_ELAPSED_TIME);  // Get current time. 
	currentTime = currentTime / 1000;  // Convert millisecond to seconds
	transform.objPosition.x = (transform.objPosition.x + (sin(currentTime) * 5));
	transform.objPosition.y = (transform.objPosition.y + (cos(currentTime) * 5));
}

void BatKnight::render(GLuint program)
{
	if (isVisible)
	{
		GameObject::render(program);
	}
}

void BatKnight::update(float deltaTime, GLuint program)
{
	GameObject::update(deltaTime, true, 1, false, frameIndex);
	collider->update();
	sound.update();
	frameIndex++;
	Movement(deltaTime);
}

void BatKnight::initialise()
{
	objectDiameter *= 2.5;

	transform.setRotationAngleZ(270);
	transform.objPosition.x = -200;
	transform.objPosition.y = +200;
	updateSprite();
	collider->initialise();
	//updateSounds();
	//sound.initialise();

	GameObject::initialise(66.25, 87, 265, 87, frameIndex, texture.getStringPath());
}

void BatKnight::updateSprite()
{
	texture.setStringPath("Dependencies/BatFlying.png");
}

void BatKnight::updateSounds()
{
}

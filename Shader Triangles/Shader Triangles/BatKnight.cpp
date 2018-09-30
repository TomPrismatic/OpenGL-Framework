#include "BatKnight.h"



BatKnight::BatKnight()
{
}


BatKnight::~BatKnight()
{
}

void BatKnight::Movement()
{
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
	GameObject::update(deltaTime, true, 1, false);
	collider->update();
	sound.update();
	frameIndex = deltaTime;
	Movement();
}

void BatKnight::initialise()
{
	objectDiameter *= 2.5;

	transform.setRotationAngleZ(270);
	transform.objPosition.y = -300;
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

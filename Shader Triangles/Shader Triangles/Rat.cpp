#include "Rat.h"



Rat::Rat()
{
}


Rat::~Rat()
{
}

void Rat::Movement()
{
}

void Rat::render(GLuint program)
{
	if (isVisible)
	{
		GameObject::render(program);
	}
}

void Rat::update(float deltaTime, GLuint program)
{
	GameObject::update(deltaTime, true, 1, false);
	collider->update();
	sound.update();
	frameIndex = deltaTime;
	Movement();
}

void Rat::initialise()
{
	objectDiameter *= 2;
	transform.objPosition.x = -100;
	transform.objPosition.y = -100;
	transform.setRotationAngleZ(270);
	updateSprite();
	collider->initialise();
	//updateSounds();
	//sound.initialise();

	GameObject::initialise(45, 44, 180, 44, frameIndex, texture.getStringPath());
}

void Rat::updateSprite()
{
	texture.setStringPath("Dependencies/CaveRatSpriteSheet.png");
}

void Rat::updateSounds()
{
}

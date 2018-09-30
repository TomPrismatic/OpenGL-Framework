#include "Zombie.h"



Zombie::Zombie()
{
}


Zombie::~Zombie()
{
}

void Zombie::Movement()
{
	if (previousDirection <= 100)
	{
		transform.objPosition.y += 2.0f;
		previousDirection++;
	}

	if (previousDirection <= 200 && previousDirection > 100)
	{
		transform.objPosition.x += 2.0f;
		previousDirection++;
		transform.setRotationAngleZ(270);
		transform.setRotationAngleY(0);
	}

	if (previousDirection <= 300 && previousDirection > 200)
	{
		transform.objPosition.y -= 2.0f;
		previousDirection++;
	}
	if (previousDirection < 400 && previousDirection > 300)
	{
		transform.objPosition.x -= 2.0f;
		transform.setRotationAngleZ(90);
		transform.setRotationAngleY(180);
		previousDirection++;
	}
	if (previousDirection == 400)
	{
		previousDirection = 0;
	}
}

void Zombie::update(float deltaTime, GLuint program)
{
	GameObject::update(deltaTime, true, 1, false, frameIndex);
	collider->update();
	sound.update();
	frameIndex++;
	Movement();
}

void Zombie::initialise()
{
	objectDiameter *= 2.5;
	transform.objPosition.x = 100;
	transform.setRotationAngleZ(270);
	updateSprite();
	collider->initialise();
	//updateSounds();
	//sound.initialise();

	GameObject::initialise(100, 89, 600, 89, frameIndex, texture.getStringPath());
}

void Zombie::render(GLuint program)
{
	if (isVisible)
	{
		GameObject::render(program);
	}
}

void Zombie::updateSprite()
{
	texture.setStringPath("Dependencies/ZombieMinerSpriteSheet.png");
}

void Zombie::updateSounds()
{
}

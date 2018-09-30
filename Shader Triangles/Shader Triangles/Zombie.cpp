#include "Zombie.h"



Zombie::Zombie()
{
}


Zombie::~Zombie()
{
}

void Zombie::Movement()
{
}

void Zombie::update(float deltaTime, GLuint program)
{
	GameObject::update(deltaTime, true, 1, false);
	collider->update();
	sound.update();
	frameIndex = deltaTime;
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

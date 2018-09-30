#include "Rat.h"



Rat::Rat()
{
}


Rat::~Rat()
{
}

void Rat::Movement()
{
	if (previousDirection <= 100)
	{
		transform.objPosition.x += 2.0f;
		transform.objPosition.y += 2.0f;
		previousDirection++;
	}

	if (previousDirection <= 200 && previousDirection > 100)
	{
		transform.objPosition.x -= 2.0f;
		transform.objPosition.y -= 2.0f;
		previousDirection++;
		//transform.setRotationAngleZ(270);
		//transform.setRotationAngleY(0);
	}

	if (previousDirection <= 300 && previousDirection > 200)
	{
		transform.objPosition.x += 2.0f;
		transform.objPosition.y -= 2.0f;
		previousDirection++;
	}

	if (previousDirection <= 400 && previousDirection > 300)
	{
		transform.objPosition.x -= 2.0f;
		transform.objPosition.y += 2.0f;
		previousDirection++;
	}

	if (previousDirection <= 500 && previousDirection > 400)
	{
		transform.objPosition.x -= 2.0f;
		transform.objPosition.y += 2.0f;
		previousDirection++;
	}
	
	if (previousDirection <= 600 && previousDirection > 500)
	{
		transform.objPosition.x += 2.0f;
		transform.objPosition.y -= 2.0f;
		previousDirection++;
	}
	
	if (previousDirection <= 700 && previousDirection > 600)
	{
		transform.objPosition.x -= 2.0f;
		transform.objPosition.y -= 2.0f;
		previousDirection++;
	}
	if (previousDirection <= 800 && previousDirection > 700)
	{
		transform.objPosition.x += 2.0f;
		transform.objPosition.y += 2.0f;
		previousDirection++;
	}
	if (previousDirection == 800)
	{
		previousDirection = 0;
	}
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
	GameObject::update(deltaTime, true, 1, false, frameIndex);
	collider->update();
	sound.update();
	frameIndex++;
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

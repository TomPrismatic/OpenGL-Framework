#include "RatScene.h"



RatScene::RatScene()
{
}


RatScene::~RatScene()
{
}

void RatScene::Movement()
{
	if (Input::GetKeyDown('p') == DOWN)
	{
		if (hasBeenReleased == true)
		{
			if (animationIndex == 8)
			{
				isVisible = false;
			}

			else
			{
				animationIndex++;
			}

			hasBeenReleased = false;
		}

	}

	if (Input::GetKeyDown('p') == UP)
	{
		hasBeenReleased = true;
	}
}

void RatScene::render(GLuint program)
{
	if (isVisible)
	{
		GameObject::render(program);
	}
}

void RatScene::update(float deltaTime, GLuint program)
{
	GameObject::update(deltaTime, true, animationIndex, false, frameIndex);
	sound.update();
	frameIndex++;
	Movement();
}

void RatScene::initialise()
{
	objectDiameter *= 16;

	transform.setRotationAngleZ(90);
	transform.setRotationAngleY(180);
	updateSprite();

	GameObject::initialise(800, 800, 800, 2400, frameIndex, texture.getStringPath());
}

void RatScene::updateSprite()
{
	texture.setStringPath("Dependencies/ratSceneSpriteSheet.png");
}

void RatScene::updateSounds()
{
}

#include "BatScene.h"



BatScene::BatScene()
{
}


BatScene::~BatScene()
{
}

void BatScene::Movement()
{
	if (Input::GetKeyDown('p') == DOWN)
	{
		if (hasBeenReleased == true)
		{
			if (animationIndex == 4)
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

void BatScene::render(GLuint program)
{
	if (isVisible)
	{
		GameObject::render(program);
	}
}

void BatScene::update(float deltaTime, GLuint program)
{
	GameObject::update(deltaTime, true, animationIndex, false, frameIndex);
	sound.update();
	frameIndex++;
	Movement();
}

void BatScene::initialise()
{
	objectDiameter *= 16;

	transform.setRotationAngleZ(90);
	transform.setRotationAngleY(180);
	updateSprite();

	GameObject::initialise(800, 800, 800, 3200, frameIndex, texture.getStringPath());
}

void BatScene::updateSprite()
{
	texture.setStringPath("Dependencies/batCutSceneSpriteSheet.png");
}

void BatScene::updateSounds()
{
}

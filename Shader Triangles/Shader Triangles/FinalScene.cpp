#include "FinalScene.h"



FinalScene::FinalScene()
{
}


FinalScene::~FinalScene()
{
}

void FinalScene::Movement()
{
	if (Input::GetKeyDown('p') == DOWN)
	{
		if (hasBeenReleased == true)
		{
			if (animationIndex == 15)
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

void FinalScene::render(GLuint program)
{
	if (isVisible)
	{
		GameObject::render(program);
	}
}

void FinalScene::update(float deltaTime, GLuint program)
{
	GameObject::update(deltaTime, true, animationIndex, false, frameIndex);
	sound.update();
	frameIndex++;
	Movement();
}

void FinalScene::initialise()
{
	objectDiameter *= 16;

	transform.setRotationAngleZ(90);
	transform.setRotationAngleY(180);
	updateSprite();

	GameObject::initialise(800, 800, 800, 6400, frameIndex, texture.getStringPath());
}

void FinalScene::updateSprite()
{
	texture.setStringPath("Dependencies/finalCutsceneSpriteSheet.png");
}

void FinalScene::updateSounds()
{
}

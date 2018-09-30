#include "IntroScene.h"



IntroScene::IntroScene()
{
}


IntroScene::~IntroScene()
{
}

void IntroScene::Movement()
{
	if (Input::GetKeyDown('p') == DOWN)
	{
		if (hasBeenReleased == true)
		{
			if (animationIndex == 13)
			{
				animationIndex = 2;
			}

			if (animationIndex == 12)
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

void IntroScene::render(GLuint program)
{
	if (isVisible)
	{
		GameObject::render(program);
	}
}

void IntroScene::update(float deltaTime, GLuint program)
{
	GameObject::update(deltaTime, true, animationIndex, false);
	sound.update();
	frameIndex = deltaTime;
	Movement();
}

void IntroScene::initialise()
{
	objectDiameter *= 16;

	transform.setRotationAngleZ(90);
	transform.setRotationAngleY(180);
	updateSprite();
	//updateSounds();
	//sound.initialise();

	GameObject::initialise(800, 800, 800, 10400, frameIndex, texture.getStringPath());
}

void IntroScene::updateSprite()
{
	texture.setStringPath("Dependencies/introSceneSpriteSheet.png");
}

void IntroScene::updateSounds()
{
}

#include "ZombieScene.h"



ZombieScene::ZombieScene()
{
}


ZombieScene::~ZombieScene()
{
}

void ZombieScene::Movement()
{
	if (Input::GetKeyDown('p') == DOWN)
	{
		if (hasBeenReleased == true)
		{
			if (animationIndex == 9)
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

void ZombieScene::render(GLuint program)
{
	if (isVisible)
	{
		GameObject::render(program);
	}
}

void ZombieScene::update(float deltaTime, GLuint program)
{
	GameObject::update(deltaTime, true, animationIndex, false, frameIndex);
	sound.update();
	frameIndex++;
	Movement();

}

void ZombieScene::initialise()
{
	objectDiameter *= 16;

	transform.setRotationAngleZ(90);
	transform.setRotationAngleY(180);
	updateSprite();
	animationIndex = 5;

	GameObject::initialise(800, 800, 800, 4000, frameIndex, texture.getStringPath());
}

void ZombieScene::updateSprite()
{
	texture.setStringPath("Dependencies/zombieSceneSpriteSheet.png");
}

void ZombieScene::updateSounds()
{
}

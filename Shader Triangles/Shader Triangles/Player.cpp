#include "Player.h"
#include "Input.h"
#include "Collision.h"
#include "RadiusCollision.h"


Player::Player()
{
}


Player::~Player()
{
}


void Player::ProcessInput(std::vector <GameObject*> vectorOfGameObjects)
{
	int movementCheck = 0;
	if (Input::GetKeyDown('w') == DOWN)
	{
		if (isAttacking == false)
		{
			for (unsigned int i = 0; i < 3; i++)
			{
				if ((vectorOfGameObjects.at(i)->getIsVisible()))
				{
					if (!(collider->isColliding(vectorOfGameObjects.at(i)->getCollider())))
					{
						movementCheck++;
						if (movementCheck == 3)
						{
							transform.objPosition.y += 2.0f;
							movementCheck = 0;
						}
					}
				}
				else
				{
					transform.objPosition.y += 2.0f;
				}
				
			}
			animationIndex = 1;
		}
		
	}

	if (Input::GetKeyDown('s') == DOWN)
	{
		if (isAttacking == false)
		{
			for (unsigned int i = 0; i < 3; i++)
			{
				if ((vectorOfGameObjects.at(i)->getIsVisible()))
				{
					if (!(collider->isColliding(vectorOfGameObjects.at(i)->getCollider())))
					{
						movementCheck++;
						if (movementCheck == 3)
						{
							transform.objPosition.y -= 2.0f;
							movementCheck = 0;
						}
					}
				}
				else
				{
					transform.objPosition.y -= 2.0f;
				}
			}
			animationIndex = 1;
		}
	}

	if (Input::GetKeyDown('d') == DOWN)
	{
		if (isAttacking == false)
		{
			for (unsigned int i = 0; i < 3; i++)
			{
				if ((vectorOfGameObjects.at(i)->getIsVisible()))
				{
					if (!(collider->isColliding(vectorOfGameObjects.at(i)->getCollider())))
					{
						movementCheck++;
						if (movementCheck == 3)
						{
							transform.objPosition.x += 2.0f;
							movementCheck = 0;
						}
					}
				}
				else
				{
					transform.objPosition.x += 2.0f;
				}
			}
			transform.setRotationAngleZ(90);
			transform.setRotationAngleY(180);
			animationIndex = 1; 
		}
	}

	if (Input::GetKeyDown('a') == DOWN)
	{
		if (isAttacking == false)
		{
			for (unsigned int i = 0; i < 3; i++)
			{
				if ((vectorOfGameObjects.at(i)->getIsVisible()))
				{
					if (!(collider->isColliding(vectorOfGameObjects.at(i)->getCollider())))
					{
						movementCheck++;
						if (movementCheck == 3)
						{
							transform.objPosition.x -= 2.0f;
							movementCheck = 0;
						}
					}
				}
				else
				{
					transform.objPosition.x -= 2.0f;
				}
			}
			transform.setRotationAngleZ(270);
			transform.setRotationAngleY(0);
			animationIndex = 1;
		}
	}

	if (Input::GetKeyDown('h') == DOWN)
	{
		if (isAttacking == false)
		{
			animationIndex = 2;
			isAttacking = true;
			sound.playSound(1);
			if (collider->isColliding(vectorOfGameObjects.at(0)->getCollider()))
			{
				vectorOfGameObjects.at(0)->setIsVisible(false);
			}
		}
	}

	if (Input::GetKeyDown('j') == DOWN)
	{
		if (isAttacking == false)
		{
			animationIndex = 3;
			isAttacking = true;
			sound.playSound(2);
			if (collider->isColliding(vectorOfGameObjects.at(1)->getCollider()))
			{
				vectorOfGameObjects.at(1)->setIsVisible(false);
			}
		}
	}

	if (Input::GetKeyDown('k') == DOWN)
	{
		if (isAttacking == false)
		{
			animationIndex = 4;
			isAttacking = true;
			sound.playSound(3);
			if (collider->isColliding(vectorOfGameObjects.at(2)->getCollider()))
			{
				vectorOfGameObjects.at(2)->setIsVisible(false);
			}
		}
	}

	/*if (   Input::GetKeyDown('w') == UP && Input::GetKeyDown('a') == UP 
		&& Input::GetKeyDown('s') == UP && Input::GetKeyDown('d') == UP
		&& Input::GetKeyDown('h') == UP && Input::GetKeyDown('j') == UP 
		&& Input::GetKeyDown('k') == UP)
	{
		animationIndex = 0;
	}*/
}

void Player::render(GLuint program)
{
	if (isVisible)
	{
		GameObject::render(program);
	}
}

void Player::update(float deltaTime, GLuint program, std::vector <GameObject*> vectorOfGameObjects)
{
	GameObject::update(deltaTime, true, animationIndex, isAttacking);
	collider->update();
	sound.update();
	frameIndex = deltaTime;
	ProcessInput(vectorOfGameObjects);
	if (getIsCompleted())
	{
		isAttacking = false;
		animationIndex = 1;
	}
}

void Player::initialise()
{
	collider->initialise();
	objectDiameter *= 4;
	transform.setRotationAngleZ(270);
	updateSprite();
	updateSounds();
	animationIndex = 0;

	GameObject::initialise(93.75, 89, 750, 356, frameIndex, texture.getStringPath());

}

void Player::updateSprite()
{
	texture.setStringPath("Dependencies/DwarfSpriteSheet3.png");
}

void Player::updateSounds()
{
	sound.setStringPath("Dependencies/TheMinesBackgroundMusic.mp3", 0);
	sound.initialise();
	sound.setStringPath("Dependencies/HeavySwing.wav", 1);
	sound.setStringPath("Dependencies/MediumSwing.wav", 2);
	sound.setStringPath("Dependencies/LightSwing.mp3", 3);
	sound.createSoundEffect(1);
	sound.createSoundEffect(2);
	sound.createSoundEffect(3);

}


#include "Player.h"
#include "Input.h"


Player::Player()
{
}


Player::~Player()
{
}


void Player::ProcessInput()
{
	if (Input::GetKeyDown('w') == DOWN)
	{
		transform.objPosition.y += 1.0f;
	}

	if (Input::GetKeyDown('s') == DOWN)
	{
		transform.objPosition.y -= 1.0f;
	}

	if (Input::GetKeyDown('d') == DOWN)
	{
		transform.objPosition.x += 1.0f;
		transform.setRotationAngleZ(90);
		transform.setRotationAngleY(180);
		animationIndex = 1;
	}

	if (Input::GetKeyDown('a') == DOWN)
	{
		transform.objPosition.x -= 1.0f;
		transform.setRotationAngleZ(270);
		transform.setRotationAngleY(0);
		animationIndex = 1;
	}

	if (Input::GetKeyDown('h') == DOWN)
	{
		animationIndex = 2;
	}

	if (Input::GetKeyDown('j') == DOWN)
	{
		animationIndex = 3;
	}

	if (Input::GetKeyDown('k') == DOWN)
	{
		animationIndex = 4;
	}

	if (   Input::GetKeyDown('w') == UP && Input::GetKeyDown('a') == UP 
		&& Input::GetKeyDown('s') == UP && Input::GetKeyDown('d') == UP
		&& Input::GetKeyDown('h') == UP && Input::GetKeyDown('j') == UP 
		&& Input::GetKeyDown('k') == UP)
	{
		animationIndex = 0;
	}
}

void Player::update(float deltaTime, GLuint program)
{
	GameObject::update(deltaTime, true, animationIndex);
	
	frameIndex = deltaTime;
	ProcessInput();
}

void Player::initialise()
{
	objectDiameter *= 4;
	transform.setRotationAngleZ(270);
	updateSprite();
	GameObject::initialise(93.75, 89, 750, 356, frameIndex, texture.getStringPath());

}

void Player::updateSprite()
{
	texture.setStringPath("Dependencies/DwarfSpriteSheet3.png");
}


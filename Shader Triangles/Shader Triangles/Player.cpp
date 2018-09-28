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
	}

	if (Input::GetKeyDown('a') == DOWN)
	{
		transform.objPosition.x -= 1.0f;
		transform.setRotationAngleZ(270);
		transform.setRotationAngleY(0);
	}
}

void Player::update(float deltaTime, GLuint program)
{
	GameObject::update(deltaTime);
	frameIndex = deltaTime;
	ProcessInput();
}

void Player::initialise()
{
	objectDiameter *= 10;
	transform.setRotationAngleZ(270);
	updateSprite();
	GameObject::initialise(93.75, 89, 750, 356, frameIndex, texture.getStringPath());

}

void Player::updateSprite()
{
	texture.setStringPath("Dependencies/DwarfSpriteSheet3.png");
}


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
	}

	if (Input::GetKeyDown('a') == DOWN)
	{
		transform.objPosition.x -= 1.0f;
	}
}

void Player::update(float deltaTime, GLuint program)
{
	GameObject::update(deltaTime);
	int frameIndex = 1;
	texture.setSpriteComponents(90, 88, 988, 610);
	texture.spriteTexCoords(frameIndex, program);
	ProcessInput();
}

void Player::initialise()
{
	updateSprite();
	GameObject::initialise();	

}

void Player::updateSprite()
{
	texture.setStringPath("Dependencies/DwarfSpriteSheet.png");
}


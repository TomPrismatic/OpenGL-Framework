#include "Player.h"
#include "Input.h"


void Player::ProcessInput(glm::vec3 objPosition)
{
	if (Input::GetKeyDown('w') == DOWN)
	{
		objPosition.y += 1.0f;
	}

	if (Input::GetKeyDown('s') == DOWN)
	{
		objPosition.y -= 1.0f;
	}

	if (Input::GetKeyDown('d') == DOWN)
	{
		objPosition.x += 1.0f;
	}

	if (Input::GetKeyDown('a') == DOWN)
	{
		objPosition.x -= 1.0f;
	}
}


Player::Player()
{
}


Player::~Player()
{
}

#include "Input.h"



void Input::KeyboardDown(unsigned char key, int x, int y)
{
	KeyState[key] = DOWN;
}

void Input::KeyboardUp(unsigned char key, int x, int y)
{
	KeyState[key] = UP;
}

void Input::KeyboardFirstDown(unsigned char key, int x, int y)
{
	KeyState[key] = DOWN_FIRST;
}

void Input::KeyboardFirstUp(unsigned char key, int x, int y)
{
	KeyState[key] = UP_FIRST;
}

void Input::ProcessInput(glm::vec3 objPosition)
{
	if (KeyState['w'] == DOWN)
	{
		objPosition.y += 1.0f;
	}

	if (KeyState['s'] == DOWN)
	{
		objPosition.y -= 1.0f;
	}

	if (KeyState['d'] == DOWN)
	{
		objPosition.y += 1.0f;
	}

	if (KeyState['a'] == DOWN)
	{
		objPosition.y -= 1.0f;
	}
}


Input::Input()
{
}


Input::~Input()
{
}

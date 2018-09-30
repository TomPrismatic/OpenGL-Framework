#include "Input.h"

Input * Input::instance = NULL;

Input * Input::GetInstance()
{
	if (instance == NULL)
	{
		instance = new Input();
	}
	return instance;
}

void Input::KeyboardDown(unsigned char key, int x, int y)
{
	GetInstance()->KeyState[key] = DOWN;
}

void Input::KeyboardUp(unsigned char key, int x, int y)
{
	GetInstance()->KeyState[key] = UP;
}

void Input::KeyboardFirstDown(unsigned char key, int x, int y)
{
	KeyState[key] = DOWN_FIRST;
}

void Input::KeyboardFirstUp(unsigned char key, int x, int y)
{
	KeyState[key] = UP_FIRST;
}

unsigned char Input::GetKeyDown(unsigned char key)
{
	return GetInstance()->KeyState[key];
}

int Input::GetMouseState(int button)
{
	return GetInstance()->mouseState[button];
}

void Input::mouseClick(int button, int state, int x, int y)
{
	if (button >= 3)
	{
		return;
	}

	GetInstance()->mouseState[button] = (state == GLUT_DOWN) ? DOWN : UP;	
}

void Input::mousePassiveMove(int x, int y)
{
	GetInstance()->screenToWorldCalculation(x, y);
}

void Input::mouseMove(int x, int y)
{
	GetInstance()->screenToWorldCalculation(x, y);
}

glm::vec2 Input::getPositionVector()
{
	return GetInstance()->mousePosition;
}

void Input::screenToWorldCalculation(int x, int y)
{
	float halfScreenWidth = 400.0f;
	float halfScreenHeight = 400.0f;

	GetInstance()->mousePosition.x = x - halfScreenWidth;
	GetInstance()->mousePosition.y = -y + halfScreenHeight;
}

Input::Input()
{
}


Input::~Input()
{
}

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

Input::Input()
{
}


Input::~Input()
{
}

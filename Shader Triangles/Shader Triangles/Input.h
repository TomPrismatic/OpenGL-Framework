#pragma once
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

class Input
{
	enum InputState
	{
		UP,
		DOWN,
		UP_FIRST,
		DOWN_FIRST,
	};

	InputState KeyState[255];

public:
	void KeyboardDown(unsigned char key, int x, int y);

	void KeyboardUp(unsigned char key, int x, int y);

	void KeyboardFirstDown(unsigned char key, int x, int y);

	void KeyboardFirstUp(unsigned char key, int x, int y);

	void ProcessInput(glm::vec3 objPosition);


	Input();
	~Input();
};


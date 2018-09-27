#pragma once
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

enum InputState
{
	UP,
	DOWN,
	UP_FIRST,
	DOWN_FIRST,
};

class Input
{
	
public:

	static Input * GetInstance();

	static void KeyboardDown(unsigned char key, int x, int y);

	static void KeyboardUp(unsigned char key, int x, int y);

	void KeyboardFirstDown(unsigned char key, int x, int y);

	void KeyboardFirstUp(unsigned char key, int x, int y);

	static unsigned char GetKeyDown(unsigned char key);

	

private:

	static Input * instance; 
	InputState KeyState[255];

	Input();
	~Input();

};


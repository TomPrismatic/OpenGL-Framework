#pragma once
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
#include "Dependencies\soil\SOIL.h"
#include "Dependencies\glew\glew.h" 
#include "Dependencies\freeglut\freeglut.h" 

enum InputState
{
	UP,
	DOWN,
	UP_FIRST,
	DOWN_FIRST,
};

enum mouseState
{
	MOUSE_LEFT,
	MOUSE_MIDDLE,
	MOUSE_RIGHT,
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

	static int GetMouseState(int button);

	static void mouseClick(int button, int state, int x, int y);

	static void mousePassiveMove(int x, int y);

	static void mouseMove(int x, int y);

	static glm::vec2 getPositionVector();

	void screenToWorldCalculation(int x, int y);
	

private:

	static Input * instance; 
	InputState KeyState[255];
	InputState mouseState[3];

	int xMousePostion;
	int yMousePostion;

	glm::vec2 mousePosition;

	Input();
	~Input();

};


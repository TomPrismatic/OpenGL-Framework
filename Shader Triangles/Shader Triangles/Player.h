#pragma once
#include "Dependencies\soil\SOIL.h"
#include "Dependencies\glew\glew.h" 
#include "Dependencies\freeglut\freeglut.h" 
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
#include "Mesh2D.h"
#include "Texture.h"
#include "Transform.h"
#include "Camera.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
#include "GameObject.h"
#include "Collision.h"
#include "RadiusCollision.h"
#include <iostream>
#include <vector>

class Player:public GameObject
{
	Texture texture;
	Sound sound;

public:
	Player();
	virtual ~Player();

	void ProcessInput(std::vector <GameObject*> vectorOfGameObjects);

	virtual void render(GLuint render);

	virtual void update(float deltaTime, GLuint program, std::vector <GameObject*> vectorOfGameObjects);

	virtual void initialise();

	void updateSprite();

	void updateSounds();

private:
	int frameIndex = 1;
	bool isAttacking = false;
};


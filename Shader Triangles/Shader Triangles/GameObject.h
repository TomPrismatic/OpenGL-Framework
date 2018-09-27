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

class GameObject
{
	Mesh2D* mesh2D = nullptr;
	Texture* texture = nullptr;

public:
	GameObject();
	~GameObject();

	virtual void initialise();
	virtual void render(GLuint program);
	virtual void update(float deltaTime);


};


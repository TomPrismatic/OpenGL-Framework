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
#include <iostream>

class MenuImage :public GameObject
{
	Texture texture;

public:
	MenuImage();
	virtual ~MenuImage();

	virtual void initialise();

	virtual void update(float deltaTime);

	void updateSprite();

};




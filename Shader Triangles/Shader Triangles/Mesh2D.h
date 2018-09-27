#pragma once
#include "Dependencies\soil\SOIL.h"
#include "Dependencies\glew\glew.h" 
#include "Dependencies\freeglut\freeglut.h" 

class Mesh2D
{
public:

	void initialise();
	const GLuint getVAO();
	
	Mesh2D();
	~Mesh2D();

private:
	GLuint VAO;

};


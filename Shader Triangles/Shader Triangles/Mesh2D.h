#pragma once
#include "Dependencies\soil\SOIL.h"
#include "Dependencies\glew\glew.h" 
#include "Dependencies\freeglut\freeglut.h" 

class Mesh2D
{
public:

	void initialise(int spriteWidth, int spriteHeight, int texWidth, int texHeight, int frameIndex);

	void update(int frameIndex);

	const GLuint getVAO();

	// spriteTexCoords(int frameIndex, GLuint program);
	
	Mesh2D();
	~Mesh2D();

private:
	GLuint VAO;

	int spriteWidthMesh, spriteHeightMesh;
	int texWidthMesh, texHeightMesh;
	GLfloat textureWidth, textureHeight;
	GLfloat textureX, textureY;
	
};


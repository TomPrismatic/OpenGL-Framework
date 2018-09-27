#pragma once
#include "Dependencies\glew\glew.h" 
#include "Dependencies\freeglut\freeglut.h" 
#include <string>
class Texture
{
public:
	Texture();
	~Texture();

	void initialise();
	void setStringPath(std::string string);
	GLuint GetTexture();
	void setSpriteComponents(int spriteWidth, int spriteHeight, int	texWidth, int texHeight);
	void spriteTexCoords(int frameIndex, GLuint program);

private:
	std::string fileName = "";
	GLuint texture = NULL;

	int spriteWidth, spriteHeight;
	int texWidth, texHeight;
	int tex;
};


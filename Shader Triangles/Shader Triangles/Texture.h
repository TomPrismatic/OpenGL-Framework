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

private:
	std::string fileName = "Dependencies/Rayman.jpg";
	GLuint texture = NULL;
};


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
	std::string getStringPath();
	GLuint GetTexture();

private:
	std::string fileName;
	GLuint texture = NULL;
};


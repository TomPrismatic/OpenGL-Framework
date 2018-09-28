#include "Texture.h"
#include "Dependencies\soil\SOIL.h"
#include "Dependencies\glew\glew.h" 
#include "Dependencies\freeglut\freeglut.h" 
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"


Texture::Texture()
{
}

Texture::~Texture()
{
}

void Texture::initialise()
{
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	int imageWidth, imageHeight, channels;
	unsigned char* image = SOIL_load_image(fileName.c_str(), &imageWidth, &imageHeight, &channels, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageWidth, imageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::setStringPath(std::string string)
{
	fileName = string;
}

std::string Texture::getStringPath()
{
	return fileName;
}

GLuint Texture::GetTexture()
{
	return texture;
}

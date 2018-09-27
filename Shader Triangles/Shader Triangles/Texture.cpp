#include "Texture.h"
#include "Dependencies\soil\SOIL.h"
#include "Dependencies\glew\glew.h" 
#include "Dependencies\freeglut\freeglut.h" 

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

GLuint Texture::GetTexture()
{
	return texture;
}

void Texture::setSpriteComponents(int spriteWidth, int spriteHeight, int texWidth, int texHeight)
{
	this->spriteWidth = spriteWidth;
	this->spriteHeight = spriteHeight;
	this->texWidth = texWidth;
	this->texHeight = texHeight;
}

void Texture::spriteTexCoords(int frameIndex, GLuint program)
{
	float textureWidth = float(spriteWidth) / texWidth;
	glUniform1f(glGetUniformLocation(program, "textureWidth"), textureWidth);
	float textureHeight = float(spriteHeight) / texHeight;
	glUniform1f(glGetUniformLocation(program, "textureHeight"), textureHeight);
	int numPerRow = texWidth / spriteWidth;
	float textureX = (frameIndex % numPerRow) * textureWidth;
	glUniform1f(glGetUniformLocation(program, "textureX"), textureX);
	float textureY = (frameIndex / numPerRow + 1) * textureHeight;
	glUniform1f(glGetUniformLocation(program, "textureY"), textureY);

	// Tex Coords
	//  textureX, textureY,
	//	textureX + textureWidth, textureY,
	//	textureX + textureWidth, textureY + textureHeight,
	//	textureX, textureY + textureHeight


	/*GLfloat verticies[] =
	{
		// Positions                                      // Colors         
		posX,               posY,                0.0f,  1.0f, 1.0f, 1.0f,   
		posX + spriteWidth, posY,                0.0f,	1.0f, 1.0f, 1.0f,   
		posX + spriteWidth, posY + spriteHeight, 0.0f,	1.0f, 1.0f, 1.0f,   
		posX,               posY + spriteHeight, 0.0f,	1.0f, 1.0f, 1.0f,   
	};*/
}

#pragma once
#include "Dependencies\soil\SOIL.h"
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include "Dependencies\glm\glm.hpp"
#include "Dependencies\glm\gtc\matrix_transform.hpp"
#include "Dependencies\glm\gtc\type_ptr.hpp"
#include "Dependencies\ft2build.h"
#include FT_FREETYPE_H
#include <map>
#include <string>
#include <iostream>
#include "ShaderLoader.h"
#include "GameObject.h"

// class BoxCollider;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

struct FontChar
{
	GLuint TextureID;
	glm::ivec2 GlyphSize;
	glm::ivec2 Bearing;		// Offset of the glyph (top left) from the baseline
	GLuint Advance;			// How far to move to the next character
};


class TextLabel
{
public:
	TextLabel(
		std::string text,
		std::string font,
		glm::vec2 screenPosition,
		glm::vec3 color			= glm::vec3(1.0f, 1.0f, 1.0f),
		float scale				= 1.0f);

	~TextLabel() {};

	void initialise();

	void render();
	void SetText(std::string newText) { text = newText; }
	void SetColor(glm::vec3 newColor) { color = newColor; }
	void SetScale(GLfloat newScale) { scale = newScale; }
	void SetPosition(glm::vec2 newPosition) { screenPosition = newPosition; }

	glm::vec2 getScreenPosition() const;

	void calculateDimensions();

	//BoxCollider * GetCollider() const;

	GLfloat getTextWidth() const;
	GLfloat getTextHeight() const;

private:

	GLuint generateTexture(FT_Face face);

	GLfloat textWidth;
	GLfloat textHeight;

	std::string text;
	GLfloat scale;
	glm::vec2 screenPosition;
	glm::vec3 color;
	std::string font;

	GLuint VAO, VBO, program;
	glm::mat4 projectionMatrix;
	std::map<GLchar, FontChar> characters;

	// COLLISION
	// BoxCollider * collider = NULL;
	
};


#include "TextLabel.h"
#include "RadiusCollision.h"





TextLabel::TextLabel(std::string text, std::string font, glm::vec2 screenPosition, glm::vec3 color, float scale)
{
	this->text = text;
	this->color = color;
	this->scale = scale;
	this->screenPosition = screenPosition;
	this->font = font;

	textWidth = 0.0;
	textHeight = 0.0;

	collider = new RadiusCollision(this);
}

void TextLabel::initialise()
{
	FT_Library fontObject;
	FT_Face face;

	GLfloat halfWidth = (GLfloat)SCREEN_WIDTH * 0.5;
	GLfloat halfHeight = (GLfloat)SCREEN_HEIGHT * 0.5;
	projectionMatrix = glm::ortho(-halfWidth, halfWidth, -halfHeight, halfHeight);
	program = ShaderLoader::getInstance()->CreateProgram("Text.vs", "Text.fs");

	
	// Initialise the font library
	if (FT_Init_FreeType(&fontObject) != NULL)
	{
		std::cout << "ERROR::FREETYPE: Could not initialise Freetype Library" << std::endl;
	}

	// Load font as face
	if (FT_New_Face(fontObject, font.c_str(), 0, &face) != NULL)
	{
		std::cout << "ERROR::FREETYPE: Could not initialise Freetype Library" << std::endl;
	}

	FT_Set_Pixel_Sizes(face, 0, 48);		// Set the size of the glyph
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);	// Disable byte-alignment restriction

	// Load the first 128 characters of the ASCI set
	for (GLubyte asciiKey = 0; asciiKey < 128; ++asciiKey)
	{
		// Load the character glyph into face
		if (FT_Load_Char(face, asciiKey, FT_LOAD_RENDER))
		{
			std::cout << "ERROR:FREETYPE: Failed to load Glyph" << std::endl;
			continue;
		}

		GLuint texture = generateTexture(face); // Generate a texture for each char (glpyh)

		// Store the character for later use
		FontChar character = 
		{
			texture, 
			glm::ivec2(face->glyph->bitmap.width, //Width
			face->glyph->bitmap.rows),  //Rows
			glm::ivec2(face->glyph->bitmap_left, //Left position
			face->glyph->bitmap_top), //Top Position
			(GLuint)face->glyph->advance.x //X value
		};

		characters.insert(std::pair<GLchar, FontChar>(asciiKey, character));
	}

	// Destroy FreeType objects once we are finished
	FT_Done_Face(face);
	FT_Done_FreeType(fontObject);

	// Configure VAO & VBO for texture quads
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// Collider calculations
	calculateDimensions();
	
	
}

void TextLabel::render()
{

	// Get textColor and projection matrix into the shader
	glUseProgram(program);
	glUniform3f(glGetUniformLocation(program, "textColor"), color.x, color.y, color.z);
	glUniformMatrix4fv(glGetUniformLocation(program, "projection"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));
	glBindVertexArray(VAO);

	// Iterate through the Characters
	glm::vec2 textPosition = screenPosition;

	for (std::string::const_iterator asciiKey = text.begin(); asciiKey != text.end(); ++asciiKey)
	{
		FontChar character = characters[*asciiKey];
		GLfloat xPosition = textPosition.x + character.Bearing.x * scale;
		GLfloat yPosition = textPosition.y - (character.GlyphSize.y - character.Bearing.y) * scale;
		GLfloat width = character.GlyphSize.x * scale;
		GLfloat height = character.GlyphSize.y * scale;

		
		// Update VBO for each character
		GLfloat vertices[6][4] = {
			{xPosition, yPosition + height,			0.0, 0.0},
			{xPosition, yPosition,		 			0.0, 1.0},
			{xPosition + width, yPosition,			1.0, 1.0},
			{xPosition, yPosition + height,			0.0, 0.0},
			{xPosition + width, yPosition,			1.0, 1.0},
			{xPosition + width, yPosition + height, 1.0, 0.0}
		};

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

		// Render the glyph over the quad
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, character.TextureID);
		glUniform1i(glGetUniformLocation(program, "tex"), 0);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		textPosition.x += (character.Advance >> 6) * scale;
	}

	glUseProgram(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);;
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);

}

glm::vec2 TextLabel::getScreenPosition() const
{
	return screenPosition;
}

void TextLabel::calculateDimensions()
{
	for (std::string::const_iterator c = text.begin(); c != text.end(); ++c)
	{
		FontChar character = characters[*c];
		GLfloat width = character.GlyphSize.x * scale;
		GLfloat height = character.GlyphSize.y * scale;

		textWidth += width;
		textHeight = height;
	}

	transform.objPosition.x = screenPosition.x + textWidth / 2;
	transform.objPosition.y = screenPosition.y;
	collider->initialise();
	collider->setRadius(textWidth);
}

RadiusCollision * TextLabel::GetCollider() const
{
	return collider;
}

GLfloat TextLabel::getTextWidth() const
{
	return textWidth;
}

GLfloat TextLabel::getTextHeight() const
{
	return textHeight;
}

GLuint TextLabel::generateTexture(FT_Face face)
{
	GLuint texture;

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		GL_RED,
		face->glyph->bitmap.width,
		face->glyph->bitmap.rows,
		0,
		GL_RED,
		GL_UNSIGNED_BYTE,
		face->glyph->bitmap.buffer
	);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return texture;
}


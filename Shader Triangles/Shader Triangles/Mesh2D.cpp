#include "Mesh2D.h"



void Mesh2D::initialise(int spriteWidth, int spriteHeight, int texWidth, int texHeight, int frameIndex)
{
	spriteWidthMesh = spriteWidth;
	spriteHeightMesh = spriteHeight;
	texWidthMesh = texWidth;
	texHeightMesh = texHeight;

	textureWidth = float(spriteWidthMesh) / texWidthMesh;
	textureHeight = float(spriteHeightMesh) / texHeightMesh;
	int numPerRow = texWidthMesh / spriteWidthMesh;
	textureX = (frameIndex % numPerRow) * textureWidth;
	textureY = (frameIndex / numPerRow + 1) * textureHeight;

	GLuint VBO;
	GLuint EBO;
	GLfloat vertices[] = {
		// Positions               // Colors             // Tex Coords
		-0.5f,  0.5f, 0.0f,      1.0f, 1.0f, 1.0f,      textureX,                textureY,                 // Top Left
		-0.5f, -0.5f, 0.0f,      1.0f, 1.0f, 1.0f,      textureX + textureWidth, textureY,                 // Bottom Left
		 0.5f, -0.5f, 0.0f,      1.0f, 1.0f, 1.0f,      textureX + textureWidth, textureY + textureHeight, // Bottom Right
		 0.5f,  0.5f, 0.0f,      1.0f, 1.0f, 1.0f,	    textureX, textureY + textureHeight                 // Top Right
	};

	GLuint indices[] =
	{
		0, 1, 2,  //Right Triangle
		0, 2, 3 //Left Triangle

	};

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO); // Bind VAO 

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)( 3 * sizeof(GLfloat)));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

}

void Mesh2D::update(int frameIndex)
{
	int spriteIndex  = frameIndex* 0.15;
	int numPerRow = texWidthMesh / spriteWidthMesh;
	textureX = (spriteIndex % numPerRow) * textureWidth;
	textureY = (spriteIndex / numPerRow + 1) * textureHeight;

	//if (textureX > 300)
	//{
	//	textureX = 0;
	//}

	GLuint VBO;
	GLuint EBO;

	GLfloat vertices[] = {
		// Positions               // Colors             // Tex Coords
		-0.5f,  0.5f, 0.0f,      1.0f, 1.0f, 1.0f,      textureX,                textureY,                 // Top Left
		-0.5f, -0.5f, 0.0f,      1.0f, 1.0f, 1.0f,      textureX + textureWidth, textureY,                 // Bottom Left
		 0.5f, -0.5f, 0.0f,      1.0f, 1.0f, 1.0f,      textureX + textureWidth, textureY + textureHeight, // Bottom Right
		 0.5f,  0.5f, 0.0f,      1.0f, 1.0f, 1.0f,	    textureX, textureY + textureHeight                 // Top Right
	};


	GLuint indices[] =
	{
		0, 1, 2,  //Right Triangle
		0, 2, 3 //Left Triangle

	};

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO); // Bind VAO 

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

}

const GLuint Mesh2D::getVAO()
{
	return VAO;
}


Mesh2D::Mesh2D()
{
}


Mesh2D::~Mesh2D()
{
}

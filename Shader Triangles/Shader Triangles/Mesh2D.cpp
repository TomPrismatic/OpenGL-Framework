#include "Mesh2D.h"



void Mesh2D::initialise()
{
	GLuint VBO;
	GLuint EBO;
	GLfloat vertices[] = {
		// Positions               // Colors           // Tex Coords
		-0.5f,  0.5f, 0.0f,      1.0f, 1.0f, 1.0f,       0.0f, 0.0f, // Top Left
		-0.5f, -0.5f, 0.0f,      1.0f, 1.0f, 1.0f,       0.0f, 1.0f, // Bottom Left
		 0.5f, -0.5f, 0.0f,      1.0f, 1.0f, 1.0f,       1.0f, 1.0f, // Bottom Right
		 0.5f,  0.5f, 0.0f,      1.0f, 1.0f, 1.0f,	     1.0f, 0.0f  // Top Right
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

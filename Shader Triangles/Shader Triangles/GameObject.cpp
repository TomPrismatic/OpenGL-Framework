#include "GameObject.h"



GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::initialise()
{
	GLuint VAO = mesh2D->getVAO();
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);


}

void GameObject::render(GLuint program)
{
}

void GameObject::update(float deltaTime)
{
}

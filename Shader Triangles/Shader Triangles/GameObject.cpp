#include "GameObject.h"



GameObject::GameObject()
{
	mesh2D = new Mesh2D();
	textureObject = new Texture();
	objectDiameter = 50.0f;
}


GameObject::~GameObject()
{
}

void GameObject::initialise(int spriteWidth, int spriteHeight, int texWidth, int texHeight, int frameIndex, std::string stringPath)
{
	mesh2D->initialise(spriteWidth, spriteHeight, texWidth, texHeight, frameIndex);
	textureObject->setStringPath(stringPath);
	textureObject->initialise();

	transform.objScale *= objectDiameter;
	


}

void GameObject::render(GLuint program)
{
	GLuint VAO = mesh2D->getVAO();
	GLuint texture = textureObject->GetTexture();

	glUseProgram(program);
	
	//Texture
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glUniform1i(glGetUniformLocation(program, "tex"), 0);

	GLuint pvmLoc = glGetUniformLocation(program, "pvm");
	glUniformMatrix4fv(pvmLoc, 1, GL_FALSE, glm::value_ptr(getPVMMatrix()));

	glBindVertexArray(VAO); // Bind VAO 
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	
}

void GameObject::update(float deltaTime, bool isSpriteSheet, int animationIndex)
{
	calculateModelMatrix();
	if (isSpriteSheet){
		mesh2D->update(deltaTime, animationIndex);
	}		
}

void GameObject::calculateModelMatrix()
{

	//Object placement using a matrix
	glm::mat4 translationMatrix = glm::translate(glm::mat4(), transform.objPosition);
	//Object Rotation using a Matrix
	glm::mat4 rotationZ = transform.getRotationMatrix();
	//Object scaling using a scaling Matrix
	glm::mat4 scaleMatrix = glm::scale(glm::mat4(), transform.objScale);
	//Combining all three into a model matrix
	modelMatrix = translationMatrix * rotationZ * scaleMatrix;
}

void GameObject::calculatePVMMatrix(glm::mat4 PV)
{
	pvmMatrix = PV * modelMatrix;
}

glm::mat4 GameObject::getModelMatrix()
{
	return modelMatrix;
}

glm::mat4 GameObject::getPVMMatrix()
{
	return pvmMatrix;
}

#include "Dependencies\soil\SOIL.h"
#include "Dependencies\glew\glew.h" 
#include "Dependencies\freeglut\freeglut.h" 
#include "Camera.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"





void Camera::generateView(glm::vec3 camPos, glm::vec3 camLookDir, glm::vec3 camUpDir, GLuint program)
{
	view = glm::lookAt(camPos, camPos + camLookDir, camUpDir);
	GLuint viewLoc = glGetUniformLocation(program, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
}

void Camera::generateProjPerspective(const unsigned int SCR_WIDTH, const unsigned int SCR_HEIGHT, GLuint program)
{
	//Perspective
	glm::mat4 proj;
	proj = glm::perspective(45.0f, (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
	GLuint projLoc = glGetUniformLocation(program, "proj");
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));
}

void Camera::generateProjOrthographicTop(const unsigned int SCR_WIDTH, const unsigned int SCR_HEIGHT, GLuint program)
{
	//Orthographic (With origin at 0,0 at the top left)
	glm::mat4 proj;
	proj = glm::ortho(0.0f, (float)SCR_WIDTH, 0.0f, (float)SCR_HEIGHT, 0.1f, 100.0f);
	GLuint projLoc = glGetUniformLocation(program, "proj");
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));
}

void Camera::generateProjOrthographicCentre(const unsigned int SCR_WIDTH, const unsigned int SCR_HEIGHT, GLuint program)
{
	//Orthographic (With origin at 0,0 at the centre)
	glm::mat4 proj;
	float halfScreenWidth = (float)SCR_WIDTH * 0.5f;
	float halfScreenHeight = (float)SCR_HEIGHT * 0.5f;
	proj = glm::ortho(-halfScreenHeight, halfScreenWidth, -halfScreenHeight, halfScreenHeight, 0.1f, 100.0f);
	GLuint projLoc = glGetUniformLocation(program, "proj");
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));
}

Camera::Camera()
{
}


Camera::~Camera()
{
}

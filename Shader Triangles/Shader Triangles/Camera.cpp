#include "Dependencies\soil\SOIL.h"
#include "Dependencies\glew\glew.h" 
#include "Dependencies\freeglut\freeglut.h" 
#include "Camera.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"


void Camera::Initialise()
{
	generateProjOrthographicCentre();

	CalculatePV();

}

void Camera::Update(float deltaTime)
{
	CalculatePV();
}


void Camera::generateProjPerspective()
{
	//Perspective
	proj = glm::perspective(45.0f, (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
}

void Camera::generateProjOrthographicCentre()
{
	//Orthographic (With origin at 0,0 at the centre)
	float halfScreenWidth = (float)SCR_WIDTH * 0.5f;
	float halfScreenHeight = (float)SCR_HEIGHT * 0.5f;

	proj = glm::ortho(-halfScreenHeight, halfScreenWidth, -halfScreenHeight, halfScreenHeight, 0.1f, 100.0f);
}

glm::mat4 Camera::getProjectionMatrix()
{
	return proj;
}

glm::mat4 Camera::getViewMatrix()
{
	return view;
}

glm::mat4 Camera::GetPV()
{
	return PV;
}

void Camera::CalculatePV()
{
	view = glm::lookAt(camPos, camPos + camLookDir, camUpDir);

	PV = proj * view;
}

Camera::Camera()
{
}


Camera::~Camera()
{
}

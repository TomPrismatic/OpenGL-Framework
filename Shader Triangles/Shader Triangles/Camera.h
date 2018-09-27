#pragma once
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

class Camera
{
public:

	void Initialise();
	void Update(float deltaTime);

	void generateProjPerspective();

	void generateProjOrthographicCentre();

	glm::mat4 getProjectionMatrix();

	glm::mat4 getViewMatrix();

	glm::mat4 GetPV();
	void CalculatePV();

	Camera();
	~Camera();

	

private:
	glm::vec3 camPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 camLookDir = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 camUpDir = glm::vec3(0.0f, 1.0f, 0.0f);

	const unsigned int SCR_WIDTH = 800;
	const unsigned int SCR_HEIGHT = 800;

	glm::mat4 view;
	glm::mat4 proj;

	glm::mat4 PV;
};


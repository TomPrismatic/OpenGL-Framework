#pragma once
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

class Camera
{
public:

	void generateView(glm::vec3 camPos, glm::vec3 camLookDir, glm::vec3 camUpDir, GLuint program);
	void generateProjPerspective(const unsigned int SCR_WIDTH, const unsigned int SCR_HEIGHT, GLuint program);
	void generateProjOrthographicTop(const unsigned int SCR_WIDTH, const unsigned int SCR_HEIGHT, GLuint program);
	void generateProjOrthographicCentre(const unsigned int SCR_WIDTH, const unsigned int SCR_HEIGHT, GLuint program);

	Camera();
	~Camera();

	glm::mat4 view;
	glm::mat4 proj;
};


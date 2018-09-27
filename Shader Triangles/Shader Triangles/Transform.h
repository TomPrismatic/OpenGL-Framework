#pragma once
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

struct Transform
{
	public:
		glm::vec3 objPosition = glm::vec3(0.5f, 0.5f, 0.0f);
		glm::vec3 objScale = glm::vec3(1.0f, 1.0f, 1.0f);
		glm::vec3 rotationAxisZ = glm::vec3(0.0f, 0.0f, 1.0f);


	private:
		
};


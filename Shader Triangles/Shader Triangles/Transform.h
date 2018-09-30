#pragma once
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
#include <math.h>

struct Transform
{
	public:
		glm::vec3 objPosition = glm::vec3(0.5f, 0.5f, 0.0f);
		glm::vec3 objScale = glm::vec3(1.0f, 1.0f, 1.0f);
		
		glm::mat4 getRotationMatrix()
		{
			return (glm::rotate(glm::mat4(), glm::radians(getRotationAngleZ()), rotationAxisZ) * glm::rotate(glm::mat4(), glm::radians(getRotationAngleY()), rotationAxisY));
		}

		void setRotationAngleZ(float angleZ)
		{
			rotationAngleZ = angleZ;
		}

		float getRotationAngleZ()
		{
			return rotationAngleZ;
		}

		void setRotationAngleY(float angleY)
		{
			rotationAngleY = angleY;
		}

		float getRotationAngleY()
		{
			return rotationAngleY;
		}

		static float getDistanceBetweenObjects(glm::vec3 objPosition1, glm::vec3 objPosition2)
		{
			//Pythagoras too find the distance between the two objects
			float distance = sqrt(pow((objPosition1.x - objPosition2.x), 2) + pow((objPosition1.y - objPosition2.y), 2));
			return distance;
		}

	private:
		glm::vec3 rotationAxisZ = glm::vec3(0.0f, 0.0f, 1.0f);
		glm::vec3 rotationAxisY = glm::vec3(0.0f, 1.0f, 0.0f);
		float rotationAngleZ;
		float rotationAngleY;
};


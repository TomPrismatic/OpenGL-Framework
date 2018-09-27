#pragma once
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
#include "Input.h"
#include "Transform.h"
class Player
{
public:

	void ProcessInput(glm::vec3 objPosition);

	Transform transform;

	Player();
	~Player();
};


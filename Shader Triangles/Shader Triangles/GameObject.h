#pragma once
#include "Mesh2D.h"
#include "Texture.h"
#include "Transform.h"
class GameObject
{
	Mesh2D mesh2D;
	Texture texture;
public:
	GameObject();
	~GameObject();
};


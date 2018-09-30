#include "Background.h"



Background::Background()
{
}


Background::~Background()
{
}


void Background::initialise()
{
	objectDiameter *= 17;
	//transform.setRotationAngleZ(180);
	updateSprite();
	GameObject::initialise(576, 336, 576, 336, 1, texture.getStringPath());
}

void Background::update(float deltaTime)
{
	GameObject::update(deltaTime, false, 0, false);
	int frameIndex = 1;
}

void Background::updateSprite()
{
	texture.setStringPath("Dependencies/Dungeon.png");
}

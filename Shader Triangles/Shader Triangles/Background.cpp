#include "Background.h"



Background::Background()
{
}


Background::~Background()
{
}


void Background::initialise()
{
	objectDiameter *= 10;
	transform.setRotationAngleZ(0);
	updateSprite();
	GameObject::initialise(480, 854, 480, 854, 1, texture.getStringPath());
}

void Background::update(float deltaTime)
{
	GameObject::update(deltaTime);
	int frameIndex = 1;
}

void Background::updateSprite()
{
	texture.setStringPath("Dependencies/BackgroundSprite.jpg");
}

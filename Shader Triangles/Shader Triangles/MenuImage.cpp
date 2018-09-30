#include "MenuImage.h"



MenuImage::MenuImage()
{
}


MenuImage::~MenuImage()
{
}


void MenuImage::initialise()
{
	objectDiameter *= 17;
	transform.setRotationAngleZ(90);
	transform.setRotationAngleY(180);
	//transform.setRotationAngleZ(180);
	updateSprite();
	GameObject::initialise(800, 800, 800, 800, 1, texture.getStringPath());
}

void MenuImage::update(float deltaTime)
{
	GameObject::update(deltaTime, false, 0, false, frameIndex);
}

void MenuImage::updateSprite()
{
	texture.setStringPath("Dependencies/IntroScreen.png");
}

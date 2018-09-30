#include "GameMenu.h"
#include "TextLabel.h"
#include "Input.h"
#include "GameManager.h"
#include "RadiusCollision.h"
#include "Dependencies\glm\glm.hpp"
#include "Dependencies\glm\gtc\matrix_transform.hpp"
#include "Dependencies\glm\gtc\type_ptr.hpp"

GameMenu::GameMenu() {};

GameMenu::GameMenu(std::string startString, std::string exitString)
{
	std::string font = "Dependencies/Fonts/SnackerComic.ttf";

	firstClicked = false;
	secondClicked = false;

	startButton = new TextLabel(startString, font, glm::vec2(-40.0f, 100.0f));
	quitButton = new TextLabel(exitString, font, glm::vec2(-20.0f, -100.0f));
}

GameMenu::~GameMenu()
{
	delete startButton;
	startButton = NULL;

	delete quitButton;
	quitButton = NULL;
}

void GameMenu::initialise()
{
	startButton->initialise();
	quitButton->initialise();
}

void GameMenu::render(GLuint program)
{
	if (isVisible)
	{
		startButton->render();
		quitButton->render();
	}	
}

void GameMenu::update(float deltaTime)
{
	// Get the location of the mouse
	glm::vec2 mousePosition = Input::getPositionVector();
	glm::vec3 mouseTransformedPosition = glm::vec3(mousePosition.x, mousePosition.y, 0.0f);

	if (Input::GetKeyDown('s') == DOWN)
	{
		firstClicked = true;
	}
	if (Input::GetKeyDown('q') == DOWN)
	{
		secondClicked = true;
	}
	/*// If the location of the mouse collide with Start --> change to Game Mode
	if (startButton->GetCollider()->isColliding(mouseTransformedPosition, startButton->GetCollider()))
	{
		// If Mouse clicked
		if (Input::GetMouseState(MOUSE_LEFT) == DOWN)
		{
			// Change Menu state
			firstClicked = true;
		}
	

	// If the location of the mouse collide with Quit --> Quit Game
	if (quitButton->GetCollider()->isColliding(mouseTransformedPosition))
	{
		// If mouse clicked
		if (Input::GetMouseState(MOUSE_LEFT) == DOWN)
		{
			// Quit game
			secondClicked = true;
		}
	}*/
}

bool GameMenu::getFirstClicked() const
{
	return firstClicked;
}

bool GameMenu::getSecondClicked() const
{
	return secondClicked;
}

void GameMenu::reset()
{
	firstClicked = false;
	secondClicked = false;
}
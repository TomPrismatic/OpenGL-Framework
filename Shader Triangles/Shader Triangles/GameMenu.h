#pragma once

#include "GameObject.h"

class TextLabel;


class GameMenu : public GameObject // TODO - Get rid of memory leak
{
public:
	GameMenu();
	GameMenu(std::string startString, std::string exitString);
	~GameMenu();

	void initialise();
	void render(GLuint program);
	void update(float deltaTime);

	bool getFirstClicked() const;
	bool getSecondClicked() const;
	void reset();


private:

	bool firstClicked;
	bool secondClicked;

	TextLabel * startButton = NULL;
	TextLabel * quitButton = NULL;
};


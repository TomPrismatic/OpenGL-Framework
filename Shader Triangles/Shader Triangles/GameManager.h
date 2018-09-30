#pragma once
#include "Dependencies\soil\SOIL.h"
#include "Dependencies\glew\glew.h" 
#include "Dependencies\freeglut\freeglut.h" 
#include "ShaderLoader.h"
#include "Camera.h"
#include "Input.h"
#include "Player.h"
#include "BatKnight.h"
#include "Zombie.h"
#include "Rat.h"
#include "GameObject.h"
#include "GameMenu.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
#include "Clock.h"
#include "TextLabel.h"
#include <vector>
#include "Background.h"
#include "IntroScene.h"
#include "RatScene.h"
#include "BatScene.h"
#include "ZombieScene.h"
#include "FinalScene.h"
#include "MenuImage.h"
#include <iostream>

enum gameState {
	menuScreen,
	introSequence,
	zombieRoom,
	zombieCutscene,
	ratRoom,
	ratCutscene,
	batRoom,
	batCutscene,
	multiRoom,
	finalCutScene,
	pauseScreen,
	gameOverScreen,
};

class GameManager
{


public:

	static GameManager * GetInstance();

	void updatePVM(GameObject * gameObject);
	
	static void render();

	void init();

	static void Update();

	static void playGame(int argc, char **argv);



private:
	//Vector of Game Objects
	std::vector <GameObject*> vectorOfGameObjects;
	//Game Menu
	GameMenu * gameMenu;
	//Global Variables
	GLuint program;
	//Camera
	Camera * camera;
	//Player
	Player * player;
	//Bat Enemy
	BatKnight * batKnight;
	//Zombie Enemy
	Zombie * zombie;
	//Rat Enemy
	Rat * rat;
	//Text Label
	TextLabel * text;
	//Background
	Background * background;
	//Menu Image
	MenuImage * menuImage;
	//GameObject
	GameObject * gameObject;

	float deltaTime = 0.0f;

	gameState currentGameState;
	static GameManager * instance;
	GameManager();
	~GameManager();
	int lifeReset = 1;

	//Scenes
	//Intro Scene
	IntroScene * introScene;
	//Bat Scene
	BatScene * batScene;
	//Rat Scene
	RatScene * ratScene;
	//Zombie Scene
	ZombieScene * zombieScene;
	//final Scene
	FinalScene * finalScene;



};


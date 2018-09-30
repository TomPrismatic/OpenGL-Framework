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
#include "IntroScene.h"
#include "GameObject.h"
#include "GameMenu.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
#include "Clock.h"
#include "TextLabel.h"
#include <vector>
#include "Background.h"
#include <iostream>

//Clock

//Vector of Game Objects
std::vector <GameObject*> vectorOfGameObjects;
//Game Menu
GameMenu * gameMenu = new GameMenu("Start Quest", "Bitch it");

//Global Variables
GLuint program;

//Camera
Camera * camera = new Camera();

//IntroScene
IntroScene * introScene = new IntroScene();

//Player
Player * player = new Player();

//Bat Enemy
BatKnight * batKnight = new BatKnight();

//Zombie Enemy
Zombie * zombie = new Zombie();

//Rat Enemy
Rat * rat = new Rat();

//Text Label
TextLabel * text = new TextLabel("Enimies Remaining:", "Dependencies/Fonts/SnackerComic.ttf", glm::vec2(-390.0f, 350.0f));

//Background
Background * background = new Background();

//GameObject
GameObject * gameObject = new GameObject();

float deltaTime = 0.0f;


void updatePVM(GameObject * gameObject)
{
	player->calculatePVMMatrix(camera->GetPV()); 
	batKnight->calculatePVMMatrix(camera->GetPV());
	zombie->calculatePVMMatrix(camera->GetPV());
	rat->calculatePVMMatrix(camera->GetPV());
	introScene->calculatePVMMatrix(camera->GetPV());
	background->calculatePVMMatrix(camera->GetPV());
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 0.0, 0.0, 1.0); //clear red

	
	background->render(program);
	player->render(program);
	batKnight->render(program);
	zombie->render(program);
	rat->render(program);
	introScene->render(program);
	text->render();
	gameMenu->render(program);

	glUseProgram(0); //Unbind Program
	
	glutSwapBuffers();
}

void init() 
{
	//ShaderLoader shaderLoader; 
	program = ShaderLoader::getInstance()->CreateProgram("VertexShader.vs", "FragmentShader.fs");

	Clock::GetInstance()->Initialise();
	gameMenu->initialise();
	player->initialise();
	batKnight->initialise();
	vectorOfGameObjects.push_back(batKnight);
	zombie->initialise();
	vectorOfGameObjects.push_back(zombie);
	rat->initialise();
	vectorOfGameObjects.push_back(rat);
	introScene->initialise();
	text->initialise();

	background->initialise();
	camera->Initialise();
}

void Update()
{
	Clock::GetInstance()->Update();
	deltaTime = Clock::GetInstance()->GetDeltaTick();
	camera->Update(deltaTime);

	player->update(deltaTime, program, vectorOfGameObjects);
	batKnight->update(deltaTime, program);
	zombie->update(deltaTime, program);
	rat->update(deltaTime, program);
	introScene->update(deltaTime, program);

	background->update(deltaTime);
	updatePVM(player);
	glutPostRedisplay();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(500, 500); glutInitWindowSize(800, 600);
	glutCreateWindow("Tom's OpenGL Assignment 2");
	glClearColor(1.0, 0.0, 0.0, 1.0);//clear red
									 // register callbacks

	glewInit();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	init();

	glutDisplayFunc(render);
	glutIdleFunc(Update);

	glutKeyboardFunc(Input::KeyboardDown);
	glutKeyboardUpFunc(Input::KeyboardUp);
	glutMouseFunc(Input::mouseClick);
	glutMotionFunc(Input::mouseMove);
	glutPassiveMotionFunc(Input::mousePassiveMove);
	glutMainLoop();

	return 0;
									 // Ensure this is the last glut line called return 0
}



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
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
#include "Clock.h"
#include "Background.h"
#include <iostream>

//Clock


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

//Background
Background * background = new Background();

//GameObject
GameObject * gameObject = new GameObject();

int deltaTime = 0;


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

	glUseProgram(0); //Unbind Program
	
	glutSwapBuffers();
}

void init() 
{
	ShaderLoader shaderLoader; 
	program = shaderLoader.CreateProgram("VertexShader.vs", "FragmentShader.fs");

	player->initialise();
	batKnight->initialise();
	zombie->initialise();
	rat->initialise();
	introScene->initialise();

	background->initialise();
	camera->Initialise();
}

void Update()
{
	deltaTime++;
	camera->Update(1.0f);

	player->update(deltaTime, program);
	batKnight->update(deltaTime, program);
	zombie->update(deltaTime, program);
	rat->update(deltaTime, program);
	introScene->update(deltaTime, program);

	background->update(1.0f);
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

	glutMainLoop();

	return 0;
									 // Ensure this is the last glut line called return 0
}



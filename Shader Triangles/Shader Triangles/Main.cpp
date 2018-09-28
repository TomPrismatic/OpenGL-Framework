#include "Dependencies\soil\SOIL.h"
#include "Dependencies\glew\glew.h" 
#include "Dependencies\freeglut\freeglut.h" 
#include "ShaderLoader.h"
#include "Camera.h"
#include "Input.h"
#include "Player.h"
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

//Player
Player * player = new Player();

//Background
Background * background = new Background();

//GameObject
GameObject * gameObject = new GameObject();

int deltaTime = 0;


void updatePVM(GameObject * gameObject)
{
	player->calculatePVMMatrix(camera->GetPV());
}



void render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 0.0, 0.0, 1.0); //clear red

	background->render(program);
	player->render(program);
	

	glUseProgram(0); //Unbind Program
	
	glutSwapBuffers();
}

void init() 
{
	ShaderLoader shaderLoader; 
	program = shaderLoader.CreateProgram("VertexShader.vs", "FragmentShader.fs");

	player->initialise();
	background->initialise();
	camera->Initialise();
}

void Update()
{
	deltaTime++;
	camera->Update(1.0f);

	player->update(deltaTime, program);
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



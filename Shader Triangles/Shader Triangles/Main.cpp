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
#include "Clock.h"
#include "gtc/type_ptr.hpp"
#include <iostream>

//Clock


//Global Variables
GLuint program;

//Camera
Camera * camera = new Camera();

//Player
Player * player = new Player();

//GameObject
GameObject * gameObject = new GameObject();


void updatePVM(GameObject * gameObject)
{
	player->calculatePVMMatrix(camera->GetPV());
}



void render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 0.0, 0.0, 1.0); //clear red
	
	player->render(program);

	GLuint pvmLoc = glGetUniformLocation(program, "pvm");
	glUniformMatrix4fv(pvmLoc, 1, GL_FALSE, glm::value_ptr(player->getPVMMatrix()));

	glUseProgram(0); //Unbind Program
	
	glutSwapBuffers();
}

void init() 
{
	ShaderLoader shaderLoader; 
	program = shaderLoader.CreateProgram("VertexShader.vs", "FragmentShader.fs");

	player->initialise();
	camera->Initialise();
}

void Update()
{
	camera->Update(1.0f);

	player->update(1.0f, program);
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
	init();

	glutDisplayFunc(render);
	glutIdleFunc(Update);

	glutKeyboardFunc(Input::KeyboardDown);
	glutKeyboardUpFunc(Input::KeyboardUp);

	glutMainLoop();

	return 0;
									 // Ensure this is the last glut line called return 0
}



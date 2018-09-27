#include "Dependencies\soil\SOIL.h"
#include "Dependencies\glew\glew.h" 
#include "Dependencies\freeglut\freeglut.h" 
#include "ShaderLoader.h"
#include "Camera.h"
#include "Input.h"
#include "Player.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
#include <iostream>


std::string raymanImage = "Dependencies/Rayman.jpg";
std::string faceImage = "Dependencies/AwesomeFace.png";

//Global Variables
GLuint program;

GLuint VBO, VBOQuad;
GLuint VAO, VAOQuad;
GLuint EBO, EBOQuad;

GLuint texture;
GLuint texture2;

GLfloat currentTime;

glm::vec3 objPosition = glm::vec3(0.5f, 0.5f, 0.0f);
glm::vec3 rotationAxisZ = glm::vec3(0.0f, 0.0f, 1.0f);
glm::vec3 objScale = glm::vec3(0.5f, 0.5f, 0.5f);

glm::mat4 translationMatrix;
glm::mat4 rotationZ;
glm::mat4 scaleMatrix;
glm::mat4 model;

//Camera
Camera camera;
glm::vec3 camPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 camLookDir = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 camUpDir = glm::vec3(0.0f, 1.0f, 0.0f);
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;

//Player
Player player;



void render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 0.0, 0.0, 1.0); //clear red

	glUseProgram(program);
	glBindVertexArray(VAO); // Bind VAO 
	glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
	//glBindVertexArray(0); // Unbind VAO

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glUniform1i(glGetUniformLocation(program, "tex"), 0);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture2);
	glUniform1i(glGetUniformLocation(program, "tex2"), 1);

	glBindVertexArray(VAOQuad); // Bind VAO
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0); // Unbind VAO

	GLint currentTimeLoc = glGetUniformLocation(program, "currentTime");
	glUniform1f(currentTimeLoc, currentTime);
	
	GLuint modelLoc = glGetUniformLocation(program, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	//Camera View
	camera.generateView(camPos, camLookDir, camUpDir, program);

	//Camera Proj
	camera.generateProjPerspective(SCR_WIDTH, SCR_HEIGHT, program);

	glUseProgram(0); //Unbind Program
	
	glutSwapBuffers();
}

void init() 
{
	ShaderLoader shaderLoader; 
	program = shaderLoader.CreateProgram("VertexShader.vs", "FragmentShader.fs");

}

void Update()
{
	player.ProcessInput(objPosition);
	currentTime = glutGet(GLUT_ELAPSED_TIME);  // Get current time. 
	currentTime = currentTime / 1000;  // Convert millisecond to seconds

	//Object placement using a matrix
	glm::mat4 translationMatrix = glm::translate(glm::mat4(), objPosition);
	//Object Rotation using a Matrix
	float rotationAngle = 180;
	rotationZ = glm::rotate(glm::mat4(), glm::radians(rotationAngle), rotationAxisZ);
	//Object scaling using a scaling Matrix
	scaleMatrix = glm::scale(glm::mat4(), objScale);
	//Combining all three into a model matrix
	model = translationMatrix * rotationZ * scaleMatrix;
	
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



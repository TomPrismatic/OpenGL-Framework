#pragma once

#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include <iostream>


class ShaderLoader
{
private:
	ShaderLoader(void);
	~ShaderLoader(void);
	ShaderLoader(const ShaderLoader& copy) {};
	ShaderLoader& operator=(const ShaderLoader& move) {};

	static ShaderLoader * instance;

	std::string ReadShader(const char *filename);
	GLuint CreateShader(GLenum shaderType, std::string source, const char* shaderName);

public:
	GLuint CreateProgram(const char* VertexShaderFilename, const char* FragmentShaderFilename);
	static ShaderLoader* getInstance();

};

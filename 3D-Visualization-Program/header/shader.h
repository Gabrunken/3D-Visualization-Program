#pragma once
#include <glew.h>
#include <iostream>
#include <string>
#include <fstream>

#define file_extension_shader_vertex "vertexshader"
#define file_extension_shader_fragment "fragmentshader"

class Shader
{
public:
	Shader();
	~Shader();
	Shader(std::string code, GLenum shader_type, std::string name);

	static Shader loadShaderFromFile(std::string file_path);

	void create();
	void free();

	unsigned int getHandle() const;

private:
	unsigned int m_handle = 0;
	std::string m_name = "unnamed shader";
	std::string m_code = "no code shader";
	GLenum m_shader_type = GL_NONE;
};

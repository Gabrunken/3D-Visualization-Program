#pragma once
#include <shaderprogram.h>

class Material
{
public:
	Material();
	~Material();
	
	Material(ShaderProgram shader_program);

	template<typename T> void setParameter1(const char* name, T value);
	template<typename T> void setParameter2(const char* name, T value01,
															  T value02);
	template<typename T> void setParameter3(const char* name, T value01,
															  T value02,
															  T value03);
	template<typename T> void setParameter4(const char* name, T value01,
															  T value02,
															  T value03,
															  T value04);

	void setTexture(const char* name, Texture texture);

	void free();
	void bind() const;

	ShaderProgram getShaderProgram() const;


private:
	ShaderProgram m_shader_program;

	std::vector<GLuint> m_uint_parameters;
	std::vector<GLfloat> m_float_parameters;
	std::vector<uint8_t> m_parameters_length;
	std::vector<GLenum> m_parameters_types;
	std::vector<const char*> m_parameters_names;

	uint8_t m_texture_slot = 0;
};

#pragma once
#include <openglobject.h>
#include <shader.h>
#include <vector>
#include <texture.h>

class ShaderProgram : OpenGLObject
{
public:
	ShaderProgram();
	~ShaderProgram();
	ShaderProgram(Shader vertex_shader, Shader fragment_shader);

	void create();
	void createAll();
	void free();
	void freeAll();
	void bind() const;

	template<typename T> bool setUniform1(const char* name, T value) const;
	template<typename T> bool setUniform2(const char* name, T value01, T value02) const;
	template<typename T> bool setUniform3(const char* name, T value01, T value02, T value03) const;
	template<typename T> bool setUniform4(const char* name, T value01, T value02, T value03, T value04) const;
	bool setUniformTexture(const char* name, Texture texture, uint8_t slot);

private:
	std::vector<Shader> m_shaders;

	int getUniformLocation(const char* uniform_name) const;
};

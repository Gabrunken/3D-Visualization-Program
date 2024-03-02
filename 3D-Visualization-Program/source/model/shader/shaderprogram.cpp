#include <shaderprogram.h>

ShaderProgram::ShaderProgram()
{}

ShaderProgram::~ShaderProgram()
{}

ShaderProgram::ShaderProgram(Shader vertex_shader, Shader fragment_shader)
{
	m_shaders.push_back(vertex_shader);
	m_shaders.push_back(fragment_shader);
}

void ShaderProgram::create()
{
	if (m_handle != 0)
		return;

	m_handle = glCreateProgram();

	for (unsigned char i = 0; i < m_shaders.size(); i++)
	{
		glAttachShader(m_handle, m_shaders[i].getHandle());
	}

	glLinkProgram(m_handle);
	glValidateProgram(m_handle);
}

void ShaderProgram::createAll()
{
	if (m_handle != 0)
		return;
	
	m_handle = glCreateProgram();

	for (unsigned char i = 0; i < m_shaders.size(); i++)
	{
		m_shaders[i].create();
		glAttachShader(m_handle, m_shaders[i].getHandle());
	}

	glLinkProgram(m_handle);
	glValidateProgram(m_handle);
}

void ShaderProgram::free()
{
	glDeleteProgram(m_handle);
	m_handle = 0;
}

void ShaderProgram::freeAll()
{
	glDeleteProgram(m_handle);
	m_handle = 0;

	for (unsigned char i = 0; i < m_shaders.size(); i++)
	{
		m_shaders[i].free();
	}
}

void ShaderProgram::bind() const
{
	glUseProgram(m_handle);
}

template<> bool ShaderProgram::setUniform1<GLint>(const char* name, GLint value) const
{
	glUseProgram(m_handle);

	int uniform_location = getUniformLocation(name);
	if (uniform_location == -1)
		return false;

	glUniform1i(uniform_location, value);
	return true;
}

template<> bool ShaderProgram::setUniform2<GLint>(const char* name, GLint value01, GLint value02) const
{
	glUseProgram(m_handle);

	int uniform_location = getUniformLocation(name);
	if (uniform_location == -1)
		return false;

	glUniform2i(uniform_location, value01, value02);
	return true;
}

template<> bool ShaderProgram::setUniform3<GLint>(const char* name, GLint value01, GLint value02, GLint value03) const
{
	glUseProgram(m_handle);

	int uniform_location = getUniformLocation(name);
	if (uniform_location == -1)
		return false;

	glUniform3i(uniform_location, value01, value02, value03);
	return true;
}

template<> bool ShaderProgram::setUniform4<GLint>(const char* name, GLint value01, GLint value02, GLint value03, GLint value04) const
{
	glUseProgram(m_handle);

	int uniform_location = getUniformLocation(name);
	if (uniform_location == -1)
		return false;

	glUniform4i(uniform_location, value01, value02, value03, value04);
	return true;
}

template<> bool ShaderProgram::setUniform1<GLfloat>(const char* name, GLfloat value) const
{
	glUseProgram(m_handle);

	int uniform_location = getUniformLocation(name);
	if (uniform_location == -1)
		return false;

	glUniform1f(uniform_location, value);
	return true;
}

template<> bool ShaderProgram::setUniform2<GLfloat>(const char* name, GLfloat value01, GLfloat value02) const
{
	glUseProgram(m_handle);

	int uniform_location = getUniformLocation(name);
	if (uniform_location == -1)
		return false;

	glUniform2f(uniform_location, value01, value02);
	return true;
}

template<> bool ShaderProgram::setUniform3<GLfloat>(const char* name, GLfloat value01, GLfloat value02, GLfloat value03) const
{
	glUseProgram(m_handle);

	int uniform_location = getUniformLocation(name);
	if (uniform_location == -1)
		return false;

	glUniform3f(uniform_location, value01, value02, value03);
	return true;
}

template<> bool ShaderProgram::setUniform4<GLfloat>(const char* name, GLfloat value01, GLfloat value02, GLfloat value03, GLfloat value04) const
{
	glUseProgram(m_handle);
	
	int uniform_location = getUniformLocation(name);
	if (uniform_location == -1)
		return false;
	
	glUniform4f(uniform_location, value01, value02, value03, value04);
	return true;
}

bool ShaderProgram::setUniformTexture(const char* name, Texture texture, uint8_t slot)
{
	glUseProgram(m_handle);
	glActiveTexture(GL_TEXTURE0 + slot);
	texture.bind();

	int uniform_location = getUniformLocation(name);
	if (uniform_location == -1)
		return false;

	glUniform1i(getUniformLocation(name), slot);
	return true;
}

int ShaderProgram::getUniformLocation(const char* name) const
{
	int location = glGetUniformLocation(m_handle, name);
	if (location == -1)
		std::cout << "Uniform " << name << " doesn't exist in a shader." << std::endl;
	
	return location;
}
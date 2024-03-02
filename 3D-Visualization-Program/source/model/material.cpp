#include <material.h>

Material::Material()
{}

Material::~Material()
{}

Material::Material(ShaderProgram shader_program)
	: m_shader_program(shader_program)
{
	m_shader_program.createAll();
}

template<> void Material::setParameter1<GLint>(const char* name, GLint value)
{
	for (uint8_t i = 0; i < m_parameters_names.size(); i++)
	{
		if (m_parameters_names[i] == name)
			return;
	}

	if (m_shader_program.setUniform1<GLint>(name, value))
	{
		m_uint_parameters.push_back(value);
		m_parameters_length.push_back(1);
		m_parameters_types.push_back(GL_UNSIGNED_INT);
		m_parameters_names.push_back(name);
	}
}

template<> void Material::setParameter2<GLint>(const char* name, GLint value01,
																  GLint value02)
{
	for (uint8_t i = 0; i < m_parameters_names.size(); i++)
	{
		if (m_parameters_names[i] == name)
			return;
	}

	if (m_shader_program.setUniform2<GLint>(name, value01, value02))
	{
		m_uint_parameters.push_back(value01);
		m_uint_parameters.push_back(value02);
		m_parameters_length.push_back(2);
		m_parameters_types.push_back(GL_UNSIGNED_INT);
		m_parameters_names.push_back(name);
	}
}

template<> void Material::setParameter3<GLint>(const char* name, GLint value01,
																  GLint value02,
																  GLint value03)
{
	for (uint8_t i = 0; i < m_parameters_names.size(); i++)
	{
		if (m_parameters_names[i] == name)
			return;
	}

	if (m_shader_program.setUniform3<GLint>(name, value01, value02, value03))
	{
		m_uint_parameters.push_back(value01);
		m_uint_parameters.push_back(value02);
		m_uint_parameters.push_back(value03);
		m_parameters_length.push_back(3);
		m_parameters_types.push_back(GL_UNSIGNED_INT);
		m_parameters_names.push_back(name);
	}
}

template<> void Material::setParameter4<GLint>(const char* name, GLint value01,
																  GLint value02,
																  GLint value03,
																  GLint value04)
{
	for (uint8_t i = 0; i < m_parameters_names.size(); i++)
	{
		if (m_parameters_names[i] == name)
			return;
	}

	if (m_shader_program.setUniform4<GLint>(name, value01, value02, value03, value04))
	{
		m_uint_parameters.push_back(value01);
		m_uint_parameters.push_back(value02);
		m_uint_parameters.push_back(value03);
		m_uint_parameters.push_back(value04);
		m_parameters_length.push_back(4);
		m_parameters_types.push_back(GL_UNSIGNED_INT);
		m_parameters_names.push_back(name);
	}
}


template<> void Material::setParameter1<GLfloat>(const char* name, GLfloat value)
{
	for (uint8_t i = 0; i < m_parameters_names.size(); i++)
	{
		if (m_parameters_names[i] == name)
			return;
	}

	if (m_shader_program.setUniform1<GLfloat>(name, value))
	{
		m_float_parameters.push_back(value);
		m_parameters_length.push_back(1);
		m_parameters_types.push_back(GL_FLOAT);
		m_parameters_names.push_back(name);
	}
}

template<> void Material::setParameter2<GLfloat>(const char* name, GLfloat value01,
																   GLfloat value02)
{
	for (uint8_t i = 0; i < m_parameters_names.size(); i++)
	{
		if (m_parameters_names[i] == name)
			return;
	}

	if (m_shader_program.setUniform2<GLfloat>(name, value01, value02))
	{
		m_float_parameters.push_back(value01);
		m_float_parameters.push_back(value02);
		m_parameters_length.push_back(2);
		m_parameters_types.push_back(GL_FLOAT);
		m_parameters_names.push_back(name);
	}
}

template<> void Material::setParameter3<GLfloat>(const char* name, GLfloat value01,
																   GLfloat value02,
																   GLfloat value03)
{
	for (uint8_t i = 0; i < m_parameters_names.size(); i++)
	{
		if (m_parameters_names[i] == name)
			return;
	}

	if (m_shader_program.setUniform3<GLfloat>(name, value01, value02, value03))
	{
		m_float_parameters.push_back(value01);
		m_float_parameters.push_back(value02);
		m_float_parameters.push_back(value03);
		m_parameters_length.push_back(3);
		m_parameters_types.push_back(GL_FLOAT);
		m_parameters_names.push_back(name);
	}
}

template<> void Material::setParameter4<GLfloat>(const char* name, GLfloat value01,
																   GLfloat value02,
																   GLfloat value03,
																   GLfloat value04)
{
	for (uint8_t i = 0; i < m_parameters_names.size(); i++)
	{
		if (m_parameters_names[i] == name)
			return;
	}

	if (m_shader_program.setUniform4<GLfloat>(name, value01, value02, value03, value04))
	{
		m_float_parameters.push_back(value01);
		m_float_parameters.push_back(value02);
		m_float_parameters.push_back(value03);
		m_float_parameters.push_back(value04);
		m_parameters_length.push_back(4);
		m_parameters_types.push_back(GL_FLOAT);
		m_parameters_names.push_back(name);
	}
}

void Material::setTexture(const char* name, Texture texture)
{
	texture.create();
	if (m_shader_program.setUniformTexture(name, texture, m_texture_slot))
		m_texture_slot++;
}

void Material::free()
{
	m_float_parameters.clear();
	m_uint_parameters.clear();
	m_parameters_length.clear();
	m_parameters_names.clear();
	m_parameters_types.clear();
}

void Material::bind() const
{
	for (uint8_t i = 0; i < m_parameters_names.size(); i++)
	{
		switch (m_parameters_types[i])
		{
		case GL_FLOAT:
			switch (m_parameters_length[i])
			{
			case 1:
				m_shader_program.setUniform1<GLfloat>(m_parameters_names[i], m_float_parameters[i]);
				break;
			case 2:
				m_shader_program.setUniform2<GLfloat>(m_parameters_names[i], m_float_parameters[(2 * i)],
																  m_float_parameters[(2 * i) + 1]);
				break;
			case 3:
				m_shader_program.setUniform3<GLfloat>(m_parameters_names[i], m_float_parameters[(2 * i)],
																  m_float_parameters[(2 * i) + 1],
																  m_float_parameters[(2 * i) + 2]);
				break;
			case 4:
				m_shader_program.setUniform4<GLfloat>(m_parameters_names[i], m_float_parameters[(2 * i)],
																  m_float_parameters[(2 * i) + 1],
																  m_float_parameters[(2 * i) + 2],
																  m_float_parameters[(2 * i) + 3]);
				break;
			}
			break;
		case GL_UNSIGNED_INT:
			switch (m_parameters_length[i])
			{
			case 1:
				m_shader_program.setUniform1<GLint>(m_parameters_names[i], m_uint_parameters[i]);
				break;
			case 2:
				m_shader_program.setUniform2<GLint>(m_parameters_names[i], m_uint_parameters[(2 * i)],
																  m_uint_parameters[(2 * i) + 1]);
				break;
			case 3:
				m_shader_program.setUniform3<GLint>(m_parameters_names[i], m_uint_parameters[(2 * i)],
																  m_uint_parameters[(2 * i) + 1],
																  m_uint_parameters[(2 * i) + 2]);
				break;
			case 4:
				m_shader_program.setUniform4<GLint>(m_parameters_names[i], m_uint_parameters[(2 * i)],
																  m_uint_parameters[(2 * i) + 1],
																  m_uint_parameters[(2 * i) + 2],
																  m_uint_parameters[(2 * i) + 3]);
				break;
			}
		}
	}
}

ShaderProgram Material::getShaderProgram() const
{
	return m_shader_program;
}
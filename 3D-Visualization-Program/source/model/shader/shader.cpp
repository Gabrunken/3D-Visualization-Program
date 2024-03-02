#include <shader.h>

Shader::Shader()
{}

Shader::~Shader()
{}

Shader::Shader(std::string code, GLenum shader_type, std::string name)
	: m_code(code),
	  m_shader_type(shader_type),
	  m_name(name)
{}

Shader Shader::loadShaderFromFile(std::string file_path)
{
	std::string file_path_string(file_path);
	if (file_path_string.empty())
	{
		std::cout << "Couldn't load shader from file: the file path given was empty." << std::endl;
		return Shader();
	}

	std::string name;
	std::string file_extension_found;
	for (int16_t i = (int16_t)(file_path_string.length() - 1);
		i >= 0;
		i--)
	{
		if (file_path_string[i] == '.')
		{
			file_extension_found.append(&file_path_string[i + 1]);
			
			if (file_path_string.find('/') != std::string::npos)
			{
				do
				{
					file_path_string = file_path_string.substr(file_path_string.find('/') + 1, file_path_string.length()- file_path_string.find('/')-1);
				} while (file_path_string.find('/') != std::string::npos);	
			}

			name = file_path_string.substr(0, file_path_string.find("."));
			break;
		}
	}

	GLenum shader_type;
	if (file_extension_found == file_extension_shader_vertex)
		shader_type = GL_VERTEX_SHADER;
	else if (file_extension_found == file_extension_shader_fragment)
		shader_type = GL_FRAGMENT_SHADER;
	else
	{
		std::cout << file_extension_found << " is not a known shader file extension." << std::endl;
		return Shader();
	}

	std::string code_string;
	
	std::ifstream file_reader(file_path.c_str());
	if (file_reader.bad())
	{
		std::cout << "Something bad happened when opening the file on this path: " << file_path << std::endl;
		return Shader();
	}

	else if (file_reader.fail())
	{
		std::cout << "Something bad happened when opening the file on this path: " << file_path << std::endl;
		return Shader();
	}

	else if (file_reader.eof())
	{
		std::cout << "File opened on this path is empty: " << file_path << std::endl;
		return Shader();
	}

	char character;
	while (file_reader.get(character))
	{
		code_string += character;
	}

	return Shader(code_string, shader_type, name);
}

void Shader::create()
{
	if (m_handle != 0)
		return;

	m_handle = glCreateShader(m_shader_type);
	const char* code = m_code.c_str();
	glShaderSource(m_handle, 1, &code, nullptr);
	glCompileShader(m_handle);

	int compile_result;
	glGetShaderiv(m_handle, GL_COMPILE_STATUS, &compile_result);
	if (compile_result == GL_FALSE)
	{
		int error_length;
		glGetShaderiv(m_handle, GL_INFO_LOG_LENGTH, &error_length);
		char* message = (char*)malloc(error_length * sizeof(char));
		glGetShaderInfoLog(m_handle, error_length, &error_length, message);

		std::cout << "Failed to compile shader of name and type: " << m_name << ", ";

		switch (m_shader_type)
		{
		case GL_VERTEX_SHADER:
			std::cout << "vertex.";
			break;

		case GL_FRAGMENT_SHADER:
			std::cout << "fragment.";
			break;

		default:
			std::cout << "unknown.";
			break;
		}

		std::cout << std::endl;
		
		std::free(message);

		glDeleteShader(m_handle);
		m_handle = 0;
	}
}

void Shader::free()
{
	glDeleteShader(m_handle);
	m_handle = 0;
}

unsigned int Shader::getHandle() const
{
	return m_handle;
}
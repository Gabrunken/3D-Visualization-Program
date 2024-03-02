#include <texture.h>

Texture::Texture()
{}

Texture::Texture(const char* file_path)
{
	m_data = stbi_load(file_path, &m_width, &m_height, &m_color_channels_count, 0);
}

Texture::~Texture()
{}

void Texture::create()
{
	if (m_handle != 0)
		return;

	glGenTextures(1, &m_handle);
	glBindTexture(GL_TEXTURE_2D, m_handle);
	
	if (m_color_channels_count == 3)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_data);
	
	else if (m_color_channels_count == 4)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_data);
	
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::free()
{
	stbi_image_free(m_data);
	glDeleteTextures(1, &m_handle);
	m_handle = 0;
}

void Texture::bind() const
{
	glBindTexture(GL_TEXTURE_2D, m_handle);
}
#pragma once
#include <openglobject.h>
#include <stb_image.h>
#include <iostream>

class Texture : OpenGLObject
{
public:
	Texture();
	Texture(const char* file_path);
	~Texture();

	void create();
	void free();
	void bind() const;

private:
	int m_width = 0;
	int m_height = 0;
	int m_color_channels_count = 0;

	unsigned char* m_data = nullptr;
};

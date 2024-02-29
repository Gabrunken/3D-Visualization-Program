#pragma once
#include <glew.h>

class OpenGLObject
{
public:
	virtual void create() = 0;
	virtual void free() = 0;
	virtual void bind() const = 0;

protected:
	unsigned int m_handle = 0;
};

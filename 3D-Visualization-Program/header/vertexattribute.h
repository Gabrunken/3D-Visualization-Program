#pragma once
#include <glew.h>
#include <gltype.h>

class VertexAttribute
{
public:
	VertexAttribute();
	VertexAttribute(one_byte_int components_count, GLenum components_type);
	~VertexAttribute();

	one_byte_int bytesCount() const;

	one_byte_int components_count = 0;
	GLenum components_type = GL_NONE;
};

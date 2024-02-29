#include <vertexattribute.h>

VertexAttribute::VertexAttribute()
{}

VertexAttribute::~VertexAttribute()
{}

VertexAttribute::VertexAttribute(one_byte_int components_count, GLenum components_type)
	: components_count(components_count),
	  components_type(components_type)
{}

one_byte_int VertexAttribute::bytesCount() const
{
	return components_count * bytesCountOfGLType(components_type);
}
#include <vertexlayout.h>

VertexLayout::VertexLayout()
{}

VertexLayout::~VertexLayout()
{}

VertexLayout::VertexLayout(const VertexAttribute* vertex_attributes, one_byte_int attributes_count)
	: vertex_attributes((VertexAttribute*)vertex_attributes),
	  attributes_count(attributes_count)
{}

one_byte_int VertexLayout::bytesCount() const
{
	one_byte_int bytes = 0;
	for (one_byte_int i = 0; i < attributes_count; i++)
		bytes += vertex_attributes[i].bytesCount();

	return bytes;
}
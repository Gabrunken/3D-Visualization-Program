#pragma once
#include <vector>
#include <vertexattribute.h>

class VertexLayout
{
public:
	VertexLayout();
	~VertexLayout();
	VertexLayout(const VertexAttribute* vertex_attributes, one_byte_int attributes_count);

	one_byte_int bytesCount() const;

	const VertexAttribute* vertex_attributes = nullptr;
	one_byte_int attributes_count = 0;
};

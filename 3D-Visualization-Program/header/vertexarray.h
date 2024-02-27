#pragma once
#include <indexbuffer.h>
#include <vertexbuffer.h>
#include <vertexlayout.h>
#include <vertexattribute.h>

class VertexArray
{
public:
	VertexArray();
	VertexArray(const VertexBuffer& vertex_buffer,
				const IndexBuffer& index_buffer,
				const VertexLayout& vertex_layout);
	~VertexArray();

private:
	unsigned int m_handle = 0;
};

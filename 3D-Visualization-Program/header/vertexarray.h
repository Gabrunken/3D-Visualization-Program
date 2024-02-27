#pragma once
#include <indexbuffer.h>
#include <vertexbuffer.h>
#include <vertexlayout.h>
#include <vertexattribute.h>

class VertexArray
{
public:
	VertexArray();
	VertexArray(VertexBuffer vertex_buffer,
				IndexBuffer index_buffer,
				VertexLayout vertex_layout);
	~VertexArray();

private:
	unsigned int m_handle = 0;
};

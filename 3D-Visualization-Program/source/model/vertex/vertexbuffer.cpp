#include <vertexbuffer.h>
#include <iostream>

VertexBuffer::VertexBuffer()
{}

VertexBuffer::~VertexBuffer()
{}

VertexBuffer::VertexBuffer(const void* vertices_data,
						   unsigned int vertices_count,
						   VertexLayout vertex_layout)
	: m_vertices_data(vertices_data),
	  m_vertices_count(vertices_count),
	  m_vertex_layout(vertex_layout)
{}

VertexLayout VertexBuffer::getVertexLayout() const
{
	return m_vertex_layout;
}

void VertexBuffer::create()
{
	glGenBuffers(1, &m_handle);
	glBindBuffer(GL_ARRAY_BUFFER, m_handle);
	glBufferData(GL_ARRAY_BUFFER, m_vertices_count * m_vertex_layout.bytesCount(), m_vertices_data, GL_STATIC_DRAW);
}

void VertexBuffer::free()
{
	glDeleteBuffers(1, &m_handle);
	m_handle = 0;
}

void VertexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_handle);
}
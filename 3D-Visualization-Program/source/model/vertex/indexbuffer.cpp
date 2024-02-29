#include <indexbuffer.h>

IndexBuffer::IndexBuffer()
{}

IndexBuffer::~IndexBuffer()
{}

IndexBuffer::IndexBuffer(const unsigned int* indices, unsigned int indices_count)
	: m_indices(indices),
	  m_indices_count(indices_count) 
{}

void IndexBuffer::create()
{
	glGenBuffers(1, &m_handle);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_handle);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices_count * sizeof(unsigned int), m_indices, GL_STATIC_DRAW);
}

void IndexBuffer::free()
{
	glDeleteBuffers(1, &m_handle);
	m_handle = 0;
}

void IndexBuffer::bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_handle);
}

unsigned int IndexBuffer::getIndicesCount() const
{
	return m_indices_count;
}

const unsigned int* IndexBuffer::getIndices() const
{
	return m_indices;
}
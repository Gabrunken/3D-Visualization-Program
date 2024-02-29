#include <vertexarray.h>
#include <glew.h>

VertexArray::VertexArray()
{}

VertexArray::~VertexArray()
{}

VertexArray::VertexArray(VertexBuffer vertex_buffer,
						 IndexBuffer index_buffer)
	: m_vertex_buffer(vertex_buffer),
	  m_index_buffer(index_buffer)
{}

void VertexArray::create()
{
	glGenVertexArrays(1, &m_handle);
	glBindVertexArray(m_handle);

	m_vertex_buffer.create();
	m_index_buffer.create();

	one_byte_int offset = 0;
	VertexLayout vertex_layout = m_vertex_buffer.getVertexLayout();
	for (unsigned int attribute = 0; attribute < 1; attribute++)
	{
		glEnableVertexAttribArray(attribute);
		glVertexAttribPointer(attribute,
						      vertex_layout.vertex_attributes[attribute].components_count,
							  vertex_layout.vertex_attributes[attribute].components_type,
							  GL_FALSE,
							  vertex_layout.bytesCount(),
							  (const void*)offset);

		offset += vertex_layout.bytesCount();
	}
}

void VertexArray::free()
{
	glDeleteVertexArrays(1, &m_handle);
	m_handle = 0;
}

void VertexArray::bind() const
{
	glBindVertexArray(m_handle);
}

void VertexArray::freeAll()
{
	glDeleteVertexArrays(1, &m_handle);
	m_handle = 0;
	m_vertex_buffer.free();
	m_index_buffer.free();
}

IndexBuffer VertexArray::getIndexBuffer() const
{
	return m_index_buffer;
}
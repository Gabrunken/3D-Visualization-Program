#pragma once
#include <indexbuffer.h>
#include <vertexbuffer.h>
#include <vertexlayout.h>
#include <vertexattribute.h>

class VertexArray : OpenGLObject
{
public:
	VertexArray();
	~VertexArray();
	VertexArray(VertexBuffer vertex_buffer,
				IndexBuffer index_buffer);

	void create();
	void free();
	void bind() const;

	void freeAll();

	IndexBuffer getIndexBuffer() const;

private:
	VertexBuffer m_vertex_buffer;
	IndexBuffer m_index_buffer;
};

#pragma once
#include <openglobject.h>
#include <vertexlayout.h>

class VertexBuffer : OpenGLObject
{
public:
	VertexBuffer();
	~VertexBuffer();
	VertexBuffer(const void* vertices_data,
				 unsigned int vertices_count,
				 VertexLayout vertex_layout);

	void create();
	void free();
	void bind() const;

	VertexLayout getVertexLayout() const;

private:
	const void* m_vertices_data = nullptr;
	unsigned int m_vertices_count = 0;
	VertexLayout m_vertex_layout;
};

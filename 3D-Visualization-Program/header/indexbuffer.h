#pragma once
#include <openglobject.h>

class IndexBuffer : OpenGLObject
{
public:
	IndexBuffer();
	~IndexBuffer();
	IndexBuffer(const unsigned int* indices, unsigned int indices_count);

	void create();
	void free();
	void bind() const;
	
	unsigned int getIndicesCount() const;
	const unsigned int* getIndices() const;

private:
	const unsigned int* m_indices = nullptr;
	unsigned int m_indices_count = 0;
};

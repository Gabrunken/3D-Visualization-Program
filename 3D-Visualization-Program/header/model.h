#pragma once
#include <vertexarray.h>

class Model
{
public:
	Model();
	~Model();
	Model(const char* name, VertexArray vertex_array);

	static Model loadFromObjFile(const char* file_path);

	const char* name = "unnamed model";
	VertexArray vertex_array;
};

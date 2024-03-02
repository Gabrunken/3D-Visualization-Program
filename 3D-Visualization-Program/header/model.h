#pragma once
#include <vertexarray.h>
#include <string>
#include <material.h>

class Model
{
public:
	Model();
	~Model();
	Model(std::string name, VertexArray vertex_array, Material material);

	static Model loadFromObjFile(const char* file_path);
	
	void bind() const;
	void create();
	void free();

	VertexArray getVertexArray() const;

	Material material;
	std::string name = "unnamed model";

private:
	VertexArray m_vertex_array;
};

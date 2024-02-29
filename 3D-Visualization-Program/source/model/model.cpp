#include <model.h>

Model::Model() {}

Model::~Model() {}

Model::Model(const char* name, VertexArray vertex_array)
	: name(name),
	  vertex_array(vertex_array)
{}

Model Model::loadFromObjFile(const char* file_path)
{
	return Model();
}
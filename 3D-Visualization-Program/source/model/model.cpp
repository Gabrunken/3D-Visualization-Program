#include <model.h>

Model::Model()
{}

Model::~Model()
{}

Model::Model(std::string name, VertexArray vertex_array, Material material)
	: name(name),
	  m_vertex_array(vertex_array),
	  material(material)
{}

Model Model::loadFromObjFile(const char* file_path)
{
	return Model();
}

void Model::bind() const
{
	m_vertex_array.bind();
	material.bind();
}

void Model::create()
{
	m_vertex_array.create();
	material.getShaderProgram().createAll();
}

void Model::free()
{
	m_vertex_array.freeAll();
	material.free();
}

VertexArray Model::getVertexArray() const
{
	return m_vertex_array;
}
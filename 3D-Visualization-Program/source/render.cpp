#include <render.h>

void render::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void render::model(Model model)
{
	model.vertex_array.bind();
	glDrawElements(GL_TRIANGLES,
				   model.vertex_array.getIndexBuffer().getIndicesCount(),
				   GL_UNSIGNED_INT,
				   nullptr);
}
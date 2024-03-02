#include <iostream>
#include <render.h>
#include <shaderprogram.h>
#include <texture.h>
#include <glfw3.h>

const GLFWwindow* init()
{
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW.\n";
		return nullptr;
	}

	GLFWwindow* window = glfwCreateWindow(1280, 720, "Window", nullptr, nullptr);

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize glew.\n";
		return nullptr;
	}
	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);

	stbi_set_flip_vertically_on_load(true);

	return window;
}

void mainLoop(const GLFWwindow* window)
{
	float vertices[] = {
		-0.5f, -0.5f, 0.0f, 0.0f,
		0.5f, -0.5f, 1.0f, 0.0f,
		0.5f, 0.5f, 1.0f, 1.0f,
		-0.5f, 0.5f, 0.0f, 1.0f
	};

	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	VertexAttribute vas[] = {VertexAttribute(2, GL_FLOAT), VertexAttribute(2, GL_FLOAT)};
	VertexBuffer vbo = VertexBuffer(VertexBuffer(VertexBuffer((const void*)vertices, 4, VertexLayout(vas, 2))));
	IndexBuffer ibo(indices, 6);

	ShaderProgram textured(Shader::loadShaderFromFile("resources/graphics/shaders/vertex/textured.vertexshader"),
					       Shader::loadShaderFromFile("resources/graphics/shaders/fragment/textured.fragmentshader"));
	
	Texture bricks("resources/graphics/textures/bricks.jpg");
	Texture woodplanks("resources/graphics/textures/woodplanks.jpeg");
	Material quad_material(textured);
	Material blue_tinted(textured);
	
	Model quad("quad", VertexArray(vbo, ibo), quad_material);
	quad.create();
	quad.material.setParameter3<GLfloat>("tint", 1.0f, 0.0f, 1.0f);
	quad.material.setTexture("u_texture", woodplanks);
	quad.material = blue_tinted;
	quad.material.setTexture("u_texture", bricks);
	quad.material.setParameter3<GLfloat>("tint", 0.0f, 0.0f, 1.0f);
	quad.material = quad_material;

	while (!glfwWindowShouldClose((GLFWwindow*)window))
	{
		render::clear();
		
		render::model(quad);

		glfwSwapBuffers((GLFWwindow*)window);
		glfwPollEvents();
	}
}

int main()
{
	const GLFWwindow* window = init();

	if (window == nullptr)
	{
		std::cout << "Failed to init." << std::endl;
		return -1;
	}

	mainLoop(window);
	
	return 0;
}
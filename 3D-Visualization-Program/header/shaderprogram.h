#pragma once
#include <openglobject.h>

class ShaderProgram : OpenGLObject
{
public:
	ShaderProgram();
	~ShaderProgram();
	ShaderProgram(int placeholder);

	void create();
	void free();
	void bind() const;
};

#include <gltype.h>

one_byte_int bytesCountOfGLType(GLenum type)
{
	switch (type)
	{
	case GL_INT:
		return sizeof(int);
	case GL_UNSIGNED_INT:
		return sizeof(unsigned int);
	case GL_BYTE:
		return sizeof(char);
	case GL_UNSIGNED_BYTE:
		return sizeof(unsigned char);
	case GL_SHORT:
		return sizeof(short);
	case GL_UNSIGNED_SHORT:
		return sizeof(unsigned short);
	case GL_FLOAT:
		return sizeof(float);
	case GL_BOOL:
		return sizeof(char);
	default:
		return 0;
	}
}
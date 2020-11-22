#pragma once

#include <GL/freeglut.h>

namespace Display
{
	namespace FreeGlut
	{
		enum struct ButtonState
		{
			DOWN = GLUT_DOWN,
			UP = GLUT_UP
		};
	}
}
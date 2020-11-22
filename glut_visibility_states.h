#pragma once

#include <GL/freeglut.h>

namespace Display
{
	namespace FreeGlut
	{
		enum struct VisibilityState
		{
			NOT_VISIBLE = GLUT_NOT_VISIBLE,
			VISIBLE = GLUT_VISIBLE
		};
	}
}
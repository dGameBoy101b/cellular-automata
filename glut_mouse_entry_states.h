#pragma once

#include <GL/freeglut.h>

namespace Display
{
	namespace FreeGlut
	{
		enum struct MouseEntryState
		{
			ENTERD = GLUT_ENTERED,
			LEFT = GLUT_LEFT
		};
	}
}
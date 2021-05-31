#pragma once

#include <GL/freeglut.h>

namespace Display
{
	namespace FreeGlut
	{
		enum struct MouseButton
		{
			LEFT = GLUT_LEFT_BUTTON,
			MIDDLE = GLUT_MIDDLE_BUTTON,
			RIGHT = GLUT_RIGHT_BUTTON,
			SCROLL_UP = 3,
			SCROLL_DOWN = 4
		};
	}
}
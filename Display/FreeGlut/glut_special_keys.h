#pragma once

#include <GL/freeglut.h>

namespace Display
{
	namespace FreeGlut
	{
		enum struct SpecialKeys
		{
			F1 = GLUT_KEY_F1,
			F2 = GLUT_KEY_F2,
			F3 = GLUT_KEY_F3,
			F4 = GLUT_KEY_F4,
			F5 = GLUT_KEY_F5,
			F6 = GLUT_KEY_F6,
			F7 = GLUT_KEY_F7,
			F8 = GLUT_KEY_F8,
			F9 = GLUT_KEY_F9,
			F10 = GLUT_KEY_F10,
			F11 = GLUT_KEY_F11,
			F12 = GLUT_KEY_F12,
			LEFT = GLUT_KEY_LEFT,
			UP = GLUT_KEY_UP,
			RIGHT = GLUT_KEY_RIGHT,
			DOWN = GLUT_KEY_DOWN,
			PAGE_UP = GLUT_KEY_PAGE_UP,
			PAGE_DOWN = GLUT_KEY_PAGE_DOWN,
			HOME = GLUT_KEY_HOME,
			END = GLUT_KEY_END,
			INSERT = GLUT_KEY_INSERT
		};
	}
}
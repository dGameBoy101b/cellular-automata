#pragma once

#include <GL/freeglut.h>

namespace Display
{
	namespace FreeGlut
	{
		enum struct DisplayMode
		{
			RGBA_COLOUR = GLUT_RGBA,
			INDEX_COLOUR = GLUT_INDEX,
			SINGLE_BUFFER = GLUT_SINGLE,
			DOUBLE_BUFFER = GLUT_DOUBLE,
			ACCUMULATION_BUFFER = GLUT_ACCUM,
			ALPHA_COLOUR_BUFFER = GLUT_ALPHA,
			DEPTH_BUFFER = GLUT_DEPTH,
			STENCIL_BUFFER = GLUT_STENCIL,
			MULTISAMPLING = GLUT_MULTISAMPLE,
			STEREO_WINDOW = GLUT_STEREO
		};
	}
}
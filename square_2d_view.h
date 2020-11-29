#pragma once

#include <vector>
#include "grid.h"
#include "colour.h"
#include "glut_colour.h"
#include "glut_model.h"
#include "square_model.h"
#include "glut_camera.h"
#include "glut_window.h"

namespace Display
{
	namespace FreeGlut
	{
		class Square2DView
		{
		public:
			static const unsigned char EXIT;
			static const unsigned char SWITCH_VIEW;
			static const unsigned char MOVE_UP;
			static const unsigned char MOVE_DOWN;
			static const unsigned char MOVE_RIGHT;
			static const unsigned char MOVE_LEFT; 
			static const float ZOOM_FAC;
			static const float MOVE_SPEED;
			static const Display::FreeGlut::MouseButton ZOOM_IN;
			static const Display::FreeGlut::MouseButton ZOOM_OUT;
			static const Display::FreeGlut::Window& getWindow();
			static void setWindow(const Display::FreeGlut::Window& window);
			static const std::vector<Display::FreeGlut::Colour>& getColours();
			static void setColours(const std::vector<Display::FreeGlut::Colour>& colours);
			static const Data::Grid& getGrid();
			static void setGrid(const Data::Grid& grid);
			static const Display::FreeGlut::Camera& getCamera();
		private:
			static Display::FreeGlut::Window window;
			static Data::Grid grid;
			static std::vector<Display::FreeGlut::Colour> colours;
			static Display::FreeGlut::Camera camera;
			static Display::FreeGlut::Model cell_model;
			static void display();
			static void close();
			static void charPress(unsigned char key, int, int);
			static void mousePress(Display::FreeGlut::MouseButton button, Display::FreeGlut::ButtonState state, int, int);
		};
	}
}
#include "square_2d_view.h"

const unsigned char Display::FreeGlut::Square2DView::EXIT 
= 27;

const unsigned char Display::FreeGlut::Square2DView::SWITCH_VIEW
= 'v';

const unsigned char Display::FreeGlut::Square2DView::MOVE_UP
= 'w';

const unsigned char Display::FreeGlut::Square2DView::MOVE_DOWN
= 's';

const unsigned char Display::FreeGlut::Square2DView::MOVE_RIGHT
= 'd';

const unsigned char Display::FreeGlut::Square2DView::MOVE_LEFT
= 'a';

const float Display::FreeGlut::Square2DView::ZOOM_FAC
= 1.1f;

const float Display::FreeGlut::Square2DView::MOVE_SPEED
= .2f;

const Display::FreeGlut::MouseButton Display::FreeGlut::Square2DView::ZOOM_IN
= Display::FreeGlut::MouseButton::SCROLL_UP;

const Display::FreeGlut::MouseButton Display::FreeGlut::Square2DView::ZOOM_OUT
= Display::FreeGlut::MouseButton::SCROLL_DOWN;

Display::FreeGlut::Window Display::FreeGlut::Square2DView::window 
= Display::FreeGlut::Window();

Data::Grid Display::FreeGlut::Square2DView::grid 
= Data::Grid();

std::vector<Display::FreeGlut::Colour> Display::FreeGlut::Square2DView::colours 
= std::vector<Display::FreeGlut::Colour>({Display::FreeGlut::Colour()});

Display::FreeGlut::Camera Display::FreeGlut::Square2DView::camera 
= Display::FreeGlut::Camera();

Display::FreeGlut::Model Display::FreeGlut::Square2DView::cell_model 
= Display::FreeGlut::Model(Data::SquareModel::getModel());

const Display::FreeGlut::Window& Display::FreeGlut::Square2DView::getWindow()
{
	return Square2DView::window;
}

void Display::FreeGlut::Square2DView::setWindow(const Display::FreeGlut::Window& window)
{
	Square2DView::window = window;

	if (Square2DView::window.exists())
	{
		Square2DView::window.destroyWindow();
	}

	Square2DView::window.addDisplayOption(Display::FreeGlut::DisplayMode::RGBA_COLOUR);
	Square2DView::window.addDisplayOption(Display::FreeGlut::DisplayMode::DOUBLE_BUFFER);
	Square2DView::window.addDisplayOption(Display::FreeGlut::DisplayMode::ALPHA_COLOUR_BUFFER);

	Square2DView::window.setDisplayFunc(Square2DView::display);
	Square2DView::window.setCloseFunc(Square2DView::close);
	Square2DView::window.setReshapeFunc(Square2DView::reshape);
	Square2DView::window.setCharKeyboardDownFunc(Square2DView::charPress);
	Square2DView::window.setMouseButtonFunc(Square2DView::mousePress);

	Square2DView::window.createWindow();
}

const std::vector<Display::FreeGlut::Colour>& Display::FreeGlut::Square2DView::getColours()
{
	return Square2DView::colours;
}

void Display::FreeGlut::Square2DView::setColours(const std::vector<Display::FreeGlut::Colour>& colours)
{
	Square2DView::colours = colours;
}

const Data::Grid& Display::FreeGlut::Square2DView::getGrid()
{
	return Square2DView::grid;
}

void Display::FreeGlut::Square2DView::setGrid(const Data::Grid& grid)
{
	Square2DView::grid = grid;
}

const Display::FreeGlut::Camera& Display::FreeGlut::Square2DView::getCamera()
{
	return Square2DView::camera;
}

void Display::FreeGlut::Square2DView::display()
{
	Data::Position<int> pos;
	unsigned int state;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT);
	Square2DView::colours[0].drawClearColour();

	Square2DView::camera.draw();
	
	for (int x = Square2DView::grid.getMinBound().getX(); x <= Square2DView::grid.getMaxBound().getX(); x++)
	{
		for (int y = Square2DView::grid.getMinBound().getY(); y <= Square2DView::grid.getMaxBound().getY(); y++)
		{
			pos = Data::Position<int>(x, y, 0);
			
			glPushMatrix();
			glTranslatef((float)pos.getX(), (float)pos.getY(), (float)pos.getZ());

			state = Square2DView::grid.getCellState(pos);
			if (state >= Square2DView::colours.size())
			{
				state = 0;
			}

			Square2DView::colours.at(state).drawColour();

			if (!Square2DView::cell_model.solidDisplayListExists())
			{
				Square2DView::cell_model.createSolidDisplayList();
			}
			Square2DView::cell_model.drawSolid();
			glPopMatrix();
		}
	}

	glutSwapBuffers();
}

void Display::FreeGlut::Square2DView::close()
{
	if (Square2DView::cell_model.solidDisplayListExists())
	{
		Square2DView::cell_model.destroySolidDisplayList();
	}
}

void Display::FreeGlut::Square2DView::charPress(unsigned char key, int, int)
{
	switch (std::tolower(key))
	{
	case Square2DView::EXIT:
		glutLeaveMainLoop();
		return;
	case Square2DView::SWITCH_VIEW:
		/** @todo Add view switch code.*/
		break;
	case Square2DView::MOVE_UP:
		Square2DView::camera.boomUp(Square2DView::MOVE_SPEED);
		break;
	case Square2DView::MOVE_DOWN:
		Square2DView::camera.boomUp(-Square2DView::MOVE_SPEED);
		break;
	case Square2DView::MOVE_LEFT:
		Square2DView::camera.dollyRight(-Square2DView::MOVE_SPEED);
		break;
	case Square2DView::MOVE_RIGHT:
		Square2DView::camera.dollyRight(Square2DView::MOVE_SPEED);
		break;
	}

	glutPostRedisplay();
}

void Display::FreeGlut::Square2DView::mousePress(Display::FreeGlut::MouseButton button, Display::FreeGlut::ButtonState state, int, int)
{
	switch (button)
	{
	case Square2DView::ZOOM_IN:
		Square2DView::camera.zoomIn(Square2DView::ZOOM_FAC);
		break;
	case Square2DView::ZOOM_OUT:
		Square2DView::camera.zoomIn(1 / Square2DView::ZOOM_FAC);
		break;
	}

	glutPostRedisplay();
}

void Display::FreeGlut::Square2DView::reshape(int w, int h)
{
	double dim;

	if (w <= 0)
	{
		w = 1;
	}
	if (h <= 0)
	{
		h = 1;
	}

	if (w < h)
	{
		dim = w;
	}
	else
	{
		dim = h;
	}

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-(double)w / dim, (double)w / dim, -(double)h / dim, (double)h / dim);

	glutPostRedisplay();
}
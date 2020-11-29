#include <GL/freeglut.h>
#include <string>
#include "glut_window.h"
#include "square_2d_view.h"

void reshape(int w, int h)
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
	gluOrtho2D(-(double)w/dim, (double)w/dim, -(double)h/dim, (double)h/dim);

	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	const std::string TITLE = "Cellular Automata";
	const int WIDTH = 500;
	const int HEIGHT = 500;
	const Data::Position<int> MIN = Data::Position<int>(-1, -1, 0);
	const Data::Position<int> MAX = Data::Position<int>(1, 1, 0);
	const Display::FreeGlut::Colour CLEAR = Display::FreeGlut::Colour(Data::Colour(0, 0, 0, 0));
	const Display::FreeGlut::Colour CELL = Display::FreeGlut::Colour(Data::Colour(1, 1, 1, 0));

	Display::FreeGlut::Window win = Display::FreeGlut::Window();
	Data::Grid grid = Data::Grid(MIN, MAX);
	for (int x = grid.getMinBound().getX(); x <= grid.getMaxBound().getX(); x++)
	{
		for (int y = grid.getMinBound().getY(); y <= grid.getMaxBound().getY(); y++)
		{
			grid.setCellState(Data::Position<int>(x, y, 0), 1);
		}
	}
	std::vector<Display::FreeGlut::Colour> colours = std::vector<Display::FreeGlut::Colour>({CLEAR, CELL});

	win.setTitle(TITLE);
	win.setWidth(WIDTH);
	win.setHeight(HEIGHT);
	win.setReshapeFunc(reshape);

	glutInit(&argc, argv);
	Display::FreeGlut::Square2DView::setWindow(win);
	Display::FreeGlut::Square2DView::setGrid(grid);
	Display::FreeGlut::Square2DView::setColours(colours);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
	glutMainLoop();

	return 0;
}
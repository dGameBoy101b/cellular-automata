#include <GL/freeglut.h>
#include <string>
#include "glut_window.h"
#include "square_2d_view.h"

int main(int argc, char** argv)
{
	const std::string TITLE = "Cellular Automata";
	const int WIDTH = 500;
	const int HEIGHT = 500;
	const Data::Position<int> MIN = Data::Position<int>(-2, -2, 0);
	const Data::Position<int> MAX = Data::Position<int>(1, 1, 0);
	const Display::FreeGlut::Colour CLEAR = Display::FreeGlut::Colour(Data::Colour(0, 0, 0, 0));
	const Display::FreeGlut::Colour CELL_OFF = Display::FreeGlut::Colour(Data::Colour(1, 0, 0, 0));
	const Display::FreeGlut::Colour CELL_ON = Display::FreeGlut::Colour(Data::Colour(0, 0, 1, 0));

	Display::FreeGlut::Window win = Display::FreeGlut::Window();
	Data::Grid grid = Data::Grid(MIN, MAX);
	unsigned int state;
	for (int x = grid.getMinBound().getX(); x <= grid.getMaxBound().getX(); x++)
	{
		for (int y = grid.getMinBound().getY(); y <= grid.getMaxBound().getY(); y++)
		{
			if (abs(x % 2) != abs(y % 2))
			{
				state = 1;
			}
			else
			{
				state = 2;
			}
			grid.setCellState(Data::Position<int>(x, y, 0), state);
		}
	}
	grid.updateAllCells();
	std::vector<Display::FreeGlut::Colour> colours = std::vector<Display::FreeGlut::Colour>({CLEAR, CELL_OFF, CELL_ON});

	win.setTitle(TITLE);
	win.setWidth(WIDTH);
	win.setHeight(HEIGHT);

	glutInit(&argc, argv);
	Display::FreeGlut::Square2DView::setWindow(win);
	Display::FreeGlut::Square2DView::setGrid(grid);
	Display::FreeGlut::Square2DView::setColours(colours);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
	glutMainLoop();

	return 0;
}
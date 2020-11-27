#include <GL/freeglut.h>
#include <string>
#include "glut_window.h"
#include "glut_colour.h"
#include "square_model.h"
#include "glut_model.h"

Display::FreeGlut::Model square = Display::FreeGlut::Model(Data::SquareModel::getModel());

void display()
{
	const Display::FreeGlut::Colour CLEAR_COLOUR = Display::FreeGlut::Colour(Data::Colour(1, .1f, 0, 1));
	const Display::FreeGlut::Colour FILL_COLOUR = Display::FreeGlut::Colour(Data::Colour(0, .3f, 1, 1));
	const Display::FreeGlut::Colour STROKE_COLOUR = Display::FreeGlut::Colour(Data::Colour(0, 0, 0, 1));
	const float STROKE_WIDTH = 5;

	CLEAR_COLOUR.drawClearColour();
	glClear(GL_COLOR_BUFFER_BIT);

	FILL_COLOUR.drawColour();
	square.drawSolid();
	
	STROKE_COLOUR.drawColour();
	glLineWidth(STROKE_WIDTH);
	square.drawWireframe();

	glutSwapBuffers();
}

void close()
{
	square.destroySolidDisplayList();
	square.destroyWireframeDisplayList();
}

int main(int argc, char** argv)
{
	const std::string TITLE = "Cellular Automata";
	const int WIDTH = 500;
	const int HEIGHT = 500;

	Display::FreeGlut::Window win = Display::FreeGlut::Window();

	win.setDisplayFunc(display);
	win.setCloseFunc(close);
	win.setTitle(TITLE);
	win.setWidth(WIDTH);
	win.setHeight(HEIGHT);
	win.addDisplayOption(Display::FreeGlut::DisplayMode::RGBA_COLOUR);
	win.addDisplayOption(Display::FreeGlut::DisplayMode::DOUBLE_BUFFER);

	glutInit(&argc, argv);
	win.createWindow();
	square.createSolidDisplayList();
	square.createWireframeDisplayList();

	glutMainLoop();

	return 0;
}
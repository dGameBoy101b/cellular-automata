#include <GL/freeglut.h>
#include <string>
#include "glut_window.h"
#include "glut_colour.h"
#include "square_model.h"
#include "glut_model.h"
#include "glut_camera.h"

Display::FreeGlut::Model square = Display::FreeGlut::Model(Data::SquareModel::getModel());
Display::FreeGlut::Camera cam = Display::FreeGlut::Camera();

void display()
{
	const Display::FreeGlut::Colour CLEAR_COLOUR = Display::FreeGlut::Colour(Data::Colour(1, .1f, 0, 1));
	const Display::FreeGlut::Colour FILL_COLOUR = Display::FreeGlut::Colour(Data::Colour(0, .3f, 1, 1));
	const Display::FreeGlut::Colour STROKE_COLOUR = Display::FreeGlut::Colour(Data::Colour(0, 0, 0, 1));
	const float STROKE_WIDTH = 5;
	const float SCALE = .7f;

	CLEAR_COLOUR.drawClearColour();
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glScalef(SCALE, SCALE, SCALE);

	cam.draw();

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

void specialPress(Display::FreeGlut::SpecialKeys key, int, int)
{
	const Display::FreeGlut::SpecialKeys LEFT = Display::FreeGlut::SpecialKeys::LEFT;
	const Display::FreeGlut::SpecialKeys RIGHT = Display::FreeGlut::SpecialKeys::RIGHT;
	const Display::FreeGlut::SpecialKeys UP = Display::FreeGlut::SpecialKeys::UP;
	const Display::FreeGlut::SpecialKeys DOWN = Display::FreeGlut::SpecialKeys::DOWN;
	const float SPEED = 1;

	Data::Position<float> pos;

	switch (key)
	{
	case LEFT:
		pos = Data::Position<float>(-SPEED, 0, 0);
		break;
	case RIGHT:
		pos = Data::Position<float>(SPEED, 0, 0);
		break;
	case UP:
		pos = Data::Position<float>(0, SPEED, 0);
		break;
	case DOWN:
		pos = Data::Position<float>(0, -SPEED, 0);
		break;
	}

	cam.setPos(cam.getPos() + pos);
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	const std::string TITLE = "Cellular Automata";
	const int WIDTH = 500;
	const int HEIGHT = 500;

	Display::FreeGlut::Window win = Display::FreeGlut::Window();

	win.setDisplayFunc(display);
	win.setCloseFunc(close);
	win.setSpecialKeyboardDownFunc(specialPress);
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
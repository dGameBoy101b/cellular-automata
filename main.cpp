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

void charPress(unsigned char key, int, int)
{
	const unsigned char EXIT = 27;
	const unsigned char RESET = ' ';
	const unsigned char ROLL_CW = 'e';
	const unsigned char ROLL_CCW = 'q';
	const unsigned char TILT_UP = 'w';
	const unsigned char TILT_DOWN = 's';
	const unsigned char PAN_LEFT = 'a';
	const unsigned char PAN_RIGHT = 'd';
	const unsigned char ZOOM_IN = 'z';
	const unsigned char ZOOM_OUT = 'x';
	const float TURN_SPEED = (float)acos(0) / 18.0f;
	const float ZOOM_SPEED = 1.1f;

	switch (std::tolower(key))
	{
	case EXIT:
		glutExit();
		return;
	case RESET:
		cam = Display::FreeGlut::Camera();
		break;
	case ROLL_CW:
		cam.rollCCW(-TURN_SPEED);
		break;
	case ROLL_CCW:
		cam.rollCCW(TURN_SPEED);
		break;
	case TILT_UP:
		cam.tiltUp(TURN_SPEED);
		break;
	case TILT_DOWN:
		cam.tiltUp(-TURN_SPEED);
		break;
	case PAN_LEFT:
		cam.panRight(-TURN_SPEED);
		break;
	case PAN_RIGHT:
		cam.panRight(TURN_SPEED);
		break;
	case ZOOM_IN:
		cam.zoomIn(ZOOM_SPEED);
		break;
	case ZOOM_OUT:
		cam.zoomIn(1.0f/ZOOM_SPEED);
		break;
	}

	glutPostRedisplay();
}

void specialPress(Display::FreeGlut::SpecialKeys key, int, int)
{
	const Display::FreeGlut::SpecialKeys LEFT = Display::FreeGlut::SpecialKeys::LEFT;
	const Display::FreeGlut::SpecialKeys RIGHT = Display::FreeGlut::SpecialKeys::RIGHT;
	const Display::FreeGlut::SpecialKeys UP = Display::FreeGlut::SpecialKeys::UP;
	const Display::FreeGlut::SpecialKeys DOWN = Display::FreeGlut::SpecialKeys::DOWN;
	const float SPEED = .1f;

	switch (key)
	{
	case LEFT:
		cam.dollyRight(-SPEED);
		break;
	case RIGHT:
		cam.dollyRight(SPEED);
		break;
	case UP:
		cam.boomUp(SPEED);
		break;
	case DOWN:
		cam.boomUp(-SPEED);
		break;
	}

	glutPostRedisplay();
}

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

	Display::FreeGlut::Window win = Display::FreeGlut::Window();

	win.setDisplayFunc(display);
	win.setCloseFunc(close);
	win.setReshapeFunc(reshape);
	win.setSpecialKeyboardDownFunc(specialPress);
	win.setCharKeyboardDownFunc(charPress);
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
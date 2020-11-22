#include "glut_window.h"

Display::FreeGlut::Window::Window()
{
	this->id = 0;
	this->x = -1;
	this->y = -1;
	this->width = 1;
	this->height = 1;
	this->title = "";
	this->displayFunc = nullptr;
	this->closeFunc = nullptr;
	this->idleFunc = nullptr;
	this->charKeyboardDownFunc = nullptr;
	this->specialKeyboardDownFunc = nullptr;
	this->reshapeFunc = nullptr;
	this->mouseButtonFunc = nullptr;
	this->mouseButtonMotionFunc = nullptr;
	this->mouseMotionFunc = nullptr;
	this->visibilityFunc = nullptr;
}

void Display::FreeGlut::Window::createWindow()
{
	if (this->exists())
	{
		throw Exceptions::WindowAlreadyCreated();
	}
	if (this->displayFunc == nullptr)
	{
		throw Exceptions::NoDisplayCallback();
	}

	this->setDimensions();
	this->id = glutCreateWindow(this->title.c_str());
	this->setCallbacks();
	this->getDimensions();
}

void Display::FreeGlut::Window::createSubWindow(int parent_id, int x, int y, int width, int height)
{
	if (this->exists())
	{
		throw Exceptions::WindowAlreadyCreated();
	}
	if (this->displayFunc == nullptr)
	{
		throw Exceptions::NoDisplayCallback();
	}
	if (parent_id < 1)
	{
		throw Exceptions::InvalidParentID();
	}

	this->id = glutCreateSubWindow(parent_id, x, y, width, height);
	this->setCallbacks();
	this->getDimensions();
}

void Display::FreeGlut::Window::destroyWindow()
{
	if (this->exists())
	{
		throw Exceptions::WindowAlreadyDestroyed();
	}

	glutDestroyWindow(this->id);
	this->id = 0;
}

Display::FreeGlut::Window::~Window()
{
	if (this->exists())
	{
		this->destroyWindow();
	}
}

bool Display::FreeGlut::Window::exists() const
{
	return this->id > 0;
}

int Display::FreeGlut::Window::getId() const
{
	return this->id;
}

int Display::FreeGlut::Window::getXPos() const
{
	return this->x;
}

void Display::FreeGlut::Window::setXPos(int x)
{
	this->x = x;
}

int Display::FreeGlut::Window::getYPos() const
{
	return this->y;
}

void Display::FreeGlut::Window::setYPos(int y)
{
	this->y = y;
}

int Display::FreeGlut::Window::getWidth() const
{
	return this->width;
}

void Display::FreeGlut::Window::setWidth(int width)
{
	if (width < 1)
	{
		throw Exceptions::NonPositiveSize();
	}

	this->width = width;
}

int Display::FreeGlut::Window::getHeight() const
{
	return this->height;
}

void Display::FreeGlut::Window::setHeight(int height)
{
	if (height < 1)
	{
		throw Exceptions::NonPositiveSize();
	}

	this->height = height;
}

const std::string Display::FreeGlut::Window::getTitle() const
{
	return this->title;
}

void Display::FreeGlut::Window::setTitle(const std::string title)
{
	this->title = title;
}

void(*Display::FreeGlut::Window::getCloseFunc() const)()
{
	return this->closeFunc;
}

void(*Display::FreeGlut::Window::getDisplayFunc() const)()
{
	return this->displayFunc;
}

void Display::FreeGlut::Window::setDisplayFunc(void(*func)())
{
	if (func == nullptr)
	{
		throw Exceptions::NoDisplayCallback();
	}

	this->displayFunc = func;
}

void(*Display::FreeGlut::Window::getIdleFunc() const)()
{
	return this->idleFunc;
}

void Display::FreeGlut::Window::setIdleFunc(void(*func)())
{
	this->idleFunc = func;
}

void(*Display::FreeGlut::Window::getReshapeFunc() const)(int, int)
{
	return this->reshapeFunc;
}

void Display::FreeGlut::Window::setReshapeFunc(void(*func)(int, int))
{
	this->reshapeFunc = func;
}

void(*Display::FreeGlut::Window::getCharKeyboardDownFunc() const)(unsigned char, int, int)
{
	return this->charKeyboardDownFunc;
}

void Display::FreeGlut::Window::setCharKeyboardDownFunc(void(*func)(unsigned char, int, int))
{
	this->charKeyboardDownFunc = func;
}

void(*Display::FreeGlut::Window::getSpecialKeyboardDownFunc() const)(SpecialKeys, int, int)
{
	return this->specialKeyboardDownFunc;
}

void Display::FreeGlut::Window::setSpecialKeyboardDownFunc(void(*func)(SpecialKeys, int, int))
{
	this->specialKeyboardDownFunc = func;
}

void(*Display::FreeGlut::Window::getMouseButtonFunc() const)(MouseButton, ButtonState, int, int)
{
	return this->mouseButtonFunc;
}

void Display::FreeGlut::Window::setMouseButtonFunc(void(*func)(MouseButton, ButtonState, int, int))
{
	this->mouseButtonFunc = func;
}

void(*Display::FreeGlut::Window::getMouseButtonMotionFunc() const)(int, int)
{
	return this->mouseButtonMotionFunc;
}

void Display::FreeGlut::Window::setMouseButtonMotionFunc(void(*func)(int, int))
{
	this->mouseButtonMotionFunc = func;
}

void(*Display::FreeGlut::Window::getMouseMotionFunc() const)(int, int)
{
	return this->mouseMotionFunc;
}

void Display::FreeGlut::Window::setMouseMotionFunc(void(*func)(int, int))
{
	this->mouseMotionFunc = func;
}

void Display::FreeGlut::Window::setCloseFunc(void(*func)())
{
	this->closeFunc = func;
}

void Display::FreeGlut::Window::setCallbacks()
{
	glutCloseFunc(this->closeFunc);
	glutDisplayFunc(this->displayFunc);
	glutReshapeFunc(this->reshapeFunc);
	glutKeyboardFunc(this->charKeyboardDownFunc);
	glutIdleFunc(this->idleFunc);
	glutMouseFunc((void(*)(int, int, int, int))this->mouseButtonFunc);
	glutMotionFunc(this->mouseButtonMotionFunc);
	glutPassiveMotionFunc(this->mouseMotionFunc);
	glutSpecialFunc((void(*)(int, int, int))this->specialKeyboardDownFunc);
	glutVisibilityFunc((void(*)(int))this->visibilityFunc);
	glutKeyboardUpFunc(this->charKeyboardUpFunc);
	glutSpecialUpFunc((void(*)(int, int, int))this->specialKeyboardUpFunc);
}

void Display::FreeGlut::Window::getDimensions()
{
	this->x = glutGet(GLUT_WINDOW_X);
	this->y = glutGet(GLUT_WINDOW_Y);
	this->width = glutGet(GLUT_WINDOW_WIDTH);
	this->height = glutGet(GLUT_WINDOW_HEIGHT);
}

void Display::FreeGlut::Window::setDimensions()
{
	if (this->width < 1
		|| this->height < 1)
	{
		throw Exceptions::NonPositiveSize();
	}

	glutInitWindowPosition(this->x, this->y);
	glutInitWindowSize(this->width, this->height);
}

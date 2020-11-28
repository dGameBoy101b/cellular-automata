#include "glut_camera.h"

Display::FreeGlut::Camera::Camera()
{
	this->pos = Data::Position<float>(0, 0, 0);
	this->dir = Data::Position<float>(0, 0, -1);
	this->up = Data::Position<float>(0, 1, 0);
}

const Data::Position<float>& Display::FreeGlut::Camera::getPos() const
{
	return this->pos;
}

void Display::FreeGlut::Camera::setPos(const Data::Position<float>& pos)
{
	this->pos = pos;
}

const Data::Position<float>& Display::FreeGlut::Camera::getDir() const
{
	return this->dir;
}

void Display::FreeGlut::Camera::setDir(Data::Position<float> dir)
{
	dir.normalise();
	this->dir = dir;
}

const Data::Position<float>& Display::FreeGlut::Camera::getUp() const
{
	return this->up;
}

void Display::FreeGlut::Camera::setUp(Data::Position<float> up)
{
	up.normalise();
	this->up = up;
}

void Display::FreeGlut::Camera::draw() const
{
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(this->pos.getX(),
		this->pos.getY(),
		this->pos.getZ(),
		this->pos.getX() + this->dir.getX(),
		this->pos.getY() + this->dir.getY(),
		this->pos.getZ() + this->dir.getZ(),
		this->up.getX(),
		this->up.getY(),
		this->up.getZ());
}

#include "glut_camera.h"

Display::FreeGlut::Camera::Camera()
{
	this->pos = Data::Position<float>(0, 0, 0);
	this->dir = Data::Position<float>(0, 0, -1);
	this->up = Data::Position<float>(0, 1, 0);
	this->zoom = 1;
}

const Data::Position<float>& Display::FreeGlut::Camera::getPos() const
{
	return this->pos;
}

void Display::FreeGlut::Camera::setPos(const Data::Position<float>& pos)
{
	this->pos = pos;
}

const Data::Position<float>& Display::FreeGlut::Camera::getForward() const
{
	return this->dir;
}

void Display::FreeGlut::Camera::setForward(Data::Position<float> dir)
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
	glScalef(this->zoom, this->zoom, this->zoom);
}

const Data::Position<float> Display::FreeGlut::Camera::calcRight() const
{
	Data::Position<float> right = this->dir.calcCrossProduct(this->up);
	right.normalise();
	return right;
}

void Display::FreeGlut::Camera::dollyRight(float dist)
{
	this->pos += this->calcRight() * dist;
}

void Display::FreeGlut::Camera::truckForward(float dist)
{
	this->pos += this->getForward() * dist;
}

void Display::FreeGlut::Camera::boomUp(float dist)
{
	this->pos += this->up * dist;
}

void Display::FreeGlut::Camera::panRight(float angle)
{
	this->dir = this->dir.calcRotation(this->up, angle);
}

void Display::FreeGlut::Camera::tiltUp(float angle)
{
	Data::Position<float> right = this->calcRight();

	this->up = this->up.calcRotation(right, angle);
	this->dir = this->dir.calcRotation(right, angle);
}

void Display::FreeGlut::Camera::rollCCW(float angle)
{
	this->up = this->up.calcRotation(this->dir, angle);
}

void Display::FreeGlut::Camera::zoomIn(float factor)
{
	if (factor <= 0)
	{
		throw Exceptions::NonPositiveZoomFactor();
	}
	this->zoom *= factor;
}

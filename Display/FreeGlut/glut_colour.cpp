#include "glut_colour.h"

Display::FreeGlut::Colour::Colour()
{
	this->colour = Data::Colour();
}

Display::FreeGlut::Colour::Colour(const Data::Colour& colour)
{
	this->colour = colour;
}

const Data::Colour& Display::FreeGlut::Colour::getColour() const
{
	return this->colour;
}

void Display::FreeGlut::Colour::setColour(const Data::Colour& colour)
{
	this->colour = colour;
}

void Display::FreeGlut::Colour::drawColour() const
{
	glColor4f(this->colour.getRed(),
		this->colour.getGreen(),
		this->colour.getBlue(),
		this->colour.getAlpha());
}

void Display::FreeGlut::Colour::drawClearColour() const
{
	glClearColor(this->colour.getRed(),
		this->colour.getGreen(),
		this->colour.getBlue(),
		this->colour.getAlpha());
}

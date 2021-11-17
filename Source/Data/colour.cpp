#include "colour.hpp"
#include <stdexcept>

Data::Colour::Colour(float r, float g, float b, float a)
{
    if (r < 0 || r > 1)
		throw std::invalid_argument("The red colour component must be between 0 and 1");
	if (g < 0 || g > 1)
		throw std::invalid_argument("The green colour component must be between 0 and 1");
	if (b < 0 || b > 1)
		throw std::invalid_argument("The blue colour component must be between 0 and 1");
	if (a < 0 || a > 1)
    {
        throw std::invalid_argument("The alpha colour component must be between 0 and 1");
    }

    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

float Data::Colour::getRed() const
{
    return this->r;
}

float Data::Colour::getGreen() const
{
    return this->g;
}

float Data::Colour::getBlue() const
{
    return this->b;
}

float Data::Colour::getAlpha() const
{
    return this->a;
}

void Data::Colour::setRed(float r)
{
    if (r < 0 || r > 1)
    {
        throw std::invalid_argument("The red colour component must be between 0 and 1");
    }

    this->r = r;
}

void Data::Colour::setGreen(float g)
{
    if (g < 0 || g > 1)
    {
        throw std::invalid_argument("The green colour component must be between 0 and 1");
    }

    this->g = g;
}

void Data::Colour::setBlue(float b)
{
    if (b < 0 || b > 1)
    {
        throw std::invalid_argument("The blue colour component must be between 0 and 1");
    }

    this->b = b;
}

void Data::Colour::setAlpha(float a)
{
    if (a < 0 || a > 0)
    {
        throw std::invalid_argument("The alpha colour component must be between 0 and 1");
    }

    this->a = a;
}

bool Data::Colour::operator==(const Colour& other) const
{
    return this->r == other.r
        && this->g == other.g
        && this->b == other.b
        && this->a == other.a;
}

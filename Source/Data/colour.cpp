#include "colour.hpp"
#include <stdexcept>

using namespace Data;

Colour::Colour(float r, float g, float b, float a)
{
    if (r < 0 || r > 1)
	{
		throw std::invalid_argument("The red colour component must be between 0 and 1");
	}
	if (g < 0 || g > 1)
	{
		throw std::invalid_argument("The green colour component must be between 0 and 1");
	}
	if (b < 0 || b > 1)
	{
		throw std::invalid_argument("The blue colour component must be between 0 and 1");
	}
	if (a < 0 || a > 1)
    {
        throw std::invalid_argument("The alpha colour component must be between 0 and 1");
    }

    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

float Colour::getRed() const
{
    return this->r;
}

float Colour::getGreen() const
{
    return this->g;
}

float Colour::getBlue() const
{
    return this->b;
}

float Colour::getAlpha() const
{
    return this->a;
}

void Colour::setRed(float r)
{
    if (r < 0 || r > 1)
    {
        throw std::invalid_argument("The red colour component must be between 0 and 1");
    }

    this->r = r;
}

void Colour::setGreen(float g)
{
    if (g < 0 || g > 1)
    {
        throw std::invalid_argument("The green colour component must be between 0 and 1");
    }

    this->g = g;
}

void Colour::setBlue(float b)
{
    if (b < 0 || b > 1)
    {
        throw std::invalid_argument("The blue colour component must be between 0 and 1");
    }

    this->b = b;
}

void Colour::setAlpha(float a)
{
    if (a < 0 || a > 1)
    {
        throw std::invalid_argument("The alpha colour component must be between 0 and 1");
    }

    this->a = a;
}

bool Colour::operator==(const Colour& other) const
{
    return this->r == other.r
        && this->g == other.g
        && this->b == other.b
        && this->a == other.a;
}

bool Colour::operator!=(const Colour& other) const
{
	return !(*this == other);
}

std::ostream& Data::operator<<(std::ostream& output, const Colour& col)
{
	return output << '(' << col.getRed() << "r," << col.getGreen() << "g," << col.getBlue() << "b," << col.getAlpha() << "a)";
}

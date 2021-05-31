#include "colour.h"

Data::Colour::Colour()
{
    this->r = 1;
    this->g = 1;
    this->b = 1;
    this->a = 1;
}

Data::Colour::Colour(float r, float g, float b, float a)
{
    if (r < 0
        || r > 1
        || g < 0
        || g > 1
        || b < 0
        || b > 1
        || a < 0
        || a > 1)
    {
        throw Exceptions::NonNormalColourComponent();
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
    if (r < 0
        || r > 1)
    {
        throw Exceptions::NonNormalColourComponent();
    }

    this->r = r;
}

void Data::Colour::setGreen(float g)
{
    if (g < 0
        || g > 1)
    {
        throw Exceptions::NonNormalColourComponent();
    }

    this->g = g;
}

void Data::Colour::setBlue(float b)
{
    if (b < 0
        || b > 1)
    {
        throw Exceptions::NonNormalColourComponent();
    }

    this->b = b;
}

void Data::Colour::setAlpha(float a)
{
    if (a < 0
        || a > 0)
    {
        throw Exceptions::NonNormalColourComponent();
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

#include "position.h"

Data::Position::Position()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Data::Position::Position(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

int Data::Position::getX() const
{
    return this->x;
}

int Data::Position::getY() const
{
    return this->y;
}

int Data::Position::getZ() const
{
    return this->z;
}

void Data::Position::setX(int x)
{
    this->x = x;
}

void Data::Position::setY(int y)
{
    this->y = y;
}

void Data::Position::setZ(int z)
{
    this->z = z;
}

bool Data::Position::operator==(const Position& other) const
{
    return this->x == other.x
        && this->y == other.y
        && this->z == other.z;
}


#include "position.h"

template<class numT>
Data::Position<numT>::Position()
{
    this->x = numT();
    this->y = numT();
    this->z = numT();
}

template<class numT>
Data::Position<numT>::Position(const numT& x, const numT& y, const numT& z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

template<class numT>
const numT& Data::Position<numT>::getX() const
{
    return this->x;
}

template<class numT>
const numT& Data::Position<numT>::getY() const
{
    return this->y;
}

template<class numT>
const numT& Data::Position<numT>::getZ() const
{
    return this->z;
}

template<class numT>
void Data::Position<numT>::setX(const numT& x)
{
    this->x = x;
}

template<class numT>
void Data::Position<numT>::setY(const numT& y)
{
    this->y = y;
}

template<class numT>
void Data::Position<numT>::setZ(const numT& z)
{
    this->z = z;
}

template<class numT>
bool Data::Position<numT>::operator==(const Position<numT>& other) const
{
    return this->x == other.x
        && this->y == other.y
        && this->z == other.z;
}

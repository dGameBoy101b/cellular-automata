#include "cell.h"

Data::Cell::Cell()
{
    this->pos = Position<int>();
    this->state = 0;
    this->next_state = 0;
}

Data::Cell::Cell(const Position<int>& pos, unsigned int state)
{
    this->pos = pos;
    this->state = state;
    this->next_state = 0;
}

const Data::Position<int>& Data::Cell::getPos() const
{
    return this->pos;
}

unsigned int Data::Cell::getState() const
{
    return this->state;
}

void Data::Cell::setPosition(const Position<int>& pos)
{
    this->pos = pos;
}

void Data::Cell::setState(unsigned int state)
{
    this->next_state = state;
}

void Data::Cell::updateState()
{
    this->state = this->next_state;
}

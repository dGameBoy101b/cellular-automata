#include "cell.hpp"

using namespace Data;

Cell::Cell(const Position<int>& pos, unsigned int state)
{
    this->pos = pos;
    this->state = state;
    this->next_state = state;
}

const Position<int>& Cell::getPosition() const
{
    return this->pos;
}

unsigned int Cell::getState() const
{
    return this->state;
}

void Cell::setPosition(const Position<int>& pos)
{
    this->pos = pos;
}

void Cell::setState(unsigned int state)
{
    this->next_state = state;
}

void Cell::updateState()
{
    this->state = this->next_state;
}

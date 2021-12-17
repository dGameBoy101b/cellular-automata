#include "cell.hpp"

using namespace Data;

Cell::Cell(const Position<int>& pos, unsigned int state)
{
    this->pos = pos;
    this->state = CellState(state);
}

const Position<int>& Cell::getPosition() const
{
    return this->pos;
}

unsigned int Cell::getState() const
{
    return this->state.getValue();
}

void Cell::setPosition(const Position<int>& pos)
{
    this->pos = pos;
}

void Cell::setState(unsigned int state)
{
    this->state.setValue(state);
}

void Cell::updateState()
{
    this->state.updateValue();
}

std::ostream& operator<<(std::ostream& output, const Data::Cell& cell)
{
	return output << '{' << cell.getPosition() << ',' << cell.getState() << '}';
}

bool Cell::operator==(const Cell& other) const
{
	return this->pos == other.pos
	&& this->state == other.state;
}

bool Cell::operator!=(const Cell& other) const
{
	return !(*this == other);
}

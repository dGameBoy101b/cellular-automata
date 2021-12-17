#include "cell_state.hpp"

using namespace Data;

CellState::CellState(unsigned int val)
{
	this->value = val;
	this->next_value = val;
}

unsigned int CellState::getValue() const
{
	return this->value;
}

void CellState::setValue(unsigned int val)
{
	this->next_value = val;
}

void CellState::updateValue()
{
	this->value = this->next_value;
}

bool CellState::operator==(const CellState& other) const
{
	return this->value == other.value;
}

bool CellState::operator!=(const CellState& other) const
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& output, const Data::CellState& state)
{
	return output << state.getValue();
}

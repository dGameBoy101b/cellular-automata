#include "colour_table.hpp"

using namespace CellularAutomata::Data;

ColourTable::ColourTable(const std::unordered_map<unsigned int, Colour>& colours)
{
	this->colours = colours;
}

const Colour& ColourTable::getColour(unsigned int state) const
{
	auto colour = this->colours.find(state);
	if (colour == this->colours.end())
	{
		throw std::invalid_argument("No colour mapping for given state");
	}
	return colour->second;
}

void ColourTable::setColour(unsigned int state, const Colour& colour)
{
	auto existing = this->colours.find(state);
	if (existing == this->colours.end())
	{
		this->colours.insert({state, colour});
	}
	else
	{
		existing->second = colour;
	}
}

const std::unordered_set<unsigned int> ColourTable::getStates() const
{
	std::unordered_set<unsigned int> states = {};
	for (auto it = this->colours.cbegin(); it != this->colours.cend(); ++it)
	{
		states.insert(it->first);
	}
	return states;
}

bool ColourTable::operator==(const ColourTable& other) const
{
	return this->colours == other.colours;
}

bool ColourTable::operator!=(const ColourTable& other) const
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& output, const CellularAutomata::Data::ColourTable& table)
{
	std::unordered_set<unsigned int> states = table.getStates();
	unsigned int len = states.size();
	output << '{';
	for (auto it = states.cbegin(); it != states.cend(); ++it)
	{
		output << *it << ": " << table.getColour(*it);
		if (--len > 0)
		{
			output << ", ";
		}
	}
	return output << '}';
}

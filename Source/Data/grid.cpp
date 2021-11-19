#include "grid.hpp"
#include <stdexcept>

using namespace Data;

Grid::Grid(const Bounds<int>& bounds)
{
    this->cells = std::vector<CellState>();
    this->setMinMaxBounds(bounds.getMin(), bounds.getMax());
}

const Bounds<int>& Grid::getBounds() const
{
    return this->bounds;
}

void Grid::setMinBound(const Position<int>& min)
{
    this->setMinMaxBounds(min, this->bounds.getMax());
}

void Grid::setMaxBound(const Position<int>& max)
{
    this->setMinMaxBounds(this->bounds.getMin(), max);
}

void Grid::setMinMaxBounds(const Position<int>& min, const Position<int>& max)
{
	Bounds<int> bounds = Bounds<int>(min, max);
	Bounds<int> copy_bounds = this->bounds.intersectWith(bounds);
	std::vector<CellState> cells = std::vector<CellState>();
	Position<int> pos = max - min + Position<int>(1, 1, 1);
	cells.reserve(pos.getX() * pos.getY() * pos.getZ());
	for (int x = min.getX(); x <= max.getX(); ++x)
	{
		for (int y = min.getY(); y <= max.getY(); ++y)
		{
			for (int z = min.getZ(); z <= max.getZ(); ++z)
			{
                pos = Position<int>(x, y, z);
                if (copy_bounds.isWithin(pos))
				{
					cells.push_back(this->cells.at(this->calcIndex(pos)));
				}
				else
				{
					cells.push_back(CellState());
				}
			}
		}
	}
	this->cells = cells;
	this->bounds = bounds;
}

unsigned int Grid::calcIndex(const Position<int>& pos) const
{
    if (!this->bounds.isWithin(pos))
    {
        throw std::invalid_argument("Out of bounds position on grid");
    }
	return pos.getX()
		* (this->bounds.getMax().getY() - this->bounds.getMin().getY())
		* (this->bounds.getMax().getZ() - this->bounds.getMin().getZ())
    + pos.getY()
		* (this->bounds.getMax().getZ() - this->bounds.getMin().getZ())
    + pos.getZ();
}

unsigned int Grid::getCellState(const Position<int>& pos) const
{
    return this->cells.at(this->calcIndex(pos)).getValue();
}

void Grid::setCellState(const Position<int>& pos, unsigned int state)
{
    this->cells.at(this->calcIndex(pos)).setValue(state);
}

void Grid::updateAllCells()
{
    for (auto it = this->cells.begin(); it != this->cells.end(); it++)
    {
        it->updateValue();
    }
}

bool Grid::operator==(const Grid& other) const
{
	if (this->bounds != other.bounds)
	{
		return false;
	}
	for (int x = this->bounds.getMin().getX(); x <= this->bounds.getMax().getX(); ++x)
	{
		for (int y = this->bounds.getMin().getY(); y <= this->bounds.getMax().getY(); ++y)
		{
			for (int z = this->bounds.getMin().getZ(); z <= this->bounds.getMax().getZ(); ++z)
			{
				if (this->getCellState(Position<int>(x, y, z)) != other.getCellState(Position<int>(x, y, z)))
				{
					return false;
				}
			}
		}
	}
	return true;
}

bool Grid::operator!=(const Grid& other) const
{
	return !(*this == other);
}

std::ostream& Data::operator<<(std::ostream& output, const Grid& grid)
{
	output << '{' << grid.getBounds() << ':';
	Position<int> pos;
	for (int x = grid.getBounds().getMin().getX(); x <= grid.getBounds().getMax().getX(); ++x)
	{
		for (int y = grid.getBounds().getMin().getY(); y <= grid.getBounds().getMax().getY(); ++y)
		{
			for (int z = grid.getBounds().getMin().getZ(); z <= grid.getBounds().getMax().getZ(); ++z)
			{
				pos = Position<int>(x, y, z);
				output << Cell(pos, grid.getCellState(pos));
				if (pos != grid.getBounds().getMax())
				{
					output << ',';
				}
			}
		}
	}
	return output << '}';
}

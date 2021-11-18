#include "grid.hpp"
#include <stdexcept>

using namespace Data;

Grid::Grid(const Position<int>& min_bound, const Position<int>& max_bound)
{
    this->cells = std::vector<Cell>();
    this->setMinMaxBounds(min_bound, max_bound);
}

const Position<int>& Grid::getMinBound() const
{
    return this->min_bound;
}

void Grid::setMinBound(const Position<int>& min)
{
    this->setMinMaxBounds(min, this->max_bound);
}

const Position<int>& Grid::getMaxBound() const
{
    return this->max_bound;
}

void Grid::setMaxBound(const Position<int>& max)
{
    this->setMinMaxBounds(this->min_bound, max);
}

void Grid::setMinMaxBounds(const Position<int>& min, const Position<int>& max)
{
	if (min.getX() > max.getX())
	{
		throw std::invalid_argument("Minimum bound X must not be greater than maximum bound X");
	}
	if (min.getY() > max.getY())
	{
		throw std::invalid_argument("Minimum bound Y must not be greater than maximum bound Y");
	}
	if (min.getZ() > max.getZ())
	{
		throw std::invalid_argument("Minimum bound Z must not be greater than maximum bound Z");
	}
    this->min_bound = min;
    this->max_bound = max;
    this->regenerate(this->cells);
}

unsigned int Grid::getCellState(const Position<int>& pos) const
{
    if (!this->withinBounds(pos))
    {
        throw std::invalid_argument("Out of bounds position on grid");
    }
    for (auto it = this->cells.cbegin(); it != this->cells.cend(); it++)
    {
        if (it->getPosition() == pos)
        {
            return it->getState();
        }
    }
}

void Grid::setCellState(const Position<int>& pos, unsigned int state)
{
    if (!this->withinBounds(pos))
    {
        throw std::invalid_argument("Out of bounds position on grid");
    }
    for (auto it = this->cells.begin(); it != this->cells.end(); it++)
    {
        if (it->getPosition() == pos)
        {
            it->setState(state);
            break;
        }
    }
}

void Grid::updateAllCells()
{
    for (auto it = this->cells.begin(); it != this->cells.end(); it++)
    {
        it->updateState();
    }
}

bool Grid::withinBounds(const Position<int>& pos) const
{
    return pos.getX() >= this->min_bound.getX()
        && pos.getX() <= this->max_bound.getX()
        && pos.getY() >= this->min_bound.getY()
        && pos.getY() <= this->max_bound.getY()
        && pos.getZ() >= this->min_bound.getZ()
        && pos.getZ() <= this->max_bound.getZ();
}

void Grid::regenerate(const std::vector<Cell> cells)
{
    Position<int> pos;
    bool found;

    this->cells = std::vector<Cell>();
    this->cells.reserve(
        (this->max_bound.getX() - this->min_bound.getX() + 1) *
        (this->max_bound.getY() - this->min_bound.getY() + 1) *
        (this->max_bound.getZ() - this->min_bound.getZ() + 1));

    for (int x = this->min_bound.getX(); x <= this->max_bound.getX(); x++)
    {
        for (int y = this->min_bound.getY(); y <= this->max_bound.getY(); y++)
        {
            for (int z = this->min_bound.getZ(); z <= this->max_bound.getZ(); z++)
            {
                pos = Position<int>(x, y, z);
                found = false;
                for (auto cell = cells.cbegin(); cell != cells.cend(); cell++)
                {
                    if (cell->getPosition() == pos)
                    {
                        this->cells.push_back(*cell);
                        found = true;
                    }
                }
                if (!found)
                {
                    this->cells.push_back(Cell(pos, 0));
                }
            }
        }
    }
}

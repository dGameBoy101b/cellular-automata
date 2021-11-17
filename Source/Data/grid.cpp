#include "grid.hpp"
#include <stdexcept>

Data::Grid::Grid()
{
    this->min_bound = Position<int>();
    this->max_bound = Position<int>();
    this->regenerate();
}

const Data::Position<int>& Data::Grid::getMinBound() const
{
    return this->min_bound;
}

void Data::Grid::setMinBound(const Position<int>& min)
{
    this->min_bound = min;
    this->correctBounds();

    this->regenerate(this->cells);
}

const Data::Position<int>& Data::Grid::getMaxBound() const
{
    return this->max_bound;
}

void Data::Grid::setMaxBound(const Position<int>& max)
{
    this->max_bound = max;
    this->correctBounds();

    this->regenerate(this->cells);
}

Data::Grid::Grid(const Position<int>& min_bound, const Position<int>& max_bound)
{
    this->min_bound = min_bound;
    this->max_bound = max_bound;
    this->correctBounds();

    this->regenerate();
}

unsigned int Data::Grid::getCellState(const Position<int>& pos) const
{
    if (!this->withinBounds(pos))
    {
        throw std::invalid_argument("Out of bounds position on grid");
    }

    for (std::vector<Cell>::const_iterator it = this->cells.begin(); it != this->cells.end(); it++)
    {
        if (it->getPos() == pos)
        {
            return it->getState();
        }
    }
    throw std::invalid_argument("Out of bounds position on grid");
}

void Data::Grid::setCellState(const Position<int>& pos, unsigned int state)
{
    for (std::vector<Cell>::iterator it = this->cells.begin(); it != this->cells.end(); it++)
    {
        if (it->getPos() == pos)
        {
            it->setState(state);
            break;
        }
    }
}

void Data::Grid::updateAllCells()
{
    for (std::vector<Cell>::iterator it = this->cells.begin(); it != this->cells.end(); it++)
    {
        it->updateState();
    }
}

bool Data::Grid::withinBounds(const Position<int>& pos) const
{
    return pos.getX() >= this->min_bound.getX()
        && pos.getX() <= this->max_bound.getX()
        && pos.getY() >= this->min_bound.getY()
        && pos.getY() <= this->max_bound.getY()
        && pos.getZ() >= this->min_bound.getZ()
        && pos.getZ() <= this->max_bound.getZ();
}

void Data::Grid::correctBounds()
{
    int temp;

    if (this->min_bound.getX() > this->max_bound.getX())
    {
        temp = this->min_bound.getX();
        this->min_bound.setX(this->max_bound.getX());
        this->max_bound.setX(temp);
    }

    if (this->min_bound.getY() > this->max_bound.getY())
    {
        temp = this->min_bound.getY();
        this->min_bound.setY(this->max_bound.getY());
        this->max_bound.setY(temp);
    }

    if (this->min_bound.getZ() > this->max_bound.getZ())
    {
        temp = this->min_bound.getZ();
        this->min_bound.setZ(this->max_bound.getZ());
        this->max_bound.setZ(temp);
    }
}

void Data::Grid::regenerate(const std::vector<Cell> cells)
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
                for (std::vector<Cell>::const_iterator cell = cells.begin(); cell != cells.end(); cell++)
                {
                    if (cell->getPos() == pos)
                    {
                        this->cells.push_back(*cell);
                        found = true;
                    }
                }
                if (!found)
                {
                    this->cells.push_back(Data::Cell(pos, 0));
                }
            }
        }
    }
}

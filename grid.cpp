#include "grid.h"

Data::Grid::Grid()
{
    this->min_bound = Position();
    this->max_bound = Position();
    this->cells = std::vector<Cell>();
}

Data::Grid::Grid(const Position& min_bound, const Position& max_bound, int state)
{
    this->min_bound = Position();
    this->max_bound = Position();

    if (min_bound.getX() > max_bound.getX())
    {
        this->min_bound.setX(max_bound.getX());
        this->max_bound.setX(min_bound.getX());
    }
    else
    {
        this->min_bound.setX(min_bound.getX());
        this->max_bound.setX(max_bound.getX());
    }
    
    if (min_bound.getY() > max_bound.getY())
    {
        this->min_bound.setY(max_bound.getY());
        this->max_bound.setY(min_bound.getY());
    }
    else
    {
        this->min_bound.setY(min_bound.getY());
        this->max_bound.setY(max_bound.getY());
    }

    if (min_bound.getZ() > max_bound.getZ())
    {
        this->min_bound.setZ(max_bound.getZ());
        this->max_bound.setZ(min_bound.getZ());
    }
    else
    {
        this->min_bound.setZ(min_bound.getZ());
        this->max_bound.setZ(max_bound.getZ());
    }

    this->cells = std::vector<Cell>(
        (this->max_bound.getX() - this->min_bound.getX() + 1) *
        (this->max_bound.getY() - this->min_bound.getY() + 1) *
        (this->max_bound.getZ() - this->min_bound.getZ() + 1));
    for (int x = this->min_bound.getX(); x < this->max_bound.getX(); x++)
    {
        for (int y = this->min_bound.getY(); y < this->max_bound.getY(); y++)
        {
            for (int z = this->min_bound.getZ(); z < this->max_bound.getZ(); z++)
            {
                this->cells.push_back(Cell(Position(x, y, z), state));
            }
        }
    }
}

const Data::Cell& Data::Grid::getCell(const Position& pos) const
{
    if (!this->withinBounds(pos))
    {
        throw Exceptions::OutOfBounds();
    }

    for (std::vector<Cell>::const_iterator it = this->cells.begin(); it != this->cells.end(); it++)
    {
        if (it->getPos() == pos)
        {
            return *it;
        }
    }
    throw Exceptions::OutOfBounds();
}

void Data::Grid::setCellState(const Position& pos, int state)
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

bool Data::Grid::withinBounds(const Position& pos) const
{
    return pos.getX() <= this->min_bound.getX()
        && pos.getX() >= this->max_bound.getX()
        && pos.getY() <= this->min_bound.getY()
        && pos.getY() >= this->max_bound.getY()
        && pos.getZ() <= this->min_bound.getZ()
        && pos.getZ() >= this->max_bound.getZ();
}

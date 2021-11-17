#include "grid_csv_loader.hpp"
#include <fstream>
#include <stdexcept>

using namespace FileIO;

const std::string GridCSVLoader::EXT = "csv";
const char GridCSVLoader::SEP = ',';
const char GridCSVLoader::END = '\n';

Data::Grid GridCSVLoader::load(const std::string& path)
{
    std::ifstream file;
    Data::Grid grid;
    Data::Position<int> pos;
    Data::Cell cell;
    int x, y, z;
    unsigned int s;
    char c;

    if (!this->checkExtension(path, GridCSVLoader::EXT))
    {
        throw std::invalid_argument("Unexpected file extension");
    }

    file.open(path, std::ios::in);
    if (!file.is_open())
    {
        throw std::invalid_argument("File not readable");
    }

    file >> x >> c;
    if (c != GridCSVLoader::SEP || !file.good())
	{
		throw std::invalid_argument("File format mismatch");
	}
    file >> y >> c;
    if (c != GridCSVLoader::SEP || !file.good())
	{
		throw std::invalid_argument("File format mismatch");
	}
    file >> z >> c;
    if (c != GridCSVLoader::SEP || !file.good())
	{
		throw std::invalid_argument("File format mismatch");
	}
	pos = Data::Position<int>(x, y, z);
    file >> x >> c;
    if (c != GridCSVLoader::SEP || !file.good())
	{
		throw std::invalid_argument("File format mismatch");
	}
    file >> y >> c;
    if (c != GridCSVLoader::SEP || !file.good())
	{
		throw std::invalid_argument("File format mismatch");
	}
    file >> z >> c;
    if (c != GridCSVLoader::END || !file.good())
	{
		throw std::invalid_argument("File format mismatch");
	}

    grid = Data::Grid(pos, Data::Position<int>(x, y, z));
    while (file.good())
    {
		file >> x >> c;
		if (c != GridCSVLoader::SEP || !file.good())
		{
			throw std::invalid_argument("File format mismatch");
		}
		file >> y >> c;
		if (c != GridCSVLoader::SEP || !file.good())
		{
			throw std::invalid_argument("File format mismatch");
		}
		file >> z >> c;
		if (c != GridCSVLoader::SEP || !file.good())
		{
			throw std::invalid_argument("File format mismatch");
		}
		file >> s >> c;
		if (c != GridCSVLoader::END || !file.good())
		{
			throw std::invalid_argument("File format mismatch");
		}
		grid.setCellState(Data::Position<int>(x, y, z), s);
    }

    file.close();
    grid.updateAllCells();
    return grid;
}

void GridCSVLoader::save(const std::string& path, const Data::Grid& grid)
{
    std::ofstream file;

    if (!this->checkExtension(path, GridCSVLoader::EXT))
    {
        throw std::invalid_argument("Unexpected file extension");
    }

    file.open(path, std::ios::out | std::ios::trunc);
    if (!file.is_open())
    {
        throw std::invalid_argument("File not writable");
    }

    file << grid.getMinBound().getX() << GridCSVLoader::SEP
    << grid.getMinBound().getY() << GridCSVLoader::SEP
    << grid.getMinBound().getZ() << GridCSVLoader::SEP
    << grid.getMaxBound().getX() << GridCSVLoader::SEP
    << grid.getMaxBound().getY() << GridCSVLoader::SEP
    << grid.getMaxBound().getZ() << GridCSVLoader::END;

    for (int x = grid.getMinBound().getX(); x <= grid.getMaxBound().getX(); x++)
    {
        for (int y = grid.getMinBound().getY(); y <= grid.getMaxBound().getY(); y++)
        {
            for (int z = grid.getMinBound().getZ(); z <= grid.getMaxBound().getZ(); z++)
            {
                if (grid.getCellState(Data::Position<int>(x, y, z)) > 0)
                {
                    file << x << GridCSVLoader::SEP
					<< y << GridCSVLoader::SEP
                    << z << GridCSVLoader::SEP
                    << grid.getCellState(Data::Position<int>(x, y, z)) << GridCSVLoader::END;
                }
            }
        }
    }
    file.close();
}

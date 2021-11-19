#include "grid_csv_loader.hpp"
#include "../Data/Bounds.hpp"
#include <fstream>
#include <stdexcept>
#include <sstream>

#include <iostream>

using namespace FileIO;

const std::string GridCSVLoader::EXT = "csv";
const char GridCSVLoader::SEP = ',';
const char GridCSVLoader::END = '\n';

void GridCSVLoader::formatError(std::ifstream& file, const std::string& part, const char expect, const char test)
{
    std::stringstream error;
    if (file.bad())
	{
		error << "Bad read of " << part;
		throw std::runtime_error(error.str());
	}
	if (file.fail() && file.eof())
	{
		file.clear(std::ios_base::iostate::_S_eofbit);
	}
    if (file.fail())
	{
		error << "Failed to read " << part;
		throw std::runtime_error(error.str());
	}
    if (test != expect || file.eof())
	{
		error << "Expected \'" << expect << "\' after " << part << " instead of \'";
		if (file.eof())
		{
			error << "EOF";
		}
		else
		{
			error << test;
		}
		error << '\'';
		throw std::runtime_error(error.str());
	}
}

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
    std::cout << x << '\'' << c << '\'' << std::endl;
    this->formatError(file, "minimum bound x", GridCSVLoader::SEP, c);
    file >> y >> c;
    std::cout << y << '\'' << c << '\'' << std::endl;
    this->formatError(file, "minimum bound y", GridCSVLoader::SEP, c);
    file >> z >> c;
    std::cout << z << '\'' << c << '\'' << std::endl;
    this->formatError(file, "minimum bound z", GridCSVLoader::SEP, c);
	pos = Data::Position<int>(x, y, z);
    file >> x >> c;
    std::cout << x << '\'' << c << '\'' << std::endl;
    this->formatError(file, "maximum bound x", GridCSVLoader::SEP, c);
    file >> y >> c;
    std::cout << y << '\'' << c << '\'' << std::endl;
    this->formatError(file, "maximum bound y", GridCSVLoader::SEP, c);
    file >> z >> c;
    std::cout << z << '\'' << c << '\'' << std::endl;
    this->formatError(file, "maximum bound z", GridCSVLoader::END, c); ///\fixme GridCSVLoader::load incorrectly skips over expected newline character

    grid = Data::Grid(Data::Bounds<int>(pos, Data::Position<int>(x, y, z)));
    while (file.good())
    {
		file >> x >> c;
		this->formatError(file, "cell x", GridCSVLoader::SEP, c);
		file >> y >> c;
		this->formatError(file, "cell y", GridCSVLoader::SEP, c);
		file >> z >> c;
		this->formatError(file, "cell z", GridCSVLoader::SEP, c);
		file >> s >> c;
		this->formatError(file, "cell state", GridCSVLoader::END, c);
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

    file << grid.getBounds().getMin().getX() << GridCSVLoader::SEP
    << grid.getBounds().getMin().getY() << GridCSVLoader::SEP
    << grid.getBounds().getMin().getZ() << GridCSVLoader::SEP
    << grid.getBounds().getMax().getX() << GridCSVLoader::SEP
    << grid.getBounds().getMax().getY() << GridCSVLoader::SEP
    << grid.getBounds().getMax().getZ() << GridCSVLoader::END;

    for (int x = grid.getBounds().getMin().getX(); x <= grid.getBounds().getMax().getX(); x++)
    {
        for (int y = grid.getBounds().getMin().getY(); y <= grid.getBounds().getMax().getY(); y++)
        {
            for (int z = grid.getBounds().getMin().getZ(); z <= grid.getBounds().getMax().getZ(); z++)
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

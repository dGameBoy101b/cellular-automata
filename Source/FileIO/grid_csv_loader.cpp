#include "grid_csv_loader.hpp"
#include <fstream>
#include <stdexcept>
#include <sstream>

using namespace CellularAutomata::FileIO;

template<> CellularAutomata::Data::Grid CSVLoader<CellularAutomata::Data::Grid>::load(std::ifstream& file)
{
    Data::Grid grid;
    Data::Position<int> pos;
    Data::Cell cell;
    int x, y, z;
    unsigned int s;
    char c;

    file >> x >> c;
    this->formatError(file, "minimum bound x", CSVLoader::SEP, c);
    file >> y >> c;
    this->formatError(file, "minimum bound y", CSVLoader::SEP, c);
    file >> z >> c;
    this->formatError(file, "minimum bound z", CSVLoader::SEP, c);
	pos = Data::Position<int>(x, y, z);
    file >> x >> c;
    this->formatError(file, "maximum bound x", CSVLoader::SEP, c);
    file >> y >> c;
    this->formatError(file, "maximum bound y", CSVLoader::SEP, c);
    file >> z >> c;
    this->formatError(file, "maximum bound z", CSVLoader::END, c);

    grid = Data::Grid(Data::Bounds<Data::Position<int>>(pos, Data::Position<int>(x, y, z)));
    while (file.good())
    {
		file >> x >> c;
		if (file.eof())
		{
			break;
		}
		this->formatError(file, "cell x", CSVLoader::SEP, c);
		file >> y >> c;
		this->formatError(file, "cell y", CSVLoader::SEP, c);
		file >> z >> c;
		this->formatError(file, "cell z", CSVLoader::SEP, c);
		file >> s >> c;
		this->formatError(file, "cell state", CSVLoader::END, c);
		grid.setCellState(Data::Position<int>(x, y, z), s);
    }

    grid.updateAllCells();
    return grid;
}

template<> void CSVLoader<CellularAutomata::Data::Grid>::save(std::ofstream& file, const CellularAutomata::Data::Grid& grid)
{
    file << grid.getBounds().getMin().getX() << CSVLoader::SEP
    << grid.getBounds().getMin().getY() << CSVLoader::SEP
    << grid.getBounds().getMin().getZ() << CSVLoader::SEP
    << grid.getBounds().getMax().getX() << CSVLoader::SEP
    << grid.getBounds().getMax().getY() << CSVLoader::SEP
    << grid.getBounds().getMax().getZ() << CSVLoader::END;

    for (int x = grid.getBounds().getMin().getX(); x <= grid.getBounds().getMax().getX(); x++)
    {
        for (int y = grid.getBounds().getMin().getY(); y <= grid.getBounds().getMax().getY(); y++)
        {
            for (int z = grid.getBounds().getMin().getZ(); z <= grid.getBounds().getMax().getZ(); z++)
            {
                if (grid.getCellState(Data::Position<int>(x, y, z)) > 0)
                {
                    file << x << CSVLoader::SEP
					<< y << CSVLoader::SEP
                    << z << CSVLoader::SEP
                    << grid.getCellState(Data::Position<int>(x, y, z)) << CSVLoader::END;
                }
            }
        }
    }
}

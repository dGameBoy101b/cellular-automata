#include "initial_state_file.h"

const std::string FileIO::InitialStateFile::EXT = ".init";
const char FileIO::InitialStateFile::END = '\n';
const char FileIO::InitialStateFile::SEP = ',';
const char FileIO::InitialStateFile::X = 'x';
const char FileIO::InitialStateFile::Y = 'y';
const char FileIO::InitialStateFile::Z = 'z';
const char FileIO::InitialStateFile::STATE = 's';

Data::Grid FileIO::InitialStateFile::load(const std::string& filename)
{
    std::ifstream file;
    Data::Grid grid;
    std::string str;
    Data::Position<int> min_bound;
    Data::Position<int> max_bound;
    Data::Cell cell;

    if (!InitialStateFile::checkExtension(filename))
    {
        throw Exceptions::UnexpectedExtension();
    }

    file.open(filename, std::ios::in);
    if (!file.is_open())
    {
        throw Exceptions::FileNotReadable();
    }

    std::getline(file, str, InitialStateFile::END);
    min_bound = InitialStateFile::parsePosition(str);

    std::getline(file, str, InitialStateFile::END);
    max_bound = InitialStateFile::parsePosition(str);

    grid = Data::Grid(min_bound, max_bound);
    while (file.good())
    {
        std::getline(file, str, InitialStateFile::END);
        cell = InitialStateFile::parseCell(str);
        grid.setCellState(cell.getPos(), cell.getState());
    }

    file.close();
    grid.updateAllCells();
    return grid;
}

void FileIO::InitialStateFile::save(const std::string& filename, const Data::Grid& grid)
{
    std::ofstream file;
    bool sep = false;

    if (!InitialStateFile::checkExtension(filename))
    {
        throw Exceptions::UnexpectedExtension();
    }

    file.open(filename, std::ios::out | std::ios::trunc);
    if (!file.is_open())
    {
        throw Exceptions::FileNotWritable();
    }

    if (grid.getMinBound().getX() != 0)
    {
        file << grid.getMinBound().getX() << InitialStateFile::X;
        sep = true;
    }
    if (grid.getMinBound().getY() != 0)
    {
        if (sep)
        {
            file << InitialStateFile::SEP;
        }
        file << grid.getMinBound().getY() << InitialStateFile::Y;
        sep = true;
    }
    if (grid.getMinBound().getZ() != 0)
    {
        if (sep)
        {
            file << InitialStateFile::SEP;
        }
        file << grid.getMinBound().getZ() << InitialStateFile::Z;
    }
    file << InitialStateFile::END;

    sep = false;
    if (grid.getMaxBound().getX() != 0)
    {
        file << grid.getMaxBound().getX() << InitialStateFile::X;
        sep = true;
    }
    if (grid.getMaxBound().getY() != 0)
    {
        if (sep)
        {
            file << InitialStateFile::SEP;
        }
        file << grid.getMaxBound().getY() << InitialStateFile::Y;
        sep = true;
    }
    if (grid.getMaxBound().getZ() != 0)
    {
        if (sep)
        {
            file << InitialStateFile::SEP;
        }
        file << grid.getMaxBound().getZ() << InitialStateFile::Z;
    }
    file << InitialStateFile::END;
    
    sep = false;
    for (int x = grid.getMinBound().getX(); x <= grid.getMaxBound().getX(); x++)
    {
        for (int y = grid.getMinBound().getY(); y <= grid.getMaxBound().getY(); y++)
        {
            for (int z = grid.getMinBound().getZ(); z <= grid.getMaxBound().getZ(); z++)
            {
                if (grid.getCellState(Data::Position<int>(x, y, z)) > 0)
                {
                    if (x != 0)
                    {
                        file << x << InitialStateFile::X;
                        sep = true;
                    }
                    if (y != 0)
                    {
                        if (sep)
                        {
                            file << InitialStateFile::SEP;
                        }
                        file << y << InitialStateFile::Y;
                        sep = true;
                    }
                    if (z != 0)
                    {
                        if (sep)
                        {
                            file << InitialStateFile::SEP;
                        }
                        file << z << InitialStateFile::Z;
                        sep = true;
                    }
                    if (sep)
                    {
                        file << InitialStateFile::SEP;
                    }
                    file << grid.getCellState(Data::Position<int>(x, y, z)) << InitialStateFile::STATE << InitialStateFile::END;
                }
            }
        }
    }
}

bool FileIO::InitialStateFile::checkExtension(const std::string& filename)
{
    return filename.length() >= InitialStateFile::EXT.length()
        && filename.substr(filename.length() - InitialStateFile::EXT.length(), 
            InitialStateFile::EXT.length()).compare(InitialStateFile::EXT) == 0;
}

const Data::Position<int> FileIO::InitialStateFile::parsePosition(const std::string& string)
{
    std::istringstream stream = std::istringstream(string, std::ios::in);
    std::string comp;
    Data::Position<int> pos = Data::Position<int>();

    while (stream.good())
    {
        std::getline(stream, comp, InitialStateFile::SEP);
        if (!stream.fail())
        {
            InitialStateFile::parsePosComponent(comp, pos);
        }
    }
    return pos;
}

void FileIO::InitialStateFile::parsePosComponent(const std::string& string, Data::Position<int>& pos)
{
    std::istringstream stream = std::istringstream(string, std::ios::in);
    int mag;
    char axis = '\0';

    stream >> mag;
    if (!stream.good())
    {
        throw Exceptions::PositionComponentFormatMismatch();
    }

    stream >> axis;
    switch (std::tolower(axis))
    {
    case InitialStateFile::X:
        pos.setX(mag);
        break;
    case InitialStateFile::Y:
        pos.setY(mag);
        break;
    case InitialStateFile::Z:
        pos.setZ(mag);
        break;
    default:
        throw Exceptions::UnrecognisedComponentSuffix();
    }
}

const Data::Cell FileIO::InitialStateFile::parseCell(const std::string& string)
{
    Data::Cell cell = Data::Cell();
    std::string comp;
    std::istringstream stream = std::istringstream(string, std::ios::in);

    while (stream.good())
    {
        std::getline(stream, comp, InitialStateFile::SEP);
        if (!stream.fail())
        {
            InitialStateFile::parseCellComponent(comp, cell);
        }
    }
    cell.updateState();
    return cell;
}

void FileIO::InitialStateFile::parseCellComponent(const std::string& string, Data::Cell& cell)
{
    std::istringstream stream = std::istringstream(string, std::ios::in);
    int mag;
    char suf = '\0';

    stream >> mag;
    if (!stream.good())
    {
        throw Exceptions::CellComponentFormatMismatch();
    }

    stream >> suf;
    switch (std::tolower(suf))
    {
    case InitialStateFile::X:
        cell.setPosition(Data::Position<int>(mag, cell.getPos().getY(), cell.getPos().getZ()));
        break;
    case InitialStateFile::Y:
        cell.setPosition(Data::Position<int>(cell.getPos().getX(), mag, cell.getPos().getZ()));
        break;
    case InitialStateFile::Z:
        cell.setPosition(Data::Position<int>(cell.getPos().getX(), cell.getPos().getY(), mag));
        break;
    case InitialStateFile::STATE:
        cell.setState(mag);
        break;
    default:
        throw Exceptions::UnrecognisedComponentSuffix();
    }
}

#include "colour_table_csv_loader.hpp"
#include <stdexcept>
#include <fstream>
#include <stdexcept>

using namespace FileIO;

const std::string ColourTableCSVLoader::EXT = "csv";
const char ColourTableCSVLoader::SEP = ',';
const char ColourTableCSVLoader::END = '\n';

std::vector<Data::Colour> ColourTableCSVLoader::load(const std::string& path)
{
	if (!this->checkExtension(path, ColourTableCSVLoader::EXT))
	{
		throw std::invalid_argument("Unsupported file extension");
	}

	std::ifstream file;
	file.open(path, std::ios::in);
	if (!file.is_open())
	{
		throw std::invalid_argument("File is unreadable");
	}

	float r, g, b, a;
	char c;
	std::vector<Data::Colour> data = std::vector<Data::Colour>();
	while (file.good())
	{
		file >> r >> c;
		if (!file.good() || c != ColourTableCSVLoader::SEP)
		{
			throw std::invalid_argument("File format mismatch");
		}
		file >> g >> c;
		if (!file.good() || c != ColourTableCSVLoader::SEP)
		{
			throw std::invalid_argument("File format mismatch");
		}
		file >> b >> c;
		if (!file.good() || c != ColourTableCSVLoader::SEP)
		{
			throw std::invalid_argument("File format mismatch");
		}
		file >> a >> c;
		if (!file.good() || c != ColourTableCSVLoader::END)
		{
			throw std::invalid_argument("File format mismatch");
		}
		data.push_back(Data::Colour(r, g, b, a));
	}

	file.close();
	return data;
}

void ColourTableCSVLoader::save(const std::string& path, const std::vector<Data::Colour>& data)
{
	if (!this->checkExtension(path, ColourTableCSVLoader::EXT))
	{
		throw std::invalid_argument("Unsupported file extension");
	}

	std::ofstream file;
	file.open(path, std::ios::trunc | std::ios::out);
	if (!file.is_open())
	{
		throw std::invalid_argument("File is unwrittable");
	}

	for (auto it = data.cbegin(); it != data.cend(); ++it)
	{
		file << it->getRed() << ColourTableCSVLoader::SEP
		<< it->getGreen() << ColourTableCSVLoader::SEP
		<< it->getBlue() << ColourTableCSVLoader::SEP
		<< it->getAlpha() << ColourTableCSVLoader::END;
		if (!file.good())
		{
			throw std::invalid_argument("File is unwrittable");
		}
	}
	file.close();
}

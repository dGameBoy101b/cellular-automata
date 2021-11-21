#include "colour_table_csv_loader.hpp"

using namespace FileIO;

template<> std::vector<Data::Colour> CSVLoader<std::vector<Data::Colour>>::load(std::ifstream& file)
{
	float r, g, b, a;
	char c;
	std::vector<Data::Colour> table = std::vector<Data::Colour>();
	while (file.good())
	{
		file >> r >> c;
		this->formatError(file, "red component", CSVLoader::SEP, c);
		file >> g >> c;
		this->formatError(file, "green component", CSVLoader::SEP, c);
		file >> b >> c;
		this->formatError(file, "blue component", CSVLoader::SEP, c);
		file >> a >> c;
		this->formatError(file, "alpha component", CSVLoader::SEP, c);
		table.push_back(Data::Colour(r, g, b, a));
	}
	return table;
}

template<> void CSVLoader<std::vector<Data::Colour>>::save(std::ofstream& file, const std::vector<Data::Colour>& table)
{
	for (auto it = table.cbegin(); it != table.cend(); ++it)
	{
		file << it->getRed() << CSVLoader::SEP
		<< it->getGreen() << CSVLoader::SEP
		<< it->getBlue() << CSVLoader::SEP
		<< it->getAlpha() << CSVLoader::END;
	}
}

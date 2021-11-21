#include "colour_table_csv_loader.hpp"

using namespace FileIO;

template<> Data::ColourTable CSVLoader<Data::ColourTable>::load(std::ifstream& file)
{
	float r, g, b, a;
	char c;
	Data::ColourTable table = {};
	unsigned int state;
	while (file.good())
	{
		file >> state >> c;
		if (file.eof())
		{
			break;
		}
		this->formatError(file, "state", CSVLoader::SEP, c);
		file >> r >> c;
		this->formatError(file, "red colour component", CSVLoader::SEP, c);
		file >> g >> c;
		this->formatError(file, "green colour component", CSVLoader::SEP, c);
		file >> b >> c;
		this->formatError(file, "blue colour component", CSVLoader::SEP, c);
		file >> a >> c;
		this->formatError(file, "alpha colour component", CSVLoader::END, c);
		table.setColour(state, Data::Colour(r, g, b, a));
	}
	return table;
}

template<> void CSVLoader<Data::ColourTable>::save(std::ofstream& file, const Data::ColourTable& table)
{
	std::unordered_set<unsigned int> states = table.getStates();
	Data::Colour colour;
	for (auto it = states.cbegin(); it != states.cend(); ++it)
	{
		colour = table.getColour(*it);
		file << *it << CSVLoader::SEP
		<< colour.getRed() << CSVLoader::SEP
		<< colour.getGreen() << CSVLoader::SEP
		<< colour.getBlue() << CSVLoader::SEP
		<< colour.getAlpha() << CSVLoader::END;
	}
}

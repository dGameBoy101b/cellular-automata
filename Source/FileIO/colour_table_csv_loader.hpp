#pragma once
#include "csv_loader.hpp"
#include "../Data/colour.hpp"
#include <vector>
#include <string>

namespace FileIO
{
	/** Load a colour table from the given open CSV file
	\param file The open CSV file to load from
	\return The loaded colour table
	\throw std::runtime_error Malformed data was encountered
	*/
	template<> std::vector<Data::Colour> CSVLoader<std::vector<Data::Colour>>::load(std::ifstream& file);
	/** Save the given colour table to the given open CSV file
	\param file The open CSV file to save to
	\param table The colour table to save
	*/
	template<> void CSVLoader<std::vector<Data::Colour>>::save(std::ofstream& file, const std::vector<Data::Colour>& table);
}

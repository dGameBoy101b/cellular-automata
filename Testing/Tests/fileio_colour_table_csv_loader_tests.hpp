#pragma once
#include <map>
#include <string>
#include <functional>

namespace Tests
{
	/** FileIO::CSVLoader<std::vector<Data::Colour>> unit tests */
	extern const std::map<std::string, std::function<void()>> FILEIO_COLOUR_TABLE_CSV_LOADER_TESTS;
}

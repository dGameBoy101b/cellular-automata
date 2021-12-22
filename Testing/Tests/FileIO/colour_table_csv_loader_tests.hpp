#pragma once
#include <map>
#include <string>
#include <functional>

namespace Tests
{
	namespace FileIO
	{
		/** FileIO::CSVLoader<std::vector<Data::Colour>> unit tests */
		extern const std::map<std::string, std::function<void()>> COLOUR_TABLE_CSV_LOADER_TESTS;
	}
}

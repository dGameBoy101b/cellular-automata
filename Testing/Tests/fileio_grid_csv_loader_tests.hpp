#pragma once
#include <map>
#include <string>
#include <functional>

namespace Tests
{
	/** Unit tests for FileIO::GridCSVLoader */
	extern const std::map<std::string, std::function<void()>> FILEIO_GRID_CSV_LOADER_TESTS;
}

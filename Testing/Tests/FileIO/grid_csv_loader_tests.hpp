#pragma once
#include <map>
#include <string>
#include <functional>

namespace Tests
{
	namespace FileIO
	{
		/** Unit tests for FileIO::GridCSVLoader */
		extern const std::map<std::string, std::function<void()>> GRID_CSV_LOADER_TESTS;
	}
}

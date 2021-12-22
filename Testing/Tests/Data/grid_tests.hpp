#pragma once
#include <map>
#include <string>
#include <functional>

namespace Tests
{
	namespace Data
	{
		/** Unit tests for Data::Grid */
		extern const std::map<std::string, std::function<void()>> GRID_TESTS;
	}
}

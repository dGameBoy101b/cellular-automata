#pragma once
#include <map>
#include <string>
#include <functional>

namespace Tests
{
	namespace Data
	{
		/** Unit tests for Data::Cell */
		extern const std::map<std::string, std::function<void()>> CELL_TESTS;
	}
}

#pragma once
#include <map>
#include <string>
#include <functional>

namespace Tests
{
	namespace Data
	{
		/** Data::CellState unit tests */
		extern const std::map<std::string, std::function<void()>> CELL_STATE_TESTS;
	}
}

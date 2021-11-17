#pragma once
#include <map>
#include <string>
#include <functional>

namespace Tests
{
	/** The unit tests for Data::Position */
	extern std::map<std::string, std::function<void()>> data_position_tests;
}

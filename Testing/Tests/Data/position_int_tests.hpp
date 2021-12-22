#pragma once
#include <map>
#include <string>
#include <functional>

namespace Tests
{
	namespace Data
	{
		/** The unit tests for Data::Position<int> */
		extern const std::map<std::string, std::function<void()>> POSITION_INT_TESTS;
	}
}

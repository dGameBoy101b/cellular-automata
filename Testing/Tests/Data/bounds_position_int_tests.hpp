#pragma once
#include <map>
#include <string>
#include <functional>

namespace Tests
{
	namespace Data
	{
		/** Unit tests for Data::Bounds<Data::Position<int>> */
		extern const std::map<std::string, std::function<void()>> BOUNDS_POSITION_INT_TESTS;
	}
}

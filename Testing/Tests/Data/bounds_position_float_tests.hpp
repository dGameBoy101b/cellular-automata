#pragma once
#include <map>
#include <string>
#include <functional>

namespace Tests
{
	namespace Data
	{
		/** Data::Bounds<Data::Position<float>> unit tests */
		extern const std::map<std::string, std::function<void()>> BOUNDS_POSITION_FLOAT_TESTS;
	}
}

#pragma once
#include <map>
#include <string>
#include <functional>

namespace Tests
{
	namespace Data
	{
		/** Unit tests for Data::Position<float> */
		extern const std::map<std::string, std::function<void()>> POSITION_FLOAT_TESTS;
	}
}

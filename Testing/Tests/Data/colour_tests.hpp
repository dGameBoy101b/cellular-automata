#pragma once
#include <map>
#include <string>
#include <functional>

namespace Tests
{
	namespace Data
	{
	/** The unit tests for Data::Colour */
	extern const std::map<std::string, std::function<void()>> COLOUR_TESTS;
	}
}

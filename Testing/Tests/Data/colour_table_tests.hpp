#pragma once
#include <map>
#include <string>
#include <functional>

namespace Tests
{
	namespace Data
	{
		/** Unit tests for Data::ColourTable */
		extern const std::map<std::string, std::function<void()>> COLOUR_TABLE_TESTS;
	}
}

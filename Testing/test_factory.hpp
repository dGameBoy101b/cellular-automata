#pragma once

#include "test_manager.hpp"
#include <functional>
#include <string>
#include <map>

namespace TestFramework
{
	/** A factory class for constructing many unit tests and adding them to test managers */
	class TestFactory
	{
	public:
		/** Constructor
		\param tests The map of unit test names and functions
		*/
		TestFactory(std::map<std::string, std::function<void()>> tests);
		/** Add tests to the given test manager
		\param manager The test manager to add tests to
		*/
		void addTests(TestManager& manager) const;
		/** Remove tests from the given manager
		\param manager The test manager to remove tests from
		*/
		void removeTests(TestManager& manager) const;
	private:
		/** The information used to construct unit tests (name and function) */
		std::map<std::string, std::function<void()>> tests;
	};
}

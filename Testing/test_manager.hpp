#pragma once
#include "unit_test.hpp"
#include <vector>
#include <string>
#include <stdexcept>

namespace TestFramework
{
	class TestManager
	{
	public:
		/** Run all the tests */
		void runAll(std::ostream& output);
		/** Add a test to the list
		\param test The test to add
		\throw std::invalid_argument The given test is already in the list
		*/
		void addTest(UnitTest test);
		/** Remove a test from the list
		\param test The test to remove
		\throw std::invalid_argument The given test is not in the list
		*/
		void removeTest(const std::string& name);
		/** Check if the given test is in the list
		\param test The test to search for
		\return True if the test is in the list
		*/
		bool hasTest(const std::string& name) const;
	private:
		/** The list of tests */
		std::vector<UnitTest> tests;
	};
}

#pragma once
#include <functional>
#include <string>
#include <exception>
#include <ostream>
#include "test_status.hpp"

namespace TestFramework
{
	/** Wrapper class to run unit tests */
	class UnitTest
	{
	public:
		/** Constructor
		\param func The function to run with this test
		\param name The name of this test
		*/
		UnitTest(const std::function<void()>& func, const std::string& name);
		/** Run the test and set the status accordingly */
		void run();
		/** Name getter
		\return The test name
		*/
		const std::string& getName() const;
		/** Status getter
		\return The current status
		*/
		TestStatus getStatus() const;
		/** Error message getter
		\return The message from the exception thrown when test was run
		\throw std::dmoain_error The test passed or has not been run
		*/
		const std::string& getErrorMessage() const;
	private:
		/** The name of the test */
		std::string name;
		/** The status of this test */
		TestStatus status;
		/** The explanation message of the error caught after running */
		std::string error_message;
		/** The function to run */
		std::function<void()> func;
	};
	std::ostream& operator<<(std::ostream& output, const UnitTest& test);
}

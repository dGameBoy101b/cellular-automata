#pragma once

namespace TestFramework
{
	/** An enumeration of the status */
	enum class TestStatus
	{
		NotRun, ///The test has yet to be run
		Error, ///The test threw an unexpected error
		Failed, ///The test failed an assertion
		Passed ///The test passed all assertions and threw no unexpected errors
	};
}

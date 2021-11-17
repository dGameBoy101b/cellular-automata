#include "test_manager.hpp"
#include "test_factory.hpp"
#include <iostream>
#include "Tests/data_position_tests.hpp"
#include "Tests/data_colour_tests.hpp"

using namespace TestFramework;

int main()
{
	TestManager tests = TestManager();

	TestFactory(Tests::DATA_POSITION_TESTS).addTests(tests);
	TestFactory(Tests::DATA_COLOUR_TESTS).addTests(tests);

	tests.runAll(std::cout);
	return 0;
}

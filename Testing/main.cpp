#include "test_manager.hpp"
#include "test_factory.hpp"
#include "Tests/data_position_tests.hpp"
#include <iostream>

using namespace TestFramework;

int main()
{
	TestManager tests = TestManager();

	TestFactory(Tests::data_position_tests).addTests(tests);

	tests.runAll(std::cout);
	return 0;
}

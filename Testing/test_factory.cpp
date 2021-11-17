#include "test_factory.hpp"
#include "unit_test.hpp"

using namespace TestFramework;

TestFactory::TestFactory(std::map<std::string, std::function<void()>> tests)
{
	this->tests = tests;
}

void TestFactory::addTests(TestManager& manager) const
{
	for (auto it = this->tests.cbegin(); it != this->tests.cend(); ++it)
	{
		manager.addTest(UnitTest(it->second, it->first));
	}
}

void TestFactory::removeTests(TestManager& manager) const
{
	for (auto it = this->tests.cbegin(); it != this->tests.cend(); ++it)
	{
		manager.removeTest(it->first);
	}
}

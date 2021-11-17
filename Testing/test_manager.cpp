#include "test_manager.hpp"
#include <ostream>

using namespace TestFramework;

void TestManager::runAll(std::ostream& output)
{
	unsigned int passes = 0;
	unsigned int errors = 0;
	unsigned int fails = 0;
	for (auto it = this->tests.begin(); it != this->tests.end(); ++it)
	{
		it->run();
		switch (it->getStatus())
		{
		case TestStatus::Passed:
			++passes;
			break;
		case TestStatus::Failed:
			++fails;
			break;
		case TestStatus::Error:
			++errors;
		}
		output << *it << std::endl;
	}
	output << this->tests.size() << " tests run: "
	<< passes << " passed; "
	<< fails << " failed; "
	<< errors << " errors" << std::endl;
}

void TestManager::addTest(UnitTest test)
{
	if (this->hasTest(test.getName()))
	{
		throw std::invalid_argument("Already has test");
	}
	this->tests.push_back(test);
}

void TestManager::removeTest(const std::string& name)
{
	for (auto it = this->tests.begin(); it != this->tests.end(); ++it)
	{
		if (it->getName() == name)
		{
			this->tests.erase(it);
			return;
		}
	}
	throw std::invalid_argument("Test not found");
}

bool TestManager::hasTest(const std::string& name) const
{
	for (auto it = this->tests.cbegin(); it != this->tests.cend(); ++it)
	{
		if (it->getName() == name)
		{
			return true;
		}
	}
	return false;
}

#include "unit_test.hpp"
#include "assertion.hpp"
#include <typeinfo>

#include <iostream>

using namespace TestFramework;

UnitTest::UnitTest(const std::function<void()>& func, const std::string& name)
{
	this->name = name;
	this->func = func;
	this->status = TestStatus::NotRun;
	this->error_message = "";
}

void UnitTest::run()
{
	try
	{
		this->func();
		this->status = TestStatus::Passed;
	}
	catch (const AssertionException& x)
	{
		this->status = TestStatus::Failed;
		this->error_message = x.what();
	}
	catch (const std::exception& x)
	{
		this->status = TestStatus::Error;
		this->error_message = x.what();
	}
}

const std::string& UnitTest::getName() const
{
	return this->name;
}

TestStatus UnitTest::getStatus() const
{
	return this->status;
}

const std::string& UnitTest::getErrorMessage() const
{
	switch (this->status)
	{
	case TestStatus::Error:
	case TestStatus::Failed:
		return this->error_message;
	default:
		throw std::domain_error("Passed or not run test does not have error");
	}
}

std::ostream& TestFramework::operator<<(std::ostream& output, const UnitTest& test)
{
	output << test.getName() << ": ";
	switch (test.getStatus())
	{
	case TestStatus::Passed:
		output << "Passed";
		break;
	case TestStatus::Failed:
		output << "Failed: " << test.getErrorMessage();
		break;
	case TestStatus::Error:
		output << "Error: " << test.getErrorMessage();
		break;
	default:
		output << "Not Run";
	}
	return output;
}

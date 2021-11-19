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

void UnitTest::run(std::ostream*const output)
{
	if (output != nullptr)
	{
		this->printPrefix(*output);
	}
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
	if (output != nullptr)
	{
		this->printSuffix(*output);
	}
}

void UnitTest::printPrefix(std::ostream& output) const
{
	output << this->name << ": ";
}

void UnitTest::printSuffix(std::ostream& output) const
{
	switch (this->status)
	{
	case TestStatus::Passed:
		output << "Passed";
		break;
	case TestStatus::Failed:
		output << "Failed: " << this->error_message;
		break;
	case TestStatus::Error:
		output << "Error: " << this->error_message;
		break;
	default:
		output << "Not Run";
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
	test.printPrefix(output);
	test.printSuffix(output);
	return output;
}

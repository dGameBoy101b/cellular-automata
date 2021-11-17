#include "assertion.hpp"

using namespace TestFramework;

AssertionException::AssertionException(const std::string& msg)
{
	this->msg = msg;
}

const char* AssertionException::what() const noexcept
{
	return this->msg.c_str();
}

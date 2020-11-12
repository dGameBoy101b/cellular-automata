#pragma once

#include <exception>

namespace FileIO
{
	namespace Exceptions
	{
		class UnexpectedExtension : std::exception
		{
		};
	}
}

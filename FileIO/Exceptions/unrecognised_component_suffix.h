#pragma once

#include <exception>
#include <string>

namespace FileIO
{
	namespace Exceptions
	{
		class UnrecognisedComponentSuffix : std::exception
		{
		};
	}
}

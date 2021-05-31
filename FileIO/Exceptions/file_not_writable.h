#pragma once

#include <exception>

namespace FileIO
{
	namespace Exceptions
	{
		class FileNotWritable : std::exception
		{
		};
	}
}

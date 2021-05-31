#pragma once

#include <exception>

namespace Display
{
	namespace FreeGlut
	{
		namespace Exceptions
		{
			class WindowAlreadyDestroyed : std::exception
			{

			};
		}
	}
}
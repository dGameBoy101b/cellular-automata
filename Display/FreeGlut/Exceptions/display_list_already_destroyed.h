#pragma once

#include <exception>

namespace Display
{
	namespace FreeGlut
	{
		namespace Exceptions
		{
			class DisplayListAlreadyDestroyed : std::exception
			{

			};
		}
	}
}

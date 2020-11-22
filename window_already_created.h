#pragma once

#include <exception>

namespace Display
{
	namespace FreeGlut
	{
		namespace Exceptions
		{
			class WindowAlreadyCreated : std::exception
			{

			};
		}
	}
}
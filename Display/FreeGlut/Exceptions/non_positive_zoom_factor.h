#pragma once

#include <exception>

namespace Display
{
	namespace FreeGlut
	{
		namespace Exceptions
		{
			class NonPositiveZoomFactor : std::exception
			{

			};
		}
	}
}
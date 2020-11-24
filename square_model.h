#pragma once

#include "model.h"

namespace Data
{
	class SquareModel
	{
	public:
		/**
		 * @brief Build a Model that is square.
		 * 
		 * @return A normalised Model that describes a square along the XY plane.
		 */
		static const Model getModel();
	};
}
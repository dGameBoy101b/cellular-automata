#pragma once

#include <GL/freeglut.h>
#include "colour.h"

namespace Display
{
	namespace FreeGlut
	{
		class Colour
		{
		public:
			/**
			 * @brief Default constructor.
			 * 
			 */
			Colour();
			/**
			 * @brief Initialiser constructor.
			 * 
			 * @param colour The underlying Data::Colour to initialise this Colour with.
			 */
			Colour(const Data::Colour& colour);
			/**
			 * @brief Get the underlying Data::Colour of this Colour.
			 * 
			 * @return The underlying Data::Colour.
			 */
			const Data::Colour& getColour() const;
			/**
			 * @brief Set the underlying Data::Colour of this Colour.
			 * 
			 * @param colour The new underlying Data::Colour.
			 */
			void setColour(const Data::Colour& colour);
			/**
			 * @brief Set the current glut colour to this Colour.
			 * 
			 */
			void drawColour() const;
			/**
			 * @brief Set the current clear colour to this Colour.
			 * 
			 */
			void drawClearColour() const;
		private:
			/**
			 * @brief The underlying Data::Colour.
			 */
			Data::Colour colour;
		};
	}
}
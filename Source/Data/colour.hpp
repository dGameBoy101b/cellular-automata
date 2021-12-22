#pragma once
#include <ostream>

namespace CellularAutomata
{
	namespace Data
	{
		class Colour
		{
		public:
			/** Initialise a new Colour object
			\param r The float red component between 0 and 1.
			\param g The float green component between 0 and 1.
			\param b The float blue component between 0 and 1.
			\param a The float alpha component between 0 and 1.
			\throw std::invalid_argument A given colour component was not between 0 and 1.
			*/
			Colour(float r = 1, float g = 1, float b = 1, float a = 1);
			/** Get the red component of this Colour.
			\return The float red component of this Colour.
			*/
			float getRed() const;
			/** Get the green component of this Colour.
			\return The float green component of this Colour.
			*/
			float getGreen() const;
			/** Get the blue component of this Colour.
			\return The float blue component of this Colour.
			*/
			float getBlue() const;
			/** Get the alpha component of this Colour.
			\return The float alpha component of this Colour.
			*/
			float getAlpha() const;
			/** Set the red component of this Colour to the given float.
			\param r The new float red component of this Colour between 0 and 1.
			*/
			void setRed(float r);
			/** brief Set the green component of this Colour to the given float.
			\param g The new float green component of this Colour between 0 and 1.
			\throw std::invalid_argument The given component was not between 0 and 1.
			*/
			void setGreen(float g);
			/** Set the blue component of this Colour to the given float.
			\param b The new float blue component of this Colour between 0 and 1.
			\throw std::invalid_argument The given component was not between 0 and 1.
			 */
			void setBlue(float b);
			/** Set the alpha component of this Colour to the given float.
			\param a The new float alpha component of this Colour between 0 and 1.
			\throw std::invalid_argument The given component was not between 0 and 1.
			*/
			void setAlpha(float a);
			/** Compare this Colour with another per component for equality.
			\param other The other Colour to compare this Colour to.
			\return true Each component pair are equal.
			\return false A component pair was not equal.
			*/
			bool operator==(const Colour& other) const;
			/** Compare this Colour with another per component for inequality.
			\param other The other Colour to compare this Colour to.
			\return true A component pair was not equal.
			\return false Each component pair are equal.
			*/
			bool operator!=(const Colour& other) const;
		private:
			/** The float red component between 0 and 1. */
			float r;
			/** The float green component between 0 and 1. */
			float g;
			/** The float blue component between 0 and 1. */
			float b;
			/** The float alpha component between 0 and 1. */
			float a;
		};
	}
}
/** Colour formatted stream insertion
\param output The output stream to insert into
\param col The colour to insert
\return The given output stream
*/
std::ostream& operator<<(std::ostream& output, const CellularAutomata::Data::Colour& col);

#pragma once

#include "non_normal_colour_component.h"

namespace Data
{
    class Colour
    {
    public:
        /**
         * @brief Construct a new white Colour object.
         *
         */
        Colour();
        /**
         * @brief Initialise a new Colour object
         *
         * @param r The float red component between 0 and 1.
         * @param g The float green component between 0 and 1.
         * @param b The float blue component between 0 and 1.
         * @param a The float alpha component between 0 and 1.
         * @throw NonNormalColourComponent A given colour component was not between 0 and 1.
         */
        Colour(float r, float g, float b, float a);
        /**
         * @brief Get the red component of this Colour.
         *
         * @return The float red component of this Colour.
         */
        float getRed() const;
        /**
         * @brief Get the green component of this Colour.
         *
         * @return The float green component of this Colour.
         */
        float getGreen() const;
        /**
         * @brief Get the blue component of this Colour.
         *
         * @return The float blue component of this Colour.
         */
        float getBlue() const;
        /**
         * @brief Get the alpha component of this Colour.
         *
         * @return The float alpha component of this Colour.
         */
        float getAlpha() const;
        /**
         * @brief Set the red component of this Colour to the given float.
         *
         * @param r The new float red component of this Colour between 0 and 1.
         */
        void setRed(float r);
        /**
         * @brief Set the green component of this Colour to the given float.
         *
         * @param g The new float green component of this Colour between 0 and 1.
         * @throw NonNormalColourComponent The given component was not between 0 and 1.
         */
        void setGreen(float g);
        /**
         * @brief Set the blue component of this Colour to the given float.
         *
         * @param b The new float blue component of this Colour between 0 and 1.
         * @throw NonNormalColourComponent The given component was not between 0 and 1.
         */
        void setBlue(float b);
        /**
         * @brief Set the alpha component of this Colour to the given float.
         *
         * @param a The new float alpha component of this Colour between 0 and 1.
         * @throw NonNormalColourComponent The given component was not between 0 and 1.
         */
        void setAlpha(float a);
        /**
         * @brief Compare this Colour with another per component for equality.
         *
         * @param other The other Colour to compare this Colour to.
         * @return true Each component pair are equal.
         * @return false A component pair was not equal.
         */
        bool operator==(const Colour& other) const;
    private:
        /**
         * @brief The float red component between 0 and 1.
         *
         */
        float r;
        /**
         * @brief The float green component between 0 and 1.
         *
         */
        float g;
        /**
         * @brief The float blue component between 0 and 1.
         *
         */
        float b;
        /**
         * @brief The float alpha component between 0 and 1.
         *
         */
        float a;
    };
}

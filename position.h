#pragma once

namespace Data
{
	class Position
	{
	public:
		/**
		 * @brief Construct a new Position object.
		 *
		 */
		Position();
		/**
		 * @brief Initialise a new Position object.
		 *
		 * @param x The integer position along the x axis.
		 * @param y The integer position along the y axis.
		 * @param z The integer position along the z axis.
		 */
		Position(int x, int y, int z);
		/**
		 * @brief Get the x coordinate.
		 *
		 * @return The integer position along the x axis.
		 */
		int getX() const;
		/**
		 * @brief Get the y coordinate.
		 *
		 * @return The integer position along the y axis.
		 */
		int getY() const;
		/**
		 * @brief Get the z coordinate.
		 *
		 * @return The integer position along the z axis.
		 */
		int getZ() const;
		/**
		 * @brief Set the x coordinate.
		 *
		 * @param x The new integer x coordinate.
		 */
		void setX(int x);
		/**
		 * @brief Set the y coordinate.
		 *
		 * @param y The new integer y coordinate.
		 */
		void setY(int y);
		/**
		 * @brief Set the z coordinate.
		 *
		 * @param z The new integer z coordinate.
		 */
		void setZ(int z);
		/**
		 * @brief Equality comparison.
		 *
		 * @param other The other Position to compare this Position with
		 * @return true If the positions on each axis are equal.
		 * @return false If any pair of coordinates are not equal.
		 */
		bool operator==(const Position& other) const;
	private:
		/**
		 * @brief The integer x coordinate of this Position.
		 *
		 */
		int x;
		/**
		 * @brief The integer y coordinate of this Position.
		 *
		 */
		int y;
		/**
		 * @brief The integer z coordinate of this Position.
		 *
		 */
		int z;
	};
}

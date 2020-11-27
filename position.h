#pragma once

namespace Data
{
	template<class numT>
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
		Position(const numT& x, const numT& y, const numT& z);
		/**
		 * @brief Get the x coordinate.
		 *
		 * @return The integer position along the x axis.
		 */
		const numT& getX() const;
		/**
		 * @brief Get the y coordinate.
		 *
		 * @return The integer position along the y axis.
		 */
		const numT& getY() const;
		/**
		 * @brief Get the z coordinate.
		 *
		 * @return The integer position along the z axis.
		 */
		const numT& getZ() const;
		/**
		 * @brief Set the x coordinate.
		 *
		 * @param x The new integer x coordinate.
		 */
		void setX(const numT& x);
		/**
		 * @brief Set the y coordinate.
		 *
		 * @param y The new integer y coordinate.
		 */
		void setY(const numT& y);
		/**
		 * @brief Set the z coordinate.
		 *
		 * @param z The new integer z coordinate.
		 */
		void setZ(const numT& z);
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
		numT x;
		/**
		 * @brief The integer y coordinate of this Position.
		 *
		 */
		numT y;
		/**
		 * @brief The integer z coordinate of this Position.
		 *
		 */
		numT z;
	};
}

template<class numT>
Data::Position<numT>::Position()
{
	this->x = numT();
	this->y = numT();
	this->z = numT();
}

template<class numT>
Data::Position<numT>::Position(const numT& x, const numT& y, const numT& z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

template<class numT>
const numT& Data::Position<numT>::getX() const
{
	return this->x;
}

template<class numT>
const numT& Data::Position<numT>::getY() const
{
	return this->y;
}

template<class numT>
const numT& Data::Position<numT>::getZ() const
{
	return this->z;
}

template<class numT>
void Data::Position<numT>::setX(const numT& x)
{
	this->x = x;
}

template<class numT>
void Data::Position<numT>::setY(const numT& y)
{
	this->y = y;
}

template<class numT>
void Data::Position<numT>::setZ(const numT& z)
{
	this->z = z;
}

template<class numT>
bool Data::Position<numT>::operator==(const Position<numT>& other) const
{
	return this->x == other.x
		&& this->y == other.y
		&& this->z == other.z;
}

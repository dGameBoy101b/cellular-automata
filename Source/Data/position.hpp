#pragma once

#include <cmath>
#include <ostream>

namespace Data
{
	template<class numT> class Position
	{
	public:
		/**
		 * @brief Initialise a new Position object.
		 *
		 * @param x The numT position along the x axis.
		 * @param y The numT position along the y axis.
		 * @param z The numT position along the z axis.
		 */
		Position(const numT& x = numT(), const numT& y = numT(), const numT& z = numT());
		/** Copy constructor
		\param <numU> The number type of the given Position
		\param other The other Position to copy
		*/
		template<class numU> Position(const Position<numU>& other);
		/**
		 * @brief Get the x coordinate.
		 *
		 * @return The numT position along the x axis.
		 */
		const numT& getX() const;
		/**
		 * @brief Get the y coordinate.
		 *
		 * @return The numT position along the y axis.
		 */
		const numT& getY() const;
		/**
		 * @brief Get the z coordinate.
		 *
		 * @return The numT position along the z axis.
		 */
		const numT& getZ() const;
		/**
		 * @brief Set the x coordinate.
		 *
		 * @param x The new numT x coordinate.
		 */
		void setX(const numT& x);
		/**
		 * @brief Set the y coordinate.
		 *
		 * @param y The new numT y coordinate.
		 */
		void setY(const numT& y);
		/**
		 * @brief Set the z coordinate.
		 *
		 * @param z The new numT z coordinate.
		 */
		void setZ(const numT& z);
		/**
		 * @brief Equality comparison.
		 *
		 * @param other The other Position to compare this Position with
		 * @return true If the positions on each axis are equal.
		 * @return false If any pair of coordinates are not equal.
		 */
		bool operator==(const Position<numT>& other) const;
		/**
		 * @brief Inequality comparison.
		 *
		 * @param other The other Position to compare this Position with
		 * @return true If the positions on each axis not equal.
		 * @return false If any pair of coordinates are equal.
		 */
		bool operator!=(const Position<numT>& other) const;
		/**
		 * @brief Add this Positon to the given Position.
		 * @param other The Position to add to this Position.
		 * @return The Position sum of this Position and the given Position.
		 */
		const Position<numT> operator+(const Position<numT>& other) const;
		/**
		 * @brief Multiply each component of this Position by the given number.
		 * @param other The number to multiply each component of this Position by.
		 * @return This Position scaled by the given number.
		 */
		const Position<numT> operator*(const numT& other) const;
		/**
		 * @brief Subtract the given Position from this Position.
		 * @param other The Positon to subtract from this Position.
		 * @return The difference between this Position and the given Position.
		 */
		const Position<numT> operator-(const Position<numT>& other) const;
		/**
		 * @brief Multiply this Position by -1.
		 * @return This Position multipled by -1.
		 */
		const Position<numT> operator-() const;
		/**
		 * @brief Divide each coponent of this Position by the given number.
		 * @param other The number to divide each component of this Position by.
		 * @return This Position scaled by the inverse of the given number.
		 * @throw Exceptions::DivideByZero The given number is zero.
		 */
		const Position<numT> operator/(const numT& other) const;
		/**
		 * @brief Add the given Position to this Position.
		 * @param other The Position to add to this Position.
		 */
		void operator+=(const Position<numT>& other);
		/**
		 * @brief Multiply each component of this Position by a given number.
		 * @param other The number to multiply each component of this Position by.
		 */
		void operator*=(const numT& other);
		/**
		 * @brief Subtract the given Position from this Position.
		 * @param other The Position to subtract from this Position.
		 */
		void operator-=(const Position<numT>& other);
		/**
		 * @brief Divide each component of this Position by the given number.
		 * @param other The number to divide each component of this Position by.
		 * @throw Exceptions::DivideByZero The given number is zero.
		 */
		void operator/=(const numT& other);
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
/** Position formatted stream insertion
\param output The output stream to insert into
\param obj The position object to insert
\return The given output stream
*/
template<class numT> std::ostream& operator<<(std::ostream& output, const Data::Position<numT>& obj);

namespace Data
{
	template<class numT> Position<numT>::Position(const numT& x, const numT& y, const numT& z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	template<class numT> template<class numU> Position<numT>::Position(const Position<numU>& other)
	{
		this->x = other.getX();
		this->y = other.getY();
		this->z = other.getZ();
	}

	template<class numT> const numT& Position<numT>::getX() const
	{
		return this->x;
	}

	template<class numT> const numT& Position<numT>::getY() const
	{
		return this->y;
	}

	template<class numT> const numT& Position<numT>::getZ() const
	{
		return this->z;
	}

	template<class numT> void Position<numT>::setX(const numT& x)
	{
		this->x = x;
	}

	template<class numT> void Position<numT>::setY(const numT& y)
	{
		this->y = y;
	}

	template<class numT> void Position<numT>::setZ(const numT& z)
	{
		this->z = z;
	}

	template<class numT> bool Position<numT>::operator==(const Position<numT>& other) const
	{
		return this->x == other.x
			&& this->y == other.y
			&& this->z == other.z;
	}

	template<class numT> bool Position<numT>::operator!=(const Position<numT>& other) const
	{
		return !(*this == other);
	}

	template<class numT> const Position<numT> Position<numT>::operator+(const Position<numT>& other) const
	{
		return Position<numT>(this->x + other.x, this->y + other.y, this->z + other.z);
	}

	template<class numT> const Position<numT> Position<numT>::operator*(const numT& other) const
	{
		return Position<numT>(this->x * other, this->y * other, this->z * other);
	}

	template<class numT> const Position<numT> Position<numT>::operator-(const Position<numT>& other) const
	{
		return Position<numT>(this->x - other.x, this->y - other.y, this->z - other.z);
	}

	template<class numT> const Position<numT> Position<numT>::operator-() const
	{
		return Position<numT>(-this->x, -this->y, -this->z);
	}

	template<class numT> const Position<numT> Position<numT>::operator/(const numT& other) const
	{
		return Position<numT>(this->x / other, this->y / other, this->z / other);
	}

	template<class numT> void Position<numT>::operator+=(const Position<numT>& other)
	{
		*this = *this + other;
	}

	template<class numT> void Position<numT>::operator*=(const numT& other)
	{
		*this = *this * other;
	}

	template<class numT> void Position<numT>::operator-=(const Position<numT>& other)
	{
		*this = *this - other;
	}

	template<class numT> void Position<numT>::operator/=(const numT& other)
	{
		*this = *this / other;
	}
}

template<class numT> std::ostream& operator<<(std::ostream& output, const Data::Position<numT>& obj)
{
	return output << '(' << obj.getX() << ',' << obj.getY() << ',' << obj.getZ() << ')';
}

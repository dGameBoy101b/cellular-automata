#pragma once

#include "divide_by_zero.h"

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
		 * @param x The numT position along the x axis.
		 * @param y The numT position along the y axis.
		 * @param z The numT position along the z axis.
		 */
		Position(const numT& x, const numT& y, const numT& z);
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
		/**
		 * @brief Calculate the vector magnitude of this Position.
		 * @return The double vector magnitude of this Position.
		 */
		double calcMagnitude() const;
		/**
		 * @brief Vector normalise this Position such that its magnitude is 1.
		 * @throw Exceptions::DivideByZero The calculated magnitude of this Position is 0.
		 */
		void normalise();
		/**
		 * @brief Calculate the vector dot product of this Position and the given Position.
		 * @param other The other Position to find the vector dot product of with this Position.
		 * @return The vector dot product of this Position and the given Position.
		 */
		double calcDotProduct(const Position<numT>& other) const;
		/**
		 * @brief Calculate the vector cross product of this Position and the given Position.
		 * @param other The other Position to find the vector cross product of with this Position.
		 * @return The vector cross product of this Position and the given Position.
		 */
		Position<numT> calcCrossProduct(const Position<numT>& other) const;
		/**
		 * @brief Calculate the rotation of this Positon about the given axis by the given angle.
		 * @param axis The Position unit vector about which to rotate this Position.
		 * @param angle The number of radians this Positon should be rotated by.
		 * @return This Position rotated about the given axis by the given angle.
		 */
		Position<numT> calcRotation(Position<numT> axis, const double& angle) const;
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

template<class numT>
double Data::Position<numT>::calcMagnitude() const
{
	return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

template<class numT>
void Data::Position<numT>::normalise()
{
	*this /= (numT)this->calcMagnitude();
}

template<class numT>
double Data::Position<numT>::calcDotProduct(const Position<numT>& other) const
{
	return this->x * other.x + this->y * other.y + this->z * other.z;
}

template<class numT>
Data::Position<numT> Data::Position<numT>::calcCrossProduct(const Position<numT>& other) const
{
	return Position<numT>(this->y * other.z - this->z * other.y,
		this->z * other.x - this->x * other.z,
		this->x * other.y - this->y * other.x);
}

template<class numT>
Data::Position<numT> Data::Position<numT>::calcRotation(Position<numT> axis, const double& angle) const
{
	axis.normalise();
	double c = cos(angle);
	double s = sin(angle);
	double C = 1 - c;
	double ax = axis.getX();
	double ay = axis.getY();
	double az = axis.getZ();
	double x = this->x;
	double y = this->y;
	double z = this->z;

	return Data::Position<numT>(
		x * (ax * ax * C + c) + y * (ax * ay * C - az * s) + z * (ax * az * C + ay * s),
		x * (ay * ax * C + az * s) + y * (ay * ay * C + c) + z * (ay * az * C - ax * s),
		x * (az * ax * C - ay * s) + y * (az * ay * C + ax * s) + z * (az * az * C + c));
}

template<class numT>
const Data::Position<numT> Data::Position<numT>::operator+(const Position<numT>& other) const
{
	return Data::Position<numT>(this->x + other.x, this->y + other.y, this->z + other.z);
}

template<class numT>
const Data::Position<numT> Data::Position<numT>::operator*(const numT& other) const
{
	return Position<numT>(this->x * other, this->y * other, this->z * other);
}

template<class numT>
const Data::Position<numT> Data::Position<numT>::operator-(const Position<numT>& other) const
{
	return Position<numT>(this->x - other.x, this->y - other.y, this->z - other.z);
}

template<class numT>
const Data::Position<numT> Data::Position<numT>::operator-() const
{
	return Position<numT>(-this->x, -this->y, -this->z);
}

template<class numT>
const Data::Position<numT> Data::Position<numT>::operator/(const numT& other) const
{
	return Position<numT>(this->x / other, this->y / other, this->z / other);
}

template<class numT>
void Data::Position<numT>::operator+=(const Position<numT>& other)
{
	*this = *this + other;
}

template<class numT>
void Data::Position<numT>::operator*=(const numT& other)
{
	*this = *this * other;
}

template<class numT>
void Data::Position<numT>::operator-=(const Position<numT>& other)
{
	*this = *this - other;
}

template<class numT>
void Data::Position<numT>::operator/=(const numT& other)
{
	*this = *this / other;
}

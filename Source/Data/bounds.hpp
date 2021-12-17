#pragma once
#include <ostream>
#include <stdexcept>
#include "position.hpp"

namespace Data
{
	template<class NumT> class Bounds
	{
	public:
		/** Constructor
		\param min The minimum bound
		\param max The maximum bound
		\throw std::invalid_argument The minimum is greater than the maximum
		*/
		Bounds<NumT>(const NumT& min = NumT(), const NumT& max = NumT());
		/** Minimum bound getter
		\return The minimum bound
		*/
		const NumT& getMin() const;
		/** Maximum bound getter
		\return The maximum bound
		*/
		const NumT& getMax() const;
		/** Minimum and maximum bounds setter
		\param min The minimum bound
		\param max The maximum bound
		\throw std::invalid_argument The minimum is greater than the maximum
		*/
		void setMinMax(const NumT& min, const NumT& max);
		/** Minimum bound setter
		\param min The minimum bound
		\throw std::invalid_argument The minimum is greater than the maximum
		*/
		void setMin(const NumT& min);
		/** Maximum bound setter
		\param max The maximum bound
		\throw std::invalid_argument The maximum is lesser than the minimum
		*/
		void setMax(const NumT& max);
		/** Bounds check given number
		\param num The number to test
		\return True if the given number is within these bounds
		\return False if the given number is not within these bounds
		*/
		bool isWithin(const NumT& num) const;
		/** Check if given Bounds overlaps with this
		\param other The other Bounds to compare with this
		\return True if this and given Bounds overlap at least one position
		\return False if this and given Bounds do not overlap any position
		*/
		bool doesOverlap(const Bounds<NumT>& other) const;
		/** Calculate bounds that encompasses both these bounds and the given bounds
		\param other The other Bounds to union with this
		\return Bounds that encompass this and the given bounds
		*/
		Bounds<NumT> unionWith(const Bounds<NumT>& other) const;
		/** Calculate bounds that are encompassed by this and the given bounds
		\param other The other Bounds to intersect with this
		\return Bounds that are encompassed by both this and the given bounds
		\throw std::range_error The given Bounds does not overlap this anywhere
		*/
		Bounds<NumT> intersectWith(const Bounds<NumT>& other) const;
		/** Equals operator
		\param other The other Bounds to compare with this
		\return True both the minimum and maximum bounds of this and the given bounds are equal
		\return False the minimum or the maximum bounds of this and the given bounds are not equal
		*/
		bool operator==(const Bounds<NumT>& other) const;
		/** Not equals operator
		\param other The other Bounds to compare with this
		\return True the minimum or the maximum bounds of this and the given bounds are not equal
		\return False both the minimum and maximum bounds of this and the given bounds are equal
		*/
		bool operator!=(const Bounds<NumT>& other) const;
	private:
		/** The minimum point */
		NumT min;
		/** The maximum point */
		NumT max;
	};
}
/** Bounds formetted stream insertion
\param output The output stream to insert into
\param bounds The Bounds to insert
\return The given output stream
*/
template<class NumT> std::ostream& operator<<(std::ostream& output, const Data::Bounds<NumT>& bounds);

namespace Data
{
	template<class NumT> Bounds<NumT>::Bounds(const NumT& min, const NumT& max)
	{
		this->setMinMax(min, max);
	}

	template<class NumT> const NumT& Bounds<NumT>::getMin() const
	{
		return this->min;
	}

	template<class NumT> const NumT& Bounds<NumT>::getMax() const
	{
		return this->max;
	}

	template<class NumT> void Bounds<NumT>::setMinMax(const NumT& min, const NumT& max)
	{
		if (min > max)
		{
			throw std::invalid_argument("Minimum bound must not be greater than maximum bound");
		}
		this->min = min;
		this->max = max;
	}

	template<class NumT> void Bounds<NumT>::setMin(const NumT& min)
	{
		this->setMinMax(min, this->max);
	}

	template<class NumT> void Bounds<NumT>::setMax(const NumT& max)
	{
		this->setMinMax(this->min, max);
	}

	template<class NumT> bool Bounds<NumT>::isWithin(const NumT& num) const
	{
		return num >= this->min
			&& num <= this->max;
	}

	template<class NumT> bool Bounds<NumT>::doesOverlap(const Bounds<NumT>& other) const
	{
		return this->min <= other.max
		&& this->max >= other.min;
	}

	template<class NumT> Bounds<NumT> Bounds<NumT>::unionWith(const Bounds<NumT>& other) const
	{
		return Bounds<NumT>(NumT(this->min > other.min ? other.min : this->min),
							 NumT(this->max < other.max ? other.max : this->max));
	}

	template<class NumT> Bounds<NumT> Bounds<NumT>::intersectWith(const Bounds<NumT>& other) const
	{
		if (!this->doesOverlap(other))
		{
			throw std::range_error("No intersection between bounds");
		}
		return Bounds<NumT>(NumT(this->min < other.min ? other.min : this->min),
							 NumT(this->max > other.max ? other.max : this->max));
	}

	template<class NumT> bool Bounds<NumT>::operator==(const Bounds<NumT>& other) const
	{
		return this->min == other.min
		&& this->max == other.max;
	}

	template<class NumT> bool Bounds<NumT>::operator!=(const Bounds<NumT>& other) const
	{
		return !(*this == other);
	}
}

template<class NumT> std::ostream& operator<<(std::ostream& output, const Data::Bounds<NumT>& bounds)
{
	return output << bounds.getMin() << ".." << bounds.getMax();
}

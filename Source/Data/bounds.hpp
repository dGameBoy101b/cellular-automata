#pragma once
#include <ostream>
#include <stdexcept>
#include "position.hpp"

namespace Data
{
	template<class numT> class Bounds
	{
	public:
		/** Constructor
		\param min The minimum bound
		\param max The maximum bound
		\throw std::invalid_argument A component of the minimum is greater then the corresponding maximum component
		*/
		Bounds<numT>(const Position<numT>& min = Position<numT>(), const Position<numT>& max = Position<numT>());
		/** Minimum bound getter
		\return The minimum bound
		*/
		const Position<numT>& getMin() const;
		/** Maximum bound getter
		\return The maximum bound
		*/
		const Position<numT>& getMax() const;
		/** Minimum and maximum bounds setter
		\param min The minimum bound
		\param max The maximum bound
		\throw std::invalid_argument A component of the minimum is greater then the corresponding maximum component
		*/
		void setMinMax(const Position<numT>& min, const Position<numT>& max);
		/** Minimum bound setter
		\param min The minimum bound
		\throw std::invalid_argument A component of the minimum is greater then the corresponding maximum component
		*/
		void setMin(const Position<numT>& min);
		/** Maximum bound setter
		\param max The maximum bound
		\throw std::invalid_argument A component of the maximum is lesser then the corresponding minimum component
		*/
		void setMax(const Position<numT>& max);
		/** Bounds check given position
		\param pos The Position to test
		\return True if the given position is within these bounds
		\return False if the given position is not within these bounds
		*/
		bool isWithin(const Position<numT>& pos) const;
		/** Check if given Bounds overlaps with this
		\param other The other Bounds to compare with this
		\return True if this and given Bounds overlap at least one position
		\return False if this and given Bounds do not overlap any position
		*/
		bool doesOverlap(const Bounds<numT>& other) const;
		/** Calculate bounds that encompasses both these bounds and the given bounds
		\param other The other Bounds to union with this
		\return Bounds that encompass this and the given bounds
		*/
		Bounds<numT> unionWith(const Bounds<numT>& other) const;
		/** Calculate bounds that are encompassed by this and the given bounds
		\param other The other Bounds to intersect with this
		\return Bounds that are encompassed by both this and the given bounds
		\throw std::range_error The given Bounds does not overlap this anywhere
		*/
		Bounds<numT> intersectWith(const Bounds<numT>& other) const;
		/** Equals operator
		\param other The other Bounds to compare with this
		\return True both the minimum and maximum bounds of this and the given bounds are equal
		\return False the minimum or the maximum bounds of this and the given bounds are not equal
		*/
		bool operator==(const Bounds<numT>& other) const;
		/** Not equals operator
		\param other The other Bounds to compare with this
		\return True the minimum or the maximum bounds of this and the given bounds are not equal
		\return False both the minimum and maximum bounds of this and the given bounds are equal
		*/
		bool operator!=(const Bounds<numT>& other) const;
	private:
		/** The minimum point */
		Position<numT> min;
		/** The maximum point */
		Position<numT> max;
	};
	/** Bounds formetted stream insertion
	\param output The output stream to insert into
	\param bounds The Bounds to insert
	\return The given output stream
	*/
	template<class numT> std::ostream& operator<<(std::ostream& output, const Bounds<numT>& bounds);

	template<class numT> Bounds<numT>::Bounds(const Position<numT>& min, const Position<numT>& max)
	{
		this->setMinMax(min, max);
	}

	template<class numT> const Position<numT>& Bounds<numT>::getMin() const
	{
		return this->min;
	}

	template<class numT> const Position<numT>& Bounds<numT>::getMax() const
	{
		return this->max;
	}

	template<class numT> void Bounds<numT>::setMinMax(const Position<numT>& min, const Position<numT>& max)
	{
		if (min.getX() > max.getX())
		{
			throw std::invalid_argument("Minimum bound X must not be greater than maximum bound X");
		}
		if (min.getY() > max.getY())
		{
			throw std::invalid_argument("Minimum bound Y must not be greater than maximum bound Y");
		}
		if (min.getZ() > max.getZ())
		{
			throw std::invalid_argument("Minimum bound Z must not be greater than maximum bound Z");
		}
		this->min = min;
		this->max = max;
	}

	template<class numT> void Bounds<numT>::setMin(const Position<numT>& min)
	{
		this->setMinMax(min, this->max);
	}

	template<class numT> void Bounds<numT>::setMax(const Position<numT>& max)
	{
		this->setMinMax(this->min, max);
	}

	template<class numT> bool Bounds<numT>::isWithin(const Position<numT>& pos) const
	{
		return pos.getX() >= this->min.getX()
			&& pos.getX() <= this->max.getX()
			&& pos.getY() >= this->min.getY()
			&& pos.getY() <= this->max.getY()
			&& pos.getZ() >= this->min.getZ()
			&& pos.getZ() <= this->max.getZ();
	}

	template<class numT> bool Bounds<numT>::doesOverlap(const Bounds<numT>& other) const
	{
		return this->min.getX() <= other.max.getX()
		&& this->min.getY() <= other.max.getY()
		&& this->min.getZ() <= other.max.getZ()
		&& this->max.getX() >= other.min.getX()
		&& this->max.getY() >= other.min.getY()
		&& this->max.getZ() >= other.min.getZ();
	}

	template<class numT> Bounds<numT> Bounds<numT>::unionWith(const Bounds<numT>& other) const
	{
		return Bounds<numT>(Position<numT>(this->min.getX() > other.min.getX() ? other.min.getX() : this->min.getX(),
											this->min.getY() > other.min.getY() ? other.min.getY() : this->min.getY(),
											this->min.getZ() > other.min.getZ() ? other.min.getZ() : this->min.getZ()),
							 Position<numT>(this->max.getX() < other.max.getX() ? other.max.getX() : this->max.getX(),
												this->max.getY() < other.max.getY() ? other.max.getY() : this->max.getY(),
												this->max.getZ() < other.max.getX() ? other.max.getZ() : this->max.getZ()));
	}

	template<class numT> Bounds<numT> Bounds<numT>::intersectWith(const Bounds<numT>& other) const
	{
		if (!this->doesOverlap(other))
		{
			throw std::range_error("No intersection between bounds");
		}
		return Bounds<numT>(Position<numT>(this->min.getX() < other.min.getX() ? other.min.getX() : this->min.getX(),
											this->min.getY() < other.min.getY() ? other.min.getY() : this->min.getY(),
											this->min.getZ() < other.min.getZ() ? other.min.getZ() : this->min.getZ()),
							 Position<numT>(this->max.getX() > other.max.getX() ? other.max.getX() : this->max.getX(),
												this->max.getY() > other.max.getY() ? other.max.getY() : this->max.getY(),
												this->max.getZ() > other.max.getX() ? other.max.getZ() : this->max.getZ()));
	}

	template<class numT> bool Bounds<numT>::operator==(const Bounds<numT>& other) const
	{
		return this->min == other.min
		&& this->max == other.max;
	}

	template<class numT> bool Bounds<numT>::operator!=(const Bounds<numT>& other) const
	{
		return !(*this == other);
	}

	template<class numT> std::ostream& operator<<(std::ostream& output, const Bounds<numT>& bounds)
	{
		return output << bounds.getMin() << ".." << bounds.getMax();
	}
}

#pragma once
#include "bounds.hpp"
#include "position.hpp"

namespace Data
{
	template<> template<class NumU> class Bounds<Position<NumU>>
	{
	public:
		/** Constructor
		\param min The minimum bound
		\param max The maximum bound
		\throw std::invalid_argument The minimum is greater than the maximum
		*/
		Bounds<Position<NumU>>(const Position<NumU>& min = {}, const Position<NumU>& max = {});
		/** Minimum bound getter
		\return The minimum bound
		*/
		const Position<NumU>& getMin() const;
		/** Maximum bound getter
		\return The maximum bound
		*/
		const Position<NumU>& getMax() const;
		/** Minimum bound setter
		\param min The minimum bound
		\throw std::invalid_argument The minimum is greater than the maximum
		*/
		void setMin(const Position<NumU>& min);
		/** Maximum bound setter
		\param max The maximum bound
		\throw std::invalid_argument The maximum is lesser than the minimum
		*/
		void setMax(const Position<NumU>& max);
		/** Equals operator
		\param other The other Bounds to compare with this
		\return True both the minimum and maximum bounds of this and the given bounds are equal
		\return False the minimum or the maximum bounds of this and the given bounds are not equal
		*/
		bool operator==(const Bounds<Position<NumU>>& other) const;
		/** Not equals operator
		\param other The other Bounds to compare with this
		\return True the minimum or the maximum bounds of this and the given bounds are not equal
		\return False both the minimum and maximum bounds of this and the given bounds are equal
		*/
		bool operator!=(const Bounds<Position<NumU>>& other) const;
		/** Minimum and maximum bounds setter
		\param min The minimum bound
		\param max The maximum bound
		\throw std::invalid_argument A component of the minimum is greater than the corresponding maximum component
		*/
		void setMinMax(const Position<NumU>& min, const Position<NumU>& max);
		/** Bounds check given position
		\param pos The Position to test
		\return True if the given position is within these bounds
		\return False if the given position is not within these bounds
		*/
		bool isWithin(const Position<NumU>& pos) const;
		/** Check if given Bounds overlaps with this
		\param other The other Bounds to compare with this
		\return True if this and given Bounds overlap at least one position
		\return False if this and given Bounds do not overlap any position
		*/
		bool doesOverlap(const Bounds<Position<NumU>>& other) const;
		/** Calculate bounds that encompasses both these bounds and the given bounds
		\param other The other Bounds to union with this
		\return Bounds that encompass this and the given bounds
		*/
		Bounds<Position<NumU>> unionWith(const Bounds<Position<NumU>>& other) const;
		/** Calculate bounds that are encompassed by this and the given bounds
		\param other The other Bounds to intersect with this
		\return Bounds that are encompassed by both this and the given bounds
		\throw std::range_error The given Bounds does not overlap this anywhere
		*/
		Bounds<Position<NumU>> intersectWith(const Bounds<Position<NumU>>& other) const;
	private:
		Position<NumU> min;
		Position<NumU> max;
	};
}
/** Bounds formetted stream insertion
\param output The output stream to insert into
\param bounds The Bounds to insert
\return The given output stream
*/
template<class NumU> std::ostream& operator<<(std::ostream& output, const Data::Bounds<Data::Position<NumU>>& bounds);

namespace Data
{
	template<> template<class NumU> void Bounds<Position<NumU>>::setMinMax(const Position<NumU>& min, const Position<NumU>& max)
	{
		if (min.getX() > max.getX())
		{
			throw std::invalid_argument("X component of minimum bounds must not be greater than x component of maximum bounds");
		}
		if (min.getY() > max.getY())
		{
			throw std::invalid_argument("Y component of minimum bounds must not be greater than y component of maximum bounds");
		}
		if (min.getZ() > max.getZ())
		{
			throw std::invalid_argument("Z component of minimum bounds must not be greater than z component of maximum bounds");
		}
		this->min = min;
		this->max = max;
	}

	template<> template<class NumU> bool Bounds<Position<NumU>>::isWithin(const Position<NumU>& pos) const
	{
		return pos.getX() >= this->min.getX()
		&& pos.getX() <= this->max.getX()
		&& pos.getY() >= this->min.getY()
		&& pos.getY() <= this->max.getY()
		&& pos.getZ() >= this->min.getZ()
		&& pos.getZ() <= this->max.getZ();
	}

	template<> template<class NumU> bool Bounds<Position<NumU>>::doesOverlap(const Bounds<Position<NumU>>& other) const
	{
		return other.max.getX() >= this->min.getX()
		&& other.min.getX() <= this->max.getX()
		&& other.max.getY() >= this->min.getY()
		&& other.min.getY() <= this->max.getY()
		&& other.max.getZ() >= this->min.getZ()
		&& other.min.getZ() <= this->max.getZ();
	}

	template<> template<class NumU> Bounds<Position<NumU>> Bounds<Position<NumU>>::unionWith(const Bounds<Position<NumU>>& other) const
	{
		return Bounds<Position<NumU>>(Position<NumU>(this->min.getX() > other.min.getX() ? other.min.getX() : this->min.getX(),
													this->min.getY() > other.min.getY() ? other.min.getY() : this->min.getY(),
													this->min.getZ() > other.min.getZ() ? other.min.getZ() : this->min.getZ()),
							 Position<NumU>(this->max.getX() < other.max.getX() ? other.max.getX() : this->max.getX(),
												this->max.getY() < other.max.getY() ? other.max.getY() : this->max.getY(),
												this->max.getZ() < other.max.getZ() ? other.max.getZ() : this->max.getZ()));
	}

	template<> template<class NumU> Bounds<Position<NumU>> Bounds<Position<NumU>>::intersectWith(const Bounds<Position<NumU>>& other) const
	{
		if (!this->doesOverlap(other))
		{
			throw std::range_error("No intersection between bounds");
		}
		return Bounds<Position<NumU>>(Position<NumU>(this->min.getX() < other.min.getX() ? other.min.getX() : this->min.getX(),
											this->min.getY() < other.min.getY() ? other.min.getY() : this->min.getY(),
											this->min.getZ() < other.min.getZ() ? other.min.getZ() : this->min.getZ()),
							 Position<NumU>(this->max.getX() > other.max.getX() ? other.max.getX() : this->max.getX(),
												this->max.getY() > other.max.getY() ? other.max.getY() : this->max.getY(),
												this->max.getZ() > other.max.getZ() ? other.max.getZ() : this->max.getZ()));
	}

	template<> template<class NumU> Bounds<Position<NumU>>::Bounds(const Position<NumU>& min, const Position<NumU>& max)
	{
		this->setMinMax(min, max);
	}

	template<> template<class NumU> const Position<NumU>& Bounds<Position<NumU>>::getMin() const
	{
		return this->min;
	}

	template<> template<class NumU> const Position<NumU>& Bounds<Position<NumU>>::getMax() const
	{
		return this->max;
	}

	template<> template<class NumU> void Bounds<Position<NumU>>::setMin(const Position<NumU>& min)
	{
		this->setMinMax(min, this->max);
	}

	template<> template<class NumU> void Bounds<Position<NumU>>::setMax(const Position<NumU>& max)
	{
		this->setMinMax(this->min, max);
	}

	template<> template<class NumU> bool Bounds<Position<NumU>>::operator==(const Bounds<Position<NumU>>& other) const
	{
		return this->min == other.min
		&& this->max == other.max;
	}

	template<> template<class NumU> bool Bounds<Position<NumU>>::operator!=(const Bounds<Position<NumU>>& other) const
	{
		return !(*this == other);
	}
}

template<class NumU> std::ostream& operator<<(std::ostream& output, const Data::Bounds<Data::Position<NumU>>& bounds)
{
	return output << bounds.getMin() << ".." << bounds.getMax();
}

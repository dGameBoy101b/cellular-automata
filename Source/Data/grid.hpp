#pragma once

#include "position.hpp"
#include "cell.hpp"
#include "cell_state.hpp"
#include "bounds.hpp"
#include <vector>

namespace Data
{
	class Grid
	{
	public:
		/** Construct a new Grid object with the given bounds.
		\param bounds The bounds of this Grid.
		 */
		Grid(const Bounds<int>& bounds = Bounds<int>());
		/** Get the bounds of this Grid
		\return The bounds of this Grid
		*/
		const Bounds<int>& getBounds() const;
		/** Set the minimum bounds of this Grid.
		\param min The Position of the new minimum bound of this Grid.
		\throw std::invalid_argument A component of the given minimum is greater than the corresponding maximum component
		\warning Triggers a cell regeneration
		*/
		void setMinBound(const Position<int>& min);
		/** Set the maximum bounds of this Grid.
		\param max The Position of the new maximum bound of this Grid.
		\throw std::invalid_argument A component of the given maximum is lesser than the corresponding minimum component
		\warning Triggers a cell regeneration
		*/
		void setMaxBound(const Position<int>& max);
		/** Set both the minimu and maximum bounds of this Grid
		\param min The new minimum bounds
		\param max The new maximum bounds
		\throw std::invalid_argument A component of the given minimum is greater than the corresponding maximum component
		\warning Triggers a cell regeneration
		*/
		void setMinMaxBounds(const Position<int>& min, const Position<int>& max);
		/**
		 * @brief Get the state of a singular Cell located at the given Position.
		 *
		 * @param pos The Position of the Cell whose state to get.
		 * @return The state of the Cell located at the given Position.
		 * @throw std::invalid_argument The given coordinates are not within the bounds of this Grid.
		 */
		unsigned int getCellState(const Position<int>& pos) const;
		/**
		 * @brief Set the state of the Cell located at the given coordinates to the given state.
		 *
		 * @param pos The position of the target Cell.
		 * @param state The new state to set the target Cell to.
		 * @throw std::invalid_argument The given coordinate is not within the bounds of this Grid.
		 */
		void setCellState(const Position<int>& pos, unsigned int state);
		/**
		 * @brief Update all the Cells in this Grid.
		 *
		 */
		void updateAllCells();
		/** Equals operator
		\param other The other grid to compare this to
		\return true If given grid has the same bounds and cell states as this
		\return false If given grid does not have same bounds or cell state as this
		*/
		bool operator==(const Grid& other) const;
		/** Not equals operator
		\param other The other grid to compare this to
		\return true If given grid does not have same bounds or cell state as this
		\return false If given grid has the same bounds and cell states as this
		*/
		bool operator!=(const Grid& other) const;
		/** Get a subgrid whose bounds are the intersection of this and the given bounds
		\param min The minimum bound of the subgrid
		\param max The maximum bound of the subgrid
		\return A Grid whose bounds are the intersection of this and the given bounds and has its cell states copied from this
		*/
		Grid intersection(const Position<int>& min, const Position<int>& max) const;
	private:
		/** The cells contained in this Grid */
		std::vector<CellState> cells; //\note A more advanced compression method to store over a million cells will be useful
		/** The minimum bounds of this Grid */
		Bounds<int> bounds;
		/** Map the given position to an index in the cells vector
		\param pos The position to convert
		\throw std::invalid_argument The given position is not within the bounds of this Grid
		*/
		unsigned int calcIndex(const Position<int>& pos) const;
	};
	/** Grid formatted stream insertion
	\param output The output stream to insert into
	\param grid The grid to insert
	\return The given output stream
	*/
	std::ostream& operator<<(std::ostream& output, const Grid& grid);
}

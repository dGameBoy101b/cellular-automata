#pragma once

#include "position.hpp"
#include "cell.hpp"
#include <vector>

namespace Data
{
	class Grid
	{
	public:
		/** Construct a new Grid object with the given bounds.
		\param min_bound The minimum bound of this Grid.
		\param max_bound The maximum bound of this Grid.
		\throw std::invalid_argument A component of the given minimum is greater than the corresponding maximum component
		 */
		Grid(const Position<int>& min_bound = Position<int>(), const Position<int>& max_bound = Position<int>());
		/**
		 * @brief Get the minimum bounds of this Grid.
		 *
		 * @return The minimum bounds of this Grid as a Position.
		 */
		const Position<int>& getMinBound() const;
		/** Set the minimum bounds of this Grid.
		\param min The Position of the new minimum bound of this Grid.
		\throw std::invalid_argument A component of the given minimum is greater than the corresponding maximum component
		\warning Triggers a cell regeneration
		 */
		void setMinBound(const Position<int>& min);
		/**
		 * @brief Get the maximum bounds of this Grid.
		 *
		 * @return The maximum bounds of this Grid as a Position.
		 */
		const Position<int>& getMaxBound() const;
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
		/**
		 * @brief Test if the given Position is within the bounds of this Grid.
		 *
		 * @param pos The Position to test.
		 * @return true The given Position is within the bounds of this Grid.
		 * @return false The given Position is not within the bounds of this Grid.
		 */
		bool withinBounds(const Position<int>& pos) const;
	private:
		/**
		 * @brief The cells contained in this Grid.
		 *
		 */
		std::vector<Cell> cells;
		/**
		 * @brief The minimum bounds of this Grid.
		 *
		 */
		Position<int> min_bound;
		/**
		 * @brief The maximum bounds of this Grid.
		 *
		 */
		Position<int> max_bound;
		/**
		 * @brief Discard the cells of this Grid and generate new cells for each position in this Grid, including any given cells within bounds.
		 *
		 * @param cells The cells to try and add to the new set of cells in this Grid.
		 * @warning Each grid cell must be regenerated which can be expensive for large grids.
		 */
		void regenerate(const std::vector<Cell> cells = std::vector<Cell>());
	};
}

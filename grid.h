#pragma once

#include "position.h"
#include "cell.h"
#include "out_of_bounds.h"
#include <vector>

namespace Data
{
	class Grid
	{
	public:
		/**
		 * @brief Construct a new zero size Grid object.
		 *
		 */
		Grid();
		/**
		 * @brief Construct a new Grid object with the given bounds and the given initial states.
		 *
		 * @param min_bound The minimum bounds of this Grid.
		 * @param max_bound The maximum bounds of this Grid.
		 * @param state The initial state of every Cell.
		 */
		Grid(const Position& min_bound, const Position& max_bound, int state);
		/**
		 * @brief Get a singular Cell located at the given position.
		 *
		 * @param pos The position of the Cell to get.
		 * @return The Cell located at the given position.
		 * @throw OutOfBounds The given coordinates are not within the bounds of this Grid.
		 */
		const Cell& getCell(const Position& pos) const;
		/**
		 * @brief Set the state of the Cell located at the given coordinates to the given state.
		 *
		 * @param pos The position of the target Cell.
		 * @param state The new state to set the target Cell to.
		 * @throw OutOfBounds The given coordinate is not within the bounds of this Grid.
		 */
		void setCellState(const Position& pos, int state);
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
		bool withinBounds(const Position& pos) const;
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
		Position min_bound;
		/**
		 * @brief The maximum bounds of this Grid.
		 *
		 */
		Position max_bound;
	};
}
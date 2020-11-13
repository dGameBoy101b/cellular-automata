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
		 * @param min_bound The minimum bound of this Grid.
		 * @param max_bound The maximum bound of this Grid.
		 */
		Grid(const Position& min_bound, const Position& max_bound);
		/**
		 * @brief Get the minimum bounds of this Grid.
		 * 
		 * @return The minimum bounds of this Grid as a Position.
		 */
		const Position& getMinBound() const;
		/**
		 * @brief Set the minimum bounds of this Grid.
		 * 
		 * @param min The Position of the new minimum bound of this Grid.
		 * @warning Each grid cell must be regenerated which can be expensive for large grids.
		 */
		void setMinBound(const Position& min);
		/**
		 * @brief Get the maximum bounds of this Grid.
		 * 
		 * @return The maximum bounds of this Grid as a Position.
		 */
		const Position& getMaxBound() const;
		/**
		 * @brief Set the maximum bounds of this Grid.
		 * 
		 * @param max The Position of the new maximum bound of this Grid.
		 * @warning Each grid cell must be regenerated which can be expensive for large grids.
		 */
		void setMaxBound(const Position& max);
		/**
		 * @brief Get the state of a singular Cell located at the given Position.
		 *
		 * @param pos The Position of the Cell whose state to get.
		 * @return The state of the Cell located at the given Position.
		 * @throw OutOfBounds The given coordinates are not within the bounds of this Grid.
		 */
		int getCellState(const Position& pos) const;
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
		/**
		 * @brief Ensure each component of the minimum bound is lesser than the corresponding component of the maximum bound.
		 * 
		 */
		void correctBounds();
		/**
		 * @brief Discard the cells of this Grid and generate new cells for each position in this Grid, including any given cells within bounds.
		 * 
		 * @param cells The cells to try and add to the new set of cells in this Grid.
		 * @warning Each grid cell must be regenerated which can be expensive for large grids.
		 */
		void regenerate(const std::vector<Cell> cells);
	};
}
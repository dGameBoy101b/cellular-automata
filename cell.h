#pragma once

#include "position.h"
#include "negative_state.h"

namespace Data
{
	class Cell
	{
	public:
		/**
		 * @brief Construct a new Cell object.
		 *
		 */
		Cell();
		/**
		 * @brief Initialise a new Cell object.
		 *
		 * @param pos The position of the cell.
		 * @param state The non-negative integer state of the cell.
		 * @throw NegativeState The given state was negative.
		 */
		Cell(const Position& pos, int state);
		/**
		 * @brief Get the position of this Cell.
		 *
		 * @return The position of this Cell.
		 */
		const Position& getPos() const;
		/**
		 * @brief Get the current state of this Cell.
		 *
		 * @return The current integer state of this Cell.
		 */
		int getState() const;
		/**
		 * @brief Set the position of this Cell.
		 *
		 * @param pos The new position of this Cell.
		 */
		void setPosition(const Position& pos);
		/**
		 * @brief Set the state of this Cell.
		 *
		 * @param state The next integer state of this Cell.
		 * @throw NegativeState The given state was negative.
		 */
		void setState(int state);
		/**
		 * @brief Update the current state of this Cell with the next state.
		 *
		 */
		void updateState();
	private:
		/**
		 * @brief The position of this Cell.
		 *
		 */
		Position pos;
		/**
		 * @brief The current non-negative integer state of this Cell.
		 *
		 */
		int state;
		/**
		 * @brief The next non-negative integer state of this Cell.
		 *
		 */
		int next_state;
	};
}
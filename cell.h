#pragma once

#include "position.h"

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
		 */
		Cell(const Position<int>& pos, unsigned int state);
		/**
		 * @brief Get the position of this Cell.
		 *
		 * @return The position of this Cell.
		 */
		const Position<int>& getPos() const;
		/**
		 * @brief Get the current state of this Cell.
		 *
		 * @return The current integer state of this Cell.
		 */
		unsigned int getState() const;
		/**
		 * @brief Set the position of this Cell.
		 *
		 * @param pos The new position of this Cell.
		 */
		void setPosition(const Position<int>& pos);
		/**
		 * @brief Set the state of this Cell.
		 *
		 * @param state The next integer state of this Cell.
		 * @throw Exceptions::NegativeState The given state was negative.
		 */
		void setState(unsigned int state);
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
		Position<int> pos;
		/**
		 * @brief The current non-negative integer state of this Cell.
		 *
		 */
		unsigned int state;
		/**
		 * @brief The next non-negative integer state of this Cell.
		 *
		 */
		unsigned int next_state;
	};
}
#pragma once
#include <ostream>

namespace Data
{
	class CellState
	{
	public:
		/** Constructor
		\param val The initial state
		*/
		CellState(unsigned int val = 0);
		/** Value getter
		\return The current value
		*/
		unsigned int getValue() const;
		/** Value setter
		\param val The next value
		\note CellState::updateValue must be called before CellState::getValue reflects the new value
		*/
		void setValue(unsigned int val);
		/** Updates the value with the value set last */
		void updateValue();
		/** Equals operator
		\param other The other CellState to compare with this
		\return True if given CellState has the same current value as this
		\return False if given CellState does not have the same current value as this
		*/
		bool operator==(const CellState& other) const;
		/** Not equals operator
		\param other The other CellState to compare with this
		\return True if given CellState does not have the same current value as this
		\return False if given CellState has the same current value as this
		*/
		bool operator!=(const CellState& other) const;
	private:
		/** The current value */
		unsigned int value;
		/** The next value */
		unsigned int next_value;
	};
}
/** CellState formatted stream insertion
\param output The output stream to insert into
\param state The CellState to insert
\return The given output stream
*/
std::ostream& operator<<(std::ostream& output, const Data::CellState& state);

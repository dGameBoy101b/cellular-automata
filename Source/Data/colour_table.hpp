#pragma once
#include "colour.hpp"
#include <unordered_map>
#include <unordered_set>

namespace Data
{
	class ColourTable
	{
	public:
		/** Constructor
		\param colours The list of colours to include in this table mapped to states by index
		*/
		ColourTable(const std::unordered_map<unsigned int, Colour>& colours = {});
		/** Map given state to a colour
		\param state The state to map
		\return The Colour the given state maps to
		\throw std::invalid_argument The given state is not defined for this table
		*/
		const Colour& getColour(unsigned int state) const;
		/** Set the mapped colour of the given state to the given colour
		\param state The state whose mapped colour should change
		\param colour The colour to set the mapped colour to
		*/
		void setColour(unsigned int state, const Colour& colour);
		/** Get the set of states that are mapped by this
		\return The set of valid states mapped by this
		*/
		const std::unordered_set<unsigned int> getStates() const;
		/** Equals operator
		\param other The other ColourTable to compare to this
		\return True if given ColourTable and this have the same mapping
		\return False if given ColourTable and this do not have the same mapping
		*/
		bool operator==(const ColourTable& other) const;
		/** Not equals operator
		\param other The other ColourTable to compare to this
		\return True if given ColourTable and this do not have the same mapping
		\return False if given ColourTable and this have the same mapping
		*/
		bool operator!=(const ColourTable& other) const;
	private:
		/** Every colour in this table mapped by index */
		std::unordered_map<unsigned int, Data::Colour> colours;
	};
	/** ColourTable formatted stream insertion
	\param output The output stream to insert into
	\param table The ColourTable to insert
	\return The given output stream
	*/
	std::ostream& operator<<(std::ostream& output, const ColourTable& table);
}

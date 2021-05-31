#pragma once

#include "colour.h"
#include "unexpected_extension.h"
#include "file_not_writable.h"
#include "file_not_readable.h"
#include "unrecognised_component_suffix.h"
#include "colour_component_format_mismatch.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

namespace FileIO
{
	class ColourFile
	{
	public:
		/**
		 * @brief The expected file extension.
		 */
		static const std::string EXT;
		/**
		 * @brief The end of a colour item.
		 */
		static const char END;
		/**
		 * @brief The separator between colour components.
		 */
		static const char SEP;
		/**
		 * @brief The suffix for the red colour component.
		 */
		static const char RED;
		/**
		 * @brief The suffix for the green colour component.
		 */
		static const char GREEN;
		/**
		 * @brief The suffix for the blue colour component.
		 */
		static const char BLUE;
		/**
		 * @brief The suffix for the alpha colour component.
		 */
		static const char ALPHA;
		/**
		 * @brief Load a list of Colours from a file.
		 * 
		 * @param filename The path to the file to load the Colours from.
		 * @return The loaded list of Colours.
		 */
		static const std::vector<Data::Colour> load(const std::string filename);
		/**
		 * @brief Save a list of Colours to a file.
		 * 
		 * @param filename The path to the file to save the Colours to.
		 * @param colours The list of Colours to save.
		 */
		static void save(const std::string filename, const std::vector<Data::Colour> colours);
		/**
		 * @brief Check a filename for the colour file extension.
		 * 
		 * @param filename The file name to check.
		 * @return Whether the given filename has the colour file extension.
		 */
		static bool checkExtension(const std::string filename);
	private:
		/**
		 * @brief Parse a Colour from a string.
		 * 
		 * @param string The string to parse as a Colour.
		 * @return The parsed Colour.
		 */
		static Data::Colour parseColour(const std::string string);
		/**
		 * @brief Parse a component of a Colour from a string.
		 * 
		 * @param string The string to parse a Colour component from.
		 * @param col The Colour to modify with the parsed Colour component.
		 * @throw UnrecognisedColourComponent The suffix of the given string does not match any known component suffixes.
		 */
		static void parseComponent(const std::string string, Data::Colour& col);
	};
}

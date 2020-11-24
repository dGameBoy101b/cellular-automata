#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include "grid.h"
#include "unexpected_extension.h"
#include "file_not_readable.h"
#include "file_not_writable.h"
#include "position_component_format_mismatch.h"
#include "unrecognised_component_suffix.h"
#include "cell_component_format_mismatch.h"

namespace FileIO
{
	class InitialStateFile
	{
	public:
		/**
		 * @brief The expected file extension.
		 */
		static const std::string EXT;
		/**
		 * @brief The record end character.
		 */
		static const char END;
		/**
		 * @brief The value separator character.
		 */
		static const char SEP;
		/**
		 * @brief The x coordinate suffix character.
		 */
		static const char X;
		/**
		 * @brief The y coordinate suffix character.
		 */
		static const char Y;
		/**
		 * @brief The z coordinate suffix character.
		 */
		static const char Z;
		/**
		 * @brief The state suffix character.
		 */
		static const char STATE;
		/**
		 * @brief Load a Data::Grid from a file.
		 * 
		 * @param filename The string filename of the file to load the Data::Grid from.
		 * @return The loaded Data::Grid.
		 */
		static Data::Grid load(const std::string& filename);
		/**
		 * @brief Save a Data::Grid to a file.
		 * 
		 * @param filename The string filename of the file to save the Data::Grid to.
		 * @param grid The Data::Grid to save.
		 * @throw Exceptions::UnexpectedExtension The given filename does not have expected file extension.
		 * @throw Exceptions::FileNotReadable The given filename could not be read.
		 */
		static void save(const std::string& filename, const Data::Grid& grid);
		/**
		 * @brief Check the extension of the given filename.
		 * 
		 * @param filename The string filename to check the extension of.
		 * @return True if the given filename is valid, false otherwise.
		 * @throw Exceptions::UnexpectedExtension The given filename does not have the expected file extension.
		 * @throw Exceptions::FileNotWritable The given filename could not be writen to.
		 */
		static bool checkExtension(const std::string& filename);
	private:
		/**
		 * @brief Parse a string into an integer Data::Position.
		 * 
		 * @param string The string to parse.
		 * @return The parsed integer Data::Position.
		 */
		static const Data::Position<int> parsePosition(const std::string& string);
		/**
		 * @brief Parse a string into a component of an Integer::Position.
		 * 
		 * @param string The string to parse.
		 * @param pos The integer Data::Position to modify with the parsed data.
		 * @throw Exceptions::PositionComponentFormatMismatch The given string does not match the expected format.
		 * @throw Exceptions::UnrecognisedComponentSuffix The detected suffix was not recognised.
		 */
		static void parsePosComponent(const std::string& string, Data::Position<int>& pos);
		/**
		 * @brief Parse a string into a Data::Cell.
		 * 
		 * @param string The string to parse.
		 * @return The parsed Data::Cell.
		 */
		static const Data::Cell parseCell(const std::string& string);
		/**
		 * @brief Parse a string into a component of a Data::Cell.
		 * 
		 * @param string The string to parse.
		 * @param cell The Data::Cell to modify with the parse data.
		 * @throw Exceptions::CellComponentFormatMismatch The given string does not match the expected format.
		 * @throw Exceptions::UnrecognisedComponentSuffix The detected suffix was not recognised.
		 */
		static void parseCellComponent(const std::string& string, Data::Cell& cell);
	};
}
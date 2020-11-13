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
		static const std::string EXT;
		static const char END;
		static const char SEP;
		static const char X;
		static const char Y;
		static const char Z;
		static const char STATE;
		static Data::Grid load(const std::string& filename);
		static void save(const std::string& filename, const Data::Grid& grid);
		static bool checkExtension(const std::string& filename);
	private:
		static const Data::Position parsePosition(const std::string& string);
		static void parsePosComponent(const std::string& string, Data::Position& pos);
		static const Data::Cell parseCell(const std::string& string);
		static void parseCellComponent(const std::string& string, Data::Cell& cell);
	};
}
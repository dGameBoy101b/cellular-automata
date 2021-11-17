#pragma once
#include "file_loader.hpp"
#include "../Data/colour.hpp"
#include <vector>
#include <string>

namespace FileIO
{
	class ColourTableCSVLoader : public FileLoader<std::vector<Data::Colour>>
	{
	public:
		std::vector<Data::Colour> load(const std::string& path);
		void save(const std::string& path, const std::vector<Data::Colour>& data);
	private:
		static const std::string EXT;
		static const char SEP;
		static const char END;
	};
}

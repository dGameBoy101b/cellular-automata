#include "../Data/grid.hpp"
#include "file_loader.hpp"

namespace FileIO
{
	class GridCSVLoader : public FileLoader<Data::Grid>
	{
	public:
		Data::Grid load(const std::string& path);
		void save(const std::string& path, const Data::Grid& data);
	private:
		static const std::string EXT;
		static const char SEP;
		static const char END;
	};
}

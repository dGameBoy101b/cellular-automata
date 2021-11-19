#include "../Data/grid.hpp"
#include "file_loader.hpp"

namespace FileIO
{
	class GridCSVLoader : public FileLoader<Data::Grid>
	{
	public:
		/** Load a Data::Grid from the CSV file at the given path
		\param path The path to the CSV file to load from
		\return The Data::Grid loaded from the given file
		\throw std::invalid_argument The given path could not be read
		\throw std::runtime_error The data read is in an unexpected format
		*/
		Data::Grid load(const std::string& path);
		/** Save the given Data::Grid to the CSV file at the given path
		\param path The path to the CSV file to save to
		\param grid The Data::Grid to save the given path
		\throw std::invalid_argument The given path could not be written to
		*/
		void save(const std::string& path, const Data::Grid& data);
	private:
		/** The expected file extension */
		static const std::string EXT;
		/** The expected value separator */
		static const char SEP;
		/** The exppected record ender */
		static const char END;
		/** Check last file read for format errors
		\param file The input file stream that was recently read from
		\param part The name of the part that was recently read
		\param expect The expected separator character
		\param test The read separator character
		\throw std::runtime_error The most recent read failed or the wrong separator was read
		*/
		void formatError(std::ifstream& file, const std::string& part, const char expect, const char test);
	};
}

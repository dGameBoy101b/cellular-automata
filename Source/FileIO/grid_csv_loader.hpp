#include "../Data/grid.hpp"
#include "csv_loader.hpp"

namespace FileIO
{
	/** Load a Data::Grid from the CSV file at the given path
	\param file The input file stream to the CSV file to load from
	\return The Data::Grid loaded from the given file
	\throw std::invalid_argument The given path could not be read
	\throw std::runtime_error The data read is in an unexpected format
	*/
	template<> Data::Grid CSVLoader<Data::Grid>::load(std::ifstream& file);
	/** Save the given Data::Grid to the CSV file at the given path
	\param file The output file stream to the CSV file to save to
	\param grid The Data::Grid to save the given path
	\throw std::invalid_argument The given path could not be written to
	*/
	template<> void CSVLoader<Data::Grid>::save(std::ofstream& file, const Data::Grid& grid);
}

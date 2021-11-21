#include "fileio_colour_table_csv_loader_tests.hpp"
#include "../assertion.hpp"
#include "../../Source/FileIO/colour_table_csv_loader.hpp"

const std::map<std::string, std::function<void()>> Tests::FILEIO_COLOUR_TABLE_CSV_LOADER_TESTS =
{
	{
		"FileIO::CSVLoader<Data::ColourTable> Save and Load Empty",
		[]{
			const Data::ColourTable TABLE = {};
			const std::string PATH = "./empty_test_colour_table.csv";
			FileIO::CSVLoader<Data::ColourTable>().save(PATH, TABLE);
			Data::ColourTable test = FileIO::CSVLoader<Data::ColourTable>().load(PATH);
			TestFramework::assertEqual(test, TABLE);
		}
	},
	{
		"FileIO::CSVLoader<Data::ColourTable> Save and Load Mixed",
		[]{
			const Data::ColourTable TABLE = {{
				{0u, {1., 1., 1., 1.}},
				{2u, {0., 0., 0., 0.}},
				{12u, {.2, .4, .6, .8}},
				{7u, {.1, .2, .3, .4}},
				{49u, {.9, .8, .7, .6}},
				{404u, {.123, .456, .789, 1.}}
			}};
			const std::string PATH = "./mixed_test_colour_table.csv";
			FileIO::CSVLoader<Data::ColourTable>().save(PATH, TABLE);
			Data::ColourTable test = FileIO::CSVLoader<Data::ColourTable>().load(PATH);
			TestFramework::assertEqual(test, TABLE);
		}
	}
};

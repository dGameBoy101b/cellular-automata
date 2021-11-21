#include "fileio_grid_csv_loader_tests.hpp"
#include "../assertion.hpp"
#include "../../Source/FileIO/grid_csv_loader.hpp"

const std::map<std::string, std::function<void()>> Tests::FILEIO_GRID_CSV_LOADER_TESTS =
{
	{
		"FileIO::CSVLoader<Data::Grid> Save and Load Empty",
		[]{
			const Data::Grid GRID = Data::Grid();
			const std::string PATH = "empty_test_grid.csv";
			FileIO::CSVLoader<Data::Grid>().save(PATH, GRID);
			Data::Grid test = FileIO::CSVLoader<Data::Grid>().load(PATH);
			TestFramework::assertEqual(test, GRID);
		}
	},
	{
		"FileIO::CSVLoader<Data::Grid> Save and Load Mixed",
		[]{
			const std::string PATH = "mixed_test_grid.csv";
			Data::Grid GRID = Data::Grid(Data::Bounds<Data::Position<int>>(Data::Position<int>(0, 0, 0), Data::Position<int>(1, 1, 1)));
			GRID.setCellState(Data::Position<int>(0, 0, 0), 0);
			GRID.setCellState(Data::Position<int>(0, 0, 1), 1);
			GRID.setCellState(Data::Position<int>(0, 1, 0), 2);
			GRID.setCellState(Data::Position<int>(0, 1, 1), 3);
			GRID.setCellState(Data::Position<int>(1, 0, 0), 4);
			GRID.setCellState(Data::Position<int>(1, 0, 1), 5);
			GRID.setCellState(Data::Position<int>(1, 1, 0), 6);
			GRID.setCellState(Data::Position<int>(1, 1, 1), 7);
			GRID.updateAllCells();
			FileIO::CSVLoader<Data::Grid>().save(PATH, GRID);
			Data::Grid test = FileIO::CSVLoader<Data::Grid>().load(PATH);
			TestFramework::assertEqual(test, GRID);
		}
	}
};

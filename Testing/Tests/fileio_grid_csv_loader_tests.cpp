#include "fileio_grid_csv_loader_tests.hpp"
#include "../assertion.hpp"
#include "../../Source/FileIO/grid_csv_loader.hpp"

const std::map<std::string, std::function<void()>> Tests::FILEIO_GRID_CSV_LOADER_TESTS =
{
	{
		"FileIO::GridCSVLoader Save and Load Empty",
		[]{
			const Data::Grid GRID = Data::Grid();
			const std::string PATH = "empty_test_grid.csv";
			FileIO::GridCSVLoader().save(PATH, GRID);
			Data::Grid test = FileIO::GridCSVLoader().load(PATH);
			TestFramework::assertEqual(test, GRID);
		}
	},
	{
		"FileIO::GridCSVLoader Save and Load Large",
		[]{
			const Data::Grid GRID = Data::Grid(Data::Bounds<int>(Data::Position<int>(-2000000, -2000001, -2000002), Data::Position<int>(2000003, 2000004, 2000005)));
			const std::string PATH = "big_test_grid.csv";
			FileIO::GridCSVLoader().save(PATH, GRID);
			Data::Grid test = FileIO::GridCSVLoader().load(PATH);
			TestFramework::assertEqual(test, GRID);
		}
	},
	{
		"FileIO::GridCSVLoader Save and Load Non-Homogeneous",
		[]{
			const std::string PATH = "mixed_test_grid.csv";
			Data::Grid GRID = Data::Grid(Data::Bounds<int>(Data::Position<int>(0, 0, 0), Data::Position<int>(1, 1, 1)));
			GRID.setCellState(Data::Position<int>(0, 0, 0), 0);
			GRID.setCellState(Data::Position<int>(0, 0, 1), 1);
			GRID.setCellState(Data::Position<int>(0, 1, 0), 2);
			GRID.setCellState(Data::Position<int>(0, 1, 1), 3);
			GRID.setCellState(Data::Position<int>(1, 0, 0), 4);
			GRID.setCellState(Data::Position<int>(1, 0, 1), 5);
			GRID.setCellState(Data::Position<int>(1, 1, 0), 6);
			GRID.setCellState(Data::Position<int>(1, 1, 1), 7);
			GRID.updateAllCells();
			FileIO::GridCSVLoader().save(PATH, GRID);
			Data::Grid test = FileIO::GridCSVLoader().load(PATH);
			TestFramework::assertEqual(test, GRID);
		}
	}
};

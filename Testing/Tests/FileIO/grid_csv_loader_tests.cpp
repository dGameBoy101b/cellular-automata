#include "grid_csv_loader_tests.hpp"
#include "Testing/assertion.hpp"
#include "Source/FileIO/grid_csv_loader.hpp"

using namespace CellularAutomata::Data;
using namespace CellularAutomata::FileIO;

const std::map<std::string, std::function<void()>> Tests::FileIO::GRID_CSV_LOADER_TESTS =
{
	{
		"FileIO::CSVLoader<Data::Grid> Save and Load Empty",
		[]{
			const Grid GRID = {};
			const std::string PATH = "empty_test_grid.csv";
			CSVLoader<Grid>().save(PATH, GRID);
			Grid test = CSVLoader<Grid>().load(PATH);
			TestFramework::assertEqual(test, GRID);
		}
	},
	{
		"FileIO::CSVLoader<Data::Grid> Save and Load Mixed",
		[]{
			const std::string PATH = "mixed_test_grid.csv";
			Grid GRID = {{{0, 0, 0}, {1, 1, 1}}};
			GRID.setCellState(Position<int>(0, 0, 0), 0);
			GRID.setCellState(Position<int>(0, 0, 1), 1);
			GRID.setCellState(Position<int>(0, 1, 0), 2);
			GRID.setCellState(Position<int>(0, 1, 1), 3);
			GRID.setCellState(Position<int>(1, 0, 0), 4);
			GRID.setCellState(Position<int>(1, 0, 1), 5);
			GRID.setCellState(Position<int>(1, 1, 0), 6);
			GRID.setCellState(Position<int>(1, 1, 1), 7);
			GRID.updateAllCells();
			CSVLoader<Grid>().save(PATH, GRID);
			Grid test = CSVLoader<Grid>().load(PATH);
			TestFramework::assertEqual(test, GRID);
		}
	}
};

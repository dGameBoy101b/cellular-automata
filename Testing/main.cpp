#include "test_manager.hpp"
#include "test_factory.hpp"
#include <iostream>
#include "Tests/data_position_int_tests.hpp"
#include "Tests/data_position_float_tests.hpp"
#include "Tests/data_colour_tests.hpp"
#include "Tests/data_colour_table_tests.hpp"
#include "Tests/data_cell_state_tests.hpp"
#include "Tests/data_cell_tests.hpp"
#include "Tests/data_bounds_position_int_tests.hpp"
#include "Tests/data_bounds_position_float_tests.hpp"
#include "Tests/data_grid_tests.hpp"
#include "Tests/fileio_grid_csv_loader_tests.hpp"
#include "Tests/fileio_colour_table_csv_loader_tests.hpp"
#include "Tests/sdl_window_tests.hpp"

using namespace TestFramework;

int main()
{
	TestManager tests = TestManager();

	TestFactory(Tests::DATA_POSITION_INT_TESTS).addTests(tests);
	TestFactory(Tests::DATA_POSITION_FLOAT_TESTS).addTests(tests);
	TestFactory(Tests::DATA_COLOUR_TESTS).addTests(tests);
	TestFactory(Tests::DATA_COLOUR_TABLE_TESTS).addTests(tests);
	TestFactory(Tests::DATA_CELL_STATE_TESTS).addTests(tests);
	TestFactory(Tests::DATA_CELL_TESTS).addTests(tests);
	TestFactory(Tests::DATA_BOUNDS_POSITION_INT_TESTS).addTests(tests);
	TestFactory(Tests::DATA_BOUNDS_POSITION_FLOAT_TESTS).addTests(tests);
	TestFactory(Tests::DATA_GRID_TESTS).addTests(tests);

	TestFactory(Tests::FILEIO_GRID_CSV_LOADER_TESTS).addTests(tests);
	TestFactory(Tests::FILEIO_COLOUR_TABLE_CSV_LOADER_TESTS).addTests(tests);

	TestFactory(Tests::SDL_WINDOW_TESTS).addTests(tests);

	tests.runAll(std::cout);
	return 0;
}

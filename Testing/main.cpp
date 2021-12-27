#define SDL_MAIN_HANDLED
#include "test_manager.hpp"
#include "test_factory.hpp"
#include <iostream>
#include "Tests/Data/position_int_tests.hpp"
#include "Tests/Data/position_float_tests.hpp"
#include "Tests/Data/colour_tests.hpp"
#include "Tests/Data/colour_table_tests.hpp"
#include "Tests/Data/cell_state_tests.hpp"
#include "Tests/Data/cell_tests.hpp"
#include "Tests/Data/bounds_position_int_tests.hpp"
#include "Tests/Data/bounds_position_float_tests.hpp"
#include "Tests/Data/grid_tests.hpp"
#include "Tests/FileIO/grid_csv_loader_tests.hpp"
#include "Tests/FileIO/colour_table_csv_loader_tests.hpp"
#include "Tests/SDL/Video/window_tests.hpp"
#include "Tests/SDL/Events/quit_event_tests.hpp"
#include "Tests/SDL/Events/keyboard_event_tests.hpp"
#include "Tests/SDL/Events/event_queue_tests.hpp"
#include "Tests/SDL/Events/event_tests.hpp"
#include "Tests/SDL/Events/mouse_button_event_tests.hpp"
#include "Tests/SDL/Events/mouse_wheel_event_tests.hpp"
#include "Tests/SDL/Events/mouse_motion_event_tests.hpp"

using namespace TestFramework;

int main()
{
	TestManager tests = TestManager();

	TestFactory(Tests::Data::POSITION_INT_TESTS).addTests(tests);
	TestFactory(Tests::Data::POSITION_FLOAT_TESTS).addTests(tests);
	TestFactory(Tests::Data::COLOUR_TESTS).addTests(tests);
	TestFactory(Tests::Data::COLOUR_TABLE_TESTS).addTests(tests);
	TestFactory(Tests::Data::CELL_STATE_TESTS).addTests(tests);
	TestFactory(Tests::Data::CELL_TESTS).addTests(tests);
	TestFactory(Tests::Data::BOUNDS_POSITION_INT_TESTS).addTests(tests);
	TestFactory(Tests::Data::BOUNDS_POSITION_FLOAT_TESTS).addTests(tests);
	TestFactory(Tests::Data::GRID_TESTS).addTests(tests);

	TestFactory(Tests::FileIO::GRID_CSV_LOADER_TESTS).addTests(tests);
	TestFactory(Tests::FileIO::COLOUR_TABLE_CSV_LOADER_TESTS).addTests(tests);

	TestFactory(Tests::SDL::Video::WINDOW_TESTS).addTests(tests);
	TestFactory(Tests::SDL::Events::QUIT_EVENT_TESTS).addTests(tests);
	TestFactory(Tests::SDL::Events::KEYBOARD_EVENT_TESTS).addTests(tests);
	TestFactory(Tests::SDL::Events::EVENT_QUEUE_TESTS).addTests(tests);
	TestFactory(Tests::SDL::Events::EVENT_TESTS).addTests(tests);
	TestFactory(Tests::SDL::Events::MOUSE_BUTTON_EVENT_TESTS).addTests(tests);
	TestFactory(Tests::SDL::Events::MOUSE_WHEEL_EVENT_TESTS).addTests(tests);
	TestFactory(Tests::SDL::Events::MOUSE_MOTION_EVENT_TESTS).addTests(tests);

	tests.runAll(std::cout);
	return 0;
}

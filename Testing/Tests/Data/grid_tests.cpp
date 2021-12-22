#include "grid_tests.hpp"
#include "Testing/assertion.hpp"
#include "Source/Data/grid.hpp"

using namespace CellularAutomata::Data;

const std::map<std::string, std::function<void()>> Tests::Data::GRID_TESTS =
{
	{
		"Data::Grid Default Constructor",
		[]{
			Grid test = {};
			TestFramework::assertEqual(test.getBounds(), Bounds<Position<int>>());
			TestFramework::assertEqual(test.getCellState(Position<int>()), 0u);
		}
	},
	{
		"Data::Grid Initialiser Constructor",
		[]{
			const Bounds<Position<int>> BOUNDS = Bounds<Position<int>>(Position<int>(-4, 7, 23), Position<int>(5, 7, 31));
			Grid test = {BOUNDS};
			TestFramework::assertEqual(test.getBounds(), BOUNDS);
		}
	},
	{
		"Data::Grid Minimum Bound Setter",
		[]{
			const Position<int> MIN = {-4, -19, 0};
			const Position<int> POS = {};
			const unsigned int STATE = 12;
			Grid test = {};
			test.setCellState(POS, STATE);
			test.updateAllCells();
			TestFramework::assertEqual(test.getCellState(POS), STATE);
			test.setMinBound(MIN);
			TestFramework::assertEqual(test.getBounds().getMin(), MIN);
			TestFramework::assertEqual(test.getBounds().getMax(), Position<int>());
			TestFramework::assertEqual(test.getCellState(POS), STATE);
		}
	},
	{
		"Data::Grid Minimum Bound Setter Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Grid().setMinBound(Position<int>(1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Grid().setMinBound(Position<int>(0, 1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Grid().setMinBound(Position<int>(0, 0, 1)); });
		}
	},
	{
		"Data::Grid Maximum Bound Setter",
		[]{
			const Position<int> MAX = {4, 0, 13};
			const Position<int> POS = {};
			const unsigned int STATE = 78;
			Grid test = {};
			test.setCellState(POS, STATE);
			test.updateAllCells();
			TestFramework::assertEqual(test.getCellState(POS), STATE);
			test.setMaxBound(MAX);
			TestFramework::assertEqual(test.getBounds().getMax(), MAX);
			TestFramework::assertEqual(test.getBounds().getMin(), Position<int>());
			TestFramework::assertEqual(test.getCellState(POS), STATE);
		}
	},
	{
		"Data::Grid Maximum Bound Setter Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Grid().setMaxBound(Position<int>(-1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Grid().setMaxBound(Position<int>(0, -1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Grid().setMaxBound(Position<int>(0, 0, -1)); });
		}
	},
	{
		"Data::Grid Minimum and Maximum Bounds Setter",
		[]{
			const Position<int> MIN = {2, 5, 10};
			const Position<int> MAX = {5, 7, 10};
			const Position<int> POS = {3, 6, 10};
			const unsigned int STATE = 8;
			Grid test = {};
			test.setMinMaxBounds(MIN, MAX);
			TestFramework::assertEqual(test.getBounds().getMin(), MIN);
			TestFramework::assertEqual(test.getBounds().getMax(), MAX);
			test.setCellState(POS, STATE);
			test.updateAllCells();
			test.setMinMaxBounds(Position<int>(), POS);
			TestFramework::assertEqual(test.getBounds().getMin(), Position<int>());
			TestFramework::assertEqual(test.getBounds().getMax(), POS);
			TestFramework::assertEqual(test.getCellState(POS), STATE);
		}
	},
	{
		"Data::Grid Minimum and Maximum Bounds Setter Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Grid().setMinMaxBounds(Position<int>(), Position<int>(-1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Grid().setMinMaxBounds(Position<int>(), Position<int>(0, -1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Grid().setMinMaxBounds(Position<int>(), Position<int>(0, -1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Grid().setMinMaxBounds(Position<int>(1), Position<int>()); });
			TestFramework::assertError<std::invalid_argument>([]{ Grid().setMinMaxBounds(Position<int>(0, 1), Position<int>()); });
			TestFramework::assertError<std::invalid_argument>([]{ Grid().setMinMaxBounds(Position<int>(0, 0, 1), Position<int>()); });
		}
	},
	{
		"Data::Grid Cell Updating",
		[]{
			const Bounds<Position<int>> BOUNDS = {{-3, -3, -3}, {3, 3, 3}};
			const Position<int> POS1 = {2, -1, 0};
			const unsigned int STATE1 = 3;
			const Position<int> POS2 = {-3, 3, 2};
			const unsigned int STATE2 = 10;
			const Position<int> POS3 = {};
			Grid test = {BOUNDS};
			test.setCellState(POS1, STATE1);
			test.setCellState(POS2, STATE2);
			TestFramework::assertNotEqual(test.getCellState(POS1), STATE1);
			TestFramework::assertNotEqual(test.getCellState(POS2), STATE2);
			TestFramework::assertEqual(test.getCellState(POS3), 0u);
			test.updateAllCells();
			TestFramework::assertEqual(test.getCellState(POS1), STATE1);
			TestFramework::assertEqual(test.getCellState(POS2), STATE2);
			TestFramework::assertEqual(test.getCellState(POS3), 0u);
		}
	},
	{
		"Data::Grid Equality",
		[]{
			const Bounds<Position<int>> BOUNDS = {{2, -34, 7}, {4, -23, 10}};
			TestFramework::assertEqual(Grid(), Grid());
			TestFramework::assertEqual(Grid(BOUNDS), Grid(BOUNDS));
		}
	},
	{
		"Data::Grid Inequality",
		[]{
			const Position<int> MIN = {-4, 0, 4};
			const Position<int> MAX = {0, 2, 8};
			Grid test = {};
			test.setCellState(Position<int>(), 3);
			test.updateAllCells();
			TestFramework::assertNotEqual(Grid(), Grid(Bounds<Position<int>>(MIN, MAX)));
			TestFramework::assertNotEqual(Grid(Bounds<Position<int>>(MIN, MAX)), Grid(Bounds<Position<int>>(MIN + 1, MAX + 1)));
			TestFramework::assertNotEqual(Grid(), test);
		}
	}
};

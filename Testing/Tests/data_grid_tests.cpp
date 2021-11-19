#include "data_grid_tests.hpp"
#include "../assertion.hpp"
#include "../../Source/Data/grid.hpp"

using namespace Tests;

const std::map<std::string, std::function<void()>> Tests::DATA_GRID_TESTS =
{
	{
		"Data::Grid Default Constructor",
		[]{
			Data::Grid test = Data::Grid();
			TestFramework::assertEqual(test.getBounds(), Data::Bounds<int>());
			TestFramework::assertEqual(test.getCellState(Data::Position<int>()), 0u);
		}
	},
	{
		"Data::Grid Initialiser Constructor",
		[]{
			const Data::Bounds<int> BOUNDS = Data::Bounds<int>(Data::Position<int>(-4, 7, 23), Data::Position<int>(5, 7, 31));
			Data::Grid test = Data::Grid(BOUNDS);
			TestFramework::assertEqual(test.getBounds(), BOUNDS);
		}
	},
	{
		"Data::Grid Minimum Bound Setter",
		[]{
			const Data::Position<int> MIN = Data::Position<int>(-4, -19, 0);
			Data::Grid test = Data::Grid();
			test.setMinBound(MIN);
			TestFramework::assertEqual(test.getBounds().getMin(), MIN);
			TestFramework::assertEqual(test.getBounds().getMax(), Data::Position<int>());
		}
	},
	{
		"Data::Grid Minimum Bound Setter Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Data::Grid().setMinBound(Data::Position<int>(1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Grid().setMinBound(Data::Position<int>(0, 1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Grid().setMinBound(Data::Position<int>(0, 0, 1)); });
		}
	},
	{
		"Data::Grid Maximum Bound Setter",
		[]{
			const Data::Position<int> MAX = Data::Position<int>(4, 0, 13);
			Data::Grid test = Data::Grid();
			test.setMaxBound(MAX);
			TestFramework::assertEqual(test.getBounds().getMax(), MAX);
			TestFramework::assertEqual(test.getBounds().getMin(), Data::Position<int>());
		}
	},
	{
		"Data::Grid Maximum Bound Setter Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Data::Grid().setMaxBound(Data::Position<int>(-1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Grid().setMaxBound(Data::Position<int>(0, -1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Grid().setMaxBound(Data::Position<int>(0, 0, -1)); });
		}
	},
	{
		"Data::Grid Minimum and Maximum Bounds Setter",
		[]{
			const Data::Position<int> MIN = Data::Position<int>(2, -5, 10);
			const Data::Position<int> MAX = Data::Position<int>(5, -2, 10);
			Data::Grid test = Data::Grid();
			test.setMinMaxBounds(MIN, MAX);
			TestFramework::assertEqual(test.getBounds().getMin(), MIN);
			TestFramework::assertEqual(test.getBounds().getMax(), MAX);
		}
	},
	{
		"Data::Grid Minimum and Maximum Bounds Setter Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Data::Grid().setMinMaxBounds(Data::Position<int>(), Data::Position<int>(-1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Grid().setMinMaxBounds(Data::Position<int>(), Data::Position<int>(0, -1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Grid().setMinMaxBounds(Data::Position<int>(), Data::Position<int>(0, -1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Grid().setMinMaxBounds(Data::Position<int>(1), Data::Position<int>()); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Grid().setMinMaxBounds(Data::Position<int>(0, 1), Data::Position<int>()); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Grid().setMinMaxBounds(Data::Position<int>(0, 0, 1), Data::Position<int>()); });
		}
	},
	{
		"Data::Grid Cell Updating",
		[]{
			const Data::Bounds<int> BOUNDS = Data::Bounds<int>(Data::Position<int>(-3, -3, -3), Data::Position<int>(3, 3, 3));
			const Data::Position<int> POS1 = Data::Position<int>(2, -1, 0);
			const unsigned int STATE1 = 3;
			const Data::Position<int> POS2 = Data::Position<int>(-3, 3, 2);
			const unsigned int STATE2 = 10;
			Data::Grid test = Data::Grid(BOUNDS);
			test.setCellState(POS1, STATE1);
			test.setCellState(POS2, STATE2);
			TestFramework::assertNotEqual(test.getCellState(POS1), STATE1);
			TestFramework::assertNotEqual(test.getCellState(POS2), STATE2);
			test.updateAllCells();
			TestFramework::assertEqual(test.getCellState(POS1), STATE1);
			TestFramework::assertEqual(test.getCellState(POS2), STATE2);
		}
	},
	{
		"Data::Grid Equality",
		[]{
			const Data::Bounds<int> BOUNDS = Data::Bounds<int>(Data::Position<int>(2, -34, 7), Data::Position<int>(4, -23, 10));
			TestFramework::assertEqual(Data::Grid(), Data::Grid());
			TestFramework::assertEqual(Data::Grid(BOUNDS), Data::Grid(BOUNDS));
		}
	},
	{
		"Data::Grid Inequality",
		[]{
			const Data::Position<int> MIN = Data::Position<int>(-4, 0, 4);
			const Data::Position<int> MAX = Data::Position<int>(0, 2, 8);
			Data::Grid test = Data::Grid();
			test.setCellState(Data::Position<int>(), 3);
			test.updateAllCells();
			TestFramework::assertNotEqual(Data::Grid(), Data::Grid(Data::Bounds<int>(MIN, MAX)));
			TestFramework::assertNotEqual(Data::Grid(Data::Bounds<int>(MIN, MAX)), Data::Grid(Data::Bounds<int>(MIN + 1, MAX + 1)));
			TestFramework::assertNotEqual(Data::Grid(), test);
		}
	}
};

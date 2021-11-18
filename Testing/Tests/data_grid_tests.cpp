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
			TestFramework::assertEqual(test.getMinBound(), Data::Position<int>());
			TestFramework::assertEqual(test.getMaxBound(), Data::Position<int>());
			TestFramework::assertEqual(test.getCellState(Data::Position<int>()), 0u);
		}
	},
	{
		"Data::Grid Initialiser Constructor",
		[]{
			const Data::Position<int> MIN = Data::Position<int>(-4, 7, 23);
			const Data::Position<int> MAX = Data::Position<int>(5, 7, 31);
			Data::Grid test = Data::Grid(MIN, MAX);
			TestFramework::assertEqual(test.getMinBound(), MIN);
			TestFramework::assertEqual(test.getMaxBound(), MAX);
		}
	},
	{
		"Data::Grid Initialiser Constructor Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Data::Grid(Data::Position<int>(), Data::Position<int>(-1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Grid(Data::Position<int>(), Data::Position<int>(0, -1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Grid(Data::Position<int>(), Data::Position<int>(0, 0, -1)); });
		}
	},
	{
		"Data::Grid Minimum Bound Setter",
		[]{
			const Data::Position<int> MIN = Data::Position<int>(-4, -19, 0);
			Data::Grid test = Data::Grid();
			test.setMinBound(MIN);
			TestFramework::assertEqual(test.getMinBound(), MIN);
			TestFramework::assertEqual(test.getMaxBound(), Data::Position<int>());
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
			TestFramework::assertEqual(test.getMaxBound(), MAX);
			TestFramework::assertEqual(test.getMinBound(), Data::Position<int>());
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
			TestFramework::assertEqual(test.getMinBound(), MIN);
			TestFramework::assertEqual(test.getMaxBound(), MAX);
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
		"Data::Grid Bounds Tester",
		[]{
			const Data::Position<int> MIN = Data::Position<int>(-1, -1, -1);
			const Data::Position<int> MAX = Data::Position<int>(2, 2, 2);
			Data::Grid test = Data::Grid(MIN, MAX);
			TestFramework::assertEqual(test.withinBounds(MIN), true);
			TestFramework::assertEqual(test.withinBounds(MAX), true);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MIN.getX(), MIN.getY(), MAX.getZ())), true);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MIN.getX(), MAX.getY(), MIN.getZ())), true);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MAX.getX(), MIN.getY(), MIN.getZ())), true);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MIN.getX(), MAX.getY(), MAX.getZ())), true);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MAX.getX(), MAX.getY(), MIN.getZ())), true);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MAX.getX(), MIN.getY(), MAX.getZ())), true);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MIN.getX() + 1, MIN.getY(), MIN.getZ())), true);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MIN.getX(), MIN.getY() + 1, MIN.getZ())), true);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MIN.getX(), MIN.getY(), MIN.getZ() + 1)), true);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MIN.getX() + 1, MIN.getY() + 1, MIN.getZ())), true);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MIN.getX(), MIN.getY() + 1, MIN.getZ() + 1)), true);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MIN.getX() + 1, MIN.getY(), MIN.getZ() + 1)), true);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MIN.getX() + 1, MIN.getY() + 1, MIN.getZ() + 1)), true);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MAX.getX() - 1, MAX.getY(), MAX.getZ())), true);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MAX.getX(), MAX.getY() - 1, MAX.getZ())), true);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MAX.getX(), MAX.getY(), MAX.getZ() - 1)), true);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MAX.getX() - 1, MAX.getY() - 1, MAX.getZ())), true);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MAX.getX(), MAX.getY() - 1, MAX.getZ() - 1)), true);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MAX.getX() - 1, MAX.getY(), MAX.getZ() - 1)), true);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MAX.getX() - 1, MAX.getY() - 1, MAX.getZ() - 1)), true);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MIN.getX() - 1, MIN.getY(), MIN.getZ())), false);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MIN.getX(), MIN.getY() - 1, MIN.getZ())), false);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MIN.getX(), MIN.getY(), MIN.getZ() - 1)), false);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MIN.getX() - 1, MIN.getY() - 1, MIN.getZ())), false);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MIN.getX(), MIN.getY() - 1, MIN.getZ() - 1)), false);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MIN.getX() - 1, MIN.getY(), MIN.getZ() - 1)), false);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MIN.getX() - 1, MIN.getY() - 1, MIN.getZ() - 1)), false);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MAX.getX() + 1, MAX.getY(), MAX.getZ())), false);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MAX.getX(), MAX.getY() + 1, MAX.getZ())), false);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MAX.getX(), MAX.getY(), MAX.getZ() + 1)), false);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MAX.getX() + 1, MAX.getY() + 1, MAX.getZ())), false);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MAX.getX(), MAX.getY() + 1, MAX.getZ() + 1)), false);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MAX.getX() + 1, MAX.getY(), MAX.getZ() + 1)), false);
			TestFramework::assertEqual(test.withinBounds(Data::Position<int>(MAX.getX() + 1, MAX.getY() + 1, MAX.getZ() + 1)), false);
		}
	},
	{
		"Data::Grid Cell Updating",
		[]{
			const Data::Position<int> MIN = Data::Position<int>(-3, -3, -3);
			const Data::Position<int> MAX = Data::Position<int>(3, 3, 3);
			const Data::Position<int> POS1 = Data::Position<int>(2, -1, 0);
			const unsigned int STATE1 = 3;
			const Data::Position<int> POS2 = Data::Position<int>(-3, 3, 2);
			const unsigned int STATE2 = 10;
			Data::Grid test = Data::Grid(MIN, MAX);
			test.setCellState(POS1, STATE1);
			test.setCellState(POS2, STATE2);
			TestFramework::assertNotEqual(test.getCellState(POS1), STATE1);
			TestFramework::assertNotEqual(test.getCellState(POS2), STATE2);
			test.updateAllCells();
			TestFramework::assertEqual(test.getCellState(POS1), STATE1);
			TestFramework::assertEqual(test.getCellState(POS2), STATE2);
		}
	}
};

#include "bounds_position_int_tests.hpp"
#include "Testing/assertion.hpp"
#include "Source/Data/bounds_position.hpp"

using namespace CellularAutomata::Data;

const std::map<std::string, std::function<void()>> Tests::Data::BOUNDS_POSITION_INT_TESTS =
{
	{
		"Data::Bounds<Data::Position<int>> Default Constructor",
		[]{
			Bounds<Position<int>> test = Bounds<Position<int>>();
			TestFramework::assertEqual(test.getMin(), Position<int>());
			TestFramework::assertEqual(test.getMax(), Position<int>());
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Initialiser Constructor",
		[]{
			const Position<int> MIN = Position<int>(34, -23, 100);
			const Position<int> MAX = Position<int>(34, -5, 234);
			Bounds<Position<int>> test = Bounds<Position<int>>(MIN, MAX);
			TestFramework::assertEqual(test.getMin(), MIN);
			TestFramework::assertEqual(test.getMax(), MAX);
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Initialiser Constructor Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<int>>(Position<int>(1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<int>>(Position<int>(0, 1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<int>>(Position<int>(0, 0, 1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<int>>(Position<int>(), Position<int>(-1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<int>>(Position<int>(), Position<int>(0, -1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<int>>(Position<int>(), Position<int>(0, 0, -1)); });
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Equals",
		[]{
			const Position<int> MIN = Position<int>(34, -23, 100);
			const Position<int> MAX = Position<int>(34, -5, 234);
			TestFramework::assertEqual(Bounds<Position<int>>(), Bounds<Position<int>>());
			TestFramework::assertEqual(Bounds<Position<int>>(MIN, MAX), Bounds<Position<int>>(MIN, MAX));
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Not Equals",
		[]{
			const Position<int> MIN = Position<int>(34, -23, 100);
			const Position<int> MAX = Position<int>(34, -5, 234);
			TestFramework::assertNotEqual(Bounds<Position<int>>(), Bounds<Position<int>>(MIN, MAX));
			TestFramework::assertNotEqual(Bounds<Position<int>>(MIN, MAX), Bounds<Position<int>>(MIN + Position<int>(1, 1, 1), MAX + Position<int>(1, 1, 1)));
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Minimum and Maximum Setter",
		[]{
			const Position<int> MIN = Position<int>(34, -23, 100);
			const Position<int> MAX = Position<int>(34, -5, 234);
			Bounds<Position<int>> test = Bounds<Position<int>>();
			test.setMinMax(MIN, MAX);
			TestFramework::assertEqual(test.getMin(), MIN);
			TestFramework::assertEqual(test.getMax(), MAX);
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Minimum and Maximum Setter Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<int>>().setMinMax(Position<int>(1), Position<int>()); });
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<int>>().setMinMax(Position<int>(0, 1), Position<int>()); });
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<int>>().setMinMax(Position<int>(0, 0, 1), Position<int>()); });
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<int>>().setMinMax(Position<int>(), Position<int>(-1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<int>>().setMinMax(Position<int>(), Position<int>(0, -1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<int>>().setMinMax(Position<int>(), Position<int>(0, 0, -1)); });
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Minimum Setter",
		[]{
			const Position<int> MIN = Position<int>(-34, -23, -100);
			Bounds<Position<int>> test = Bounds<Position<int>>();
			test.setMin(MIN);
			TestFramework::assertEqual(test.getMin(), MIN);
			TestFramework::assertEqual(test.getMax(), Position<int>());
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Minimum Setter Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<int>>().setMin(Position<int>(1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<int>>().setMin(Position<int>(0, 1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<int>>().setMin(Position<int>(0, 0, 1)); });
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Maximum Setter",
		[]{
			const Position<int> MAX = Position<int>(34, 5, 234);
			Bounds<Position<int>> test = Bounds<Position<int>>();
			test.setMax(MAX);
			TestFramework::assertEqual(test.getMin(), Position<int>());
			TestFramework::assertEqual(test.getMax(), MAX);
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Maximum Setter Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<int>>().setMax(Position<int>(-1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<int>>().setMax(Position<int>(0, -1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<int>>().setMax(Position<int>(0, 0, -1)); });
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Bounds Checker",
		[]{
			const Position<int> MIN = Position<int>(34, -23, 100);
			const Position<int> MAX = Position<int>(35, -5, 234);
			Bounds<Position<int>> test = Bounds<Position<int>>(MIN, MAX);
			TestFramework::assertEqual(test.isWithin(MIN), true);
			TestFramework::assertEqual(test.isWithin(MIN + Position<int>(1)), true);
			TestFramework::assertEqual(test.isWithin(MIN + Position<int>(0, 1)), true);
			TestFramework::assertEqual(test.isWithin(MIN + Position<int>(0, 0, 1)), true);
			TestFramework::assertEqual(test.isWithin(MIN + Position<int>(1, 1)), true);
			TestFramework::assertEqual(test.isWithin(MIN + Position<int>(1, 0, 1)), true);
			TestFramework::assertEqual(test.isWithin(MIN + Position<int>(0, 1, 1)), true);
			TestFramework::assertEqual(test.isWithin(MIN + Position<int>(1, 1, 1)), true);
			TestFramework::assertEqual(test.isWithin(MAX), true);
			TestFramework::assertEqual(test.isWithin(MAX - Position<int>(1)), true);
			TestFramework::assertEqual(test.isWithin(MAX - Position<int>(0, 1)), true);
			TestFramework::assertEqual(test.isWithin(MAX - Position<int>(0, 0, 1)), true);
			TestFramework::assertEqual(test.isWithin(MAX - Position<int>(1, 1)), true);
			TestFramework::assertEqual(test.isWithin(MAX - Position<int>(1, 0, 1)), true);
			TestFramework::assertEqual(test.isWithin(MAX - Position<int>(0, 1, 1)), true);
			TestFramework::assertEqual(test.isWithin(MAX - Position<int>(1, 1, 1)), true);
			TestFramework::assertEqual(test.isWithin(Position<int>(MIN.getX(), MIN.getY(), MAX.getZ())), true);
			TestFramework::assertEqual(test.isWithin(Position<int>(MIN.getX(), MAX.getY(), MIN.getZ())), true);
			TestFramework::assertEqual(test.isWithin(Position<int>(MAX.getX(), MIN.getY(), MIN.getZ())), true);
			TestFramework::assertEqual(test.isWithin(Position<int>(MIN.getX(), MAX.getY(), MAX.getZ())), true);
			TestFramework::assertEqual(test.isWithin(Position<int>(MAX.getX(), MIN.getY(), MAX.getZ())), true);
			TestFramework::assertEqual(test.isWithin(Position<int>(MAX.getX(), MAX.getY(), MIN.getZ())), true);
			TestFramework::assertEqual(test.isWithin(MIN - Position<int>(1)), false);
			TestFramework::assertEqual(test.isWithin(MIN - Position<int>(0, 1)), false);
			TestFramework::assertEqual(test.isWithin(MIN - Position<int>(0, 0, 1)), false);
			TestFramework::assertEqual(test.isWithin(MIN - Position<int>(1, 1)), false);
			TestFramework::assertEqual(test.isWithin(MIN - Position<int>(1, 0, 1)), false);
			TestFramework::assertEqual(test.isWithin(MIN - Position<int>(0, 1, 1)), false);
			TestFramework::assertEqual(test.isWithin(MIN - Position<int>(1, 1, 1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Position<int>(1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Position<int>(0, 1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Position<int>(0, 0, 1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Position<int>(1, 1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Position<int>(1, 0, 1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Position<int>(0, 1, 1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Position<int>(1, 1, 1)), false);
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Overlap Check",
		[]{
			const Position<int> MIN = Position<int>(34, -23, 100);
			const Position<int> MAX = Position<int>(37, -5, 234);
			TestFramework::assertEqual(Bounds<Position<int>>(MIN, MAX).doesOverlap(Bounds<Position<int>>(MIN, MAX)), true);
			TestFramework::assertEqual(Bounds<Position<int>>(MIN, MAX).doesOverlap(Bounds<Position<int>>(MIN + Position<int>(1), MAX)), true);
			TestFramework::assertEqual(Bounds<Position<int>>(MIN, MAX).doesOverlap(Bounds<Position<int>>(MIN + Position<int>(0, 1), MAX)), true);
			TestFramework::assertEqual(Bounds<Position<int>>(MIN, MAX).doesOverlap(Bounds<Position<int>>(MIN + Position<int>(0, 0, 1), MAX)), true);
			TestFramework::assertEqual(Bounds<Position<int>>(MIN, MAX).doesOverlap(Bounds<Position<int>>(MIN, MAX - Position<int>(1))), true);
			TestFramework::assertEqual(Bounds<Position<int>>(MIN, MAX).doesOverlap(Bounds<Position<int>>(MIN, MAX - Position<int>(0, 1))), true);
			TestFramework::assertEqual(Bounds<Position<int>>(MIN, MAX).doesOverlap(Bounds<Position<int>>(MIN, MAX - Position<int>(0, 0, 1))), true);
			TestFramework::assertEqual(Bounds<Position<int>>(MIN, MAX).doesOverlap(Bounds<Position<int>>(MIN + Position<int>(1, 1, 1), MAX - Position<int>(1, 1, 1))), true);
			TestFramework::assertEqual(Bounds<Position<int>>(MIN, MAX).doesOverlap(Bounds<Position<int>>(MIN - Position<int>(1), MAX)), true);
			TestFramework::assertEqual(Bounds<Position<int>>(MIN, MAX).doesOverlap(Bounds<Position<int>>(MIN - Position<int>(0, 1), MAX)), true);
			TestFramework::assertEqual(Bounds<Position<int>>(MIN, MAX).doesOverlap(Bounds<Position<int>>(MIN - Position<int>(0, 0, 1), MAX)), true);
			TestFramework::assertEqual(Bounds<Position<int>>(MIN, MAX).doesOverlap(Bounds<Position<int>>(MIN, MAX + Position<int>(1))), true);
			TestFramework::assertEqual(Bounds<Position<int>>(MIN, MAX).doesOverlap(Bounds<Position<int>>(MIN, MAX + Position<int>(0, 1))), true);
			TestFramework::assertEqual(Bounds<Position<int>>(MIN, MAX).doesOverlap(Bounds<Position<int>>(MIN, MAX + Position<int>(0, 0, 1))), true);
			TestFramework::assertEqual(Bounds<Position<int>>(MIN, MAX).doesOverlap(Bounds<Position<int>>(MIN - Position<int>(1, 1, 1), MAX + Position<int>(1, 1, 1))), true);
			TestFramework::assertEqual(Bounds<Position<int>>(MIN, MAX).doesOverlap(Bounds<Position<int>>(MIN - Position<int>(2, 1, 1), MIN - Position<int>(1, 1, 1))), false);
			TestFramework::assertEqual(Bounds<Position<int>>(MIN, MAX).doesOverlap(Bounds<Position<int>>(MIN - Position<int>(1, 2, 1), MIN - Position<int>(1, 1, 1))), false);
			TestFramework::assertEqual(Bounds<Position<int>>(MIN, MAX).doesOverlap(Bounds<Position<int>>(MIN - Position<int>(1, 1, 2), MIN - Position<int>(1, 1, 1))), false);
			TestFramework::assertEqual(Bounds<Position<int>>(MIN, MAX).doesOverlap(Bounds<Position<int>>(MIN - Position<int>(2, 2, 2), MIN - Position<int>(1, 1, 1))), false);
			TestFramework::assertEqual(Bounds<Position<int>>(MIN, MAX).doesOverlap(Bounds<Position<int>>(MAX + Position<int>(1, 1, 1), MAX + Position<int>(2, 1, 1))), false);
			TestFramework::assertEqual(Bounds<Position<int>>(MIN, MAX).doesOverlap(Bounds<Position<int>>(MAX + Position<int>(1, 1, 1), MAX + Position<int>(1, 2, 1))), false);
			TestFramework::assertEqual(Bounds<Position<int>>(MIN, MAX).doesOverlap(Bounds<Position<int>>(MAX + Position<int>(1, 1, 1), MAX + Position<int>(1, 1, 2))), false);
			TestFramework::assertEqual(Bounds<Position<int>>(MIN, MAX).doesOverlap(Bounds<Position<int>>(MAX + Position<int>(1, 1, 1), MAX + Position<int>(2, 2, 2))), false);
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Union",
		[]{
			const Position<int> MIN1 = Position<int>(34, -23, 100);
			const Position<int> MAX1 = Position<int>(34, -5, 234);
			const Position<int> MIN2 = Position<int>(-40, 20, -100);
			const Position<int> MAX2 = Position<int>(0, 74, -13);
			TestFramework::assertEqual(Bounds<Position<int>>(MIN1, MAX1).unionWith(Bounds<Position<int>>(MIN1, MAX1)), Bounds<Position<int>>(MIN1, MAX1));
			TestFramework::assertEqual(Bounds<Position<int>>(MIN2, MAX2).unionWith(Bounds<Position<int>>(MIN2, MAX2)), Bounds<Position<int>>(MIN2, MAX2));
			TestFramework::assertEqual(Bounds<Position<int>>(MIN1, MAX1).unionWith(Bounds<Position<int>>(MIN2, MAX2)), Bounds<Position<int>>(Position<int>(MIN2.getX(), MIN1.getY(), MIN2.getZ()), Position<int>(MAX1.getX(), MAX2.getY(), MAX1.getZ())));
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Intersection",
		[]{
			const Position<int> MIN1 = Position<int>(34, -23, -100);
			const Position<int> MAX1 = Position<int>(34, -5, 234);
			const Position<int> MIN2 = Position<int>(-40, -20, -100);
			const Position<int> MAX2 = Position<int>(100, 74, -13);
			TestFramework::assertEqual(Bounds<Position<int>>(MIN1, MAX1).intersectWith(Bounds<Position<int>>(MIN1, MAX1)), Bounds<Position<int>>(MIN1, MAX1));
			TestFramework::assertEqual(Bounds<Position<int>>(MIN2, MAX2).intersectWith(Bounds<Position<int>>(MIN2, MAX2)), Bounds<Position<int>>(MIN2, MAX2));
			TestFramework::assertEqual(Bounds<Position<int>>(MIN1, MAX1).intersectWith(Bounds<Position<int>>(MIN2, MAX2)), Bounds<Position<int>>(Position<int>(MIN1.getX(), MIN2.getY(), MIN1.getZ()), Position<int>(MAX1.getX(), MAX1.getY(), MAX2.getZ())));
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Intersection None",
		[]{
			TestFramework::assertError<std::range_error>([]{ Bounds<Position<int>>().intersectWith(Bounds<Position<int>>(Position<int>(1, 1, 1), Position<int>(1, 1, 1))); });
		}
	}
};

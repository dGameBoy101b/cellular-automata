#include "data_bounds_position_int_tests.hpp"
#include "../assertion.hpp"
#include "../../Source/Data/bounds_position.hpp"

const std::map<std::string, std::function<void()>> Tests::DATA_BOUNDS_POSITION_INT_TESTS =
{
	{
		"Data::Bounds<Data::Position<int>> Default Constructor",
		[]{
			Data::Bounds<Data::Position<int>> test = Data::Bounds<Data::Position<int>>();
			TestFramework::assertEqual(test.getMin(), Data::Position<int>());
			TestFramework::assertEqual(test.getMax(), Data::Position<int>());
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Initialiser Constructor",
		[]{
			const Data::Position<int> MIN = Data::Position<int>(34, -23, 100);
			const Data::Position<int> MAX = Data::Position<int>(34, -5, 234);
			Data::Bounds<Data::Position<int>> test = Data::Bounds<Data::Position<int>>(MIN, MAX);
			TestFramework::assertEqual(test.getMin(), MIN);
			TestFramework::assertEqual(test.getMax(), MAX);
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Initialiser Constructor Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<int>>(Data::Position<int>(1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<int>>(Data::Position<int>(0, 1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<int>>(Data::Position<int>(0, 0, 1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<int>>(Data::Position<int>(), Data::Position<int>(-1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<int>>(Data::Position<int>(), Data::Position<int>(0, -1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<int>>(Data::Position<int>(), Data::Position<int>(0, 0, -1)); });
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Equals",
		[]{
			const Data::Position<int> MIN = Data::Position<int>(34, -23, 100);
			const Data::Position<int> MAX = Data::Position<int>(34, -5, 234);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(), Data::Bounds<Data::Position<int>>());
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN, MAX), Data::Bounds<Data::Position<int>>(MIN, MAX));
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Not Equals",
		[]{
			const Data::Position<int> MIN = Data::Position<int>(34, -23, 100);
			const Data::Position<int> MAX = Data::Position<int>(34, -5, 234);
			TestFramework::assertNotEqual(Data::Bounds<Data::Position<int>>(), Data::Bounds<Data::Position<int>>(MIN, MAX));
			TestFramework::assertNotEqual(Data::Bounds<Data::Position<int>>(MIN, MAX), Data::Bounds<Data::Position<int>>(MIN + Data::Position<int>(1, 1, 1), MAX + Data::Position<int>(1, 1, 1)));
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Minimum and Maximum Setter",
		[]{
			const Data::Position<int> MIN = Data::Position<int>(34, -23, 100);
			const Data::Position<int> MAX = Data::Position<int>(34, -5, 234);
			Data::Bounds<Data::Position<int>> test = Data::Bounds<Data::Position<int>>();
			test.setMinMax(MIN, MAX);
			TestFramework::assertEqual(test.getMin(), MIN);
			TestFramework::assertEqual(test.getMax(), MAX);
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Minimum and Maximum Setter Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<int>>().setMinMax(Data::Position<int>(1), Data::Position<int>()); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<int>>().setMinMax(Data::Position<int>(0, 1), Data::Position<int>()); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<int>>().setMinMax(Data::Position<int>(0, 0, 1), Data::Position<int>()); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<int>>().setMinMax(Data::Position<int>(), Data::Position<int>(-1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<int>>().setMinMax(Data::Position<int>(), Data::Position<int>(0, -1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<int>>().setMinMax(Data::Position<int>(), Data::Position<int>(0, 0, -1)); });
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Minimum Setter",
		[]{
			const Data::Position<int> MIN = Data::Position<int>(-34, -23, -100);
			Data::Bounds<Data::Position<int>> test = Data::Bounds<Data::Position<int>>();
			test.setMin(MIN);
			TestFramework::assertEqual(test.getMin(), MIN);
			TestFramework::assertEqual(test.getMax(), Data::Position<int>());
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Minimum Setter Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<int>>().setMin(Data::Position<int>(1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<int>>().setMin(Data::Position<int>(0, 1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<int>>().setMin(Data::Position<int>(0, 0, 1)); });
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Maximum Setter",
		[]{
			const Data::Position<int> MAX = Data::Position<int>(34, 5, 234);
			Data::Bounds<Data::Position<int>> test = Data::Bounds<Data::Position<int>>();
			test.setMax(MAX);
			TestFramework::assertEqual(test.getMin(), Data::Position<int>());
			TestFramework::assertEqual(test.getMax(), MAX);
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Maximum Setter Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<int>>().setMax(Data::Position<int>(-1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<int>>().setMax(Data::Position<int>(0, -1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<int>>().setMax(Data::Position<int>(0, 0, -1)); });
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Bounds Checker",
		[]{
			const Data::Position<int> MIN = Data::Position<int>(34, -23, 100);
			const Data::Position<int> MAX = Data::Position<int>(35, -5, 234);
			Data::Bounds<Data::Position<int>> test = Data::Bounds<Data::Position<int>>(MIN, MAX);
			TestFramework::assertEqual(test.isWithin(MIN), true);
			TestFramework::assertEqual(test.isWithin(MIN + Data::Position<int>(1)), true);
			TestFramework::assertEqual(test.isWithin(MIN + Data::Position<int>(0, 1)), true);
			TestFramework::assertEqual(test.isWithin(MIN + Data::Position<int>(0, 0, 1)), true);
			TestFramework::assertEqual(test.isWithin(MIN + Data::Position<int>(1, 1)), true);
			TestFramework::assertEqual(test.isWithin(MIN + Data::Position<int>(1, 0, 1)), true);
			TestFramework::assertEqual(test.isWithin(MIN + Data::Position<int>(0, 1, 1)), true);
			TestFramework::assertEqual(test.isWithin(MIN + Data::Position<int>(1, 1, 1)), true);
			TestFramework::assertEqual(test.isWithin(MAX), true);
			TestFramework::assertEqual(test.isWithin(MAX - Data::Position<int>(1)), true);
			TestFramework::assertEqual(test.isWithin(MAX - Data::Position<int>(0, 1)), true);
			TestFramework::assertEqual(test.isWithin(MAX - Data::Position<int>(0, 0, 1)), true);
			TestFramework::assertEqual(test.isWithin(MAX - Data::Position<int>(1, 1)), true);
			TestFramework::assertEqual(test.isWithin(MAX - Data::Position<int>(1, 0, 1)), true);
			TestFramework::assertEqual(test.isWithin(MAX - Data::Position<int>(0, 1, 1)), true);
			TestFramework::assertEqual(test.isWithin(MAX - Data::Position<int>(1, 1, 1)), true);
			TestFramework::assertEqual(test.isWithin(Data::Position<int>(MIN.getX(), MIN.getY(), MAX.getZ())), true);
			TestFramework::assertEqual(test.isWithin(Data::Position<int>(MIN.getX(), MAX.getY(), MIN.getZ())), true);
			TestFramework::assertEqual(test.isWithin(Data::Position<int>(MAX.getX(), MIN.getY(), MIN.getZ())), true);
			TestFramework::assertEqual(test.isWithin(Data::Position<int>(MIN.getX(), MAX.getY(), MAX.getZ())), true);
			TestFramework::assertEqual(test.isWithin(Data::Position<int>(MAX.getX(), MIN.getY(), MAX.getZ())), true);
			TestFramework::assertEqual(test.isWithin(Data::Position<int>(MAX.getX(), MAX.getY(), MIN.getZ())), true);
			TestFramework::assertEqual(test.isWithin(MIN - Data::Position<int>(1)), false);
			TestFramework::assertEqual(test.isWithin(MIN - Data::Position<int>(0, 1)), false);
			TestFramework::assertEqual(test.isWithin(MIN - Data::Position<int>(0, 0, 1)), false);
			TestFramework::assertEqual(test.isWithin(MIN - Data::Position<int>(1, 1)), false);
			TestFramework::assertEqual(test.isWithin(MIN - Data::Position<int>(1, 0, 1)), false);
			TestFramework::assertEqual(test.isWithin(MIN - Data::Position<int>(0, 1, 1)), false);
			TestFramework::assertEqual(test.isWithin(MIN - Data::Position<int>(1, 1, 1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Data::Position<int>(1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Data::Position<int>(0, 1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Data::Position<int>(0, 0, 1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Data::Position<int>(1, 1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Data::Position<int>(1, 0, 1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Data::Position<int>(0, 1, 1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Data::Position<int>(1, 1, 1)), false);
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Overlap Check",
		[]{
			const Data::Position<int> MIN = Data::Position<int>(34, -23, 100);
			const Data::Position<int> MAX = Data::Position<int>(37, -5, 234);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<int>>(MIN, MAX)), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<int>>(MIN + Data::Position<int>(1), MAX)), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<int>>(MIN + Data::Position<int>(0, 1), MAX)), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<int>>(MIN + Data::Position<int>(0, 0, 1), MAX)), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<int>>(MIN, MAX - Data::Position<int>(1))), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<int>>(MIN, MAX - Data::Position<int>(0, 1))), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<int>>(MIN, MAX - Data::Position<int>(0, 0, 1))), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<int>>(MIN + Data::Position<int>(1, 1, 1), MAX - Data::Position<int>(1, 1, 1))), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<int>>(MIN - Data::Position<int>(1), MAX)), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<int>>(MIN - Data::Position<int>(0, 1), MAX)), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<int>>(MIN - Data::Position<int>(0, 0, 1), MAX)), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<int>>(MIN, MAX + Data::Position<int>(1))), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<int>>(MIN, MAX + Data::Position<int>(0, 1))), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<int>>(MIN, MAX + Data::Position<int>(0, 0, 1))), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<int>>(MIN - Data::Position<int>(1, 1, 1), MAX + Data::Position<int>(1, 1, 1))), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<int>>(MIN - Data::Position<int>(2, 1, 1), MIN - Data::Position<int>(1, 1, 1))), false);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<int>>(MIN - Data::Position<int>(1, 2, 1), MIN - Data::Position<int>(1, 1, 1))), false);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<int>>(MIN - Data::Position<int>(1, 1, 2), MIN - Data::Position<int>(1, 1, 1))), false);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<int>>(MIN - Data::Position<int>(2, 2, 2), MIN - Data::Position<int>(1, 1, 1))), false);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<int>>(MAX + Data::Position<int>(1, 1, 1), MAX + Data::Position<int>(2, 1, 1))), false);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<int>>(MAX + Data::Position<int>(1, 1, 1), MAX + Data::Position<int>(1, 2, 1))), false);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<int>>(MAX + Data::Position<int>(1, 1, 1), MAX + Data::Position<int>(1, 1, 2))), false);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<int>>(MAX + Data::Position<int>(1, 1, 1), MAX + Data::Position<int>(2, 2, 2))), false);
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Union",
		[]{
			const Data::Position<int> MIN1 = Data::Position<int>(34, -23, 100);
			const Data::Position<int> MAX1 = Data::Position<int>(34, -5, 234);
			const Data::Position<int> MIN2 = Data::Position<int>(-40, 20, -100);
			const Data::Position<int> MAX2 = Data::Position<int>(0, 74, -13);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN1, MAX1).unionWith(Data::Bounds<Data::Position<int>>(MIN1, MAX1)), Data::Bounds<Data::Position<int>>(MIN1, MAX1));
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN2, MAX2).unionWith(Data::Bounds<Data::Position<int>>(MIN2, MAX2)), Data::Bounds<Data::Position<int>>(MIN2, MAX2));
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN1, MAX1).unionWith(Data::Bounds<Data::Position<int>>(MIN2, MAX2)), Data::Bounds<Data::Position<int>>(Data::Position<int>(MIN2.getX(), MIN1.getY(), MIN2.getZ()), Data::Position<int>(MAX1.getX(), MAX2.getY(), MAX1.getZ())));
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Intersection",
		[]{
			const Data::Position<int> MIN1 = Data::Position<int>(34, -23, -100);
			const Data::Position<int> MAX1 = Data::Position<int>(34, -5, 234);
			const Data::Position<int> MIN2 = Data::Position<int>(-40, -20, -100);
			const Data::Position<int> MAX2 = Data::Position<int>(100, 74, -13);
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN1, MAX1).intersectWith(Data::Bounds<Data::Position<int>>(MIN1, MAX1)), Data::Bounds<Data::Position<int>>(MIN1, MAX1));
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN2, MAX2).intersectWith(Data::Bounds<Data::Position<int>>(MIN2, MAX2)), Data::Bounds<Data::Position<int>>(MIN2, MAX2));
			TestFramework::assertEqual(Data::Bounds<Data::Position<int>>(MIN1, MAX1).intersectWith(Data::Bounds<Data::Position<int>>(MIN2, MAX2)), Data::Bounds<Data::Position<int>>(Data::Position<int>(MIN1.getX(), MIN2.getY(), MIN1.getZ()), Data::Position<int>(MAX1.getX(), MAX1.getY(), MAX2.getZ())));
		}
	},
	{
		"Data::Bounds<Data::Position<int>> Intersection None",
		[]{
			TestFramework::assertError<std::range_error>([]{ Data::Bounds<Data::Position<int>>().intersectWith(Data::Bounds<Data::Position<int>>(Data::Position<int>(1, 1, 1), Data::Position<int>(1, 1, 1))); });
		}
	}
};

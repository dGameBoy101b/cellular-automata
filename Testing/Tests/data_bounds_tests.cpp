#include "data_bounds_tests.hpp"
#include "../assertion.hpp"
#include "../../Source/Data/Bounds.hpp"

const std::map<std::string, std::function<void()>> Tests::DATA_BOUNDS_TESTS =
{
	{
		"Data::Bounds<int> Default Constructor",
		[]{
			Data::Bounds<int> test = Data::Bounds<int>();
			TestFramework::assertEqual(test.getMin(), Data::Position<int>());
			TestFramework::assertEqual(test.getMax(), Data::Position<int>());
		}
	},
	{
		"Data::Bounds<float> Default Constructor",
		[]{
			Data::Bounds<float> test = Data::Bounds<float>();
			TestFramework::assertEqual(test.getMin(), Data::Position<float>());
			TestFramework::assertEqual(test.getMax(), Data::Position<float>());
		}
	},
	{
		"Data::Bounds<int> Initialiser Constructor",
		[]{
			const Data::Position<int> MIN = Data::Position<int>(34, -23, 100);
			const Data::Position<int> MAX = Data::Position<int>(34, -5, 234);
			Data::Bounds<int> test = Data::Bounds<int>(MIN, MAX);
			TestFramework::assertEqual(test.getMin(), MIN);
			TestFramework::assertEqual(test.getMax(), MAX);
		}
	},
	{
		"Data::Bounds<float> Initialiser Constructor",
		[]{
			const Data::Position<float> MIN = Data::Position<float>(34.4389, -23.24, 100.00021);
			const Data::Position<float> MAX = Data::Position<float>(34.4389, -5.123, 234.328891);
			Data::Bounds<float> test = Data::Bounds<float>(MIN, MAX);
			TestFramework::assertEqual(test.getMin(), MIN);
			TestFramework::assertEqual(test.getMax(), MAX);
		}
	},
	{
		"Data::Bounds<int> Initialiser Constructor Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<int>(Data::Position<int>(1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<int>(Data::Position<int>(0, 1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<int>(Data::Position<int>(0, 0, 1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<int>(Data::Position<int>(), Data::Position<int>(-1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<int>(Data::Position<int>(), Data::Position<int>(0, -1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<int>(Data::Position<int>(), Data::Position<int>(0, 0, -1)); });
		}
	},
	{
		"Data::Bounds<float> Initialiser Constructor Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<float>(Data::Position<float>(.1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<float>(Data::Position<float>(0., .1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<float>(Data::Position<float>(0., 0., .1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<float>(Data::Position<float>(), Data::Position<float>(-.1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<float>(Data::Position<float>(), Data::Position<float>(0., -.1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<float>(Data::Position<float>(), Data::Position<float>(0., 0., -.1)); });
		}
	},
	{
		"Data::Bounds<int> Equals",
		[]{
			const Data::Position<int> MIN = Data::Position<int>(34, -23, 100);
			const Data::Position<int> MAX = Data::Position<int>(34, -5, 234);
			TestFramework::assertEqual(Data::Bounds<int>(), Data::Bounds<int>());
			TestFramework::assertEqual(Data::Bounds<int>(MIN, MAX), Data::Bounds<int>(MIN, MAX));
		}
	},
	{
		"Data::Bounds<float> Equals",
		[]{
			const Data::Position<float> MIN = Data::Position<float>(34.4389, -23.24, 100.00021);
			const Data::Position<float> MAX = Data::Position<float>(34.4389, -5.123, 234.328891);
			TestFramework::assertEqual(Data::Bounds<float>(), Data::Bounds<float>());
			TestFramework::assertEqual(Data::Bounds<float>(MIN, MAX), Data::Bounds<float>(MIN, MAX));
		}
	},
	{
		"Data::Bounds<int> Not Equals",
		[]{
			const Data::Position<int> MIN = Data::Position<int>(34, -23, 100);
			const Data::Position<int> MAX = Data::Position<int>(34, -5, 234);
			TestFramework::assertNotEqual(Data::Bounds<int>(), Data::Bounds<int>(MIN, MAX));
			TestFramework::assertNotEqual(Data::Bounds<int>(MIN, MAX), Data::Bounds<int>(MIN + Data::Position<int>(1, 1, 1), MAX + Data::Position<int>(1, 1, 1)));
		}
	},
	{
		"Data::Bounds<float> Not Equals",
		[]{
			const Data::Position<float> MIN = Data::Position<float>(34.4389, -23.24, 100.00021);
			const Data::Position<float> MAX = Data::Position<float>(34.4389, -5.123, 234.328891);
			TestFramework::assertNotEqual(Data::Bounds<float>(), Data::Bounds<float>(MIN, MAX));
			TestFramework::assertNotEqual(Data::Bounds<float>(MIN, MAX), Data::Bounds<float>(MIN + Data::Position<float>(1, 1, 1), MAX + Data::Position<float>(1, 1, 1)));
		}
	},
	{
		"Data::Bounds<int> Minimum and Maximum Setter",
		[]{
			const Data::Position<int> MIN = Data::Position<int>(34, -23, 100);
			const Data::Position<int> MAX = Data::Position<int>(34, -5, 234);
			Data::Bounds<int> test = Data::Bounds<int>();
			test.setMinMax(MIN, MAX);
			TestFramework::assertEqual(test.getMin(), MIN);
			TestFramework::assertEqual(test.getMax(), MAX);
		}
	},
	{
		"Data::Bounds<float> Minimum and Maximum Setter",
		[]{
			const Data::Position<float> MIN = Data::Position<float>(34.4389, -23.24, 100.00021);
			const Data::Position<float> MAX = Data::Position<float>(34.4389, -5.123, 234.328891);
			Data::Bounds<float> test = Data::Bounds<float>();
			test.setMinMax(MIN, MAX);
			TestFramework::assertEqual(test.getMin(), MIN);
			TestFramework::assertEqual(test.getMax(), MAX);
		}
	},
	{
		"Data::Bounds<int> Minimum and Maximum Setter Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<int>().setMinMax(Data::Position<int>(1), Data::Position<int>()); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<int>().setMinMax(Data::Position<int>(0, 1), Data::Position<int>()); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<int>().setMinMax(Data::Position<int>(0, 0, 1), Data::Position<int>()); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<int>().setMinMax(Data::Position<int>(), Data::Position<int>(-1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<int>().setMinMax(Data::Position<int>(), Data::Position<int>(0, -1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<int>().setMinMax(Data::Position<int>(), Data::Position<int>(0, 0, -1)); });
		}
	},
	{
		"Data::Bounds<float> Minimum and Maximum Setter Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<float>().setMinMax(Data::Position<float>(.1), Data::Position<float>()); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<float>().setMinMax(Data::Position<float>(0., .1), Data::Position<float>()); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<float>().setMinMax(Data::Position<float>(0., 0., .1), Data::Position<float>()); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<float>().setMinMax(Data::Position<float>(), Data::Position<float>(-.1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<float>().setMinMax(Data::Position<float>(), Data::Position<float>(0., -.1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<float>().setMinMax(Data::Position<float>(), Data::Position<float>(0., 0., -.1)); });
		}
	},
	{
		"Data::Bounds<int> Minimum Setter",
		[]{
			const Data::Position<int> MIN = Data::Position<int>(-34, -23, -100);
			Data::Bounds<int> test = Data::Bounds<int>();
			test.setMin(MIN);
			TestFramework::assertEqual(test.getMin(), MIN);
			TestFramework::assertEqual(test.getMax(), Data::Position<int>());
		}
	},
	{
		"Data::Bounds<float> Minimum Setter",
		[]{
			const Data::Position<float> MIN = Data::Position<float>(-34.4389, -23.24, -100.00021);
			Data::Bounds<float> test = Data::Bounds<float>();
			test.setMin(MIN);
			TestFramework::assertEqual(test.getMin(), MIN);
			TestFramework::assertEqual(test.getMax(), Data::Position<float>());
		}
	},
	{
		"Data::Bounds<int> Minimum Setter Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<int>().setMin(Data::Position<int>(1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<int>().setMin(Data::Position<int>(0, 1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<int>().setMin(Data::Position<int>(0, 0, 1)); });
		}
	},
	{
		"Data::Bounds<float> Minimum Setter Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<float>().setMin(Data::Position<float>(.1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<float>().setMin(Data::Position<float>(0., .1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<float>().setMin(Data::Position<float>(0., 0., .1)); });
		}
	},
	{
		"Data::Bounds<int> Maximum Setter",
		[]{
			const Data::Position<int> MAX = Data::Position<int>(34, 5, 234);
			Data::Bounds<int> test = Data::Bounds<int>();
			test.setMax(MAX);
			TestFramework::assertEqual(test.getMin(), Data::Position<int>());
			TestFramework::assertEqual(test.getMax(), MAX);
		}
	},
	{
		"Data::Bounds<float> Maximum Setter",
		[]{
			const Data::Position<float> MAX = Data::Position<float>(34.4389, 5.123, 234.328891);
			Data::Bounds<float> test = Data::Bounds<float>();
			test.setMax(MAX);
			TestFramework::assertEqual(test.getMin(), Data::Position<float>());
			TestFramework::assertEqual(test.getMax(), MAX);
		}
	},
	{
		"Data::Bounds<int> Maximum Setter Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<int>().setMax(Data::Position<int>(-1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<int>().setMax(Data::Position<int>(0, -1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<int>().setMax(Data::Position<int>(0, 0, -1)); });
		}
	},
	{
		"Data::Bounds<float> Maximum Setter Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<float>().setMax(Data::Position<float>(-.1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<float>().setMax(Data::Position<float>(0., -.1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<float>().setMax(Data::Position<float>(0., 0., -.1)); });
		}
	},
	{
		"Data::Bounds<int> Bounds Checker",
		[]{
			const Data::Position<int> MIN = Data::Position<int>(34, -23, 100);
			const Data::Position<int> MAX = Data::Position<int>(35, -5, 234);
			Data::Bounds<int> test = Data::Bounds<int>(MIN, MAX);
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
		"Data::Bounds<float> Bounds Checker",
		[]{
			const Data::Position<float> MIN = Data::Position<float>(34.4389, -23.24, 100.00021);
			const Data::Position<float> MAX = Data::Position<float>(34.9389, -5.123, 234.328891);
			Data::Bounds<float> test = Data::Bounds<float>(MIN, MAX);
			TestFramework::assertEqual(test.isWithin(MIN), true);
			TestFramework::assertEqual(test.isWithin(MIN + Data::Position<float>(.1)), true);
			TestFramework::assertEqual(test.isWithin(MIN + Data::Position<float>(0, .1)), true);
			TestFramework::assertEqual(test.isWithin(MIN + Data::Position<float>(0, 0, .1)), true);
			TestFramework::assertEqual(test.isWithin(MIN + Data::Position<float>(.1, .1)), true);
			TestFramework::assertEqual(test.isWithin(MIN + Data::Position<float>(.1, 0, .1)), true);
			TestFramework::assertEqual(test.isWithin(MIN + Data::Position<float>(0, .1, .1)), true);
			TestFramework::assertEqual(test.isWithin(MIN + Data::Position<float>(.1, .1, .1)), true);
			TestFramework::assertEqual(test.isWithin(MAX), true);
			TestFramework::assertEqual(test.isWithin(MAX - Data::Position<float>(.1)), true);
			TestFramework::assertEqual(test.isWithin(MAX - Data::Position<float>(0, .1)), true);
			TestFramework::assertEqual(test.isWithin(MAX - Data::Position<float>(0, 0, .1)), true);
			TestFramework::assertEqual(test.isWithin(MAX - Data::Position<float>(.1, .1)), true);
			TestFramework::assertEqual(test.isWithin(MAX - Data::Position<float>(.1, 0, .1)), true);
			TestFramework::assertEqual(test.isWithin(MAX - Data::Position<float>(0, .1, .1)), true);
			TestFramework::assertEqual(test.isWithin(MAX - Data::Position<float>(.1, .1, .1)), true);
			TestFramework::assertEqual(test.isWithin(Data::Position<float>(MIN.getX(), MIN.getY(), MAX.getZ())), true);
			TestFramework::assertEqual(test.isWithin(Data::Position<float>(MIN.getX(), MAX.getY(), MIN.getZ())), true);
			TestFramework::assertEqual(test.isWithin(Data::Position<float>(MAX.getX(), MIN.getY(), MIN.getZ())), true);
			TestFramework::assertEqual(test.isWithin(Data::Position<float>(MIN.getX(), MAX.getY(), MAX.getZ())), true);
			TestFramework::assertEqual(test.isWithin(Data::Position<float>(MAX.getX(), MIN.getY(), MAX.getZ())), true);
			TestFramework::assertEqual(test.isWithin(Data::Position<float>(MAX.getX(), MAX.getY(), MIN.getZ())), true);
			TestFramework::assertEqual(test.isWithin(MIN - Data::Position<float>(.1)), false);
			TestFramework::assertEqual(test.isWithin(MIN - Data::Position<float>(0, .1)), false);
			TestFramework::assertEqual(test.isWithin(MIN - Data::Position<float>(0, 0, .1)), false);
			TestFramework::assertEqual(test.isWithin(MIN - Data::Position<float>(.1, .1)), false);
			TestFramework::assertEqual(test.isWithin(MIN - Data::Position<float>(.1, 0, .1)), false);
			TestFramework::assertEqual(test.isWithin(MIN - Data::Position<float>(0, .1, .1)), false);
			TestFramework::assertEqual(test.isWithin(MIN - Data::Position<float>(.1, .1, .1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Data::Position<float>(.1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Data::Position<float>(0, .1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Data::Position<float>(0, 0, .1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Data::Position<float>(.1, .1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Data::Position<float>(.1, 0, .1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Data::Position<float>(0, .1, .1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Data::Position<float>(.1, .1, .1)), false);
		}
	},
	{
		"Data::Bounds<int> Overlap Check",
		[]{
			const Data::Position<int> MIN = Data::Position<int>(34, -23, 100);
			const Data::Position<int> MAX = Data::Position<int>(37, -5, 234);
			TestFramework::assertEqual(Data::Bounds<int>(MIN, MAX).doesOverlap(Data::Bounds<int>(MIN, MAX)), true);
			TestFramework::assertEqual(Data::Bounds<int>(MIN, MAX).doesOverlap(Data::Bounds<int>(MIN + Data::Position<int>(1), MAX)), true);
			TestFramework::assertEqual(Data::Bounds<int>(MIN, MAX).doesOverlap(Data::Bounds<int>(MIN + Data::Position<int>(0, 1), MAX)), true);
			TestFramework::assertEqual(Data::Bounds<int>(MIN, MAX).doesOverlap(Data::Bounds<int>(MIN + Data::Position<int>(0, 0, 1), MAX)), true);
			TestFramework::assertEqual(Data::Bounds<int>(MIN, MAX).doesOverlap(Data::Bounds<int>(MIN, MAX - Data::Position<int>(1))), true);
			TestFramework::assertEqual(Data::Bounds<int>(MIN, MAX).doesOverlap(Data::Bounds<int>(MIN, MAX - Data::Position<int>(0, 1))), true);
			TestFramework::assertEqual(Data::Bounds<int>(MIN, MAX).doesOverlap(Data::Bounds<int>(MIN, MAX - Data::Position<int>(0, 0, 1))), true);
			TestFramework::assertEqual(Data::Bounds<int>(MIN, MAX).doesOverlap(Data::Bounds<int>(MIN + Data::Position<int>(1, 1, 1), MAX - Data::Position<int>(1, 1, 1))), true);
			TestFramework::assertEqual(Data::Bounds<int>(MIN, MAX).doesOverlap(Data::Bounds<int>(MIN - Data::Position<int>(1), MAX)), true);
			TestFramework::assertEqual(Data::Bounds<int>(MIN, MAX).doesOverlap(Data::Bounds<int>(MIN - Data::Position<int>(0, 1), MAX)), true);
			TestFramework::assertEqual(Data::Bounds<int>(MIN, MAX).doesOverlap(Data::Bounds<int>(MIN - Data::Position<int>(0, 0, 1), MAX)), true);
			TestFramework::assertEqual(Data::Bounds<int>(MIN, MAX).doesOverlap(Data::Bounds<int>(MIN, MAX + Data::Position<int>(1))), true);
			TestFramework::assertEqual(Data::Bounds<int>(MIN, MAX).doesOverlap(Data::Bounds<int>(MIN, MAX + Data::Position<int>(0, 1))), true);
			TestFramework::assertEqual(Data::Bounds<int>(MIN, MAX).doesOverlap(Data::Bounds<int>(MIN, MAX + Data::Position<int>(0, 0, 1))), true);
			TestFramework::assertEqual(Data::Bounds<int>(MIN, MAX).doesOverlap(Data::Bounds<int>(MIN - Data::Position<int>(1, 1, 1), MAX + Data::Position<int>(1, 1, 1))), true);
			TestFramework::assertEqual(Data::Bounds<int>(MIN, MAX).doesOverlap(Data::Bounds<int>(MIN - Data::Position<int>(2, 1, 1), MIN - Data::Position<int>(1, 1, 1))), false);
			TestFramework::assertEqual(Data::Bounds<int>(MIN, MAX).doesOverlap(Data::Bounds<int>(MIN - Data::Position<int>(1, 2, 1), MIN - Data::Position<int>(1, 1, 1))), false);
			TestFramework::assertEqual(Data::Bounds<int>(MIN, MAX).doesOverlap(Data::Bounds<int>(MIN - Data::Position<int>(1, 1, 2), MIN - Data::Position<int>(1, 1, 1))), false);
			TestFramework::assertEqual(Data::Bounds<int>(MIN, MAX).doesOverlap(Data::Bounds<int>(MIN - Data::Position<int>(2, 2, 2), MIN - Data::Position<int>(1, 1, 1))), false);
			TestFramework::assertEqual(Data::Bounds<int>(MIN, MAX).doesOverlap(Data::Bounds<int>(MAX + Data::Position<int>(1, 1, 1), MAX + Data::Position<int>(2, 1, 1))), false);
			TestFramework::assertEqual(Data::Bounds<int>(MIN, MAX).doesOverlap(Data::Bounds<int>(MAX + Data::Position<int>(1, 1, 1), MAX + Data::Position<int>(1, 2, 1))), false);
			TestFramework::assertEqual(Data::Bounds<int>(MIN, MAX).doesOverlap(Data::Bounds<int>(MAX + Data::Position<int>(1, 1, 1), MAX + Data::Position<int>(1, 1, 2))), false);
			TestFramework::assertEqual(Data::Bounds<int>(MIN, MAX).doesOverlap(Data::Bounds<int>(MAX + Data::Position<int>(1, 1, 1), MAX + Data::Position<int>(2, 2, 2))), false);
		}
	},
	{
		"Data::Bounds<float> Overlap Check",
		[]{
			const Data::Position<float> MIN = Data::Position<float>(34.4389, -23.24, 100.00021);
			const Data::Position<float> MAX = Data::Position<float>(34.9389, -5.123, 234.328891);
			TestFramework::assertEqual(Data::Bounds<float>(MIN, MAX).doesOverlap(Data::Bounds<float>(MIN, MAX)), true);
			TestFramework::assertEqual(Data::Bounds<float>(MIN, MAX).doesOverlap(Data::Bounds<float>(MIN + Data::Position<float>(.1), MAX)), true);
			TestFramework::assertEqual(Data::Bounds<float>(MIN, MAX).doesOverlap(Data::Bounds<float>(MIN + Data::Position<float>(0., .1), MAX)), true);
			TestFramework::assertEqual(Data::Bounds<float>(MIN, MAX).doesOverlap(Data::Bounds<float>(MIN + Data::Position<float>(0., 0., .1), MAX)), true);
			TestFramework::assertEqual(Data::Bounds<float>(MIN, MAX).doesOverlap(Data::Bounds<float>(MIN, MAX - Data::Position<float>(.1))), true);
			TestFramework::assertEqual(Data::Bounds<float>(MIN, MAX).doesOverlap(Data::Bounds<float>(MIN, MAX - Data::Position<float>(0., .1))), true);
			TestFramework::assertEqual(Data::Bounds<float>(MIN, MAX).doesOverlap(Data::Bounds<float>(MIN, MAX - Data::Position<float>(0., 0., .1))), true);
			TestFramework::assertEqual(Data::Bounds<float>(MIN, MAX).doesOverlap(Data::Bounds<float>(MIN + Data::Position<float>(.1, .1, .1), MAX - Data::Position<float>(.1, .1, .1))), true);
			TestFramework::assertEqual(Data::Bounds<float>(MIN, MAX).doesOverlap(Data::Bounds<float>(MIN - Data::Position<float>(.1), MAX)), true);
			TestFramework::assertEqual(Data::Bounds<float>(MIN, MAX).doesOverlap(Data::Bounds<float>(MIN - Data::Position<float>(0., .1), MAX)), true);
			TestFramework::assertEqual(Data::Bounds<float>(MIN, MAX).doesOverlap(Data::Bounds<float>(MIN - Data::Position<float>(0., 0., .1), MAX)), true);
			TestFramework::assertEqual(Data::Bounds<float>(MIN, MAX).doesOverlap(Data::Bounds<float>(MIN, MAX + Data::Position<float>(.1))), true);
			TestFramework::assertEqual(Data::Bounds<float>(MIN, MAX).doesOverlap(Data::Bounds<float>(MIN, MAX + Data::Position<float>(0., .1))), true);
			TestFramework::assertEqual(Data::Bounds<float>(MIN, MAX).doesOverlap(Data::Bounds<float>(MIN, MAX + Data::Position<float>(0., 0., .1))), true);
			TestFramework::assertEqual(Data::Bounds<float>(MIN, MAX).doesOverlap(Data::Bounds<float>(MIN - Data::Position<float>(.1, .1, .1), MAX + Data::Position<float>(.1, .1, .1))), true);
			TestFramework::assertEqual(Data::Bounds<float>(MIN, MAX).doesOverlap(Data::Bounds<float>(MIN - Data::Position<float>(.2, .1, .1), MIN - Data::Position<float>(.1, .1, .1))), false);
			TestFramework::assertEqual(Data::Bounds<float>(MIN, MAX).doesOverlap(Data::Bounds<float>(MIN - Data::Position<float>(.1, .2, .1), MIN - Data::Position<float>(.1, .1, .1))), false);
			TestFramework::assertEqual(Data::Bounds<float>(MIN, MAX).doesOverlap(Data::Bounds<float>(MIN - Data::Position<float>(.1, .1, .2), MIN - Data::Position<float>(.1, .1, .1))), false);
			TestFramework::assertEqual(Data::Bounds<float>(MIN, MAX).doesOverlap(Data::Bounds<float>(MIN - Data::Position<float>(.2, .2, .2), MIN - Data::Position<float>(.1, .1, .1))), false);
			TestFramework::assertEqual(Data::Bounds<float>(MIN, MAX).doesOverlap(Data::Bounds<float>(MAX + Data::Position<float>(.1, .1, .1), MAX + Data::Position<float>(.2, .1, .1))), false);
			TestFramework::assertEqual(Data::Bounds<float>(MIN, MAX).doesOverlap(Data::Bounds<float>(MAX + Data::Position<float>(.1, .1, .1), MAX + Data::Position<float>(.1, .2, .1))), false);
			TestFramework::assertEqual(Data::Bounds<float>(MIN, MAX).doesOverlap(Data::Bounds<float>(MAX + Data::Position<float>(.1, .1, .1), MAX + Data::Position<float>(.1, .1, .2))), false);
			TestFramework::assertEqual(Data::Bounds<float>(MIN, MAX).doesOverlap(Data::Bounds<float>(MAX + Data::Position<float>(.1, .1, .1), MAX + Data::Position<float>(.2, .2, .2))), false);
		}
	},
	{
		"Data::Bounds<int> Union",
		[]{
			const Data::Position<int> MIN1 = Data::Position<int>(34, -23, 100);
			const Data::Position<int> MAX1 = Data::Position<int>(34, -5, 234);
			const Data::Position<int> MIN2 = Data::Position<int>(-40, 20, -100);
			const Data::Position<int> MAX2 = Data::Position<int>(0, 74, -13);
			TestFramework::assertEqual(Data::Bounds<int>(MIN1, MAX1).unionWith(Data::Bounds<int>(MIN1, MAX1)), Data::Bounds<int>(MIN1, MAX1));
			TestFramework::assertEqual(Data::Bounds<int>(MIN2, MAX2).unionWith(Data::Bounds<int>(MIN2, MAX2)), Data::Bounds<int>(MIN2, MAX2));
			TestFramework::assertEqual(Data::Bounds<int>(MIN1, MAX1).unionWith(Data::Bounds<int>(MIN2, MAX2)), Data::Bounds<int>(Data::Position<int>(MIN2.getX(), MIN1.getY(), MIN2.getZ()), Data::Position<int>(MAX1.getX(), MAX2.getY(), MAX1.getZ())));
		}
	},
	{
		"Data::Bounds<float> Union",
		[]{
			const Data::Position<float> MIN1 = Data::Position<float>(34.4389, -23.24, 100.00021);
			const Data::Position<float> MAX1 = Data::Position<float>(34.4389, -5.123, 234.328891);
			const Data::Position<float> MIN2 = Data::Position<float>(-40.43, 20.88924, -100.29825);
			const Data::Position<float> MAX2 = Data::Position<float>(0., 74.002034, -13.058894);
			TestFramework::assertEqual(Data::Bounds<float>(MIN1, MAX1).unionWith(Data::Bounds<float>(MIN1, MAX1)), Data::Bounds<float>(MIN1, MAX1));
			TestFramework::assertEqual(Data::Bounds<float>(MIN2, MAX2).unionWith(Data::Bounds<float>(MIN2, MAX2)), Data::Bounds<float>(MIN2, MAX2));
			TestFramework::assertEqual(Data::Bounds<float>(MIN1, MAX1).unionWith(Data::Bounds<float>(MIN2, MAX2)), Data::Bounds<float>(Data::Position<float>(MIN2.getX(), MIN1.getY(), MIN2.getZ()), Data::Position<float>(MAX1.getX(), MAX2.getY(), MAX1.getZ())));
		}
	},
	{
		"Data::Bounds<int> Intersection",
		[]{
			const Data::Position<int> MIN1 = Data::Position<int>(34, -23, -100);
			const Data::Position<int> MAX1 = Data::Position<int>(34, -5, 234);
			const Data::Position<int> MIN2 = Data::Position<int>(-40, -20, -100);
			const Data::Position<int> MAX2 = Data::Position<int>(100, 74, -13);
			TestFramework::assertEqual(Data::Bounds<int>(MIN1, MAX1).intersectWith(Data::Bounds<int>(MIN1, MAX1)), Data::Bounds<int>(MIN1, MAX1));
			TestFramework::assertEqual(Data::Bounds<int>(MIN2, MAX2).intersectWith(Data::Bounds<int>(MIN2, MAX2)), Data::Bounds<int>(MIN2, MAX2));
			TestFramework::assertEqual(Data::Bounds<int>(MIN1, MAX1).intersectWith(Data::Bounds<int>(MIN2, MAX2)), Data::Bounds<int>(Data::Position<int>(MIN1.getX(), MIN2.getY(), MIN1.getZ()), Data::Position<int>(MAX1.getX(), MAX1.getY(), MAX2.getZ())));
		}
	},
	{
		"Data::Bounds<float> Intersection",
		[]{
			const Data::Position<float> MIN1 = Data::Position<float>(34.4389, -23.24, -100.00021);
			const Data::Position<float> MAX1 = Data::Position<float>(34.4389, -5.123, 234.328891);
			const Data::Position<float> MIN2 = Data::Position<float>(-40.43, -20.88924, -100.29825);
			const Data::Position<float> MAX2 = Data::Position<float>(100., 74.002034, -13.058894);
			TestFramework::assertEqual(Data::Bounds<float>(MIN1, MAX1).intersectWith(Data::Bounds<float>(MIN1, MAX1)), Data::Bounds<float>(MIN1, MAX1));
			TestFramework::assertEqual(Data::Bounds<float>(MIN2, MAX2).intersectWith(Data::Bounds<float>(MIN2, MAX2)), Data::Bounds<float>(MIN2, MAX2));
			TestFramework::assertEqual(Data::Bounds<float>(MIN1, MAX1).intersectWith(Data::Bounds<float>(MIN2, MAX2)), Data::Bounds<float>(Data::Position<float>(MIN1.getX(), MIN2.getY(), MIN1.getZ()), Data::Position<float>(MAX1.getX(), MAX1.getY(), MAX2.getZ())));
		}
	},
	{
		"Data::Bounds<int> Intersection None",
		[]{
			TestFramework::assertError<std::range_error>([]{ Data::Bounds<int>().intersectWith(Data::Bounds<int>(Data::Position<int>(1, 1, 1), Data::Position<int>(1, 1, 1))); });
		}
	},
	{
		"Data::Bounds<float> Intersection None",
		[]{
			TestFramework::assertError<std::range_error>([]{ Data::Bounds<float>().intersectWith(Data::Bounds<float>(Data::Position<float>(.1, .1, .1), Data::Position<float>(.1, .1, .1))); });
		}
	}
};

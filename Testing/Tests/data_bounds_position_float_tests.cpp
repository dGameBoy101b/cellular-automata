#include "data_bounds_position_float_tests.hpp"
#include "../assertion.hpp"
#include "../../Source/Data/bounds_position.hpp"

const std::map<std::string, std::function<void()>> Tests::DATA_BOUNDS_POSITION_FLOAT_TESTS =
{
	{
		"Data::Bounds<Data::Position<float>> Default Constructor",
		[]{
			Data::Bounds<Data::Position<float>> test = Data::Bounds<Data::Position<float>>();
			TestFramework::assertEqual(test.getMin(), Data::Position<float>());
			TestFramework::assertEqual(test.getMax(), Data::Position<float>());
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Initialiser Constructor",
		[]{
			const Data::Position<float> MIN = Data::Position<float>(34.4389, -23.24, 100.00021);
			const Data::Position<float> MAX = Data::Position<float>(34.4389, -5.123, 234.328891);
			Data::Bounds<Data::Position<float>> test = Data::Bounds<Data::Position<float>>(MIN, MAX);
			TestFramework::assertEqual(test.getMin(), MIN);
			TestFramework::assertEqual(test.getMax(), MAX);
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Initialiser Constructor Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<float>>(Data::Position<float>(.1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<float>>(Data::Position<float>(0., .1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<float>>(Data::Position<float>(0., 0., .1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<float>>(Data::Position<float>(), Data::Position<float>(-.1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<float>>(Data::Position<float>(), Data::Position<float>(0., -.1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<float>>(Data::Position<float>(), Data::Position<float>(0., 0., -.1)); });
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Equals",
		[]{
			const Data::Position<float> MIN = Data::Position<float>(34.4389, -23.24, 100.00021);
			const Data::Position<float> MAX = Data::Position<float>(34.4389, -5.123, 234.328891);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(), Data::Bounds<Data::Position<float>>());
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN, MAX), Data::Bounds<Data::Position<float>>(MIN, MAX));
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Not Equals",
		[]{
			const Data::Position<float> MIN = Data::Position<float>(34.4389, -23.24, 100.00021);
			const Data::Position<float> MAX = Data::Position<float>(34.4389, -5.123, 234.328891);
			TestFramework::assertNotEqual(Data::Bounds<Data::Position<float>>(), Data::Bounds<Data::Position<float>>(MIN, MAX));
			TestFramework::assertNotEqual(Data::Bounds<Data::Position<float>>(MIN, MAX), Data::Bounds<Data::Position<float>>(MIN + Data::Position<float>(1, 1, 1), MAX + Data::Position<float>(1, 1, 1)));
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Minimum and Maximum Setter",
		[]{
			const Data::Position<float> MIN = Data::Position<float>(34.4389, -23.24, 100.00021);
			const Data::Position<float> MAX = Data::Position<float>(34.4389, -5.123, 234.328891);
			Data::Bounds<Data::Position<float>> test = Data::Bounds<Data::Position<float>>();
			test.setMinMax(MIN, MAX);
			TestFramework::assertEqual(test.getMin(), MIN);
			TestFramework::assertEqual(test.getMax(), MAX);
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Minimum and Maximum Setter Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<float>>().setMinMax(Data::Position<float>(.1), Data::Position<float>()); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<float>>().setMinMax(Data::Position<float>(0., .1), Data::Position<float>()); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<float>>().setMinMax(Data::Position<float>(0., 0., .1), Data::Position<float>()); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<float>>().setMinMax(Data::Position<float>(), Data::Position<float>(-.1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<float>>().setMinMax(Data::Position<float>(), Data::Position<float>(0., -.1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<float>>().setMinMax(Data::Position<float>(), Data::Position<float>(0., 0., -.1)); });
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Minimum Setter",
		[]{
			const Data::Position<float> MIN = Data::Position<float>(-34.4389, -23.24, -100.00021);
			Data::Bounds<Data::Position<float>> test = Data::Bounds<Data::Position<float>>();
			test.setMin(MIN);
			TestFramework::assertEqual(test.getMin(), MIN);
			TestFramework::assertEqual(test.getMax(), Data::Position<float>());
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Minimum Setter Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<float>>().setMin(Data::Position<float>(.1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<float>>().setMin(Data::Position<float>(0., .1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<float>>().setMin(Data::Position<float>(0., 0., .1)); });
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Maximum Setter",
		[]{
			const Data::Position<float> MAX = Data::Position<float>(34.4389, 5.123, 234.328891);
			Data::Bounds<Data::Position<float>> test = Data::Bounds<Data::Position<float>>();
			test.setMax(MAX);
			TestFramework::assertEqual(test.getMin(), Data::Position<float>());
			TestFramework::assertEqual(test.getMax(), MAX);
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Maximum Setter Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<float>>().setMax(Data::Position<float>(-.1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<float>>().setMax(Data::Position<float>(0., -.1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Data::Bounds<Data::Position<float>>().setMax(Data::Position<float>(0., 0., -.1)); });
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Bounds Checker",
		[]{
			const Data::Position<float> MIN = Data::Position<float>(34.4389, -23.24, 100.00021);
			const Data::Position<float> MAX = Data::Position<float>(34.9389, -5.123, 234.328891);
			Data::Bounds<Data::Position<float>> test = Data::Bounds<Data::Position<float>>(MIN, MAX);
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
		"Data::Bounds<Data::Position<float>> Overlap Check",
		[]{
			const Data::Position<float> MIN = Data::Position<float>(34.4389, -23.24, 100.00021);
			const Data::Position<float> MAX = Data::Position<float>(34.9389, -5.123, 234.328891);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<float>>(MIN, MAX)), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<float>>(MIN + Data::Position<float>(.1), MAX)), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<float>>(MIN + Data::Position<float>(0., .1), MAX)), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<float>>(MIN + Data::Position<float>(0., 0., .1), MAX)), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<float>>(MIN, MAX - Data::Position<float>(.1))), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<float>>(MIN, MAX - Data::Position<float>(0., .1))), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<float>>(MIN, MAX - Data::Position<float>(0., 0., .1))), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<float>>(MIN + Data::Position<float>(.1, .1, .1), MAX - Data::Position<float>(.1, .1, .1))), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<float>>(MIN - Data::Position<float>(.1), MAX)), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<float>>(MIN - Data::Position<float>(0., .1), MAX)), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<float>>(MIN - Data::Position<float>(0., 0., .1), MAX)), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<float>>(MIN, MAX + Data::Position<float>(.1))), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<float>>(MIN, MAX + Data::Position<float>(0., .1))), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<float>>(MIN, MAX + Data::Position<float>(0., 0., .1))), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<float>>(MIN - Data::Position<float>(.1, .1, .1), MAX + Data::Position<float>(.1, .1, .1))), true);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<float>>(MIN - Data::Position<float>(.2, .1, .1), MIN - Data::Position<float>(.1, .1, .1))), false);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<float>>(MIN - Data::Position<float>(.1, .2, .1), MIN - Data::Position<float>(.1, .1, .1))), false);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<float>>(MIN - Data::Position<float>(.1, .1, .2), MIN - Data::Position<float>(.1, .1, .1))), false);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<float>>(MIN - Data::Position<float>(.2, .2, .2), MIN - Data::Position<float>(.1, .1, .1))), false);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<float>>(MAX + Data::Position<float>(.1, .1, .1), MAX + Data::Position<float>(.2, .1, .1))), false);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<float>>(MAX + Data::Position<float>(.1, .1, .1), MAX + Data::Position<float>(.1, .2, .1))), false);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<float>>(MAX + Data::Position<float>(.1, .1, .1), MAX + Data::Position<float>(.1, .1, .2))), false);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN, MAX).doesOverlap(Data::Bounds<Data::Position<float>>(MAX + Data::Position<float>(.1, .1, .1), MAX + Data::Position<float>(.2, .2, .2))), false);
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Union",
		[]{
			const Data::Position<float> MIN1 = Data::Position<float>(34.4389, -23.24, 100.00021);
			const Data::Position<float> MAX1 = Data::Position<float>(34.4389, -5.123, 234.328891);
			const Data::Position<float> MIN2 = Data::Position<float>(-40.43, 20.88924, -100.29825);
			const Data::Position<float> MAX2 = Data::Position<float>(0., 74.002034, -13.058894);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN1, MAX1).unionWith(Data::Bounds<Data::Position<float>>(MIN1, MAX1)), Data::Bounds<Data::Position<float>>(MIN1, MAX1));
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN2, MAX2).unionWith(Data::Bounds<Data::Position<float>>(MIN2, MAX2)), Data::Bounds<Data::Position<float>>(MIN2, MAX2));
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN1, MAX1).unionWith(Data::Bounds<Data::Position<float>>(MIN2, MAX2)), Data::Bounds<Data::Position<float>>(Data::Position<float>(MIN2.getX(), MIN1.getY(), MIN2.getZ()), Data::Position<float>(MAX1.getX(), MAX2.getY(), MAX1.getZ())));
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Intersection",
		[]{
			const Data::Position<float> MIN1 = Data::Position<float>(34.4389, -23.24, -100.00021);
			const Data::Position<float> MAX1 = Data::Position<float>(34.4389, -5.123, 234.328891);
			const Data::Position<float> MIN2 = Data::Position<float>(-40.43, -20.88924, -100.29825);
			const Data::Position<float> MAX2 = Data::Position<float>(100., 74.002034, -13.058894);
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN1, MAX1).intersectWith(Data::Bounds<Data::Position<float>>(MIN1, MAX1)), Data::Bounds<Data::Position<float>>(MIN1, MAX1));
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN2, MAX2).intersectWith(Data::Bounds<Data::Position<float>>(MIN2, MAX2)), Data::Bounds<Data::Position<float>>(MIN2, MAX2));
			TestFramework::assertEqual(Data::Bounds<Data::Position<float>>(MIN1, MAX1).intersectWith(Data::Bounds<Data::Position<float>>(MIN2, MAX2)), Data::Bounds<Data::Position<float>>(Data::Position<float>(MIN1.getX(), MIN2.getY(), MIN1.getZ()), Data::Position<float>(MAX1.getX(), MAX1.getY(), MAX2.getZ())));
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Intersection None",
		[]{
			TestFramework::assertError<std::range_error>([]{ Data::Bounds<Data::Position<float>>().intersectWith(Data::Bounds<Data::Position<float>>(Data::Position<float>(.1, .1, .1), Data::Position<float>(.1, .1, .1))); });
		}
	}
};

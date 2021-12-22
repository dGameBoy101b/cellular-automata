#include "bounds_position_float_tests.hpp"
#include "Testing/assertion.hpp"
#include "Source/Data/bounds_position.hpp"

using namespace CellularAutomata::Data;

const std::map<std::string, std::function<void()>> Tests::Data::BOUNDS_POSITION_FLOAT_TESTS =
{
	{
		"Data::Bounds<Data::Position<float>> Default Constructor",
		[]{
			Bounds<Position<float>> test = {};
			TestFramework::assertEqual(test.getMin(), Position<float>());
			TestFramework::assertEqual(test.getMax(), Position<float>());
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Initialiser Constructor",
		[]{
			const Position<float> MIN = {34.4389, -23.24, 100.00021};
			const Position<float> MAX = {34.4389, -5.123, 234.328891};
			Bounds<Position<float>> test = {MIN, MAX};
			TestFramework::assertEqual(test.getMin(), MIN);
			TestFramework::assertEqual(test.getMax(), MAX);
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Initialiser Constructor Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{
				Bounds<Position<float>>(Position<float>(.1));
			});
			TestFramework::assertError<std::invalid_argument>([]{
				Bounds<Position<float>>(Position<float>(0., .1));
			});
			TestFramework::assertError<std::invalid_argument>([]{
				Bounds<Position<float>>(Position<float>(0., 0., .1));
			});
			TestFramework::assertError<std::invalid_argument>([]{
				Bounds<Position<float>>(Position<float>(), Position<float>(-.1));
			});
			TestFramework::assertError<std::invalid_argument>([]{
				Bounds<Position<float>>(Position<float>(), Position<float>(0., -.1));
			});
			TestFramework::assertError<std::invalid_argument>([]{
				Bounds<Position<float>>(Position<float>(), Position<float>(0., 0., -.1));
			});
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Equals",
		[]{
			const Position<float> MIN = {34.4389, -23.24, 100.00021};
			const Position<float> MAX = {34.4389, -5.123, 234.328891};
			TestFramework::assertEqual(Bounds<Position<float>>(), Bounds<Position<float>>());
			TestFramework::assertEqual(Bounds<Position<float>>(MIN, MAX), Bounds<Position<float>>(MIN, MAX));
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Not Equals",
		[]{
			const Position<float> MIN = {34.4389, -23.24, 100.00021};
			const Position<float> MAX = {34.4389, -5.123, 234.328891};
			TestFramework::assertNotEqual(Bounds<Position<float>>(), Bounds<Position<float>>(MIN, MAX));
			TestFramework::assertNotEqual(Bounds<Position<float>>(MIN, MAX), Bounds<Position<float>>(MIN + Position<float>(1, 1, 1), MAX + Position<float>(1, 1, 1)));
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Minimum and Maximum Setter",
		[]{
			const Position<float> MIN = {34.4389, -23.24, 100.00021};
			const Position<float> MAX = {34.4389, -5.123, 234.328891};
			Bounds<Position<float>> test = {};
			test.setMinMax(MIN, MAX);
			TestFramework::assertEqual(test.getMin(), MIN);
			TestFramework::assertEqual(test.getMax(), MAX);
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Minimum and Maximum Setter Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<float>>().setMinMax(Position<float>(.1), Position<float>()); });
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<float>>().setMinMax(Position<float>(0., .1), Position<float>()); });
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<float>>().setMinMax(Position<float>(0., 0., .1), Position<float>()); });
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<float>>().setMinMax(Position<float>(), Position<float>(-.1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<float>>().setMinMax(Position<float>(), Position<float>(0., -.1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<float>>().setMinMax(Position<float>(), Position<float>(0., 0., -.1)); });
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Minimum Setter",
		[]{
			const Position<float> MIN = {-34.4389, -23.24, -100.00021};
			Bounds<Position<float>> test = {};
			test.setMin(MIN);
			TestFramework::assertEqual(test.getMin(), MIN);
			TestFramework::assertEqual(test.getMax(), Position<float>());
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Minimum Setter Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<float>>().setMin(Position<float>(.1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<float>>().setMin(Position<float>(0., .1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<float>>().setMin(Position<float>(0., 0., .1)); });
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Maximum Setter",
		[]{
			const Position<float> MAX = {34.4389, 5.123, 234.328891};
			Bounds<Position<float>> test = {};
			test.setMax(MAX);
			TestFramework::assertEqual(test.getMin(), Position<float>());
			TestFramework::assertEqual(test.getMax(), MAX);
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Maximum Setter Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<float>>().setMax(Position<float>(-.1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<float>>().setMax(Position<float>(0., -.1)); });
			TestFramework::assertError<std::invalid_argument>([]{ Bounds<Position<float>>().setMax(Position<float>(0., 0., -.1)); });
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Bounds Checker",
		[]{
			const Position<float> MIN = {34.4389, -23.24, 100.00021};
			const Position<float> MAX = {34.9389, -5.123, 234.328891};
			Bounds<Position<float>> test = {MIN, MAX};
			TestFramework::assertEqual(test.isWithin(MIN), true);
			TestFramework::assertEqual(test.isWithin(MIN + Position<float>(.1)), true);
			TestFramework::assertEqual(test.isWithin(MIN + Position<float>(0, .1)), true);
			TestFramework::assertEqual(test.isWithin(MIN + Position<float>(0, 0, .1)), true);
			TestFramework::assertEqual(test.isWithin(MIN + Position<float>(.1, .1)), true);
			TestFramework::assertEqual(test.isWithin(MIN + Position<float>(.1, 0, .1)), true);
			TestFramework::assertEqual(test.isWithin(MIN + Position<float>(0, .1, .1)), true);
			TestFramework::assertEqual(test.isWithin(MIN + Position<float>(.1, .1, .1)), true);
			TestFramework::assertEqual(test.isWithin(MAX), true);
			TestFramework::assertEqual(test.isWithin(MAX - Position<float>(.1)), true);
			TestFramework::assertEqual(test.isWithin(MAX - Position<float>(0, .1)), true);
			TestFramework::assertEqual(test.isWithin(MAX - Position<float>(0, 0, .1)), true);
			TestFramework::assertEqual(test.isWithin(MAX - Position<float>(.1, .1)), true);
			TestFramework::assertEqual(test.isWithin(MAX - Position<float>(.1, 0, .1)), true);
			TestFramework::assertEqual(test.isWithin(MAX - Position<float>(0, .1, .1)), true);
			TestFramework::assertEqual(test.isWithin(MAX - Position<float>(.1, .1, .1)), true);
			TestFramework::assertEqual(test.isWithin(Position<float>(MIN.getX(), MIN.getY(), MAX.getZ())), true);
			TestFramework::assertEqual(test.isWithin(Position<float>(MIN.getX(), MAX.getY(), MIN.getZ())), true);
			TestFramework::assertEqual(test.isWithin(Position<float>(MAX.getX(), MIN.getY(), MIN.getZ())), true);
			TestFramework::assertEqual(test.isWithin(Position<float>(MIN.getX(), MAX.getY(), MAX.getZ())), true);
			TestFramework::assertEqual(test.isWithin(Position<float>(MAX.getX(), MIN.getY(), MAX.getZ())), true);
			TestFramework::assertEqual(test.isWithin(Position<float>(MAX.getX(), MAX.getY(), MIN.getZ())), true);
			TestFramework::assertEqual(test.isWithin(MIN - Position<float>(.1)), false);
			TestFramework::assertEqual(test.isWithin(MIN - Position<float>(0, .1)), false);
			TestFramework::assertEqual(test.isWithin(MIN - Position<float>(0, 0, .1)), false);
			TestFramework::assertEqual(test.isWithin(MIN - Position<float>(.1, .1)), false);
			TestFramework::assertEqual(test.isWithin(MIN - Position<float>(.1, 0, .1)), false);
			TestFramework::assertEqual(test.isWithin(MIN - Position<float>(0, .1, .1)), false);
			TestFramework::assertEqual(test.isWithin(MIN - Position<float>(.1, .1, .1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Position<float>(.1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Position<float>(0, .1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Position<float>(0, 0, .1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Position<float>(.1, .1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Position<float>(.1, 0, .1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Position<float>(0, .1, .1)), false);
			TestFramework::assertEqual(test.isWithin(MAX + Position<float>(.1, .1, .1)), false);
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Overlap Check",
		[]{
			const Position<float> MIN = {34.4389, -23.24, 100.00021};
			const Position<float> MAX = {34.9389, -5.123, 234.328891};
			TestFramework::assertEqual(Bounds<Position<float>>(MIN, MAX).doesOverlap(Bounds<Position<float>>(MIN, MAX)), true);
			TestFramework::assertEqual(Bounds<Position<float>>(MIN, MAX).doesOverlap(Bounds<Position<float>>(MIN + Position<float>(.1), MAX)), true);
			TestFramework::assertEqual(Bounds<Position<float>>(MIN, MAX).doesOverlap(Bounds<Position<float>>(MIN + Position<float>(0., .1), MAX)), true);
			TestFramework::assertEqual(Bounds<Position<float>>(MIN, MAX).doesOverlap(Bounds<Position<float>>(MIN + Position<float>(0., 0., .1), MAX)), true);
			TestFramework::assertEqual(Bounds<Position<float>>(MIN, MAX).doesOverlap(Bounds<Position<float>>(MIN, MAX - Position<float>(.1))), true);
			TestFramework::assertEqual(Bounds<Position<float>>(MIN, MAX).doesOverlap(Bounds<Position<float>>(MIN, MAX - Position<float>(0., .1))), true);
			TestFramework::assertEqual(Bounds<Position<float>>(MIN, MAX).doesOverlap(Bounds<Position<float>>(MIN, MAX - Position<float>(0., 0., .1))), true);
			TestFramework::assertEqual(Bounds<Position<float>>(MIN, MAX).doesOverlap(Bounds<Position<float>>(MIN + Position<float>(.1, .1, .1), MAX - Position<float>(.1, .1, .1))), true);
			TestFramework::assertEqual(Bounds<Position<float>>(MIN, MAX).doesOverlap(Bounds<Position<float>>(MIN - Position<float>(.1), MAX)), true);
			TestFramework::assertEqual(Bounds<Position<float>>(MIN, MAX).doesOverlap(Bounds<Position<float>>(MIN - Position<float>(0., .1), MAX)), true);
			TestFramework::assertEqual(Bounds<Position<float>>(MIN, MAX).doesOverlap(Bounds<Position<float>>(MIN - Position<float>(0., 0., .1), MAX)), true);
			TestFramework::assertEqual(Bounds<Position<float>>(MIN, MAX).doesOverlap(Bounds<Position<float>>(MIN, MAX + Position<float>(.1))), true);
			TestFramework::assertEqual(Bounds<Position<float>>(MIN, MAX).doesOverlap(Bounds<Position<float>>(MIN, MAX + Position<float>(0., .1))), true);
			TestFramework::assertEqual(Bounds<Position<float>>(MIN, MAX).doesOverlap(Bounds<Position<float>>(MIN, MAX + Position<float>(0., 0., .1))), true);
			TestFramework::assertEqual(Bounds<Position<float>>(MIN, MAX).doesOverlap(Bounds<Position<float>>(MIN - Position<float>(.1, .1, .1), MAX + Position<float>(.1, .1, .1))), true);
			TestFramework::assertEqual(Bounds<Position<float>>(MIN, MAX).doesOverlap(Bounds<Position<float>>(MIN - Position<float>(.2, .1, .1), MIN - Position<float>(.1, .1, .1))), false);
			TestFramework::assertEqual(Bounds<Position<float>>(MIN, MAX).doesOverlap(Bounds<Position<float>>(MIN - Position<float>(.1, .2, .1), MIN - Position<float>(.1, .1, .1))), false);
			TestFramework::assertEqual(Bounds<Position<float>>(MIN, MAX).doesOverlap(Bounds<Position<float>>(MIN - Position<float>(.1, .1, .2), MIN - Position<float>(.1, .1, .1))), false);
			TestFramework::assertEqual(Bounds<Position<float>>(MIN, MAX).doesOverlap(Bounds<Position<float>>(MIN - Position<float>(.2, .2, .2), MIN - Position<float>(.1, .1, .1))), false);
			TestFramework::assertEqual(Bounds<Position<float>>(MIN, MAX).doesOverlap(Bounds<Position<float>>(MAX + Position<float>(.1, .1, .1), MAX + Position<float>(.2, .1, .1))), false);
			TestFramework::assertEqual(Bounds<Position<float>>(MIN, MAX).doesOverlap(Bounds<Position<float>>(MAX + Position<float>(.1, .1, .1), MAX + Position<float>(.1, .2, .1))), false);
			TestFramework::assertEqual(Bounds<Position<float>>(MIN, MAX).doesOverlap(Bounds<Position<float>>(MAX + Position<float>(.1, .1, .1), MAX + Position<float>(.1, .1, .2))), false);
			TestFramework::assertEqual(Bounds<Position<float>>(MIN, MAX).doesOverlap(Bounds<Position<float>>(MAX + Position<float>(.1, .1, .1), MAX + Position<float>(.2, .2, .2))), false);
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Union",
		[]{
			const Position<float> MIN1 = {34.4389, -23.24, 100.00021};
			const Position<float> MAX1 = {34.4389, -5.123, 234.328891};
			const Position<float> MIN2 = {-40.43, 20.88924, -100.29825};
			const Position<float> MAX2 = {0., 74.002034, -13.058894};
			TestFramework::assertEqual(Bounds<Position<float>>(MIN1, MAX1).unionWith(Bounds<Position<float>>(MIN1, MAX1)), Bounds<Position<float>>(MIN1, MAX1));
			TestFramework::assertEqual(Bounds<Position<float>>(MIN2, MAX2).unionWith(Bounds<Position<float>>(MIN2, MAX2)), Bounds<Position<float>>(MIN2, MAX2));
			TestFramework::assertEqual(Bounds<Position<float>>(MIN1, MAX1).unionWith(Bounds<Position<float>>(MIN2, MAX2)), Bounds<Position<float>>(Position<float>(MIN2.getX(), MIN1.getY(), MIN2.getZ()), Position<float>(MAX1.getX(), MAX2.getY(), MAX1.getZ())));
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Intersection",
		[]{
			const Position<float> MIN1 = {34.4389, -23.24, -100.00021};
			const Position<float> MAX1 = {34.4389, -5.123, 234.328891};
			const Position<float> MIN2 = {-40.43, -20.88924, -100.29825};
			const Position<float> MAX2 = {100., 74.002034, -13.058894};
			TestFramework::assertEqual(Bounds<Position<float>>(MIN1, MAX1).intersectWith(Bounds<Position<float>>(MIN1, MAX1)), Bounds<Position<float>>(MIN1, MAX1));
			TestFramework::assertEqual(Bounds<Position<float>>(MIN2, MAX2).intersectWith(Bounds<Position<float>>(MIN2, MAX2)), Bounds<Position<float>>(MIN2, MAX2));
			TestFramework::assertEqual(Bounds<Position<float>>(MIN1, MAX1).intersectWith(Bounds<Position<float>>(MIN2, MAX2)), Bounds<Position<float>>(Position<float>(MIN1.getX(), MIN2.getY(), MIN1.getZ()), Position<float>(MAX1.getX(), MAX1.getY(), MAX2.getZ())));
		}
	},
	{
		"Data::Bounds<Data::Position<float>> Intersection None",
		[]{
			TestFramework::assertError<std::range_error>([]{ Bounds<Position<float>>().intersectWith(Bounds<Position<float>>(Position<float>(.1, .1, .1), Position<float>(.1, .1, .1))); });
		}
	}
};

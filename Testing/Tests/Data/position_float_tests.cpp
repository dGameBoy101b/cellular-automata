#include "position_float_tests.hpp"
//#include <utility>
//#include <initializer_list>
#include "Testing/assertion.hpp"
#include "Source/Data/position.hpp"

using namespace CellularAutomata::Data;

const std::map<std::string, std::function<void()>> Tests::Data::POSITION_FLOAT_TESTS =
{
	{
		"Data::Position<float> Default Constructor",
		[]{
			Position<float> test = {};
			TestFramework::assertEqual(test.getX(), 0.f);
			TestFramework::assertEqual(test.getY(), 0.f);
			TestFramework::assertEqual(test.getZ(), 0.f);
		}
	},
	{
		"Data::Position<float> Initialiser Constructor",
		[]{
			const float X = .004232589;
			const float Y = -29804982.4893;
			const float Z = -390.38943;
			Position<float> test = {X, Y, Z};
			TestFramework::assertEqual(test.getX(), X);
			TestFramework::assertEqual(test.getY(), Y);
			TestFramework::assertEqual(test.getZ(), Z);
		}
	},
	{
		"Data::Position<float> X Setter",
		[]{
			const float X = 28409.3845018;
			Position<float> test = {};
			test.setX(X);
			TestFramework::assertEqual(test.getX(), X);
		}
	},
	{
		"Data::Position<float> Y Setter",
		[]{
			const float Y = -289434.244823;
			Position<float> test = {};
			test.setY(Y);
			TestFramework::assertEqual(test.getY(), Y);
		}
	},
	{
		"Data::Position<float> Z Setter",
		[]{
			const float Z = 2092.3248;
			Position<float> test = {};
			test.setZ(Z);
			TestFramework::assertEqual(test.getZ(), Z);
		}
	},
	{
		"Data::Position<float> Equality",
		[]{
			const float X = -4930.489104;
			const float Y = 284;
			const float Z = 3893840.34849;
			TestFramework::assertEqual(Position<float>(X, Y, Z), Position<float>(X, Y, Z));
		}
	},
	{
		"Data::Position<float> Inequality",
		[]{
			const float X = -489.3000324;
			const float Y = 28900243.48939;
			const float Z = 0;
			TestFramework::assertNotEqual(Position<float>(X, Y, Z), Position<float>(X + 1, Y + 1, Z + 1));
		}
	},
	{
		"Data::Position<float> Addition",
		[]{
			const float X1 = 48902.4895092747;
			const float X2 = -9048.58904;
			const float Y1 = -48959.4389284;
			const float Y2 = -19.000043;
			const float Z1 = 0;
			const float Z2 = 0.4799972;
			TestFramework::assertEqual(Position<float>(X1, Y1, Z1) + Position<float>(X2, Y2, Z2), Position<float>(X1 + X2, Y1 + Y2, Z1 + Z2));
		}
	},
	{
		"Data::Position<float> Subtraction",
		[]{
			const float X1 = -348.38902;
			const float X2 = -4893.384917;
			const float Y1 = 0;
			const float Y2 = 489.4839;
			const float Z1 = 100.493048;
			const float Z2 = 0.004034;
			TestFramework::assertEqual(Position<float>(X1, Y1, Z1) - Position<float>(X2, Y2, Z2), Position<float>(X1 - X2, Y1 - Y2, Z1 - Z2));
		}
	},
	{
		"Data::Position<float> Multiplication",
		[]{
			const float X = 0.224;
			const float Y = -139.48;
			const float Z = 1883.0;
			const float S = 1.2;
			TestFramework::assertEqual(Position<float>(X, Y, Z) * S, Position<float>(X * S, Y * S, Z * S));
		}
	},
	{
		"Data::Position<float> Division",
		[]{
			const float X = 7718333.490213;
			const float Y = -4895.00001234;
			const float Z = 0.4824;
			const float S = 4.82;
			TestFramework::assertEqual(Position<float>(X, Y, Z) / S, Position<float>(X / S, Y / S, Z / S));
		}
	},
	{
		"Data::Position<float> Negation",
		[]{
			const float X = 0;
			const float Y = 37772.900341;
			const float Z = -939.38999234;
			TestFramework::assertEqual(-Position<float>(X, Y, Z), Position<float>(-X, -Y, -Z));
		}
	},
	{
		"Data::Position<float> Addition Assignment",
		[]{
			const float X1 = 0;
			const float X2 = -489993.4899;
			const float Y1 = -999.00023;
			const float Y2 = 100434.88;
			const float Z1 = 0.28899003;
			const float Z2 = -0.432243;
			Position<float> test = {X1, Y1, Z1};
			test += Position<float>(X2, Y2, Z2);
			TestFramework::assertEqual(test, Position<float>(X1, Y1, Z1) + Position<float>(X2, Y2, Z2));
		}
	},
	{
		"Data::Position<float> Subtraction Assignment",
		[]{
			const float X1 = -2934.002;
			const float X2 = 0;
			const float Y1 = 49994.39902;
			const float Y2 = -100043.30002;
			const float Z1 = -294.299;
			const float Z2 = 23.490992;
			Position<float> test = {X1, Y1, Z1};
			test -= Position<float>(X2, Y2, Z2);
			TestFramework::assertEqual(test, Position<float>(X1, Y1, Z1) - Position<float>(X2, Y2, Z2));
		}
	},
	{
		"Data::Position<float> Multiplication Assignment",
		[]{
			const float X = -288.384;
			const float Y = 2894.828;
			const float Z = 333.002;
			const float S = -3.5;
			Position<float> test = {X, Y, Z};
			test *= S;
			TestFramework::assertEqual(test, Position<float>(X, Y, Z) * S);
		}
	},
	{
		"Data::Position<float> Division Assignment",
		[]{
			const float X = 4494.2901;
			const float Y = -23.002;
			const float Z = 0;
			const float S = -0.034;
			Position<float> test = {X, Y, Z};
			test /= S;
			TestFramework::assertEqual(test, Position<float>(X, Y, Z) / S);
		}
	}
};

#include "position_int_tests.hpp"
//#include <utility>
//#include <initializer_list>
#include "Testing/assertion.hpp"
#include "Source/Data/position.hpp"

using namespace CellularAutomata::Data;

const std::map<std::string, std::function<void()>> Tests::Data::POSITION_INT_TESTS =
{
	{
		"Data::Position<int> Default Constructor",
		[]{
			Position<int> test = {};
			TestFramework::assertEqual(test.getX(), 0);
			TestFramework::assertEqual(test.getY(), 0);
			TestFramework::assertEqual(test.getZ(), 0);
		}
	},
	{
		"Data::Position<int> Initialiser Constructor",
		[]{
			const int X = 274;
			const int Y = 4892;
			const int Z = -43485682;
			Position<int> test = {X, Y, Z};
			TestFramework::assertEqual(test.getX(), X);
			TestFramework::assertEqual(test.getY(), Y);
			TestFramework::assertEqual(test.getZ(), Z);
		}
	},
	{
		"Data::Position<int> X Setter",
		[]{
			const int X = -389032749;
			Position<int> test = {};
			test.setX(X);
			TestFramework::assertEqual(test.getX(), X);
		}
	},
	{
		"Data::Position<int> Y Setter",
		[]{
			const int Y = 439099210;
			Position<int> test = {};
			test.setY(Y);
			TestFramework::assertEqual(test.getY(), Y);
		}
	},
	{
		"Data::Position<int> Z Setter",
		[]{
			const int Z = 2843;
			Position<int> test = {};
			test.setZ(Z);
			TestFramework::assertEqual(test.getZ(), Z);
		}
	},
	{
		"Data::Position<int> Equality",
		[]{
			const int X = 2904;
			const int Y = 28043094;
			const int Z = -284928;
			TestFramework::assertEqual(Position<int>(X, Y, Z), Position<int>(X, Y, Z));
		}
	},
	{
		"Data::Position<int> Inequality",
		[]{
			const int X = 389994;
			const int Y = 0;
			const int Z = -499903;
			TestFramework::assertNotEqual(Position<int>(X, Y, Z), Position<int>(X + 1, Y + 1, Z + 1));
		}
	},
	{
		"Data::Position<int> Addition",
		[]{
			const int X1 = 3894;
			const int X2 = -4043;
			const int Y1 = -438;
			const int Y2 = 0;
			const int Z1 = 4839205;
			const int Z2 = -48935;
			TestFramework::assertEqual(Position<int>(X1, Y1, Z1) + Position<int>(X2, Y2, Z2), Position<int>(X1 + X2, Y1 + Y2, Z1 + Z2));
		}
	},
	{
		"Data::Position<int> Subtraction",
		[]{
			const int X1 = -3895;
			const int X2 = 98004;
			const int Y1 = 0;
			const int Y2 = -4099902;
			const int Z1 = 4892654;
			const int Z2 = 0;
			TestFramework::assertEqual(Position<int>(X1, Y1, Z1) - Position<int>(X2, Y2, Z2), Position<int>(X1 - X2, Y1 - Y2, Z1 - Z2));
		}
	},
	{
		"Data::Position<int> Multiplication",
		[]{
			const int X = 13;
			const int Y = -48;
			const int Z = 100;
			const int S = -5;
			TestFramework::assertEqual(Position<int>(X, Y, Z) * S, Position<int>(X * S, Y * S, Z * S));
		}
	},
	{
		"Data::Position<int> Division",
		[]{
			const int X = 4893;
			const int Y = -389234;
			const int Z = 0;
			const int S = -3;
			TestFramework::assertEqual(Position<int>(X, Y, Z) / S, Position<int>(X / S, Y / S, Z / S));
		}
	},
	{
		"Data::Position<int> Negation",
		[]{
			const int X = 222345;
			const int Y = -37859;
			const int Z = 0;
			TestFramework::assertEqual(-Position<int>(X, Y, Z), Position<int>(-X, -Y, -Z));
		}
	},
	{
		"Data::Position<int> Addition Assignment",
		[]{
			const int X1 = -4893;
			const int X2 = 8893556;
			const int Y1 = 889388;
			const int Y2 = 0;
			const int Z1 = -87834;
			const int Z2 = -8930478;
			Position<int> test = {X1, Y1, Z1};
			test += Position<int>(X2, Y2, Z2);
			TestFramework::assertEqual(test, Position<int>(X1, Y1, Z1) + Position<int>(X2, Y2, Z2));
		}
	},
	{
		"Data::Position<int> Subtraction Assignment",
		[]{
			const int X1 = 3892;
			const int X2 = 0;
			const int Y1 = -48;
			const int Y2 = -2894;
			const int Z1 = 78;
			const int Z2 = -488889;
			Position<int> test = {X1, Y1, Z1};
			test -= Position<int>(X2, Y2, Z2);
			TestFramework::assertEqual(test, Position<int>(X1, Y1, Z1) - Position<int>(X2, Y2, Z2));
		}
	},
	{
		"Data::Position<int> Multiplication Assignment",
		[]{
			const int X = 2894;
			const int Y = 0;
			const int Z = -43;
			const int S = 4;
			Position<int> test = {X, Y, Z};
			test *= S;
			TestFramework::assertEqual(test, Position<int>(X, Y, Z) * S);
		}
	},
	{
		"Data::Position<int> Division Assignment",
		[]{
			const int X = 389294;
			const int Y = -2989439;
			const int Z = 0;
			const int S = -12;
			Position<int> test = {X, Y, Z};
			test /= S;
			TestFramework::assertEqual(test, Position<int>(X, Y, Z) / S);
		}
	}
};

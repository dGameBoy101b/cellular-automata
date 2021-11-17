#include "DATA_POSITION_TESTS.hpp"
#include <utility>
#include <initializer_list>
#include "../assertion.hpp"
#include "../../Source/Data/position.hpp"

namespace Tests
{
	const std::map<std::string, std::function<void()>> DATA_POSITION_TESTS =
	{
		{
			"Data::Position<int> Default Constructor",
			[]{
				Data::Position<int> test = Data::Position<int>();
				TestFramework::assertEqual(test.getX(), 0);
				TestFramework::assertEqual(test.getY(), 0);
				TestFramework::assertEqual(test.getZ(), 0);
			}
		},
		{
			"Data::Position<float> Default Constructor",
			[]{
				Data::Position<float> test = Data::Position<float>();
				TestFramework::assertEqual(test.getX(), 0.f);
				TestFramework::assertEqual(test.getY(), 0.f);
				TestFramework::assertEqual(test.getZ(), 0.f);
			}
		},
		{
			"Data::Position<int> Initialiser Constructor",
			[]{
				const int X = 274;
				const int Y = 4892;
				const int Z = -43485682;
				Data::Position<int> test = Data::Position<int>(X, Y, Z);
				TestFramework::assertEqual(test.getX(), X);
				TestFramework::assertEqual(test.getY(), Y);
				TestFramework::assertEqual(test.getZ(), Z);
			}
		},
		{
			"Data::Position<float> Initialiser Constructor",
			[]{
				const float X = .004232589;
				const float Y = -29804982.4893;
				const float Z = -390.38943;
				Data::Position<float> test = Data::Position<float>(X, Y, Z);
				TestFramework::assertEqual(test.getX(), X);
				TestFramework::assertEqual(test.getY(), Y);
				TestFramework::assertEqual(test.getZ(), Z);
			}
		},
		{
			"Data::Position<int> X Setter",
			[]{
				const int X = -389032749;
				Data::Position<int> test = Data::Position<int>();
				test.setX(X);
				TestFramework::assertEqual(test.getX(), X);
			}
		},
		{
			"Data::Position<float> X Setter",
			[]{
				const float X = 28409.3845018;
				Data::Position<float> test = Data::Position<float>();
				test.setX(X);
				TestFramework::assertEqual(test.getX(), X);
			}
		},
		{
			"Data::Position<int> Y Setter",
			[]{
				const int Y = 439099210;
				Data::Position<int> test = Data::Position<int>();
				test.setY(Y);
				TestFramework::assertEqual(test.getY(), Y);
			}
		},
		{
			"Data::Position<float> Y Setter",
			[]{
				const float Y = -289434.244823;
				Data::Position<float> test = Data::Position<float>();
				test.setY(Y);
				TestFramework::assertEqual(test.getY(), Y);
			}
		},
		{
			"Data::Position<int> Z Setter",
			[]{
				const int Z = 2843;
				Data::Position<int> test = Data::Position<int>();
				test.setZ(Z);
				TestFramework::assertEqual(test.getZ(), Z);
			}
		},
		{
			"Data::Position<float> Z Setter",
			[]{
				const float Z = 2092.3248;
				Data::Position<float> test = Data::Position<float>();
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
				TestFramework::assertEqual(Data::Position<int>(X, Y, Z), Data::Position<int>(X, Y, Z));
			}
		},
		{
			"Data::Position<float> Equality",
			[]{
				const float X = -4930.489104;
				const float Y = 284;
				const float Z = 3893840.34849;
				TestFramework::assertEqual(Data::Position<float>(X, Y, Z), Data::Position<float>(X, Y, Z));
			}
		},
		{
			"Data::Position<int> Inequality",
			[]{
				const int X = 389994;
				const int Y = 0;
				const int Z = -499903;
				TestFramework::assertNotEqual(Data::Position<int>(X, Y, Z), Data::Position<int>(X + 1, Y + 1, Z + 1));
			}
		},
		{
			"Data::Position<float> Inequality",
			[]{
				const float X = -489.3000324;
				const float Y = 28900243.48939;
				const float Z = 0;
				TestFramework::assertNotEqual(Data::Position<float>(X, Y, Z), Data::Position<float>(X + 1, Y + 1, Z + 1));
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
				TestFramework::assertEqual(Data::Position<int>(X1, Y1, Z1) + Data::Position<int>(X2, Y2, Z2), Data::Position<int>(X1 + X2, Y1 + Y2, Z1 + Z2));
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
				TestFramework::assertEqual(Data::Position<float>(X1, Y1, Z1) + Data::Position<float>(X2, Y2, Z2), Data::Position<float>(X1 + X2, Y1 + Y2, Z1 + Z2));
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
				TestFramework::assertEqual(Data::Position<int>(X1, Y1, Z1) - Data::Position<int>(X2, Y2, Z2), Data::Position<int>(X1 - X2, Y1 - Y2, Z1 - Z2));
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
				TestFramework::assertEqual(Data::Position<float>(X1, Y1, Z1) - Data::Position<float>(X2, Y2, Z2), Data::Position<float>(X1 - X2, Y1 - Y2, Z1 - Z2));
			}
		},
		{
			"Data::Position<int> Multiplication",
			[]{
				const int X = 13;
				const int Y = -48;
				const int Z = 100;
				const int S = -5;
				TestFramework::assertEqual(Data::Position<int>(X, Y, Z) * S, Data::Position<int>(X * S, Y * S, Z * S));
			}
		},
		{
			"Data::Position<float> Multiplication",
			[]{
				const float X = 0.224;
				const float Y = -139.48;
				const float Z = 1883.0;
				const float S = 1.2;
				TestFramework::assertEqual(Data::Position<float>(X, Y, Z) * S, Data::Position<float>(X * S, Y * S, Z * S));
			}
		},
		{
			"Data::Position<int> Division",
			[]{
				const int X = 4893;
				const int Y = -389234;
				const int Z = 0;
				const int S = -3;
				TestFramework::assertEqual(Data::Position<int>(X, Y, Z) / S, Data::Position<int>(X / S, Y / S, Z / S));
			}
		},
		{
			"Data::Position<float> Division",
			[]{
				const float X = 7718333.490213;
				const float Y = -4895.00001234;
				const float Z = 0.4824;
				const float S = 4.82;
				TestFramework::assertEqual(Data::Position<float>(X, Y, Z) / S, Data::Position<float>(X / S, Y / S, Z / S));
			}
		},
		{
			"Data::Position<int> Negation",
			[]{
				const int X = 222345;
				const int Y = -37859;
				const int Z = 0;
				TestFramework::assertEqual(-Data::Position<int>(X, Y, Z), Data::Position<int>(-X, -Y, -Z));
			}
		},
		{
			"Data::Position<float> Negation",
			[]{
				const float X = 0;
				const float Y = 37772.900341;
				const float Z = -939.38999234;
				TestFramework::assertEqual(-Data::Position<float>(X, Y, Z), Data::Position<float>(-X, -Y, -Z));
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
				Data::Position<int> test = Data::Position<int>(X1, Y1, Z1);
				test += Data::Position<int>(X2, Y2, Z2);
				TestFramework::assertEqual(test, Data::Position<int>(X1, Y1, Z1) + Data::Position<int>(X2, Y2, Z2));
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
				Data::Position<float> test = Data::Position<float>(X1, Y1, Z1);
				test += Data::Position<float>(X2, Y2, Z2);
				TestFramework::assertEqual(test, Data::Position<float>(X1, Y1, Z1) + Data::Position<float>(X2, Y2, Z2));
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
				Data::Position<int> test = Data::Position<int>(X1, Y1, Z1);
				test -= Data::Position<int>(X2, Y2, Z2);
				TestFramework::assertEqual(test, Data::Position<int>(X1, Y1, Z1) - Data::Position<int>(X2, Y2, Z2));
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
				Data::Position<float> test = Data::Position<float>(X1, Y1, Z1);
				test -= Data::Position<float>(X2, Y2, Z2);
				TestFramework::assertEqual(test, Data::Position<float>(X1, Y1, Z1) - Data::Position<float>(X2, Y2, Z2));
			}
		},
		{
			"Data::Position<int> Multiplication Assignment",
			[]{
				const int X = 2894;
				const int Y = 0;
				const int Z = -43;
				const int S = 4;
				Data::Position<int> test = Data::Position<int>(X, Y, Z);
				test *= S;
				TestFramework::assertEqual(test, Data::Position<int>(X, Y, Z) * S);
			}
		},
		{
			"Data::Position<float> Multiplication Assignment",
			[]{
				const float X = -288.384;
				const float Y = 2894.828;
				const float Z = 333.002;
				const float S = -3.5;
				Data::Position<float> test = Data::Position<float>(X, Y, Z);
				test *= S;
				TestFramework::assertEqual(test, Data::Position<float>(X, Y, Z) * S);
			}
		},
		{
			"Data::Position<int> Division Assignment",
			[]{
				const int X = 389294;
				const int Y = -2989439;
				const int Z = 0;
				const int S = -12;
				Data::Position<int> test = Data::Position<int>(X, Y, Z);
				test /= S;
				TestFramework::assertEqual(test, Data::Position<int>(X, Y, Z) / S);
			}
		},
		{
			"Data::Position<float> Division Assignment",
			[]{
				const float X = 4494.2901;
				const float Y = -23.002;
				const float Z = 0;
				const float S = -0.034;
				Data::Position<float> test = Data::Position<float>(X, Y, Z);
				test /= S;
				TestFramework::assertEqual(test, Data::Position<float>(X, Y, Z) / S);
			}
		}
	};
}

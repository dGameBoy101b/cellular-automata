#include "data_colour_tests.hpp"
#include <utility>
#include <initializer_list>
#include "../assertion.hpp"
#include "../../Source/Data/colour.hpp"

namespace Tests
{
	const std::map<std::string, std::function<void()>> DATA_COLOUR_TESTS =
	{
		{
			"Data::Colour Default Constructor",
			[]{
				Data::Colour test = Data::Colour();
				TestFramework::assertEqual(test.getRed(), 1.f);
				TestFramework::assertEqual(test.getGreen(), 1.f);
				TestFramework::assertEqual(test.getBlue(), 1.f);
				TestFramework::assertEqual(test.getAlpha(), 1.f);
			}
		},
		{
			"Data::Colour Initialiser Constructor",
			[]{
				const float R = .4;
				const float G = .83;
				const float B = 1;
				const float A = 0;
				Data::Colour test = Data::Colour(R, G, B, A);
				TestFramework::assertEqual(test.getRed(), R);
				TestFramework::assertEqual(test.getGreen(), G);
				TestFramework::assertEqual(test.getBlue(), B);
				TestFramework::assertEqual(test.getAlpha(), A);
			}
		},
		{
			"Data::Colour Initialiser Constructor Invalid",
			[]{
				TestFramework::assertError<std::invalid_argument>([]{ Data::Colour(-1, 1, 1, 1); });
				TestFramework::assertError<std::invalid_argument>([]{ Data::Colour(2, 1, 1, 1); });
				TestFramework::assertError<std::invalid_argument>([]{ Data::Colour(1, -1, 1, 1); });
				TestFramework::assertError<std::invalid_argument>([]{ Data::Colour(1, 2, 1, 1); });
				TestFramework::assertError<std::invalid_argument>([]{ Data::Colour(1, 1, -1, 1); });
				TestFramework::assertError<std::invalid_argument>([]{ Data::Colour(1, 1, 2, 1); });
				TestFramework::assertError<std::invalid_argument>([]{ Data::Colour(1, 1, 1, -1); });
				TestFramework::assertError<std::invalid_argument>([]{ Data::Colour(1, 1, 1, 2); });
			}
		},
		{
			"Data::Colour Red Setter",
			[]{
				const float R1 = .284;
				const float R2 = 0;
				const float R3 = 1;
				Data::Colour test = Data::Colour();
				test.setRed(R1);
				TestFramework::assertEqual(test.getRed(), R1);
				test.setRed(R2);
				TestFramework::assertEqual(test.getRed(), R2);
				test.setRed(R3);
				TestFramework::assertEqual(test.getRed(), R3);
			}
		},
		{
			"Data::Colour Red Setter Invalid",
			[]{
				TestFramework::assertError<std::invalid_argument>([]{ Data::Colour().setRed(-.1); });
				TestFramework::assertError<std::invalid_argument>([]{ Data::Colour().setRed(1.1); });
			}
		},
		{
			"Data::Colour Green Setter",
			[]{
				const float G1 = .843;
				const float G2 = 0;
				const float G3 = 1;
				Data::Colour test = Data::Colour();
				test.setGreen(G1);
				TestFramework::assertEqual(test.getGreen(), G1);
				test.setGreen(G2);
				TestFramework::assertEqual(test.getGreen(), G2);
				test.setGreen(G3);
				TestFramework::assertEqual(test.getGreen(), G3);
			}
		},
		{
			"Data::Colour Green Setter Invalid",
			[]{
				TestFramework::assertError<std::invalid_argument>([]{ Data::Colour().setGreen(-.1); });
				TestFramework::assertError<std::invalid_argument>([]{ Data::Colour().setGreen(1.1); });
			}
		},
		{
			"Data::Colour Blue Setter",
			[]{
				const float B1 = .003;
				const float B2 = 0;
				const float B3 = 1;
				Data::Colour test = Data::Colour();
				test.setBlue(B1);
				TestFramework::assertEqual(test.getBlue(), B1);
				test.setBlue(B2);
				TestFramework::assertEqual(test.getBlue(), B2);
				test.setBlue(B3);
				TestFramework::assertEqual(test.getBlue(), B3);
			}
		},
		{
			"Data::Colour Blue Setter Invalid",
			[]{
				TestFramework::assertError<std::invalid_argument>([]{ Data::Colour().setBlue(-.1); });
				TestFramework::assertError<std::invalid_argument>([]{ Data::Colour().setBlue(1.1); });
			}
		},
		{
			"Data::Colour Alpha Setter",
			[]{
				const float A1 = .28;
				const float A2 = 0;
				const float A3 = 1;
				Data::Colour test = Data::Colour();
				test.setAlpha(A1);
				TestFramework::assertEqual(test.getAlpha(), A1);
				test.setAlpha(A2);
				TestFramework::assertEqual(test.getAlpha(), A2);
				test.setAlpha(A3);
				TestFramework::assertEqual(test.getAlpha(), A3);
			}
		},
		{
			"Data::Colour Alpha Setter Invalid",
			[]{
				TestFramework::assertError<std::invalid_argument>([]{ Data::Colour().setAlpha(-.1); });
				TestFramework::assertError<std::invalid_argument>([]{ Data::Colour().setAlpha(1.1); });
			}
		},
		{
			"Data::Colour Equality",
			[]{
				const float R = .234;
				const float G = .34;
				const float B = .93;
				const float A = 1;
				TestFramework::assertEqual(Data::Colour(R, G, B, A), Data::Colour(R, G, B, A));
			}
		},
		{
			"Data::Colour Inequality",
			[]{
				const float R = .821;
				const float G = .012;
				const float B = .501;
				const float A = 0;
				TestFramework::assertNotEqual(Data::Colour(R, G, B, A), Data::Colour(R + .01, G + .01, B + .01, A + .01));
			}
		}
	};
}

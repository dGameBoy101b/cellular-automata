#include "data_cell_tests.hpp"
#include "../assertion.hpp"
#include "../../Source/Data/cell.hpp"

const std::map<std::string, std::function<void()>> Tests::DATA_CELL_TESTS =
{
	{
		"Data::Cell Default Constructor",
		[]{
			Data::Cell test = Data::Cell();
			TestFramework::assertEqual(test.getPosition(), Data::Position<int>());
			TestFramework::assertEqual(test.getState(), 0u);
		}
	},
	{
		"Data::Cell Initialiser Constructor",
		[]{
			const Data::Position<int> POS = Data::Position<int>(12, 3, 72);
			const unsigned int STATE = 4;
			Data::Cell test = Data::Cell(POS, STATE);
			TestFramework::assertEqual(test.getPosition(), POS);
			TestFramework::assertEqual(test.getState(), STATE);
		}
	},
	{
		"Data::Cell Position Setter",
		[]{
			const Data::Position<int> POS = Data::Position<int>(-34, 0, 32);
			Data::Cell test = Data::Cell();
			test.setPosition(POS);
			TestFramework::assertEqual(test.getPosition(), POS);
		}
	},
	{
		"Data::Cell State Updating",
		[]{
			const unsigned int STATE = 19;
			Data::Cell test = Data::Cell();
			test.setState(STATE);
			TestFramework::assertNotEqual(test.getState(), STATE);
			test.updateState();
			TestFramework::assertEqual(test.getState(), STATE);
		}
	}
};

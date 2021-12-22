#include "cell_tests.hpp"
#include "Testing/assertion.hpp"
#include "Source/Data/cell.hpp"

using namespace CellularAutomata::Data;

const std::map<std::string, std::function<void()>> Tests::Data::CELL_TESTS =
{
	{
		"Data::Cell Default Constructor",
		[]{
			Cell test = {};
			TestFramework::assertEqual(test.getPosition(), Position<int>());
			TestFramework::assertEqual(test.getState(), 0u);
		}
	},
	{
		"Data::Cell Initialiser Constructor",
		[]{
			const Position<int> POS = {12, 3, 72};
			const unsigned int STATE = 4;
			Cell test = {POS, STATE};
			TestFramework::assertEqual(test.getPosition(), POS);
			TestFramework::assertEqual(test.getState(), STATE);
		}
	},
	{
		"Data::Cell Position Setter",
		[]{
			const Position<int> POS = {-34, 0, 32};
			Cell test = {};
			test.setPosition(POS);
			TestFramework::assertEqual(test.getPosition(), POS);
		}
	},
	{
		"Data::Cell State Updating",
		[]{
			const unsigned int STATE = 19;
			Cell test = {};
			test.setState(STATE);
			TestFramework::assertNotEqual(test.getState(), STATE);
			test.updateState();
			TestFramework::assertEqual(test.getState(), STATE);
		}
	},
	{
		"Data::Cell Equality",
		[]{
			const Position<int> POS = {2, 9, -27};
			const unsigned int STATE = 21;
			TestFramework::assertEqual(Cell(), Cell());
			TestFramework::assertEqual(Cell(POS, STATE), Cell(POS, STATE));
		}
	},
	{
		"Data::Cell Inequality",
		[]{
			const Position<int> POS = {200, -42, 0};
			const unsigned int STATE = 90;
			TestFramework::assertNotEqual(Cell(), Cell(POS, STATE));
			TestFramework::assertNotEqual(Cell(POS, STATE), Cell(POS + 1, STATE));
			TestFramework::assertNotEqual(Cell(POS, STATE), Cell(POS, STATE + 1));
		}
	}
};

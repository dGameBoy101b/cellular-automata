#include "cell_state_tests.hpp"
#include "Testing/assertion.hpp"
#include "Source/Data/cell_state.hpp"

using namespace CellularAutomata::Data;

const std::map<std::string, std::function<void()>> Tests::Data::CELL_STATE_TESTS =
{
	{
		"Data::CellState Default Constructor",
		[]{
			CellState test = {};
			TestFramework::assertEqual(test.getValue(), 0u);
		}
	},
	{
		"Data::CellState Initialiser Constructor",
		[]{
			const unsigned int VAL = 12;
			CellState test = {VAL};
			TestFramework::assertEqual(test.getValue(), VAL);
		}
	},
	{
		"Data::CellState Equals",
		[]{
			const unsigned int VAL = 203;
			TestFramework::assertEqual(CellState(), CellState());
			TestFramework::assertEqual(CellState(VAL), CellState(VAL));
		}
	},
	{
		"Data::CellState Not Equals",
		[]{
			const unsigned int VAL = 41;
			TestFramework::assertNotEqual(CellState(), CellState(VAL));
			TestFramework::assertNotEqual(CellState(VAL), CellState(VAL + 1));
		}
	},
	{
		"Data::CellState Updating",
		[]{
			const unsigned int VAL = 27;
			CellState test = {};
			test.setValue(VAL);
			TestFramework::assertNotEqual(test.getValue(), VAL);
			test.updateValue();
			TestFramework::assertEqual(test.getValue(), VAL);
		}
	}
};

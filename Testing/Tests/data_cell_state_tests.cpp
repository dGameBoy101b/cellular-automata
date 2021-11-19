#include "data_cell_state_tests.hpp"
#include "../assertion.hpp"
#include "../../Source/Data/cell_state.hpp"

const std::map<std::string, std::function<void()>> Tests::DATA_CELL_STATE_TESTS =
{
	{
		"Data::CellState Default Constructor",
		[]{
			Data::CellState test = Data::CellState();
			TestFramework::assertEqual(test.getValue(), 0u);
		}
	},
	{
		"Data::CellState Initialiser Constructor",
		[]{
			const unsigned int VAL = 12;
			Data::CellState test = Data::CellState(VAL);
			TestFramework::assertEqual(test.getValue(), VAL);
		}
	},
	{
		"Data::CellState Equals",
		[]{
			const unsigned int VAL = 203;
			TestFramework::assertEqual(Data::CellState(), Data::CellState());
			TestFramework::assertEqual(Data::CellState(VAL), Data::CellState(VAL));
		}
	},
	{
		"Data::CellState Not Equals",
		[]{
			const unsigned int VAL = 41;
			TestFramework::assertNotEqual(Data::CellState(), Data::CellState(VAL));
			TestFramework::assertNotEqual(Data::CellState(VAL), Data::CellState(VAL + 1));
		}
	},
	{
		"Data::CellState Updating",
		[]{
			const unsigned int VAL = 27;
			Data::CellState test = Data::CellState();
			test.setValue(VAL);
			TestFramework::assertNotEqual(test.getValue(), VAL);
			test.updateValue();
			TestFramework::assertEqual(test.getValue(), VAL);
		}
	}
};

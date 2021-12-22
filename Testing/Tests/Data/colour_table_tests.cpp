#include "colour_table_tests.hpp"
#include "Testing/assertion.hpp"
#include "Source/Data/colour_table.hpp"

using namespace CellularAutomata::Data;

std::ostream& operator<<(std::ostream& output, const std::unordered_set<unsigned int>& data)
{
	output << "{";
	unsigned int len = data.size();
	for (auto it = data.cbegin(); it != data.cend(); ++it)
	{
		output << *it;
		if (--len > 0)
		{
			output << ", ";
		}
	}
	return output << "}" << std::endl;
}

const std::map<std::string, std::function<void()>> Tests::Data::COLOUR_TABLE_TESTS =
{
	{
		"Data::ColourTable Default Constructor",
		[]{
			ColourTable test = {};
			TestFramework::assertEqual(test.getStates(), std::unordered_set<unsigned int>());
		}
	},
	{
		"Data::ColourTable Initialiser Constructor",
		[]{
			const std::unordered_map<unsigned int, Colour> TABLE = {
				{0, {1, 0, 0, 1}},
				{3, {0, 1, 0, 1}},
				{2, {0, 0, 1, 1}},
				{1, {1, 1, 1, 1}}
			};
			ColourTable test = {TABLE};
			TestFramework::assertEqual(test.getStates().size(), TABLE.size());
			for (auto it = TABLE.cbegin(); it != TABLE.cend(); ++it)
			{
				TestFramework::assertEqual(test.getColour(it->first), it->second);
			}
		}
	},
	{
		"Data::ColourTable Colour Setter",
		[]{
			const std::pair<unsigned int, Colour> ROW1 = {0, {0, 0, 0, 1}};
			const std::pair<unsigned int, Colour> ROW2 = {3, {1, .5, 0, 1}};
			const std::pair<unsigned int, Colour> ROW3 = {3, {0, .5, 1, 1}};
			ColourTable test = {};
			test.setColour(ROW1.first, ROW1.second);
			TestFramework::assertEqual(test.getColour(ROW1.first), ROW1.second);
			test.setColour(ROW2.first, ROW2.second);
			TestFramework::assertEqual(test.getColour(ROW2.first), ROW2.second);
			test.setColour(ROW3.first, ROW3.second);
			TestFramework::assertEqual(test.getColour(ROW3.first), ROW3.second);
		}
	},
	{
		"Data::ColourTable Equals",
		[]{
			const std::unordered_map<unsigned int, Colour> TABLE = {
				{0, {.5, .3, .2, 1}},
				{7, {.93, .52, .99, .4}}
			};
			TestFramework::assertEqual(ColourTable(), ColourTable());
			TestFramework::assertEqual(ColourTable(TABLE), ColourTable(TABLE));
		}
	},
	{
		"Data::ColourTable Not Equals",
		[]{
			const std::unordered_map<unsigned int, Colour> TABLE = {
				{2, {1, 0, 1, 0}},
				{67, {0, .2, .75, 1}}
			};
			TestFramework::assertNotEqual(ColourTable(), ColourTable(TABLE));
			TestFramework::assertNotEqual(ColourTable(TABLE), ColourTable());
		}
	},
	{
		"Data::ColourTable Colour Getter Invalid",
		[]{
			TestFramework::assertError<std::invalid_argument>([]{ ColourTable().getColour(0u); });
			TestFramework::assertError<std::invalid_argument>([]{ ColourTable().getColour(42); });
		}
	}
};

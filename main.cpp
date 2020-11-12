#include <iostream>
#include <vector>
#include "colour.h"
#include "colour_file.h"

int main(int argc, char** argv)
{
	std::cout << "Hello World!\n";

	const std::string colour_file = "./test_colours.cls";
	const std::vector<Data::Colour> colours = { Data::Colour(), Data::Colour(.3,.6,.2,1) };

	std::vector<Data::Colour> load_colours;

	FileIO::ColourFile::save(colour_file, colours);
	std::cout << "Colours Saved\n";

	load_colours = FileIO::ColourFile::load(colour_file);
	std::cout << "Colours Loaded\n";

	return 0;
}
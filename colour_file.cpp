	#include "colour_file.h"

const std::string FileIO::ColourFile::EXT = ".cls";

const char FileIO::ColourFile::END = '\n';

const char FileIO::ColourFile::SEP = ',';

const char FileIO::ColourFile::RED = 'r';

const char FileIO::ColourFile::GREEN = 'g';

const char FileIO::ColourFile::BLUE = 'b';

const char FileIO::ColourFile::ALPHA = 'a';

const std::vector<Data::Colour> FileIO::ColourFile::load(const std::string filename)
{
	std::ifstream file;
	std::vector<Data::Colour> colours = std::vector<Data::Colour>();
	std::string col_string;

	if (!ColourFile::checkExtension(filename))
	{
		throw Exceptions::UnexpectedExtension();
	}

	file.open(filename, std::ios_base::in);
	if (!file.is_open())
	{
		throw Exceptions::FileNotReadable();
	}

	while (file.good())
	{
		std::getline(file, col_string, ColourFile::END);
		if (file.good())
		{
			colours.push_back(ColourFile::parseColour(col_string));
		}
	}

	file.close();
	return colours;
}

void FileIO::ColourFile::save(const std::string filename, const std::vector<Data::Colour> colours)
{
	std::ofstream file;
	bool sep;

	if (!ColourFile::checkExtension(filename))
	{
		throw Exceptions::UnexpectedExtension();
	}

	file.open(filename, std::ios_base::out | std::ios_base::trunc);
	if (!file.is_open() || !file.good())
	{
		throw Exceptions::FileNotWritable();
	}

	for (std::vector<Data::Colour>::const_iterator col = colours.begin(); col != colours.end(); col++)
	{
		sep = false;
		if (col->getRed() != 1)
		{
			file << col->getRed() << ColourFile::RED;
			sep = true;
		}
		if (col->getGreen() != 1)
		{
			if (sep)
			{
				file << ColourFile::SEP;
			}
			file << col->getGreen() << ColourFile::GREEN;
			sep = true;
		}
		if (col->getBlue() != 1)
		{
			if (sep)
			{
				file << ColourFile::SEP;
			}
			file << col->getBlue() << ColourFile::BLUE;
			sep = true;
		}
		if (col->getAlpha() != 1)
		{
			if (sep)
			{
				file << ColourFile::SEP;
			}
			file << col->getAlpha() << ColourFile::ALPHA;
			sep = true;
		}
		file << ColourFile::END;
	}

	file.close();
}

bool FileIO::ColourFile::checkExtension(const std::string filename)
{
	return filename.length() >= ColourFile::EXT.length()
		&& filename.substr(filename.length() - ColourFile::EXT.length(), 
			ColourFile::EXT.length()).compare(ColourFile::EXT) == 0;
}

Data::Colour FileIO::ColourFile::parseColour(const std::string string)
{
	std::istringstream col_stream = std::istringstream(string, std::ios_base::in);
	std::string comp_string;
	Data::Colour col = Data::Colour();

	while (col_stream.good())
	{
		std::getline(col_stream, comp_string, ColourFile::SEP);
		if (!col_stream.fail())
		{
			ColourFile::parseComponent(comp_string, col);
		}
	}

	return col;
}

void FileIO::ColourFile::parseComponent(const std::string string, Data::Colour& col)
{
	std::istringstream comp_stream = std::istringstream(string, std::ios::in);
	float comp;
	char comp_suf = '\0';

	comp_stream >> comp;
	if (!comp_stream.good())
	{
		throw Exceptions::ColourComponentFormatMismatch();
	}

	comp_stream >> comp_suf;
	switch (std::tolower(comp_suf))
	{
	case ColourFile::RED:
		col.setRed(comp);
		break;
	case ColourFile::GREEN:
		col.setGreen(comp);
		break;
	case ColourFile::BLUE:
		col.setBlue(comp);
		break;
	case ColourFile::ALPHA:
		col.setAlpha(comp);
		break;
	default:
		throw Exceptions::UnrecognisedComponentSuffix();
	}
}

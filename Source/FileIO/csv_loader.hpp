#pragma once
#include "file_loader.hpp"
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>

namespace FileIO
{
	/** CSV file loader template
	\param <ReturnT> The data type this CSVLoader handles
	*/
	template<class ReturnT> class CSVLoader : public FileLoader<ReturnT>
	{
	public:
		ReturnT load(const std::string& path);
		void save(const std::string& path, const ReturnT& data);
	private:
		/** The expected file extension */
		static const std::string EXT;
		/** The expected value separator */
		static const char SEP;
		/** The exppected record ender */
		static const char END;
		/** Check last file read for format errors
		\param file The input file stream that was recently read from
		\param part The name of the part that was recently read
		\param expect The expected separator character
		\param test The read separator character
		\throw std::runtime_error The most recent read failed or the wrong separator was read
		*/
		void formatError(std::ifstream& file, const std::string& part, const char expect, const char test);
		/** Body of the load function that should be specialised
		\param file The open file to load from
		\return The loaded data
		\throw std::domain_error No template specialisation is available for the requested data type
		*/
		ReturnT load(std::ifstream& file) { throw std::domain_error("Not implemented"); };
		/** Body of the save function that should be specialised
		\param file The open file to save to
		\param data The data to save
		\throw std::domain_error No template specialisation is available for the requested data type
		*/
		void save(std::ofstream& file, const ReturnT& data) { throw std::domain_error("Not implemented"); };
	};

	template<class ReturnT> const std::string CSVLoader<ReturnT>::EXT = "csv";

	template<class ReturnT> const char CSVLoader<ReturnT>::SEP = ',';

	template<class ReturnT> const char CSVLoader<ReturnT>::END = '\n';

	template<class ReturnT> void CSVLoader<ReturnT>::formatError(std::ifstream& file, const std::string& part, const char expect, const char test)
	{
		std::stringstream error;
		if (file.bad())
		{
			error << "Bad read of " << part;
			throw std::runtime_error(error.str());
		}
		if (file.fail() && file.eof())
		{
			file.clear(std::ios_base::iostate::_S_eofbit);
		}
		if (file.fail())
		{
			error << "Failed to read " << part;
			throw std::runtime_error(error.str());
		}
		if (test != expect || file.eof())
		{
			error << "Expected \'" << expect << "\' after " << part << " instead of \'";
			if (file.eof())
			{
				error << "EOF";
			}
			else
			{
				error << test;
			}
			error << '\'';
			throw std::runtime_error(error.str());
		}
	}

	template<class ReturnT> ReturnT CSVLoader<ReturnT>::load(const std::string& path)
	{
		std::ifstream file;
		ReturnT res;

		if (!this->checkExtension(path, CSVLoader::EXT))
		{
			throw std::invalid_argument("Unexpected file extension");
		}

		file.open(path, std::ios::in);
		if (!file.is_open())
		{
			throw std::invalid_argument("File not readable");
		}

		file >> std::noskipws;
		res = this->load(file);
		file.close();
		return res;
	}

	template<class ReturnT> void CSVLoader<ReturnT>::save(const std::string& path, const ReturnT& data)
	{
		std::ofstream file;

		if (!this->checkExtension(path, CSVLoader::EXT))
		{
			throw std::invalid_argument("Unexpected file extension");
		}

		file.open(path, std::ios::out | std::ios::trunc);
		if (!file.is_open())
		{
			throw std::invalid_argument("File not writable");
		}

		this->save(file, data);
		file.close();
	}
}

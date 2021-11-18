#pragma once

#include <string>

namespace FileIO
{
	/** File Loader template
	\param <ReturnT> The data type this file loader handles
	\param <ExtV> The file extension this file loader handles
	*/
	template <class ReturnT> class FileLoader
	{
	public:
		/** Load data from a file.
		\param path The string path of the file to load the data from.
		\return The loaded data.
		*/
		virtual ReturnT load(const std::string& path) = 0;
		/** Save data to a file.
		\param path The string path of the file to save the data to.
		\param data The data to save.
		\throw Exceptions::UnexpectedExtension The given path does not have expected file extension.
		\throw Exceptions::FileNotReadable The given path could not be read.
		 */
		virtual void save(const std::string& path, const ReturnT& data) = 0;
		virtual ~FileLoader<ReturnT>() = default;
	protected:
		/** Check the extension of the given path.
		\param path The string path to check the extension of.
		\param ext The correct extention
		\return True if the given path is valid, false otherwise.
		\throw Exceptions::UnexpectedExtension The given path does not have the expected file extension.
		\throw Exceptions::FileNotWritable The given path could not be writen to.
		*/
		bool checkExtension(const std::string& path, const std::string& ext);
	};

	template <class ReturnT> inline bool FileLoader<ReturnT>::checkExtension(const std::string& path, const std::string& ext)
	{
		if (path.size() < ext.size())
		{
			return false;
		}
		std::string::size_type index = path.rfind('.');
		return index == std::string::npos ? false
		: path.substr(index + 1).compare(ext) == 0;
	}
}

#pragma once
#include <exception>
#include <functional>
#include <sstream>
#include <string>

namespace TestFramework
{
	/** Custom exception used for assertion */
	class AssertionException : virtual public std::exception
	{
	public:
		/** Constructor
		\param msg The explanatory string
		*/
		AssertionException(const std::string& msg = "");
		/** Default copy constructor
		\param other The other AssertionException to copy
		*/
		AssertionException(const AssertionException& other) = default;
		/** Default destructor */
		virtual ~AssertionException() noexcept = default;
		/** Get explanation C-string from message
		\return The message as a C-String
		*/
		virtual const char* what() const noexcept;
	private:
		/** The explanatory message */
		std::string msg;
	};

	/** Assert given expression should be true
	\param expr The expression to test
	\param msg The string message to include in the exception
	\throw AssertionException The given expression evaluated to false
	*/
	inline void assert(bool expr, const std::string& msg = "")
	{
		if (!expr) throw AssertionException(msg);
	}

	/** Assert two given values should be equal
	\param <T> The type of the compared values
	\param val The value to test
	\param expect The expected value
	\throw AssertionException The given values were not equal
	*/
	template <class T> void assertEqual(const T& val, const T& expect)
	{
		if (val != expect)
		{
			std::stringstream msg;
			msg << "Expected " << expect << " but got " << val;
			throw AssertionException(msg.str());
		}
	}

	/** Assert two given value should not be equal
	\param <T> The type of the compared values
	\param val The value to test
	\param expect The unexpected value
	\throw AssertionException The given values were equal
	*/
	template <class T> void assertNotEqual(const T& val, const T& expect)
	{
		if (val == expect)
		{
			std::stringstream msg;
			msg << "Did not expect " << expect << " but got " << val;
			throw AssertionException(msg.str());
		}
	}

	/** Assert a given value is within a given range
	\param <T> The type of the compared values
	\param val The value to test
	\param min The expected minimum value
	\param max The expected maximum value
	\throw AssertionException The given value was lesser than the minimum or greater than the maximum
	*/
	template <class T> void assertRange(const T& val, const T& min, const T& max)
	{
		if (val < min)
		{
			std::stringstream msg;
			msg << "Expected " << min << " or greater but got " << val;;
			throw AssertionException(msg.str());
		}
		if (val > max)
		{
			std::stringstream msg;
			msg << "Expected " << max << " or lesser but got " << val;
			throw AssertionException(msg.str());
		}
	}

	/** Assert given expression should throw given exception
	\param <ErrorT> The expected exception type
	\param func The function to test
	\throw AssertionException The given function did not throw the expected error
	*/
	template <class ErrorT> void assertError(const std::function<void()>& func)
	{
		try
		{
			func();
		}
		catch (const ErrorT& x)
		{
			return;
		}
		catch (const std::exception& x)
		{
			std::stringstream error;
			error << "Unexpected error thrown: " << x.what();
			throw AssertionException(error.str());
		}
		throw AssertionException("No error thrown");
	}
}

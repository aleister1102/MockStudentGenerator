#include "include/Number.h"

/**
 * It takes a string and returns a tuple containing a ReturnFlags object and an int
 *
 * @param str The string to parse
 *
 * @return A tuple of ReturnFlags and int.
 */
tuple<ReturnFlags, int> Number::parseInt(string str)
{
	ReturnFlags flags;
	int number = 0;

	if (str.size() == 0)
	{
		flags.setSuccessful(false);
		flags.setErrorCode(2);
		flags.setMessage("Empty string");
	}
	else
	{
		regex pattern(NUMBERS);
		smatch match;
		bool isMatched = regex_search(str, match, pattern);
		if (!isMatched)
		{
			flags.setSuccessful(false);
			flags.setErrorCode(1);
			flags.setMessage("Invalid int number");
		}
		else
		{
			number = stoi(match[0]);
		}
	}

	auto result = make_tuple(flags, number);
	return result;
}

/**
 * It takes a string and returns a tuple containing a ReturnFlags object and a float
 *
 * @param str The string to be parsed
 *
 * @return A tuple of ReturnFlags and float.
 */
tuple<ReturnFlags, float> Number::parseFloat(string str)
{
	ReturnFlags flags;
	float number = 0;

	if (str.size() == 0)
	{
		flags.setSuccessful(false);
		flags.setErrorCode(2);
		flags.setMessage("Empty string");
	}
	else
	{
		regex pattern(FLOAT);
		smatch match;
		bool isMatched = regex_search(str, match, pattern);
		if (!isMatched)
		{
			flags.setSuccessful(false);
			flags.setErrorCode(1);
			flags.setMessage("Invalid float number");
		}
		else
		{
			number = stof(str);
		}
	}

	auto result = make_tuple(flags, number);
	return result;
}

/**
 * It takes a string, and returns an integer
 *
 * @param str The string to be parsed.
 *
 * @return A tuple containing a ReturnFlags object and an int.
 */
int Number::tryParseInt(string str)
{
	ReturnFlags flags;
	int number = 0;

	tie(flags, number) = parseInt(str);
	if (!flags.Successful())
	{
		cout << "Error code: " << flags.ErrorCode() << endl;
		cout << "Message: " << flags.Message() << endl;
	}
	return number;
}

/**
 * It takes a string, and returns a float
 *
 * @param str The string to be parsed.
 *
 * @return A tuple of flags and a number.
 */
float Number::tryParseFloat(string str)
{
	ReturnFlags flags;
	float number = 0;

	tie(flags, number) = parseFloat(str);
	if (!flags.Successful())
	{
		cout << "Error code: " << flags.ErrorCode() << endl;
		cout << "Message: " << flags.Message() << endl;
	}
	return number;
}
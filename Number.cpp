#include "include/Number.h"

/// <summary>
/// Error code:
/// 1. Invalid format
/// 2. Empty string
/// </summary>
/// <param name="str"></param>
/// <returns></returns>
tuple<bool, int, string, int> Number::parseInt(string str)
{
	bool successful = true;
	int errorCode = 0;
	string message = "";
	int number = 0;

	if (str.size() == 0) {
		successful = false;
		errorCode = 2;
		message = "Empty string";
	}
	else
	{
		try {
			number = stoi(str);
		}
		catch (exception ex)
		{
			successful = false;
			errorCode = 1;
			message = ex.what();
		}
	}

	auto result = make_tuple(
		successful, errorCode, message, number
	);
	return result;
}

/// <summary>
/// Error code:
/// 1. Invalid format
/// 2. Empty string
/// 3. Another exception
/// </summary>
/// <param name="str"></param>
/// <returns></returns>
tuple<bool, int, string, float> Number::parseFloat(string str)
{
	bool successful = true;
	int errorCode = 0;
	string message = "";
	float number = 0;

	if (str.size() == 0)
	{
		successful = false;
		errorCode = 2;
		message = "Empty string";
	}

	regex pattern("-?[0-9]+\\.?[0-9]+(?![A-z])");
	smatch match;
	bool isMatched = regex_search(str, match, pattern);
	if (!isMatched)
	{
		successful = false;
		errorCode = 1;
		message = "Invalid float number";
	}

	try {
		number = stof(str);
	}
	catch (exception ex)
	{
		successful = false;
		errorCode = 1;
		message = ex.what();
	}
	

	auto result = make_tuple(
		successful, errorCode, message, number
	);
	return result;
}
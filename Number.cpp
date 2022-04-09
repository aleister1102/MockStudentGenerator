#include "include/Number.h"

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

tuple<bool, int, string, float> Number::parseFloat(string str)
{
	bool successful = true;
	int errorCode = 0;
	string message = "";
	int number = 0;

	if (str.size() == 0)
	{
	}

	auto result = make_tuple(
		successful, errorCode, message, number
	);
	return result;
}
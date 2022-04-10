#include "include/Number.h"

tuple<ReturnFlags, int> Number::parseInt(string str)
{
	ReturnFlags flags;
	int number = 0;

	if (str.size() == 0) {
		flags.successful = false;
		flags.errorCode = 2;
		flags.message = "Empty string";
	}
	else
	{
		regex pattern(NUMBERS);
		smatch match;
		bool isMatched = regex_search(str, match, pattern);
		if (!isMatched)
		{
			flags.successful = false;
			flags.errorCode = 1;
			flags.message = "Invalid int number";
		}
		else
		{
			number = stoi(match[0]);
		}
	}

	auto result = make_tuple(flags, number);
	return result;
}

tuple<ReturnFlags, float> Number::parseFloat(string str)
{
	ReturnFlags flags;
	float number = 0;

	if (str.size() == 0)
	{
		flags.successful = false;
		flags.errorCode = 2;
		flags.message = "Empty string";
	}
	else
	{
		regex pattern("-?[0-9]+\\.{1}[0-9]+");
		smatch match;
		bool isMatched = regex_search(str, match, pattern);
		if (!isMatched)
		{
			flags.successful = false;
			flags.errorCode = 1;
			flags.message = "Invalid float number";
		}
		else
		{
			number = stof(str);
		}
	}

	auto result = make_tuple(flags, number);
	return result;
}

int Number::tryParseInt(string str)
{
	ReturnFlags flags;
	int number = 0;

	tie(flags, number) = parseInt(str);
	if (!flags.successful)
	{
		cout << "Error code: " << flags.errorCode << endl;
		cout << "Message: " << flags.message << endl;
	}
	return number;
}

float Number::tryParseFloat(string str)
{
	ReturnFlags flags;
	float number = 0;

	tie(flags, number) = parseFloat(str);
	if (!flags.successful)
	{
		cout << "Error code: " << flags.errorCode << endl;
		cout << "Message: " << flags.message << endl;
	}
	return number;
}
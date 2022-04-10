#pragma once
#include "lib.h"

struct ReturnFlags
{
	bool successful = true;
	int errorCode = 0;
	string message = "";
};

class Number
{
public:
	static tuple<ReturnFlags, int> parseInt(string);
	static tuple<ReturnFlags, float> parseFloat(string);
	static int tryParseInt(string);
	static float tryParseFloat(string);
};

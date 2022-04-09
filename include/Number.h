#pragma once
#include "lib.h"

class Number
{
public:
	static tuple<bool, int, string, int> parseInt(string);
	static tuple<bool, int, string, float> parseFloat(string);
};

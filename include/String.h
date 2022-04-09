#pragma once
#include "lib.h"

class String
{
public:
	static vector<string> split(string, string del = " ");
	static string trim(string, char character = ' ');
	static string searchRegex(string, string);
	static string toLowerCase(string);
	static vector<string> parseStudentStrings(vector<string>);
};

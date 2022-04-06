#include "include/FullName.h"

FullName::FullName()
{
	_first = "NULL";
	_middle = "NULL";
	_last = "NULL";
}

FullName::FullName(string first, string middle, string last)
{
	_first = first;
	_middle = middle;
	_last = last;
}

string FullName::toString()
{
	stringstream builder;

	builder << _first << " " << _middle << " " << _last;
	return builder.str();
}

/**
 * Given a vector of vectors of strings, parse the first string of each vector and return a vector of
 * strings
 *
 * @param collections A vector of vectors of strings. Each vector of strings is a collection of names.
 * @param frequencies A vector of floats that contains the frequencies of each name.
 *
 * @return The vector of names.
 */
vector<string> FullName::parseFirstNames(vector<vector<string>> collections, vector<float>& frequencies)
{
	vector<string> names;

	for (int i = 0; i < collections.size(); i++)
	{
		names.push_back(collections[i][0]);
		frequencies.push_back(stof(collections[i][1]));
	}

	return names;
}

FullName FullName::parseFullName(string str)
{
	vector<string> names = String::parseString(str);

	FullName result;

	result.setFirst(names[0]);
	result.setMiddle(names[1]);
	result.setLast(names[2]);

	return result;
}
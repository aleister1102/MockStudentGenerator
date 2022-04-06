#include "include/String.h"

/**
 * Given a string, it will return a vector of strings, where each string is a substring of the original
 * string delimited by the del string
 *
 * @param s The string to be parsed.
 * @param del The delimiter string.
 *
 * @return A vector of strings.
 */
vector<string> String::parseString(string s, string del)
{
	vector<string> infos;

	int start = 0;
	int end = (int)s.find(del);
	while (end != -1)
	{
		infos.push_back(s.substr(start, end - start));
		start = end + del.size();
		end = s.find(del, start);
	}
	infos.push_back(s.substr(start, end - start));

	return infos;
}

string String::toLowerCase(string str)
{
	string builder;

	for (int i = 0; i < str.length(); i++)
	{
		builder += (char)tolower(str.at(i));
	}

	return builder;
}
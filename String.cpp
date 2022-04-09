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
vector<string> String::split(string s, string delimiter)
{
	vector<string> infos;

	size_t start = 0;
	size_t end = (int)s.find(delimiter);
	while (end != string::npos)
	{
		infos.push_back(s.substr(start, end - start));
		start = end + delimiter.size();
		end = s.find(delimiter, start);
	}
	infos.push_back(s.substr(start, end - start));

	return infos;
}

/**
 * It removes all leading and trailing characters of a given type, and then removes all instances of
 * that character that are next to each other
 *
 * @param line The string to be trimmed.
 * @param character The character to trim from the string.
 *
 * @return a string.
 */
string String::trim(string line, char character)
{
	string result = line;
	while (result.at(0) == character)
	{
		result.erase(0, 1);
	}
	while (result.at(result.length() - 1) == character)
	{
		result.erase(result.length() - 1, 1);
	}

	for (size_t i = 0; i < result.size(); i++)
	{
		if (result.at(i) == character)
		{
			if (result.at(i - 1) == character || result.at(i + 1) == character)
			{
				result.erase(i, 1);
				i -= 1;
			}
		}
	}

	return result;
}

/**
 * It takes a string and a regex pattern and returns the first match of the pattern in the string
 *
 * @param line The string to search in
 * @param pattern The pattern to search for.
 *
 * @return The first match of the pattern in the line.
 */
string String::searchRegex(string line, string pattern)
{
	regex rgx(pattern);
	smatch match;
	regex_search(line, match, rgx);
	return match[0];
}

string String::toLowerCase(string str)
{
	string builder;

	for (size_t i = 0; i < str.length(); i++)
	{
		builder += (char)tolower(str.at(i));
	}

	return builder;
}

/**
 * It takes a vector of strings, each string is a line of a student's information, and returns a vector
 * of strings, each string is an attribute of a student
 *
 * @param lines a vector of strings, each string is a line of the student's information
 *
 * @return A vector of strings.
 */
vector<string> String::parseStudentStrings(vector<string> lines)
{
	vector<string> attributes;

	string id_name = lines[0];
	string id = searchRegex(id_name, ID);
	string name = searchRegex(id_name, NAME);

	string gpa_tel = lines[1];
	string gpa = searchRegex(gpa_tel, GPA);
	string tel = searchRegex(gpa_tel, TEL);

	string email = lines[2];
	email = searchRegex(email, EMAIL);

	string dob = lines[3];
	dob = searchRegex(dob, DATE);

	string address = lines[4];
	vector<string> addressDetails = split(address, ", ");
	string houseNumber_street = searchRegex(addressDetails[0], HOUSE_NUMBER_STREET);

	string houseNumber = searchRegex(houseNumber_street, HOUSE_NUMBER);
	string street = searchRegex(houseNumber_street, WORDS);

	string ward = addressDetails[1];
	string wardName = searchRegex(ward, WARD);
	string wardNumber = searchRegex(ward, NUMBERS);

	string district = addressDetails[2];
	string districtName = searchRegex(district, DISTRICT);
	string districtNumber = searchRegex(district, NUMBERS);

	string city = addressDetails[3];
	city = searchRegex(city, CITY);

	attributes.push_back(id);
	attributes.push_back(trim(name));
	attributes.push_back(gpa);
	attributes.push_back(tel);
	attributes.push_back(email);
	attributes.push_back(dob);
	attributes.push_back(houseNumber);
	attributes.push_back(trim(street));
	attributes.push_back(trim(wardName != "" ? wardName : wardNumber));
	attributes.push_back(trim(districtName != "" ? districtName : districtNumber));
	attributes.push_back(trim(city));

	return attributes;
}

int String::parseInt(string str)
{
	int number = 0;

	try {
		number = stoi(str);
	}
	catch (exception e)
	{
		cout << e.what();
	}
	return number;
}
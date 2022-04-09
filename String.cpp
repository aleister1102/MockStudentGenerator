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
vector<string> String::split(string s, string del)
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

	for (int i = 0; i < result.size(); i++)
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

	for (int i = 0; i < str.length(); i++)
	{
		builder += (char)tolower(str.at(i));
	}

	return builder;
}

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

	string houseNumber = searchRegex(houseNumber_street, NUMBERS);
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
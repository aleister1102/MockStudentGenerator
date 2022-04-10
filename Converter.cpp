#include "include/Converter.h"

/**
 * It takes a vector of strings, and returns a Student object
 *
 * @param attributes a vector of strings that contains the attributes of a student
 *
 * @return A Student object.
 */
Student StringToStudentConverter::convert(vector<string> attributes)
{
	Student result;

	result.setID(Number::tryParseInt(attributes[0]));
	result.setName(FullName::parseFullName(attributes[1]));
	result.setGPA(Number::tryParseFloat(attributes[2]));
	result.setTelephone(attributes[3]);
	result.setEmail(attributes[4]);
	result.setDOB(Date::parseDate(attributes[5]));
	result.setAddress(Address::parseAddress(attributes));

	return result;
}

/**
 * It converts a Student object into a vector of strings
 *
 * @param student The student object to be converted to a vector of strings.
 *
 * @return A vector of strings.
 */
vector<string> StringToStudentConverter::convertBack(Student student)
{
	vector<string> result;
	string string;

	string = "Student: " + to_string(student.getID()) +
		" - " + student.getName().toString() + "\n";
	result.push_back(string);
	string = "    GPA=" + to_string(student.getGPA()).substr(0, 4)
		+ ", Telephone=" + student.getTelephone() + "\n";
	result.push_back(string);
	string = "    Email=" + student.getEmail() + "\n";
	result.push_back(string);
	string = "    DOB=" + student.getDOB().toString() + "\n";
	result.push_back(string);
	string = "    Address=" + student.getAddress().toString() + "\n";
	result.push_back(string);

	return 	result;
}
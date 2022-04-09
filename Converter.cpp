#include "include/Converter.h"

Student StringToStudentConverter::convert(vector<string> attributes)
{
	Student result;

	result.setID(stoi(attributes[0]));
	result.setName(FullName::parseFullName(attributes[1]));
	result.setGPA(stof(attributes[2]));
	result.setTelephone(attributes[3]);
	result.setEmail(attributes[4]);
	result.setDOB(Date::parseDate(attributes[5]));
	result.setAddress(Address::parseAddress(attributes));

	return result;
}

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
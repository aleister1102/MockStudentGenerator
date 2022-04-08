#include "include/Student.h"

Student::Student()
{
	_id = 0;
	_GPA = 0.0;
	_telephone = "0000-000-000";
	_email = "null@gmail.com";
}

string Student::toString()
{
	stringstream builder;

	builder << "ID: " << _id << "\n"
		<< "Name: " << _name.toString() << "\n"
		<< "GPA: " << _GPA << "\n"
		<< "Telephone: " << _telephone << "\n"
		<< "Email: " << _email << "\n"
		<< "DOB: " << _dob.toString() << "\n"
		<< "Address: " << _address.toString() << "\n";

	string result = builder.str();

	return result;
}

Student Student::parseStudent(vector<string> attributes)
{
	Student result;

	result.setID(stoi(attributes[0]));
	result.setName(FullName::parseFullName(attributes[1]));
	result.setGPA(stof(attributes[2]));
	result.setTelephone(attributes[3]);
	result.setEmail(attributes[4]);
	result.setDOB(Date::parseDate(attributes[5]));
	result.setAddress(Address::parseAddress(attributes[6]));

	return result;
}

Students::Students()
{
	
}

Students::Students(vector<Student> list)
{
	_students = list;
}

Students::Students(vector<vector<string>> collections)
{
	for (int i = 0; i < collections.size(); i++)
	{
		_students.push_back(Student::parseStudent(collections[i]));
	}
}

void Students::add(Student student)
{
	_students.push_back(student);
}

void Students::append(vector<Student> list)
{
	for (int i = 0; i < list.size(); i++)
	{
		add(list[i]);
	}
}

string Students::toString()
{
	stringstream builder;
	for (int i = 0; i < _students.size(); i++)
	{
		builder << _students[i].toString() << "\ns";
	}

	return builder.str();
}

double Students::calcAvgGPA()
{
	double sum = 0;
	for (int i = 0; i < _students.size(); i++)
	{
		sum += _students[i].GPA();
	}

	double avgGPA = sum / _students.size();
	return avgGPA;
}

vector<Student> Students::findAboveAvg()
{
	vector<Student> result;
	double avgGPA = calcAvgGPA();

	for (int i = 0; i < _students.size(); i++)
	{
		if (_students[i].GPA() >= avgGPA)
		{
			result.push_back(_students[i]);
		}
	}

	return result;
}


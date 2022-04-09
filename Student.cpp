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

string Student::toStringWriteToFile()
{
	stringstream builder;

	builder << _id << ","
		   << _name.toString() << ","
		   << _GPA << ","
		   << _telephone << ","
		   << _email << ","
		   << _dob.toString() << ","
		   << _address.toString();

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
	// result.setAddress(Address::parseAddress(attributes[6]));

	return result;
}

Students::Students(vector<vector<string>> collections)
{
	for (int i = 0; i < collections.size(); i++)
	{
		_students.push_back(Student::parseStudent(collections[i]));
	}
}

string Students::toString()
{
	stringstream builder;
	for (int i = 0; i < _students.size(); i++)
	{
		builder << _students[i].toString() << "\n";
	}

	return builder.str();
}

float Students::calcAvgGPA()
{
	return 0;
}

void Students::writeStudentToFile(string filename)
{
	ofstream f;
	f.open(filename.c_str(), ios::out);
	for (int i = 0; i < _students.size(); i++)
	{
		string temp = _students[i].toStringWriteToFile();
		f << temp << endl;
	}
	f.close();
}
#include "include/Student.h"

// ---- Student ----

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
	result.setAddress(Address::parseAddress(attributes));

	return result;
}

// ---- Students ----

Students::Students(vector<Student> students)
{
	_students = students;
}

void Students::add(Student student)
{
	_students.push_back(student);
}

void Students::add(vector<Student> students)
{
	for (int i = 0; i < students.size(); i++)
	{
		add(students[i]);
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

float Students::averageScore()
{
	float sum = 0;

	for (int i = 0; i < _students.size(); i++)
	{
		sum += _students[i].getGPA();
	}

	float avgScore = sum / _students.size();
	return avgScore;
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

vector<Student> Students::findAboveAvg()
{
	vector<Student> result;
	double avgGPA = averageScore();

	for (int i = 0; i < _students.size(); i++)
	{
		if (_students[i].getGPA() >= avgGPA)
		{
			result.push_back(_students[i]);
		}
	}

	return result;
}


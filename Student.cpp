#include "include/Student.h"

// ---- Student ----

Student::Student()
{
	_id = 0;
	_gpa = 0.0;
	_telephone = "0000-000-000";
	_email = "null@gmail.com";
}

string Student::toString()
{
	stringstream builder;

	builder << "ID: " << _id << "\n"
		<< "Name: " << _name.toString() << "\n"
		<< "GPA: " << _gpa << "\n"
		<< "Telephone: " << _telephone << "\n"
		<< "Email: " << _email << "\n"
		<< "DOB: " << _dob.toString() << "\n"
		<< "Address: " << _address.toString() << "\n";

	string result = builder.str();

	return result;
}

// ---- Students ----

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

Students::Students()
{
}

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

void Students::append(Students students)
{
	add(students.getStudents());
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

Students Students::findAboveAvg()
{
	Students result;
	double avgGPA = averageScore();

	for (int i = 0; i < _students.size(); i++)
	{
		if (_students[i].getGPA() >= avgGPA)
		{
			result.add(_students[i]);
		}
	}

	return result;
}
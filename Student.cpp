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
		<< "GPA: " << to_string(_gpa).substr(0, 4) << "\n"
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

	for (size_t i = 0; i < _students.size(); i++)
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

/**
 * The function `add` takes a `Student` object as an argument and adds it to the `_students` vector
 *
 * @param student The student to add to the list.
 */
void Students::add(Student student)
{
	_students.push_back(student);
}

/**
 * This function takes a vector of students and adds each student to the students vector
 *
 * @param students A vector of Student objects.
 */
void Students::add(vector<Student> students)
{
	for (size_t i = 0; i < students.size(); i++)
	{
		add(students[i]);
	}
}

/**
 * Appends the students in the given Students object to the end of the list of students in this
 * Students object
 *
 * @param students The students to add to the list.
 */
void Students::append(Students students)
{
	add(students.getStudents());
}

string Students::toString()
{
	stringstream builder;
	for (size_t i = 0; i < _students.size(); i++)
	{
		builder << _students[i].toString() << "\n";
	}

	return builder.str();
}

void Students::findAboveAvg()
{
	Students students;
	double avgGPA = averageScore();

	for (size_t i = 0; i < _students.size(); i++)
	{
		if (_students[i].getGPA() >= avgGPA)
		{
			students.add(_students[i]);
		}
	}

	vector<Student> resultList = students.getStudents();
	for (size_t i = 0; i < resultList.size(); i++)
	{
		cout << resultList[i].getID() << " - "
			<< resultList[i].getName().toString() << ", "
			<< "GPA: " << to_string(resultList[i].getGPA()).substr(0, 4) << endl;
	}
}

bool Student::isDuplicated(vector<Student> students, Student student)
{
	for (size_t i = 0; i < students.size(); i++)
	{
		Student studentToCheck = students[i];

		if (studentToCheck.getID() == student.getID())
		{
			return true;
		}
		if (studentToCheck.getDOB() == student.getDOB()
			&& studentToCheck.getName() == student.getName())
		{
			return true;
		}
		if (studentToCheck.getTelephone() == student.getTelephone())
		{
			return true;
		}
	}

	return false;
}
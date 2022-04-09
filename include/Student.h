#pragma once
#include "lib.h"
#include "FullName.h"
#include "DOB.h"
#include "Address.h"
#include "String.h"

class Student
{
private:
	int _id;
	FullName _name;
	float _GPA;
	string _email;

	string _telephone;
	Date _dob;
	Address _address;

public:
	float getGPA() { return _GPA; }
	void setID(int id) { _id = id; }
	void setName(FullName name) { _name = name; }
	void setGPA(float gpa) { _GPA = gpa; }
	void setTelephone(string telephone) { _telephone = telephone; }
	void setEmail(string email) { _email = email; }
	void setDOB(Date dob) { _dob = dob; }
	void setAddress(Address address) { _address = address; }

public:
	Student();

public:
	string toString();
	string toStringWriteToFile();
	static Student parseStudent(vector<string>);
};

class Students
{
private:
	vector<Student> _students;
public:
	float averageScore();

public:
	Students(vector<Student>);

public:
	void add(Student);
	void add(vector<Student>);
	string toString();
	void writeStudentToFile(string);
};

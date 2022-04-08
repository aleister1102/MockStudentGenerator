#pragma once
#include "lib.h"
#include "FullName.h"
#include "DOB.h"
#include "Address.h"

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
	float GPA() { return _GPA; }
	void setID(int id) { _id = id; }
	void setName(FullName name) { _name = name; }
	void setGPA(float GPA) { _GPA = GPA; }
	void setTelephone(string telephone) { _telephone = telephone; }
	void setEmail(string email) { _email = email; }
	void setDOB(Date dob) { _dob = dob; }
	void setAddress(Address address) { _address = address; }

public:
	Student();

public:
	string toString();
	static Student parseStudent(vector<string>);
};

class Students
{
private:
	vector<Student> _students;

public:
	Students();
	Students(vector<Student>);
	Students(vector<vector<string>>);

public:
	void add(Student);
	void append(vector<Student>);
	string toString();
	double calcAvgGPA();
	vector<Student> findAboveAvg();
};

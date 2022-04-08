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
	Students(vector<vector<string>>);
	Students(vector<Student>);

public:
	string toString();
	float calcAvgGPA();
};

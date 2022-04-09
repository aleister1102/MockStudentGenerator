#pragma once
#include "lib.h"
#include "FullName.h"
#include "Date.h"
#include "Address.h"
#include "String.h"

class Student;
class Students;

class Student
{
private:
	int _id;
	FullName _name;
	float _gpa;
	string _email;
	string _telephone;
	Date _dob;
	Address _address;

public:
	int getID() { return _id; }
	FullName getName() { return _name; }
	float getGPA() { return _gpa; }
	string getEmail() { return _email; }
	string getTelephone() { return _telephone; }
	Date getDOB() { return _dob; }
	Address getAddress() { return _address; }
	void setID(int id) { _id = id; }
	void setName(FullName name) { _name = name; }
	void setGPA(float gpa) { _gpa = gpa; }
	void setTelephone(string telephone) { _telephone = telephone; }
	void setEmail(string email) { _email = email; }
	void setDOB(Date dob) { _dob = dob; }
	void setAddress(Address address) { _address = address; }

public:
	Student();

public:
	string toString();
	static bool isDuplicated(vector<Student>, Student);
};

class Students
{
private:
	vector<Student> _students;

public:
	vector<Student> getStudents() { return _students; }
	float averageScore();

public:
	Students();
	Students(vector<Student>);
	Students(vector<vector<string>>);

public:
	void add(Student);
	void add(vector<Student>);
	void append(Students);
	string toString();
	void findAboveAvg();
};

#pragma once
#include "lib.h"

class Student
{
private:
    int _id;
    string _name;
    float _GPA;
    string _email;

    string _telephone;
    string _dob;
    string _address;

public:
    void setID(int id) { _id = id; }
    void setName(string name) { _name = name; }
    void setGPA(float GPA) { _GPA = GPA; }
    void setTelephone(string telephone) { _telephone = telephone; }
    void setEmail(string email) { _email = email; }
    void setDOB(string dob) { _dob = dob; }
    void setAddress(string address) { _address = address; }

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

public:
    string toString();
};

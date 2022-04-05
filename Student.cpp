#include "include/Student.h"

Student::Student()
{
    _id = 0;
    _name = "null";
    _GPA = 0.0;
    _telephone = "0000-000-000";
    _email = "null@gmail.com";
    _dob = "00/00/0000";
    _address = "homeless";
}

string Student::toString()
{
    stringstream builder;

    builder << "ID: " << _id << "\n"
            << "Name: " << _name << "\n"
            << "GPA: " << _GPA << "\n"
            << "Telephone: " << _telephone << "\n"
            << "Email: " << _email << "\n"
            << "DOB: " << _dob << "\n"
            << "Address: " << _address;

    string result = builder.str();

    return result;
}

Student Student::parseStudent(vector<string> attributes)
{
    Student result;

    result.setID(stoi(attributes[0]));
    result.setName(attributes[1]);
    result.setGPA(stof(attributes[2]));
    result.setTelephone(attributes[3]);
    result.setEmail(attributes[4]);
    result.setDOB(attributes[5]);
    result.setAddress(attributes[6]);

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
        builder << _students[i].toString() << "\ns";
    }

    return builder.str();
}
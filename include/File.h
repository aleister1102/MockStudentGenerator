#pragma once
#include "lib.h"
#include "Student.h"
#include "String.h"

class File
{
private:
    fstream _input;
public:
    vector<Student> readStudents(string);
    void writeStudents(string, vector<Student>);
};
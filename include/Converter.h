#pragma once
#include "lib.h"
#include "Student.h"

class StringToStudentConverter
{
public:
	Student convert(vector<string>);
	vector<string> convertBack(Student);
};
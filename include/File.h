#pragma once
#include "String.h"
#include "Student.h"
#include "lib.h"

class File
{
private:
	fstream _file;

public:
	void readFile(string);
	void writeFile(string);
	vector<vector<string>> readCSV(string);
	vector<string> readTXT(string);
	vector<Student> readStudents(string);
};
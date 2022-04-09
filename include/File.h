#pragma once
#include "String.h"
#include "Student.h"
#include "lib.h"
#include "Converter.h"

class File
{
private:
	fstream _file;

public:
	void readFile(string);
	void writeFile(string);
	vector<vector<string>> readCSV(string);
	vector<string> readTXT(string);
	vector<string> readStudentStrings(fstream&);
	vector<Student> readStudents(string);
	void writeStudents(string, vector<Student>);
};
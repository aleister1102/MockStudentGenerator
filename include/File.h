#pragma once
#include "lib.h"
#include "Student.h"
#include "String.h"

class File
{
private:
    fstream _input;
public:
    vector<vector<string>> readCSV(string);
    vector<string> readTXT(string);
};
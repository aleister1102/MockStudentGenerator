#pragma once
#include "String.h"
#include "Student.h"
#include "lib.h"

class File
{
private:
    fstream _input;

public:
    vector<vector<string>> readCSV(string);
    vector<string> readTXT(string);
};
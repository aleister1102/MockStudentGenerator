#include "include/File.h"

vector<Student> File::readStudents(string fileName)
{
    vector<Student> students;
    Student student;
    _input.open(fileName, ios::in);

    if (!_input)
    {
        cout << "File is not found!\n";
        return students;
    }
    string reader;
    getline(_input, reader);
    while (!_input.eof())
    {
        getline(_input, reader);

        vector<string> parsedStrings = String::parseString(reader, ",");
        student = student.parseStudent(parsedStrings);

        students.push_back(student);
    }

    _input.close();
    return students;
}
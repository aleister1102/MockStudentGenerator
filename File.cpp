#include "include/File.h"

/* Reading the file and creating a vector of students. */
/**
 * Reads the students from the file and returns them in a vector
 * 
 * @param fileName the name of the file that contains the students.
 * 
 * @return A vector of students.
 */
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
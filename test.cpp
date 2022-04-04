#include "include/File.h"
#include "include/Student.h"
#include "include/lib.h"

int main()
{
    File file;
    vector<Student> studentList = file.readStudents("data/students.csv");
    for (int i = 0; i < studentList.size(); i++)
    {
        cout << studentList[i].toString() << endl;
    }

    return 1;
}
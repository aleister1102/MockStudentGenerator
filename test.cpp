#include "include/File.h"
#include "include/Random.h"
#include "include/Student.h"
#include "include/lib.h"

int main()
{
    File file;
    // Thay đổi đường dẫn nếu "File not found"
    vector<Student> studentList = file.readStudents("data/students.csv");
    for (unsigned int i = 0; i < studentList.size(); i++)
    {
        cout << studentList[i].toString() << endl;
    }

    Random generator;
    cout << generator.next() << "\n";

    return 0;
}
#include "include/File.h"
#include "include/Random.h"
#include "include/Student.h"
#include "include/fullname.h"
#include "include/lib.h"

int main()
{
    File file;
#if 0
    vector<vector<string>> parsedStrings = file.readCSV("data/students.csv");

    Students students(parsedStrings);
    cout << students.toString() << endl;

    FullName name("Le", "Minh", "Quan");
    cout << name.toString() << endl;
#endif

    RandomFullName generator;

    for (int i = 0; i < 100; i++)
    {
        string s = generator.next().toString();
        cout << s << endl;
    }

    return 0;
}
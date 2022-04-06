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

    Random rng;
    RandomFullName fullNameRng;
  
    for (int i = 0; i < 100; i++)
    {
        cout << fullNameRng.next(rng).toString() << endl;
    }

    return 0;
}
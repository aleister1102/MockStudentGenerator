#include "include/Address.h"
#include "include/File.h"
#include "include/FullName.h"
#include "include/Random.h"
#include "include/Student.h"
#include "include/lib.h"

int main()
{
    File file;
	vector<vector<string>> parsedStrings = file.readCSV("data/students.csv");
	Students students(parsedStrings);
	cout << students.toString() << endl;
    
#if 0
	RandomStudents studentsRng;
	vector<Student> randomStudents = studentsRng.next();
	
	students.append(randomStudents);

	cout << students.toString() << endl;
	cout << students.calcAvgGPA() << endl;
#endif
    return 0;
}
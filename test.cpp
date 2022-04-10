#include "include/Address.h"
#include "include/File.h"
#include "include/FullName.h"
#include "include/Random.h"
#include "include/Student.h"
#include "include/lib.h"
#include "include/Number.h"

int main()
{
	//Read all students saved in the file "students.txt" back into a vector of Student
	File file;
	Students students(file.readStudents(STUDENTS));
	cout << students.toString() << endl;
	// Generate randomly a number n in the range of [5, 10]
	// and generate randomly n Students and add to the previous vector
	RandomStudents studentsRng;
	Students randomStudents(studentsRng.next());
	cout << "----- Random Students -----\n";
	cout << randomStudents.toString() << endl;
	// Overwrite and save and the students in the current vector back to the file "students.txt"
	cout << "----- Students after appending -----\n";
	students.append(randomStudents);
	cout << students.toString() << endl;
	file.writeStudents(STUDENTS, students.getStudents());
	// Print out the average GPA of all students
	cout << "----- Average Score -----\n";
	cout << "\t" << students.averageScore() << "\t" << endl;
	// Print out all the students that have a GPA greater than the average GPA
	cout << "----- Students have above average scorce -----\n";
	students.findAboveAvg();
	system("pause");
	return 0;
}
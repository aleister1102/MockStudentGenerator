#include "include/Address.h"
#include "include/File.h"
#include "include/FullName.h"
#include "include/Random.h"
#include "include/Student.h"
#include "include/lib.h"

int main()
{
	// Đọc students từ file (task 0)
	File file;
	Students students(file.readStudents(STUDENTS2));
	cout << students.toString() << endl;
	// Random số n và students (task 1 + 2)
	RandomStudents studentsRng;
	Students randomStudents(studentsRng.next());
	cout << "----- Random Students -----\n";
	cout << randomStudents.toString() << endl;
	// Tính điểm trung bình của students (task 4)
	cout << "----- Average Score -----\n";
	cout << students.averageScore() << endl;

#if 0
	// Viết các test unit như này,
	// chẳng hạn viết test cho phương thức String::trim
	string s = "    Nguyen Van    A   ";
	cout << String::trim(s) << endl;
#endif

#if 0
	string s = "20120356 Le Minh Quan";
	cout << String::searchRegex(s, ID) << endl;
#endif

	return 0;
}
#include "include/Address.h"
#include "include/File.h"
#include "include/FullName.h"
#include "include/Random.h"
#include "include/Student.h"
#include "include/lib.h"
#include "include/Number.h"

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
	// Append vào students và ghi đè vào file (task 3)
	cout << "----- Students after appending -----\n";
	students.append(randomStudents);
	cout << students.toString() << endl;
	file.writeStudents(STUDENTS2, students.getStudents());
	// Tính điểm trung bình của students (task 4)
	cout << "----- Average Score -----\n";
	cout << "\t" << students.averageScore() << "\t" << endl;
	// Tìm students có điểm lớn hơn trung bình (task 5)
	cout << "----- Students have above average scorce -----\n";
	students.findAboveAvg();
	system("pause");
	return 0;
}
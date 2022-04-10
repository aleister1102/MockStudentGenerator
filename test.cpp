#include "include/Address.h"
#include "include/File.h"
#include "include/FullName.h"
#include "include/Random.h"
#include "include/Student.h"
#include "include/lib.h"
#include "include/Number.h"

int main()
{
	// Đọc students từ file
	File file;
	Students students(file.readStudents(STUDENTS));
	cout << students.toString() << endl;
	// Random số n và students
	RandomStudents studentsRng;
	Students randomStudents(studentsRng.next());
	cout << "----- Random Students -----\n";
	cout << randomStudents.toString() << endl;
	// Append vào students và ghi đè vào file
	cout << "----- Students after appending -----\n";
	students.append(randomStudents);
	cout << students.toString() << endl;
	file.writeStudents(STUDENTS, students.getStudents());
	// Tính điểm trung bình của students
	cout << "----- Average Score -----\n";
	cout << "\t" << students.averageScore() << "\t" << endl;
	// Tìm students có điểm lớn hơn trung bình
	cout << "----- Students have above average scorce -----\n";
	students.findAboveAvg();
	system("pause");
	return 0;
}
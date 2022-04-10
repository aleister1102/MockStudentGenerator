#include "include/Address.h"
#include "include/File.h"
#include "include/FullName.h"
#include "include/Random.h"
#include "include/Student.h"
#include "include/lib.h"
#include "include/Number.h"

int main()
{
#if 0
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
	cout << students.averageScore() << endl;
	// Tìm students có điểm lớn hơn trung bình (task 5)
	cout << "----- Students have above average scorce -----\n";
	students.findAboveAvg();
#endif

#if 0
	// Viết các test unit như này,
	// chẳng hạn viết test cho phương thức String::trim
	string s = "    Nguyen   Van    A   ";
	cout << String::trim(s) << endl;
#endif

#if 0
	string s = "20120356 Le Minh Quan";
	cout << String::searchRegex(s, ID) << endl;
#endif

#if 0
	File file;
	vector<vector<string>> firstNames = file.readCSV(FIRSTNAMES);

	vector<tuple<string, string>> firstNamesTuples = parseFirstNames(firstNames);

	for (size_t i = 0; i < firstNamesTuples.size(); i++)
	{
		string firstName;
		string frequency;
		tie(firstName, frequency) = firstNamesTuples[i];
		cout << firstName << ": " << frequency << endl;
	}
#endif

#if 1
	string str = "12121.a1212";
	bool successful = false;
	int errorCode = 0;
	string message = "";
	float number = 0;

	tie(successful, errorCode, message, number) = Number::parseFloat(str);
	cout << number << endl;

#endif
	return 0;
}
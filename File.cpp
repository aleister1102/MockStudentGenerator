#include "include/File.h"

void File::readFile(string fileName)
{
	_file.open(fileName, ios::in);

	if (!_file)
	{
		cout << "File is not found!\n";
		_file.close();
	}
}

void File::writeFile(string fileName)
{
	_file.open(fileName, ios::out | ios::trunc);

	if (!_file)
	{
		cout << "File is not found!\n";
		_file.close();
	}
}

/**
 * Reads a CSV file and returns a vector of vectors of strings
 *
 * @param fileName the name of the file to be read
 *
 * @return A vector of vectors of strings.
 */
vector<vector<string>> File::readCSV(string fileName)
{
	vector<vector<string>> parsedStrings;

	readFile(fileName);

	string line;
	getline(_file, line);

	while (!_file.eof())
	{
		getline(_file, line);
		if (line == "")
			continue;
		vector<string> parsedString = String::split(line, ",");
		parsedStrings.push_back(parsedString);
	}

	_file.close();
	return parsedStrings;
}

/**
 * Reads a text file and returns a vector of strings
 *
 * @param fileName the name of the file to be read.
 *
 * @return A vector of strings.
 */
vector<string> File::readTXT(string fileName)
{
	vector<string> strings;

	readFile(fileName);

	string line;
	while (!_file.eof())
	{
		getline(_file, line);
		if (line == "")
			continue;
		strings.push_back(line);
	}

	_file.close();
	return strings;
}

vector<string> File::readStudentStrings(fstream& file)
{
	vector<string> studentStrings;
	for (int i = 0; i < 5; i++)
	{
		string line;
		getline(file, line);

		if (line == "")
			break;
		studentStrings.push_back(line);
	}
	return studentStrings;
}

/**
 * It reads a file, parses the file into a vector of strings, converts the vector of strings into a
 * vector of students, and returns the vector of students
 *
 * @param fileName The name of the file to read from.
 *
 * @return A vector of students.
 */
vector<Student> File::readStudents(string fileName)
{
	readFile(fileName);
	vector<Student> students;

	while (!_file.eof())
	{
		vector<string> studentStrings = readStudentStrings(_file);
		if (studentStrings.size() == 0)
			break;
		vector<string> attributes = String::parseStudentStrings(studentStrings);
		StringToStudentConverter converter;
		Student student = converter.convert(attributes);
		students.push_back(student);
	}

	_file.close();
	return students;
}

/**
 * It takes a vector of students and writes them to a file
 *
 * @param fileName The name of the file to be written to.
 * @param students
 */
void File::writeStudents(string fileName, vector<Student> students)
{
	writeFile(fileName);
	StringToStudentConverter converter;

	for (size_t i = 0; i < students.size(); i++)
	{
		vector<string> studentStrings = converter.convertBack(students[i]);
		for (int i = 0; i < 5; i++)
		{
			_file << studentStrings[i];
		}
	}

	_file.close();
}
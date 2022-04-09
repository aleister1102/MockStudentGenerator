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
	_file.open(fileName, ios::out);

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

vector<Student> File::readStudents(string fileName)
{
	readFile(fileName);
	vector<Student> students;

	while (!_file.eof())
	{
		vector<string> studentStrings;
		for (int i = 0; i < 5; i++)
		{
			string line;
			getline(_file, line);

			if (line.empty())
				continue;
			studentStrings.push_back(line);
		}
		vector<string> attributes = String::parseStudentStrings(studentStrings);
		Student student = Student::parseStudent(attributes);
		students.push_back(student);
	}

	_file.close();
	return students;
}
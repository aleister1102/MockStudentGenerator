#include "include/Random.h"
#include "include/Address.h"
#include "include/Date.h"
#include "include/File.h"

/**
 * @brief Khởi tạo hạt giống thời gian
 */
Random::Random()
{
	srand(time(NULL));
}

/**
 * @brief Tạo ra một số ngẫu nhiên
 *
 * @return Số vừa tạo
 */
int Random::next()
{
	int num = rand();
	return num;
}

/**
 * @brief Tạo ra một số ngẫu nhiên trong đoạn [min, max]
 *
 * @param min cận dưới
 * @param max cận trên
 * @return Số vừa tạo
 */
int Random::next(int min, int max)
{
	int num = rand() % (max - min + 1) + min;
	return num;
}

/**
 * @brief Tạo một số ngẫu nhiên trong nửa khoảng [0, ceiling)
 *
 * @param ceiling khoảng tạo số ngẫu nhiên mong muốn
 * @return Số vừa tạo
 */
int Random::next(int ceiling)
{
	int num = rand() % ceiling;
	return num;
}

// ---- First name ----

tuple <vector<string>, vector<float>> RandomFirstName::parseFirstNames(vector<vector<string>> collections)
{
	tuple <vector<string>, vector<float>> names_frequencies;

	for (size_t i = 0; i < collections.size(); i++)
	{
		get<0>(names_frequencies).push_back(collections[i][0]);
		get<1>(names_frequencies).push_back(Number::tryParseFloat(collections[i][1]));
	}

	return names_frequencies;
}

RandomFirstName::RandomFirstName()
{
	File file;
	auto firstNamesData = file.readCSV(FIRSTNAMES);
	tie(_firstNames, _frequencies) = parseFirstNames(firstNamesData);
}

string RandomFirstName::next(Random rng)
{
	float u = rng.next(0, 100) % 101 / 100.0;
	float sp = 0;
	int result = 0;

	for (size_t i = 0; i < _frequencies.size(); i++)
	{
		sp += _frequencies[i] / 100;
		if (sp >= u)
		{
			result = i;
			break;
		}
	}

	return _firstNames[result];
}

// ---- Full name ----

RandomFullName::RandomFullName()
{
	File file;
	_middleNames = file.readTXT(MIDDLENAMES);
	_lastNames = file.readTXT(LASTNAMES);
}

FullName RandomFullName::next(Random rng)
{
	string firstName = RandomFirstName().next(rng);
	string middleName = _middleNames[rng.next() % _middleNames.size()];
	string lastName = _lastNames[rng.next() % _lastNames.size()];

	FullName result(firstName, middleName, lastName);

	return result;
}

// ---- GPA ----

float RandomGPA::next(Random rng)
{
	return rng.next() % 1001 / 100.0;
}

// ---- Email ----

RandomEmail::RandomEmail()
{
	File file;
	_domains = file.readTXT(DOMAINS);
}

string RandomEmail::next(Random rng, FullName name)
{
	stringstream builder;
	builder << name.First().at(0) << name.Middle().at(0) << name.Last();
	builder << "@" << _domains[rng.next(10)];

	string result = String::toLowerCase(builder.str());
	return result;
}

// ---- Telephone ----

RandomTelephone::RandomTelephone()
{
	File file;
	_operator = file.readTXT(OPERATOR);
}

string RandomTelephone::next(Random rng)
{
	stringstream builder;

	int index = rng.next(_operator.size());
	builder << _operator[index];

	for (int i = 0; i < 7; i++)
	{
		int num = rng.next(10);
		builder << num;
		if (i == 0 || i == 3)
		{
			builder << "-";
		}
	}

	string result = builder.str();
	return result;
}

// ---- Date of Birth

Date RandomDOB::next(Random rng)
{
	Date dob;
	int year = rng.next(1905, 2022);
	int month = rng.next(1, 12);

	dob.setMonth(month);
	dob.setYear(year);

	int dayInMonth = dob.dateInMonth();

	int day = rng.next(1, dayInMonth);

	dob.setDay(day);

	return dob;
}

// ---- Adress ----

string RandomAddress::randomHouseNumber(Random rng)
{
	stringstream builder;

	int s1 = rng.next(1, 50);
	int s2 = rng.next(10, 40);

	builder << s1 << "/" << s2;

	string result = builder.str();

	return result;
}

RandomAddress::RandomAddress()
{
	File file;
	_streets = file.readTXT(STREETS);
	_wards = file.readTXT(WARDS);
	_districts = { "1", "2", "Tan Binh",
				"Binh Thanh", "Binh Tan" };
}

Address RandomAddress::next(Random rng)
{
	int temp1 = rng.next(_streets.size());
	string street = _streets[temp1];

	int temp2 = rng.next(_wards.size());
	string ward = _wards[temp2];

	int temp3 = rng.next(_districts.size());
	string district = _districts[temp3];

	string number = this->randomHouseNumber(rng);

	Address add(number, street, ward, district, "Ho Chi Minh");

	return add;
}

// ---- Student ----

Student RandomStudent::next(Random rng)
{
	Student result;

	RandomFullName fullNameRng;
	RandomGPA gpaRng;
	RandomEmail emailRng;
	RandomTelephone telephoneRng;
	RandomDOB dobRng;
	RandomAddress addressRng;

	result.setID(rng.next());
	FullName name = fullNameRng.next(rng);
	result.setName(name);
	result.setGPA(gpaRng.next(rng));
	result.setEmail(emailRng.next(rng, name));
	result.setTelephone(telephoneRng.next(rng));
	result.setDOB(dobRng.next(rng));
	result.setAddress(addressRng.next(rng));

	return result;
}

// ---- Students ----

vector<Student> RandomStudents::next()
{
	int size = _rng.next(5, 10);
	RandomStudent studentRng;
	vector<Student> randomStudents;

	for (int i = 0; i < size; i++)
	{
		Student randomStudent = studentRng.next(_rng);
		while (Student::isDuplicated(randomStudents, randomStudent))
		{
			randomStudent = studentRng.next(_rng);
		}

		randomStudents.push_back(randomStudent);
	}

	return randomStudents;
}
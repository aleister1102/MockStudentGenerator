#include "include/Random.h"
#include "include/Address.h"
#include "include/DOB.h"
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

// ---- Full name ----
RandomFullName::RandomFullName()
{
	File file;
	_middleNames = file.readTXT(MIDDLENAMES);
	_lastNames = file.readTXT(LASTNAMES);
}

FullName RandomFullName::next()
{
	string firstName = _firstNameRng.next();
	string middleName = _middleNames[_rng.next() % _middleNames.size()];
	string lastName = _lastNames[_rng.next() % _lastNames.size()];

	FullName result(firstName, middleName, lastName);

	return result;
}

// ---- First name ----
RandomFirstName::RandomFirstName()
{
	File file;

	vector<vector<string>> firstNamesData = file.readCSV(FIRSTNAMES);
	_firstNames = FullName::parseFirstNames(firstNamesData, _frequencies);
}

string RandomFirstName::next()
{
	float u = _rng.next() % 100 / 100.0;
	float sp = 0;
	int result = 0;

	for (int i = 0; i < _frequencies.size(); i++)
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

// ---- Email ----
RandomEmail::RandomEmail()
{
	File file;
	_domains = file.readTXT(DOMAINS);
}

/**
 * Generate a random email address for a given name
 *
 * @param name The full name of the person.
 *
 * @return A string.
 */
string RandomEmail::next(FullName name)
{
	stringstream builder;
	builder << name.First().at(0) << name.Middle().at(0) << name.Last();
	builder << "@" << _domains[_rng.next(10)];

	string result = String::toLowerCase(builder.str());
	return result;
}

// ---- Telephone ----
RandomTelephone::RandomTelephone()
{
	File file;

	_operator = file.readTXT(OPERATOR);
}

string RandomTelephone::next()
{
	stringstream builder;

	int index = _rng.next(_operator.size());
	builder << _operator[index];

	for (int i = 0; i < 7; i++)
	{
		int num = _rng.next(10);
		builder << num;
		if (i == 0 || i == 3)
		{
			builder << "-";
		}
	}

	string result = builder.str();
	return result;
}

// ---- Day of birth ----
Date RandomDOB::next()
{
	Date dob;
	int year = _rng.next(1905, 2022);
	int month = _rng.next(1, 12);

	dob.setMonth(month);
	dob.setYear(year);

	int dayInMonth = dob.dateInMonth();

	int day = _rng.next(1, dayInMonth);

	dob.setDay(day);

	return dob;
}

// ---- Adress ----
RandomAddress::RandomAddress()
{
	_streets = { "Binh Hung Hoa", "Nam Ky Khoi Nghia", "Nguyen Van Cu", "Ton Duc Thang",
				"Pham Ngoc Thach" };
	_wards = {
		"Ward 2",
		"Ward 3",
		"Son Ky Ward",
		"Tan Son Nhi Ward",
		"Da Kao Ward" };

	_districts = { "District 1", "District 2", "Tan Binh District", "Binh Thanh District", "Binh Tan District" };
}

string RandomAddress::randomNumber()
{
	stringstream builder;

	int s1 = _rng.next(1, 50);
	int s2 = _rng.next(10, 40);

	builder << s1 << "/" << s2;

	string result = builder.str();

	return result;
}

Address RandomAddress::next()
{
	int temp1 = _rng.next(_streets.size());
	string street = _streets[temp1];

	int temp2 = _rng.next(_wards.size());
	string ward = _wards[temp2];

	int temp3 = _rng.next(_districts.size());
	string district = _districts[temp3];

	string number = this->randomNumber();

	Address add(number, street, ward, district, "Ho Chi Minh city");

	return add;
}

RandomStudent::RandomStudent()
{
}

Student RandomStudent::next()
{
	Student result;

	Random rng;
	RandomFullName fullNameRng;
	RandomEmail emailRng;
	RandomTelephone telephoneRng;
	RandomDOB dobRng;
	RandomAddress addressRng;

	result.setID(rng.next());
	FullName name = fullNameRng.next();
	result.setName(name);
	result.setGPA(rng.next() % 100 / 100.0);
	result.setEmail(emailRng.next(name));
	result.setTelephone(telephoneRng.next());
	result.setDOB(dobRng.next());
	result.setAddress(addressRng.next());

	return result;
}
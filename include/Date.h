#pragma once
#include "lib.h"
#include "String.h"
#include "Number.h"

class Date;

class Date
{
private:
	int _day;
	int _month;
	int _year;

public:
	void setDay(int value) { _day = value; }
	void setMonth(int value) { _month = value; }
	void setYear(int value) { _year = value; }

public:
	Date();
	Date(int, int, int);

public:
	bool checkLeapYear();
	int dateInMonth();
	bool isDate();
	string toString();
	static Date parseDate(string);
	bool operator==(const Date&);
};
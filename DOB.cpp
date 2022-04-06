#include "include/DOB.h"

Date::Date()
{
	_day = 1;
	_month = 1;
	_year = 1;
}

Date::Date(int d, int m, int y)
{
	_day = d;
	_month = m;
	_year = y;
}

string Date::toString()
{
	stringstream builder;

	builder << _day << "/" << _month << "/" << _year;

	string result = builder.str();
	return result;
}

bool Date::checkLeapYear()
{
	return (((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0));
}

int Date::dateInMonth()
{
	int countDays = 0;

	switch (_month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		countDays = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		countDays = 30;
		break;
	case 2:
		if (this->checkLeapYear())
		{
			countDays = 29;
		}
		else
		{
			countDays = 28;
		}
		break;
	}

	return countDays;
}

bool Date::isDate()
{
	if (_year < 0)
	{
		return false;
	}

	if (_month < 1 || _month > 12)
	{
		return false;
	}

	if (_day < 1 || _day > this->dateInMonth())
	{
		return false;
	}

	return true;
}
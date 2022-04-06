#pragma once
#include "lib.h"
#include "String.h"

class Date
{
private:
     int _day;
     int _month;
     int _year;

public:
     Date();
     Date(int, int, int);

public:
     bool checkLeapYear();
     int dateInMonth();
     bool isDate();

     void setDay(int value) { _day = value; }
     void setMonth(int value) { _month = value; }
     void setYear(int value) { _year = value; }

     Date parseDOB(string);

     string toString();
};
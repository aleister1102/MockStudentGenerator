#include "include/RandomDOB.h"
#include "include/DOB.h"

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

#pragma once
#include "lib.h"

class Address
{
private:
     string _number;
     string _street;
     string _ward;
     string _district;
     string _city;

public:
     Address();
     Address(string, string, string, string, string);

public:
     string toString();
};
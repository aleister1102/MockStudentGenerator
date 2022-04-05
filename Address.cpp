#include "include/Address.h"

Address::Address()
{
     _number = "";
     _street = "";
     _ward = "";
     _district = "";
     _city = "";
}

Address::Address(string number, string street, string ward, string district, string city)
{
     _number = number;
     _street = street;
     _ward = ward;
     _district = district;
     _city = city;
}

string Address::toString()
{
     stringstream builder;

     builder << "Address of student: " << _number << " " << _street << " "
             << _ward << " " << _district << " " << _city << "\n";

     string result = builder.str();
     return result;
}
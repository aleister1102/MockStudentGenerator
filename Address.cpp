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

	builder << _number << ", " << _street << ", "
		   << _ward << ", " << _district << ", " << _city;

	string result = builder.str();
	return result;
}

Address Address::parseAddress(string str)
{
	vector<string> address = String::parseString(str);

	Address result;

	result.setNumber(address[0]);
	result.setStreet(address[1]);
	result.setWard(address[2]);
	result.setDistrict(address[3]);
	result.setCity(address[4]);

	return result;
}
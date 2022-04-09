#pragma once
#include "lib.h"
#include "String.h"

class Address;

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
	void setNumber(string value) { _number = value; }
	void setStreet(string value) { _street = value; }
	void setWard(string value) { _ward = value; }
	void setDistrict(string value) { _district = value; }
	void setCity(string value) { _city = value; }

	static Address parseAddress(vector<string>);

	string toString();
};
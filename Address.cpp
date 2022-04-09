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

	builder << _number << " " << _street << ", ";

	if (String::searchRegex(_ward, NUMBERS) != "")
	{
		builder << "Ward " << _ward << ", ";
	}
	else
	{
		builder << _ward << " Ward" << ", ";
	}

	if (String::searchRegex(_district, NUMBERS) != "")
	{
		builder << "District " << _district << ", ";
	}
	else
	{
		builder << _district << " District" << ", ";
	}

	builder << _city << " city";

	string result = builder.str();
	return result;
}

// addressDetails thực chất là vector gồm các thuộc tính của Student
// index từ 6 - 10 là thuộc về Address
Address Address::parseAddress(vector<string> addressDetails)
{
	Address result;

	result.setNumber(addressDetails[6]);
	result.setStreet(addressDetails[7]);
	result.setWard(addressDetails[8]);
	result.setDistrict(addressDetails[9]);
	result.setCity(addressDetails[10]);

	return result;
}
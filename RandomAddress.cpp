#include "include/RandomAddress.h"
#include "include/Address.h"

string RandomAddress::randomNumber()
{
     stringstream builder;

     int s1 = _rng.next(1, 50);
     int s2 = _rng.next(10, 40);

     builder << s1 << "/" << s2;

     string result = builder.str();

     return result;
}

RandomAddress::RandomAddress()
{
     _streets = {"Binh Hung Hoa", "Nam Ky Khoi Nghia", "Nguyen Van Cu", "Ton Duc Thang",
                 "Pham Ngoc Thach"};
     _wards = {
         "Ward 2",
         "Ward 3",
         "Son Ky Ward",
         "Tan Son Nhi Ward",
         "Da Kao Ward"};

     _districts = {"District 1", "District 2", "Tan Binh District", "Binh Thanh District", "Binh Tan District"};
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

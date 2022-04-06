#pragma once
#include "lib.h"
#include "DOB.h"
#include "Address.h"

class Random;
class RandomDOB;
class RanmdomAddress;

class Random
{
public:
     Random();

public:
     int next();
     int next(int, int);
     int next(int);
};

string RandomTelephone();
class RandomDOB
{
private:
     Random _rng;

public:
     Date next();
};
class RandomAddress
{
private:
     vector<string> _numbers;
     vector<string> _streets;
     vector<string> _wards;
     vector<string> _districts;
     vector<string> _citys;

     Random _rng;

public:
     RandomAddress();

public:
     string randomNumber();
     Address next();
};

// class Fullname
// {
// private:
//      string _first;
//      string _middlle;
//      string _last;

// public:
//      Fullname();
//      Fullname(string, string, string);

// public:
//      string toString();
// };

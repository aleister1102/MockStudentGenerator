#pragma once
#include "File.h"
#include "FullName.h"
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

class RandomFullName
{
private:
     vector<string> _middleNames;
     vector<string> _lastNames;
public:
     RandomFullName();

public:
     FullName next(Random);
};

class RandomFirstName
{
private:
    vector<string> _firstNames;
    vector<float> _frequencies;
public:
    RandomFirstName();
public:
    string next(Random rng);
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

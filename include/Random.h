#pragma once
#include "Address.h"
#include "DOB.h"
#include "File.h"
#include "FullName.h"
#include "lib.h"

class Random;
class RandomFirstName;
class RandomFullName;
class RandomDOB;
class RanmdomAddress;
class RandomEmail;

class Random
{
public:
     Random();

public:
     int next();
     int next(int, int);
     int next(int);
};

class RandomFirstName
{
private:
     vector<string> _firstNames;
     vector<float> _frequencies;
     Random _rng;

public:
     RandomFirstName();

public:
     string next();
};
class RandomFullName
{
private:
     vector<string> _middleNames;
     vector<string> _lastNames;
     Random _rng;
     RandomFirstName _firstNameRng;

public:
     RandomFullName();

public:
     FullName next();
};

class RandomEmail
{
private:
    vector<string> _domains;
    Random _rng;
public:
    RandomEmail();
public:
    string next(FullName);
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
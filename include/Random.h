#pragma once
#include "Address.h"
#include "Date.h"
#include "File.h"
#include "FullName.h"
#include "lib.h"

class Random;
class RandomFirstName;
class RandomFullName;
class RandomEmail;
class RandomTelephone;
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

class RandomFirstName
{
private:
	vector<string> _firstNames;
	vector<float> _frequencies;

public:
	RandomFirstName();

public:
	string next(Random);
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

class RandomGPA {
public:
	float next(Random);
};

class RandomEmail
{
private:
	vector<string> _domains;

public:
	RandomEmail();

public:
	string next(Random, FullName);
};

class RandomTelephone
{
private:
	vector<string> _operator;

public:
	RandomTelephone();

public:
	string next(Random);
};

class RandomDOB
{
public:
	Date next(Random);
};

class RandomAddress
{
private:
	vector<string> _numbers;
	vector<string> _streets;
	vector<string> _wards;
	vector<string> _districts;

public:
	RandomAddress();

public:
	string randomNumber(Random);
	Address next(Random);
};

class RandomStudent
{
public:
	Student next(Random);
};

class RandomStudents
{
private:
	Random _rng;
public:
	vector<Student> next();
};
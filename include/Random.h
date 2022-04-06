#pragma once
#include "File.h"
#include "FullName.h"
#include "lib.h"

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